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
#include "gtest_lite.h"

double Resistor::defR = 76;

Resistor::Resistor(): R(defR) {
    Pr("ctor0");
}

Resistor::Resistor(double r): R(r) {
    Pr("ctor1");
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

Resistor::Resistor(const Resistor& rhs): R(rhs.getR()) {
    Pr("copy");
}

Resistor::~Resistor() {
    Pr("dtor");
}

Resistor& Resistor::operator=(const Resistor& rhs) {
    Pr("assign");
    this->R = rhs.getR();
    return *this;
}

double Resistor::getI(double u) const {
    return u / this->R;
}

double Resistor::getU(double i) const {
    return i * this->R;
}

bool Resistor::operator==(const Resistor& r) const {
    return gtest_lite::almostEQ<double>(this->R, r.getR());
}

std::ostream& operator<<(std::ostream& os, const Resistor& rhs) {
    os << rhs.getR();
    return os;
}
