/**
 * \file: vektor_test.cpp

 * Egyszerű teszt iterátoros generikus tömb továbbfejlesztéséhez.
 * STL algoritmusainak próbálgatásához.
 */


#define ELKESZULT 12

#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>
#include <iomanip>
#include "compat.hpp"
#include "vektor.hpp"

#if ELKESZULT >= 12
#include "mystack.hpp"
#endif

using std::cout;
using std::endl;


/// -----------------------------------------
/// 9. laboron elkészített sablonok: (forEach, ostreamFunktor)
/// forEach sablon
template <typename Iter, class Func>
Func forEach(Iter first, Iter last, Func func) {
    while (first != last)
        func(*first++);
    return func;
}
/// Funktor a kiírásokhoz
template <class T>
class ostreamFunctor {
   std::ostream& os;
   const char* delim;
public:
   ostreamFunctor(std::ostream& os, const char* delim = "") : os(os), delim(delim) {}
   void operator()(const T& d) const { os << d << delim; }
};
///------------------------------------------

/// Funktor hogy negatív-e
/// cout_if-ben használjuk
template <typename T>
struct negativ {
    bool operator()(const T& val) { return val < 0; }
};

int main() {
    /// Egyszerű C tömbök, amiből majd az adatokat vesszük
    int it1[] = {-5, -4, -3, -2, -1, 0, 1, -82, 3, 4 };                 // 10 adat van
    double dt1[] = { .0,  234.1,  .2,  .3,  -444.4, -12.4, 128.799 };   //  7 adat van

    try {

#if ELESZULT >= 0
        /// létrehozunk egy funktort a kiíráshoz
        ostreamFunctor<int> intout(cout, ", ");
        /// segítségével kiírjuk az it1 adatait
        cout << "it1: ";
		forEach(it1, it1+10, intout);
		cout << endl;
#endif // ELEKSZULT >= 0

#if ELKESZULT >= 1
/// 1. feladat:
        /// Kiírás std::for_each segítségével.
        /// A funktort a for_each paraméterlistáján példányosítsa!
        /// Próbálja ki!
        std::for_each(it1, it1+10, ostreamFunctor<int>(cout, ", "));
        cout << endl;
        cout << "it1 (for_each): ";
#endif // ELKESZULT >= 1

#if ELKESZULT >= 2
        Vektor<double, 50> otos(8, 5.1);
        cout << "otos: ";
        std::for_each(otos.begin(), otos.end(), ostreamFunctor<double>(cout, ", "));
		cout << endl;
#endif // ELKESZULT >= 2

#if ELKESZULT >= 3
        Vektor<double, 100> darr(dt1, dt1+7);
        cout << "darr: ";
		std::for_each(darr.begin(), darr.end(), ostreamFunctor<double>(cout, ", "));
		cout << endl;
#endif // ELKESZULT >= 3

#if ELKESZULT >= 4
        cout << "push_back proba" << endl;
        darr.push_back(100);
        cout << "darr: ";
		std::for_each(darr.begin(), darr.end(), ostreamFunctor<double>(cout, ", "));
		cout << endl;
#endif // ELKESZULT >= 4

#if ELKESZULT >= 5
        cout << "back: " << darr.back() << endl;
        darr.pop_back();
        cout << "darr: ";
		std::for_each(darr.begin(), darr.end(), ostreamFunctor<double>(cout, ", "));
		cout << endl;
		cout << "empty: " << std::boolalpha << darr.empty() << endl;
#endif // ELKESZULT >= 5

#if ELKESZULT >= 6
        cout << "it1-ben negativ: ";
        std::cout << std::count_if(it1, it1+10, negativ<int>());
		cout << endl;
#endif // ELKESZULT >= 6

#if ELKESZULT >= 7
        cout << "darr-ban negativ: ";
        cout << std::count_if(darr.begin(), darr.end(), negativ<double>());
		cout << endl;
#endif // ELKESZULT >= 7

#if ELKESZULT >= 8
        std::less<int> lt;
        cout << "less teszt: " << std::boolalpha << lt(8, 100) << endl;
        cout << "darr-ban kisebb, mint 100: ";
        cout << std::count_if(darr.begin(), darr.end(), std::bind2nd(std::less<double>(), 100));
		cout << endl;
#endif // ELKESZULT >= 8

#if ELKESZULT >= 9
        cout << "copy-val darr: ";
		std::copy(darr.begin(), darr.end(), std::ostream_iterator<double>(cout, ", "));
		cout << endl;

#endif // ELKESZULT >= 9

#if ELKESZULT == 10
        std::remove_if(darr.begin(), darr.end(), std::bind2nd(std::less<double>(), 100)); // 100-nál kisebb elemek törlése
        cout << "remove_if utan: ";
		std::for_each(darr.begin(), darr.end(), ostreamFunctor<double>(cout, ", "));
		cout << endl;
#endif // ELKESZULT == 10

#if ELKESZULT >= 11
        Vektor<double, 100>::iterator dblit;
        dblit = std::remove_if(darr.begin(), darr.end(), std::bind2nd(std::less<double>(), 100)); // 100-nál kisebb elemek törlése
        darr.erase(dblit, darr.end());
        cout << "remove es erase utan: ";
		std::for_each(darr.begin(), darr.end(), ostreamFunctor<double>(cout, ", "));
		cout << endl;
#endif // ELKESZULT >= 11

#if ELKESZULT >= 12
    MyStack<char, Vektor<char, 15> > cstk;
    cstk.push('*');
    cstk.push('*');
    cstk.push('*');
    cstk.push('E');
    cstk.push('G');
    cstk.push('E');
    cstk.push('V');
    cstk.push('*');
    cstk.push('*');
    cstk.push('*');
    while (!cstk.empty()) {
        cout << cstk.top();
        cstk.pop();
    }
    cout << endl;
    cstk.pop();     // hibát kell dobnia
#endif // ELKESZULT >= 12

    } catch (std::exception& e) {   // az out_of_range, és a runtime_error is
                                    // az excetion-ból származik. Így kompatibilisek
                                    // az alaposztállyal
        cout << e.what() << endl;
    }
}
