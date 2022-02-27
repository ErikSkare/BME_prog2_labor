/**
 * \file komplex.cpp
 *
 * Komplex osztályt megvalósító függvények definíciója.
 *
 * Folytassa a megvalósítást sorrendben a komplex.h fájlban levő feladatoknak megfelelően!
 *
 */


#include <iostream>         // Valószínű, hogy a kiíráshoz majd kell
#include <iomanip>          // ... és ez is.
#include <cmath>            // az sqrt miatt kell.

#include "komplex.h"        // Ebben van a Komplex osztály, és néhány globális függvény deklarációja

///using namespace std;  // ha nagyon kell, akkor csak itt nyissuk ki a névteret, a headerben soha!

/// Előre elkészített tagfüggvények

/// 0, 1 és 2 paraméteres konstruktor
/// Figyelje meg, hogy a default argumentumokat CSAK a deklarációnál
/// adtuk meg!
Komplex::Komplex(double r, double im) {
    re = r; // ha nincs névütközés, nem kell kiírni a this-t
    this->im = im;
}

///---- Egy példa a konstans tagfüggvényre, ehhez hasonlóan kell
///     elkészíteni a gettereket az 1. feladatban (ELKESZULT=1)
/// Abszolút érték lekérdezése
/// @return - abszolút érték
double Komplex::abs() const { return sqrt(re*re + im*im); }

// 1. feladat
double Komplex::getRe() const { return re; }
double Komplex::getIm() const { return im; }

// 2. feladat
void Komplex::setRe(double re) { this->re = re; }
void Komplex::setIm(double im) { this->im = im; }

// 3. feladat
bool Komplex::operator==(const Komplex& rhs_k) const {
    return this->re == rhs_k.re && this->im == rhs_k.im;
}

// 4. feladat
Komplex Komplex::operator+(const Komplex& rhs_k) const {
    return {this->re + rhs_k.re, this->im + rhs_k.im};
}
Komplex Komplex::operator+(double rhs_d) const {
    return {this->re + rhs_d, this->im};
}

// 5. feladat
Komplex operator+(double rhs_d, const Komplex& rhs_k) {
    return {rhs_d + rhs_k.getRe(), rhs_k.getIm()};
}

// 6. feladat
Komplex& Komplex::operator+=(const Komplex& rhs_k) {
    this->re += rhs_k.getRe();
    this->im += rhs_k.getIm();
    return *this;
}

// 7. feladat
std::ostream& operator<<(std::ostream& o, const Komplex& rhs_k) {
    o << rhs_k.getRe();
    o << (rhs_k.getIm() >= 0 ? "+" : "");
    o << rhs_k.getIm() << "j";
    return o;
}
std::istream& operator>>(std::istream& i, Komplex& rhs_k) {
    std::string s;
    i>>s;
    int pos = std::min(s.find("+"), s.find("-"));
    std::string re = s.substr(0, pos);
    std::string im = s.substr(pos, s.length() - pos - 1);
    rhs_k.setRe(std::stod(re.c_str()));
    rhs_k.setIm(std::stod(im.c_str()));
    return i;
}

// 8. feladat
Komplex Komplex::operator~() const {
    return {re, -im};
}

// 9. feladat
Komplex Komplex::operator*(const Komplex& rhs_k) const {
    return {
        this->re * rhs_k.re - this->im * rhs_k.im,
        this->re * rhs_k.im + this->im * rhs_k.re
    };
}
Komplex Komplex::operator*(double rhs_d) const {
    return {
        this->re * rhs_d,
        this->im * rhs_d
    };
}
Komplex& Komplex::operator*=(const Komplex& rhs_k) {
    double cpy_re = this->re;
    double cpy_im = this->im;
    this->re = cpy_re * rhs_k.re - cpy_im * rhs_k.im;
    this->im = cpy_re * rhs_k.im + cpy_im * rhs_k.re;
    return *this;
}
Komplex& Komplex::operator*=(double rhs_d) {
    this->re = this->re * rhs_d;
    this->im = this->im * rhs_d;
    return *this;
}

#if ELKESZULT >= 3
// 3. feladathoz (ELKESZULT 3)
// összehasonlítás
/// Egyenlőtlenség vizsgálat
/// @param rhs_k - jobb oldali operandus (Komplex)
/// @return hamis - ha a képzetes és a valós rész is azonos, egyébként false
bool Komplex::operator!=(const Komplex& rhs_k) const {  // visszavezetjük az egyenlőség vizsgálatra
    return !(*this == rhs_k);
}
#endif

#if ELKESZULT >= 6
// 6. feladathoz (ELKESZULT 6)
// a += művelet viszont módosítja önmagát!
/// Komplex + double
/// @param rhs_d - jobb oldali operandus (double)
/// @return eredeti (bal oldali) objektum ref., amihez hozzáadtuk rhd_d-t
Komplex& Komplex::operator+=(double rhs_d) {
    re += rhs_d;
    return *this;
}
#endif

// ------------------------ Eddig elkészítettük -------------------------
// TODO: A hiányzó tag- és globális függvények itt következnek

