/**
 * \file resistor.cpp
 *   (UTF-8 kodolasu fajl. Allitsa at a megjenetes kodolasat,
 *    ha a tovabbi kommentek nem olvashatok helyesen!)
 *
 * Ohmikus ellenállást modellező osztály megvalósítása
 */

/**
 * Itt kell megvalósítani a resistor.h-ban deklarált nem inline függvényeket.
 * A Jportára ezt a fájlt kell feltölteni.
 */

#include "resistor.h"

double Resistor::defR = 76;

Resistor::Resistor() {
    this->R = defR;
}

Resistor::Resistor(double r) {
    this->R = r;
}

void Resistor::setDef(double r) {
    Resistor::defR = r;
}

Resistor Resistor::operator+(const Resistor& r) const {
    return Resistor(this->R + r.getR());
}

Resistor Resistor::operator%(const Resistor& r) const {
    return Resistor(1 / ((1 / this->R) + (1 / r.getR())));
}

Resistor operator*(int n, const Resistor& r) {
    if(n <= 0)
        throw "Z7ZF6D";
    return Resistor(n * r.getR());
}
