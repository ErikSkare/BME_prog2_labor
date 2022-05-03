/**
 * \file: mystack.hpp
 *
 */


template <class T, class Container = std::vector<T>>
class MyStack {
    Container tar;

public:
    bool empty() const { return tar.size() == 0; }

    T& top() {
        if (empty()) throw std::out_of_range("hiba");
        return tar.back();
    }

    void push(const T& t) { tar.push_back(t); }

    void pop() {
        if (empty()) throw std::out_of_range("hiba");
        tar.pop_back();
    }
};
