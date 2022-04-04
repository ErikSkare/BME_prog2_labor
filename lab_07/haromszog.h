/**
 *  \file haromszog.h
 *  Haromszog osztály deklarációja
 */
#ifndef HAROMSZOG_H
#define HAROMSZOG_H

/// Ügyeljen arra, hogy a csúcspontokat az alaposztály orgiójához relatívan tárolja!

#include "alakzat.h"
#include "pont.h"

class Haromszog : public Alakzat {
    Pont p1, p2;

public:
    Haromszog(const Pont& p0, const Pont& p1, const Pont& p2, const Szin& sz)
        : Alakzat(p0, sz), p1(p1), p2(p2) {}

    void rajzol() const;

    Pont getp1() const { return p1; }

    Pont getp2() const { return p2; }
};

std::ostream& operator<<(std::ostream&, const Haromszog&);

#endif // KOR_H

