/**
 * \file: hetero_store.hpp
 *
 */

#ifndef HETEROSTORE_HPP
#define HETEROSTORE_HPP

#include <iostream>
#include <stdexcept>

template <typename T, size_t C = 100, class E = std::out_of_range>
class HeteroStore {
    size_t index = 0;
    T *elems[C];

private:
    HeteroStore(const HeteroStore&);
    HeteroStore& operator=(const HeteroStore&);

public:
    HeteroStore() {}
    ~HeteroStore() { clear(); }

    inline size_t size() { return index; }
    inline size_t capacity() { return C; }

    void add(T *p) {
        if(index == C) {
            delete p;
            throw E("");
        }
        elems[index++] = p;
    }

    void traverse(std::function<void(T*)> func) {
        for(size_t i = 0; i < index; ++i)
            func(elems[i]);
    }

    void clear() {
        for(size_t i = 0; i < index; ++i)
            delete elems[i];
        index = 0;
    }
};

#endif // HETEROSTORE_HPP
