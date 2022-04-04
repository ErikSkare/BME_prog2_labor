/**
 *  \file rajztabla.h
 *  Rajztabla osztály deklarációja
 */

#ifndef RAJZTABLA_H
#define RAJZTABLA_H

#include "alakzat.h"


/// Rajztabla osztály
class Rajztabla  {
    static const size_t MAXDB = 100;///< legegyszerűbb így belső (egész) konstanst felvenni egy osztályban.
    Alakzat* tabla[MAXDB];          ///< tároló
    size_t db;                      ///< aktuális darabszám

    /// "Elrejtett" másoló konstruktor és értékadó operátor.
    /// Az alapértelmezett változat nem jó, ezért ne legyen elérhető.
    Rajztabla(const Rajztabla& rhs);
    Rajztabla& operator=(const Rajztabla& rhs);
public:
    Rajztabla() :db(0) { }

    /// Visszadja, hogy hány síkidom van a táblán
    /// @return - darabszám
    size_t size() const { return db; }

    /// Alakzatot tesz a rajztáblára
    /// @param ap - pointer az alakzatra
    void felrak(Alakzat *ap);

    /// Kirajzolja az összes alakzatot
    void rajzol() const ;

    /// Az összes alakzatot elmozdítja
    /// @param d - eltolás vektora
    void mozgat(const Pont& d) const ;

    /// letörli a táblát eltávolítja az objektumokat
    void torol();

    /// Lehet, hogy kell destruktor is.
    ~Rajztabla() { torol(); }

};

inline std::ostream& operator<<(std::ostream& os, const Rajztabla& r) {
    return os << r.size();
}

#endif // RAJZTABLA_H
