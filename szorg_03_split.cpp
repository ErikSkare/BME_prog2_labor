/**
*    @file split.cpp
*    Be kell adni!
*    Ide kerül a Split osztály megvalósítása
*/

#include "split.hpp"
#include "memtrace.h"

Split::Split(char hat) : Allapotgep(SplitAllapot::kezdo, tab), aktualis(""), hat(hat) {
    tab[SplitAllapot::kezdo] = {
        {SplitInput::hatarolo, new Nop(SplitAllapot::elhagy)},
        {SplitInput::egyeb, new Kiir(SplitAllapot::normal, *this)}
    };
    tab[SplitAllapot::normal] = {
        {SplitInput::hatarolo, new Berak(SplitAllapot::elhagy, *this)},
        {SplitInput::egyeb, new Kiir(SplitAllapot::normal, *this)}
    };
    tab[SplitAllapot::elhagy] = {
        {SplitInput::hatarolo, new Nop(SplitAllapot::elhagy)},
        {SplitInput::egyeb, new Kiir(SplitAllapot::normal, *this)}
    };
}

SplitInput Split::input(char ch) const {
    if(ch == hat) return SplitInput::hatarolo;
    else return SplitInput::egyeb;
}
