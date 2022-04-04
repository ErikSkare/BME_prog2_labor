/**
 *  \file haromszog.cpp
 *  Haromszog osztály tagfüggvényeinek megvalósítása
 */
#include "haromszog.h"

void Haromszog::rajzol() const {
    std::cout << "Rajzol: " << *this << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Haromszog& h) {
    return os
    << "Haromszog "
    << h.getp0() << " "
    << h.getp1() << " "
    << h.getp2() << " "
    << h.getsz();
}
