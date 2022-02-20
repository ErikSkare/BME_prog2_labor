#ifndef STRING1_H
#define STRING1_H

/**
 * \file string2.h
 * (UTF-8 kodolasu fajl. Allitsa/konvertalja at a kodolast,
 *  ha a tovabbi kommentek nem olvashatok helyesen!)
 *
 *
 * Dinamikus String létrehozása C++-ban.
 * A példa a C++ osztály fogalmának megértését készíti elő.
 *
 * A C nyelvű megoldáshoz képesti változtatások:
 *   1. Kihasználjuk, hogy a struktúra név típussá változott.
 *   2. Kihasználjuk a fv túlterhelés (oveload) lehetőségét, így az azonos
 *      funkciójú függvényeknek azonos a neve (createString, addString)
 *   3. A String paramétereket pointer helyett referenciával adjuk át.
 *   4. C++ memóriakezelését használjuk.
 *   5. Hibás indexelést kivétellel jelezzük
 *
 */

#define ELKESZULT    5  /// értékeit l. alább
/**
 * Az ELKESZULT makró értékét annak megfelelően állítsa
 * 0,1,2,3,4 vagy 5 értékűre, hogy hol tart a feladat megoldásában!
 * Ha folyamatosan halad, akkor a kód mindig fordítható és futtatható lesz.
 * Így az egyes részek a teljes feladat befejezése nélkül is kipróbálhatók.
 *
 * ELKESZULT lehetséges értékei:
 *   0 - Nem egészített ki egyetlen hiányos függvényt sem.
 *   1 - Elkészítette a createString(String&, const char*) függvényt.
 *   2 - Elkészítette a createString(String&, const String&) függvényt.
 *   3 - Elkészítette a charAtString(const String& s0, unsigned int idx) függvényt
 *   4 - Elkészítette az addString(cont String&, char) függvényt.
 *   5   ELkészítette az addString(const String&, const String& b) függvényt
 */

/**
 * String struktúra
 * A pData által mutatott dinamikus területen vannak a karakterek (a lezáró nullával együtt).
 * A len mező a tényleges hossz, amibe nem számít bele a lezáró nulla.
 */
struct String {
    char *pData;        /// pointer az adatra
    unsigned int len;   /// hossz lezáró nulla nélkül
};

inline std::ostream& operator<<(std::ostream& os, const String& s) {
    os << s.pData;
    return os;
}

/**
 * Inicializálatlan struktúrát hoz alapállapotba
 * @param s0  - referencia az adatstruktúrára (String-re)
 */
void createString(String &s0);

/**
 * Sztring felszabadítása
 * Ha dinamikus memóriát használunk, gondoskodni kell a lefoglalt terület felszabadításról is.
 * Feltételezzük, hogy csak létező (inicializált) String-re használjuk.
 * @param s0  - referencia a String-re
 */
void disposeString(String& s0);

/**
 * C sztringre konvertál, azaz visszaad egy pointert a tárolt,
 * nullával lezárt sztring-re.
 * Most így tárolunk, de nem feltétlen kell így tárolnunk.
 * Ez az interfész (fv.) elfedi a belső tárolást.
 * Feltételezzük, hogy a paraméterként megadott sztring létezik
 * @param s0  - referencia a String-re
 */
const char* StringC_str(const String &s0);

/**
 * Visszaadja a sztring tényleges hosszát (lezáró nulla nélkül).
 * Most így tárolunk, de nem feltétlen kell így tárolnunk.
 * Ez az interfész (fv.) elfedi a belső tárolást.
 * Feltételezzük, hogy a paraméterként megadott sztring létezik
 * @param s0  - referencia a String-re
 */
unsigned int StringLen(const String &s0);


/**
 * Kiírunk egy sztringet (debug célokra)
 * Feltételezzük, hogy a paraméterként megadott sztring létezik
 * @param s0  - referencia a String-re
 */
void printStringDbg(const String &s0);

/**
 * Stringet készít egy karakterből
 * Feltételezzük, hogy a sztring nem létezik még (pData és len inicializálatlan).
 * @param s0  - referencia a String-re
 * @param ch - a karakter amiből elkészíti a Stringet
 */
void createString(String &s0, char ch);

/**
 * SZringet készít nullával lezárt karaktersorozatból (C-sztringből)
 * Feltételezzük, hogy a String nem létezik még (pData és len inicializálatlan).
 * @param s0 - referencia a String-re
 * @param p  - pointer a C sztringre (feltételezhetjük, hogy nem NULL)
 */
void createString(String& s0, const char *p);

/**
 * Stringet készít egy sztringből
 * Feltételezzük, hogy a sztring nem létezik még (pData és len inicializálatlan).
 * @param s0  - referencia a String-re
 * @param s1  - referencia a másik String-re (Feltételezzük, hogy ez létezik!)
 */
void createString(String& s0, const String& s1);

/**
 * Egy megadott indexű elemmel tér vissza.
 * Feltételezzük, hogy a paraméterként megadott String létezik
 * Hibás index esetén const char* kivételt dob-
 * @param s0  - referencia a String-re
 * @param idx - index
 * @return idx indexű karakter
 */
char charAtString(const String& s0, unsigned int idx);

/**
 * Két sztringet összefűz.
 * Az eredményt egy harmadikba (visszatérési érték) írja.
 * Feltételezzük, hogy a paraméterként megadott String-ek léteznek
 * @param s0  - referencia az egyik String-re
 * @param s1  - referencia a másik String-re
 * @return új String: A két sztring összefûzve.
 */
 String addString(const String& s0, const String& s1);

/**
 * String végéhez karaktert ad.
 * Az eredményt egy harmadikba (visszatérési érték) írja.
 * Feltételezzük, hogy a paraméterként megadott sztring létezik
 * @param s0 - referencia a String-re
 * @param ch - a karakter amit hozzáfűz
 * @return új String
 */
String addString(const String& s0, char ch);


#endif
