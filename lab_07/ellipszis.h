/**
 *  \file ellipszis.h
 *  Ellipszis osztály deklarációja és definiciója.
 *
 * !!!HIBÁS!!!
 *  Ez a megoldás egy könnyen elkövethető hibát mutat be.
 *  A hiba elkövetését a "mindent írjunk egy fájlba" gondolat/gyakorlat mágnesként vonzza.
 *
 *  A hiba igazi oka a kompatibilitásból fakadó típuskonverzióra vezethető vissza.
 *
 *
 */
#ifndef ELLIPSZIS_H
#define ELLIPSZIS_H

#include "kor.h"

class Ellipszis;
std::ostream& operator<<(std::ostream&, const Ellipszis&);

/// Ellipszis osztály.
/// A Kor adatait excentricitás értékkel bővítjük
class Ellipszis : public Kor {
    double e;       /// excentricitás értéke  [ e = c/a, e = sqrt(1-b^2/a^2) ]
public:
    /// konstruktor 2 pontból
    /// @param p0 - kezdőpont
    /// @param r  - sugár
    /// @param e  - excentricitás
    /// @param sz - szín és átlátszóság
    Ellipszis(const Pont& p0, int r, double e, Szin sz)
                     : Kor(p0, r, sz), e(e) { }

    /// Ellipszis excentricitásának lekérdezése
    /// @return excentricitás
    double gete() const { return e; }

    /// Eltipszist rajzol
    void rajzol() const	   { std::cout << "Rajzol: " << *this << std::endl; }
};

/// Globális << operátor a Ellipszis adatainak kiírásához
/// @param os - ostream
/// @param el - ellipszis
/// @return os - ostream
inline std::ostream& operator<<(std::ostream& os, const Ellipszis& el) {
     return os << "Ellipszis " << (Alakzat&)el << ",r=" << el.getr() << ",e=" << el.gete();
}

#endif // ELLIPSZIS_H

