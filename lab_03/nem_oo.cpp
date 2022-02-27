#include <cstring>
#include <cctype>
#include "nem_oo.h"

/**
 * \file nem_oo_teszt.cpp
 * (UTF-8 kodolasu fajl. Allitsa at a kodolast,
 *  ha a tovabbi kommentek nem olvashatok helyesen!)
 *
 * FELADATOK:
 *  1. Ebben a fájlban valósítsa meg a nem_oo.h állományban deklarált függvényeket!
 *
 * Ügyeljen a helyes névtér használatra!
 *   Tipp: Használja a scope operátort, vagy nyisson névteret!
 */

int sajat::atoi(const char *p, int base) {
    int val = 0;
    for(int i = 0; p[i] != ' ' && p[i] != '\0'; ++i) {
        int curr;
        if(p[i] <= '9')
            curr = p[i] - '0';
        else
            curr = 10 + p[i] - 'A';
        if(curr < 0 || curr >= base)
            throw "Z7ZF6D";
        val = val * base + curr;
    }
    return val;
}

char *sajat::strcat(const char *p1, const char *p2) {
    int len1 = strlen(p1);
    int len2 = strlen(p2);
    int len = len1 + len2;
    char *res = new char[len + 1];
    for(int i = 0; i < len1; ++i)
        res[i] = p1[i];
    for(int i = 0; i < len2; ++i)
        res[len1 + i] = p2[i];
    res[len] = '\0';
    return res;
}

char *sajat::unique(char *first, char *last) {
    int index = 0;
    char prev = '\0';
    for(char *curr = first; curr != last; ++curr) {
        if(*curr != prev)
            first[index++] = *curr;
        prev = *curr;
    }
    return first + index;
}
