/**
 * \file allapotgep.cpp
 *
 * Ebben a fájlban kell megvalósítania az Allapotgep osztály
 * metódusait, valamint mindazon további osztályokat, melyek szükségesek
 * a feladat megvalósításához.
 *
 * Ezt a fájlt be kell adni (fel kell tölteni) a megoldással.
 */

#include <iostream>
#include <fstream>

#include "allapotgep.h"
#include "memtrace.h"

inline int Atmenetek::cast_id(Bazis b) {
    int id;
    switch(b) {
        case Adenin: id = 0; break;
        case Citozin: id = 1; break;
        case Guanin: id = 2; break;
        case Timin: id = 3; break;
    }
    return id;
}

Allapot *Atmenetek::operator[](Bazis b) {
    return hova[cast_id(b)];
}

void Atmenetek::setHova(Bazis b, Allapot *hova) {
    this->hova[cast_id(b)] = hova;
}

char *Allapot::getNev() { return nev; }
void Allapot::setNev(char *nev) { this->nev = nev; }

bool Allapot::getElfogado() { return elfogado; }
void Allapot::setElfogado(bool elfogado) { this->elfogado = elfogado; }

Allapot::~Allapot() { delete[] nev; }

std::istream& operator>>(std::istream& is, Allapot& rhs) {
    char *nev = new char[21];
    char elfogado_c;

    is >> elfogado_c >> nev;

    rhs.setNev(nev);
    rhs.setElfogado((elfogado_c == 'I'));

    return is;
}

void Allapotgep::konfigural(const char* fajlnev) {
    std::ifstream fs; fs.open(fajlnev);
    if(!fs.is_open())
        throw "Z7ZF6D";

    delete[] allapotok;
    int N; fs >> N;
    allapotok = new Allapot[N];
    aktualis = allapotok;

    for(int i = 0; i < N; ++i)
        fs >> allapotok[i];

    char c;
    fs.get(c);

    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            char c;
            fs.get(c);
            while(c == ' ' || c == '\n')
                fs.get(c);
            if(c == '0') continue;
            while(c != ' ' && c != '\n') {
                allapotok[i].atmenetek.setHova(cast(c), &allapotok[j]);
                fs.get(c);
            }
        }
    }

    fs.close();
}

const char* Allapotgep::aktualisallapot() {
    return aktualis->getNev();
}

bool Allapotgep::elfogad() {
    return aktualis->getElfogado();
}

void Allapotgep::atmenet(Bazis b) {
    Allapot *kov = aktualis->atmenetek[b];
    if(kov != NULL)
        aktualis = kov;
}

bool Allapotgep::feldolgoz(const Bazis *b, int n) {
    for(int i = 0; i < n; ++i)
        atmenet(b[i]);
    return elfogad();
}

void Allapotgep::alaphelyzet() {
    aktualis = allapotok;
}

Allapotgep::~Allapotgep() {
    delete[] allapotok;
}
