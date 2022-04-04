#ifndef MYSET_HPP
#define MYSET_HPP

#define ELKESZULT 4

#include "point.h"

bool operator==(const Point& a, const Point& b) {
    return a.getX() == b.getX() && a.getY() == b.getY();
}

template <typename T>
bool equal(const T& a, const T& b) {
    return a == b;
}

template <>
bool equal(const Point& a, const Point& b) {
    return a.getX() == b.getX();
}


template <typename T, size_t N = 10>
class Set {
    T t[N];
    size_t db;

public:
    Set(): db(0) { }

    size_t size() const { return db; }

    bool isElement(T elem) const {
        for(size_t i = 0; i < db; ++i)
            if(equal(t[i], elem))
                return true;
        return false;
    }

    void insert(T elem) {
        if(db == N) throw "hiba";
        if(!isElement(elem)) t[db++] = elem;
    }
};

#endif
