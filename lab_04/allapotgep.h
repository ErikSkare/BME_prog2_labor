/**
 * \file allapotgep.h
 *
 * Ebben a fájlban találja az Allapotgep osztály kezdeti definícióját és két segédfüggvényt.
 *
 * A fájlt tetszés szerint módosíthatja, azzal a megkötéssel, hogy
 * nem hozhat létre globális függvényt és nem változtathatja az Allapotgep osztály
 * publikus interfészét.
 *
 * Új osztályokat, típusokat felvehet.
 *
 * Ezt a fájlt be kell adni (fel kell tölteni) a megoldással.
 */

#ifndef ALLAPOTGEP_H
#define ALLAPOTGEP_H

#include <locale>
#include <iostream>
#include <exception>

#include "memtrace.h"

/**
 * Bázisok
 */
enum Bazis {
    Adenin, Citozin, Guanin, Timin
};

class Allapot;
class Atmenetek;

class Atmenetek {
    Allapot *hova[4] = {NULL, NULL, NULL, NULL}; // A-0, C-1, G-2, T-3

    inline int cast_id(Bazis b);

public:
    Allapot *operator[](Bazis b);

    void setHova(Bazis b, Allapot *hova);
};

class Allapot {
    char *nev;
    bool elfogado;

public:
    Atmenetek atmenetek;

    char *getNev();
    void setNev(char *nev);

    bool getElfogado();
    void setElfogado(bool elfogado);

    ~Allapot();
};

std::istream& operator>>(std::istream& is, Allapot& rhs);

/**
 * Állapotgép publikus interfésze.
 * A privát részt szabadon változtathatja, de a publikus részt ne változtassa, ne bővítse!
 */
class Allapotgep {
    Allapot *allapotok = NULL;
    Allapot *aktualis = NULL;

public:
    /**
     * Konfig fájl beolvasása. Ha a fájl nem létezik/nem lehet megnyitni eldobja a NEPTUN-kódot.
     * Újra felépíti az állapotgépet, a korábbit törli ha volt. Kezdő állapotba áll.
     * @param  fajlnév - fájl neve
     * @return -
     * @exception fájl megnyitási hiba esetén NEPTUN_KÓD
    */
    void konfigural(const char* fajlnev);

    /** Visszaadja melyik állapot aktív.
     * @return pointer az aktív állapot nevére
     */
    const char* aktualisallapot();

    /**
     * Elfogadó állapotban van-e az állapotgép.
     * @return true, ha elfogadó állapotban van
     */
    bool elfogad();

    /**
     * Az aktuális állapotnak és inputnak megfelelő következő állapotba léptet.
     * @param b - beérkező bázis, mint input
     */
    void atmenet(Bazis b);

    /**
     * Feldolgozza a paraméterként kapott bázissorozatot.
     * Visszaadja, hogy elfogadó állapotba került-e. (Nem áll vissza kezdő állapotba.)
     * @param b - input sorozatra mutató pointer
     * @param n - a sorozat hossza
     * @return tru, ha elfogadó állapotba került
    */
    bool feldolgoz(const Bazis *b, int n);

    /**
     * Kezdő állapotba visz.
     */
    void alaphelyzet();

    ~Allapotgep();
};

/**
 * Segédfüggvény, karakterből enummá konvertál.
 * @param  b - bázis 1 betűs jele
 * @return Bazis enum kontans
 */
inline Bazis cast(char b) {
    std::locale loc;
    char k = std::tolower(b, loc);
    Bazis ret;
    switch(k) {
        case 'a': ret = Adenin; break;
        case 'c': ret = Citozin; break;
        case 'g': ret = Guanin; break;
        case 't': ret = Timin; break;
        default: throw "Format!!"; break;
    }
    return ret;
}

/**
 * Segédfüggvény, Bazis konstansból karakterré konvertál.
 * @param b - bazis enum konstansa
 * @param upper - nagybetűs legyen-e
 * @return bázis 1 betűs jele
 */
inline char cast(Bazis b, bool upper = true) {
    char ret = '0';
    switch (b)
    {
        case Adenin: ret = 'a'; break;
        case Citozin: ret = 'c'; break;
        case Guanin: ret = 'g'; break;
        case Timin: ret = 't'; break;
    }
    if(upper) {
        std::locale loc;
        ret = std::toupper(ret, loc);
    }
    return ret;
}

#endif
