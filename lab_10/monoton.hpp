#ifndef MONOTON_HPP
#define MONOTON_HPP
#include "iterator"

template <typename Iter, typename T>
bool monoton(Iter eleje, Iter vege, T funk) {
    bool flag = true;
    while(eleje != vege) {
        Iter curr = eleje;
        ++eleje;
        Iter nxt = eleje;
        if(nxt != vege)
            flag &= funk(*nxt, *curr);
    }
    return flag;
}

#endif
