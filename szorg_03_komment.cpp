/**
*    @file komment.cpp
*    Be kell adni!
*    Ide kerül a Komment osztály megvalósított függvényei
*/

#include <string>
#include "memtrace.h"
#include "komment.hpp"

Komment::Komment() : Allapotgep(KommentAllapot::normal, tab), result("") {
    tab[KommentAllapot::normal] = {
        {KommentInput::per, new Nop(KommentAllapot::elhagy_lehet)},
        {KommentInput::csillag, new Kiir1(KommentAllapot::normal, *this)},
        {KommentInput::egyeb, new Kiir1(KommentAllapot::normal, *this)}
    };
    tab[KommentAllapot::elhagy_lehet] = {
        {KommentInput::per, new Kiir1(KommentAllapot::elhagy_lehet, *this)},
        {KommentInput::csillag, new Nop(KommentAllapot::elhagy)},
        {KommentInput::egyeb, new Kiir2(KommentAllapot::normal, *this)}
    };
    tab[KommentAllapot::elhagy] = {
        {KommentInput::per, new Nop(KommentAllapot::elhagy)},
        {KommentInput::csillag, new Nop(KommentAllapot::vege_lehet)},
        {KommentInput::egyeb, new Nop(KommentAllapot::elhagy)}
    };
    tab[KommentAllapot::vege_lehet] = {
        {KommentInput::per, new Nop(KommentAllapot::normal)},
        {KommentInput::csillag, new Nop(KommentAllapot::vege_lehet)},
        {KommentInput::egyeb, new Nop(KommentAllapot::elhagy)}
    };
}

KommentInput Komment::input(char ch) const {
    if(ch == '/') return KommentInput::per;
    else if(ch == '*') return KommentInput::csillag;
    else return KommentInput::egyeb;
}
