/**
 *  \file rajztabla.cpp
 *   Ebben a fájlban valósítsa meg a Rajztábla osztály nem inline tagfüggvényeit
 */


#include "rajztabla.h"

void Rajztabla::felrak(Alakzat *ap) {
    tabla[db++] = ap;
}

void Rajztabla::rajzol() const {
    for(size_t i = 0; i < db; ++i)
        tabla[i]->rajzol();
}

void Rajztabla::mozgat(const Pont& d) const {
    for(size_t i = 0; i < db; ++i)
        tabla[i]->mozgat(d);
}

void Rajztabla::torol() {
    for(size_t i = 0; i < db; ++i)
        delete tabla[i];
    db = 0;
}
