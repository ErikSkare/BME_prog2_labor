/**
 * \file: hetero_store.hpp
 *
 */

#ifndef HETEROSTORE_HPP
#define HETEROSTORE_HPP

#include <iostream>
#include <stdexcept>

template<typename T, size_t N = 100, class E = std::out_of_range>
class HeteroStore {
    T* t[N];
    size_t db;

public:
    HeteroStore(): db(0) { }

    size_t size() const { return db; }

    size_t capacity() const { return N; }

    void add(T* p) {
        if(db == N) { delete p; throw E("hello"); }
        t[db++] = p;
    }

    void traverse(std::function<void(T*)> func) const {
        for(size_t i = 0; i < db; ++i)
            func(t[i]);
    }

    void clear() {
        for(size_t i = 0; i < db; ++i)
            delete t[i];
        db = 0;
    }

    ~HeteroStore() { clear(); }
};

#endif // HETEROSTORE_HPP
