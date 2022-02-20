/**
 * \file string2.cpp
 * (UTF-8 kodolasu fajl. Allitsa/konvertalja at a kodolast,
 *  ha a tovabbi kommentek nem olvashatok helyesen!)
 *
 * Dinamikus String létrehozása C-ben.
 * A példa a C++ osztály fogalmának megértését készíti elő.
 * Az egységesség kedvéért minden String paramétert referenciaként adtunk át.
 *
 * FELADAT:
 * Valósítsa meg a hiányzó függvényeket C++ nyelven!
 *   (2 db createString, charAtString, és 2 db addString)
 * A függvények prototípusát a fájl végére másoltuk sring2.h fáljból
 * A megvalósítást segíti a C nyelvű változat (string1.c).
 */

#include <iostream>             // Kiíratáshoz
#include <cstring>              // Stringműveletekhez
#include "string2.h"

/// malloc, new felüldefiniálásával készített memóriaszivárgás és konzisztencia ellenőrző
#include "memtrace.h"           // a standard headerek után kell lennie

#include "string2.h"            /// saját sztring header

using std::cout;
using std::endl;

/**
 * Inicializálatlan struktúrát hoz alapállapotba
 * @param s0  - referencia az adatstruktúrára (String-re)
 */
void createString(String &s0) {
    s0.pData = NULL;
    s0.len = 0;
}

/**
 * Sztring felszabadítása
 * Ha dinamikus memóriát használunk, gondoskodni kell a lefoglalt terület felszabadításról is.
 * Feltételezzük, hogy csak létező (inicializált) String-re használjuk.
 * @param s0  - referencia a String-re
 */
void disposeString(String& s0) {
    delete[] s0.pData;		// felszabadítjuk
}

/**
 * C sztringre konvertál, azaz visszaad egy pointert a tárolt,
 * nullával lezárt sztring-re.
 * Most így tárolunk, de nem feltétlen kell így tárolnunk.
 * Ez az interfész (fv.) elfedi a belső tárolást.
 * Feltételezzük, hogy a paraméterként megadott sztring létezik
 * @param s0  - referencia a String-re
 */
const char* StringC_str(const String &s0) {
    return s0.pData;
}

/**
 * Visszaadja a sztring tényleges hosszát (lezáró nulla nélkül).
 * Most így tárolunk, de nem feltétlen kell így tárolnunk.
 * Ez az interfész (fv.) elfedi a belső tárolást.
 * Feltételezzük, hogy a paraméterként megadott sztring létezik
 * @param s0  - referencia a String-re
 */
unsigned int StringLen(const String &s0) {
    return s0.len;
}

/**
 * Kiírunk egy sztringet (debug célokra)
 * Feltételezzük, hogy a paraméterként megadott sztring létezik
 * @param s0  - referencia a String-re
 */
void printStringDbg(const String &s0) {
#ifdef DEBUG
    cout << '[' << s0.len << "], " << s0.pData << '|' << endl;
#endif
}

/**
 * Stringet készít egy karakterből
 * Feltételezzük, hogy a sztring nem létezik még (pData és len inicializálatlan).
 * @param s0  - referencia a String-re
 * @param ch - a karakter amiből elkészíti a Stringet
 */
void createString(String& s0, char ch) {
    /// Meghatározzuk a hosszát
    s0.len = 1;
    /// Lefoglalunk a helyet a hossznak + a lezáró nullának
    s0.pData = new char[s0.len+1];
    /// Betesszük a karaktert
    s0.pData[0] = ch;
    s0.pData[1] = '\0';
}


// Az alábbi függvényeket kell megvalósítania.
// Alakítsa át a deklarációkat definíciókká!

/**
 * SZringet készít nullával lezárt karaktersorozatból (C-sztringből)
 * Feltételezzük, hogy a String nem létezik még (pData és len inicializálatlan).
 * @param s0 - referencia a String-re
 * @param p  - pointer a C sztringre (feltételezhetjük, hogy nem NULL)
 */
void createString(String& s0, const char *p) {
    s0.len = strlen(p);
    s0.pData = new char[s0.len + 1];
    strcpy(s0.pData, p);
}

/**
 * Stringet készít egy sztringből
 * Feltételezzük, hogy a sztring nem létezik még (pData és len inicializálatlan).
 * @param s0  - referencia a String-re
 * @param s1  - referencia a másik String-re (Feltételezzük, hogy ez létezik!)
 */
void createString(String& s0, const String& s1) {
    s0.len = s1.len;
    s0.pData = new char[s0.len + 1];
    strcpy(s0.pData, s1.pData);
}

/**
 * Egy megadott indexű elemmel tér vissza.
 * Feltételezzük, hogy a paraméterként megadott String létezik
 * Hibás index esetén const char* kivételt dob-
 * @param s0  - referencia a String-re
 * @param idx - index
 * @return idx indexű karakter
 */
char charAtString(const String& s0, unsigned int idx) {
    if(idx >= s0.len)
        throw "hiba";
    return s0.pData[idx];
}

/**
 * Két sztringet összefűz.
 * Az eredményt egy harmadikba (visszatérési érték) írja.
 * Feltételezzük, hogy a paraméterként megadott String-ek léteznek
 * @param s0  - referencia az egyik String-re
 * @param s1  - referencia a másik String-re
 * @return új String: A két sztring összefûzve.
 */
 String addString(const String& s0, const String& s1) {
    String res;
    res.len = s0.len + s1.len;
    res.pData = new char[res.len + 1];
    strcpy(res.pData, s0.pData);
    strcat(res.pData, s1.pData);
    return res;
 }

/**
 * String végéhez karaktert ad.
 * Az eredményt egy harmadikba (visszatérési érték) írja.
 * Feltételezzük, hogy a paraméterként megadott sztring létezik
 * @param s0 - referencia a String-re
 * @param ch - a karakter amit hozzáfűz
 * @return új String
 */
String addString(const String& s0, char ch) {
    String res, temp;
    createString(temp, ch);
    res = addString(s0, temp);
    disposeString(temp);
    return res;
}
