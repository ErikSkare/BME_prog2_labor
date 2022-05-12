/**
*    @file komment.hpp
*    Be kell adni!
*    Ide kerül a Komment osztály deklarációja
*/

#ifndef KOMMENT_HPP
#define KOMMENT_HPP

#include <string>  //használandó az std::string
#include "memtrace.h"
#include "allapotgep.hpp"

enum class KommentAllapot {
    normal,
    elhagy_lehet,
    elhagy,
    vege_lehet,
};

enum class KommentInput {
    per,
    csillag,
    egyeb
};

class Komment : public Allapotgep<KommentAllapot, KommentInput, char> {
    Allapotgep::AllTabla tab;
    std::string result;

    struct Kiir1 : public Nop {
        Komment& allapotgep;
        Kiir1(KommentAllapot all, Komment& allapotgep) : Nop(all), allapotgep(allapotgep) { }
        void akcio(char ch) { allapotgep.result += ch; }
    };
    struct Kiir2 : public Nop {
        Komment& allapotgep;
        Kiir2(KommentAllapot all, Komment& allapotgep) : Nop(all), allapotgep(allapotgep) { }
        void akcio(char ch) {
            allapotgep.result += '/';
            allapotgep.result += ch;
        }
    };

public:
    Komment();

    KommentInput input(char ch) const;

    std::string get() const { return result; }
};

#endif
