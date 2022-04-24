#ifndef SABLONOK_HPP
#define SABLONOK_HPP
#include <iostream>

template <typename Iter>
void printEach(Iter eleje, Iter vege, std::ostream& os = std::cout, std::string szep = ", ") {
    while(eleje != vege) {
        os << *eleje;
        ++eleje;
        os << (eleje == vege ? "\n" : szep);
    }
}

template <typename Iter>
int szamol_ha_negativ(Iter eleje, Iter vege) {
    int cnt = 0;
    while(eleje != vege) {
        cnt += (*eleje < 0);
        eleje++;
    }
    return cnt;
}

template <typename T>
struct nagyobb_mint {
    T a;

    nagyobb_mint(T a) : a(a) { }

    bool operator()(T x) { return x > a; }
};

template <typename Iter, typename Pred>
int szamol_ha(Iter eleje, Iter vege, Pred x) {
    int cnt = 0;
    while(eleje != vege) {
        cnt += x(*eleje);
        ++eleje;
    }
    return cnt;
}


/// F�ggv�nysablon, ami ki�rja egy generikus t�mb adatait
/// Felt�telezz�k, hogy a generikus t�mbnek van:
///   - ForwardIteratora, size(), valamint capacity() tagf�ggv�nye
/// @param T   - sablon param�ter: iter�toros t�mb t�pus
/// @param txt - ki�rand� sz�veg
/// @param arr - konkr�t t�mb
/// @param os  - output steram
template <class T>
void PrintArray(const char *txt, const T& arr, std::ostream& os = std::cout) {
    os << txt << " size=" << arr.size()
         << " capacity=" << arr.capacity() << std::endl;
    os << "\t data=";
    // ki�rjuk az adatokat
    printEach(arr.begin(), arr.end(), os, ",");
}

template <typename InputIterator, class Func>
Func forEach(InputIterator first, InputIterator last, Func func) {
    while(first != last) {
        func(*first);
        ++first;
    }
    return func;
}

template <typename T>
struct ostreamFunctor {
    std::ostream& os;
    std::string szep;

    ostreamFunctor(std::ostream& os, std::string szep) : os(os), szep(szep) { }

    void operator()(T x) { os << x << szep;}
};

#endif
