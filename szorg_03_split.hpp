/**
*    @file split.hpp
*    Be kell adni!
*    Ide kerül a Split osztály deklarációja
*/

#ifndef SPLIT_HPP
#define SPLIT_HPP

#include <string>
#include <vector>
#include "memtrace.h"
#include "allapotgep.hpp"

enum class SplitAllapot {
    kezdo,
    normal,
    elhagy,
};

enum class SplitInput {
    hatarolo,
    egyeb
};

class Split : public Allapotgep<SplitAllapot, SplitInput, char> {
    Allapotgep::AllTabla tab;
    std::vector<std::string> result;
    std::string aktualis;
    char hat;

    struct Kiir : public Nop {
        Split& allapotgep;
        Kiir(SplitAllapot all, Split& allapotgep) : Nop(all), allapotgep(allapotgep) { }
        void akcio(char ch) { allapotgep.aktualis += ch; }
    };

    struct Berak : public Nop {
        Split& allapotgep;
        Berak(SplitAllapot all, Split& allapotgep) : Nop(all), allapotgep(allapotgep) { }
        void akcio(char ch) {
            allapotgep.result.push_back(allapotgep.aktualis);
            allapotgep.aktualis = "";
        }
    };

public:
    Split(char hat);

    SplitInput input(char ch) const;

    std::vector<std::string> get() {
        if(aktualis != "") {
            std::vector<std::string> cpy = result;
            cpy.push_back(aktualis);
            return cpy;
        }
        return result;
    }
};

#endif
