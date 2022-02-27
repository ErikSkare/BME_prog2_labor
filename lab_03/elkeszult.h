#ifndef ELKESZULT_H
#define ELKESZULT_H
/**
 * \file elkeszult.h
 *
 */

/// Készültségi fok beállítása
#define ELKESZULT 9
/**
 *ELKESZULT értéke - feladatok:
 * 0. Csak az előre elkészített tagfüggvények (konstruktorok, getRe, abs) működnek.
 * 1. Készítsen lekérdező függvényeket a valós és képzetes rész lekérdezésére:
 *    getRe(), getIm()! Ügyeljen arra, hogy konstans objektumra is működjön!
 *    (Konstans objektumra csak olyan tagfüggvény alkalmazható, ami nem
 *    változtatja az objektum állapotát.)
 *    A példában a getRe() függvénynek van const és nem const változata is.
 *    Esetünkben ez értelmetlen, de azt kívánja demonstrálni, hogy ez két külön
 *    tagfüggvény.
 * 2. Készítsen beállító függvényeket a valós és képzetes rész beállítására!
 *    setRe(double), setIm(double)
 * 3. Készítsen egyenlőségvizsgáló (==) operátort!
 *    A != operátort már elkészítettük, ami az == -re vezeti vissza a feladatot.
 * 4. Készítsen + operátort (összeadás)! Működjön valóssal is (először csak jobbról)!
 * 5. Készítsen olyan összeadó operátort, ami alkalmas valós + komplex összeadására!
 *    (A double + Komplex esetben a bal oldali operandus nem objektum, így globális
 *     operátorfüggvénnyel kell megvalósítani a feladatot.)
 * 6. Készítsen += operátort!
 *    Megj: A += valós változatot már elkészítettük!
 *
 * Szorgalmi feladatok:
 * 7. Legyen kiírható a komplex adat egy ostream típusú objektumra a << operátorral
 *    1+34j ill. 1-34j alakban!
 *    Be lehessen olvasni egy istream típusú objektumból a >> operátorral
 *    ugyanilyen (1+34j) alakban!
 *    Megj: A kért kiírási formátumban a képzetes rész előtt ki kell írni a képzetes rész
 *    előjelét (a pozitívat is), de a valós rész előtt csak a negatív előjel
 *    jelenjen meg! (tipp: showpos, noshowpos, ignore)
 * 8. Valósítsa meg a ~ operátort, amely a komplex szám konjugáltját képzi.
 * 9. Készítsen * operátort (szorzás)! Működjön valóssal balról és jobbról is!
 *    Készítsen *= operátort! Működjön valóssal (double) is!
 */
#endif
