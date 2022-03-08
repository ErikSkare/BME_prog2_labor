#include "vektor.h"

size_t Vektor::defSize = 21.;
double Vektor::defValue = 51.;

Vektor::Vektor(const Vektor& v) {
    size_t size = v.size();
    nElements = size;
    pVec = new double[size];
    for(size_t i = 0; i < size; ++i)
        pVec[i] = v[i];
}

Vektor::~Vektor() {
    delete[] pVec;
}

Vektor& Vektor::operator=(const Vektor& v) {
    if(&v != this) {
        delete[] pVec;
        size_t size = v.size();
        nElements = size;
        pVec = new double[size];
        for(size_t i = 0; i < size; ++i)
            pVec[i] = v[i];
    }
    return *this;
}

double& Vektor::operator[](size_t idx) {
    if(idx < 0 || idx >= nElements)
        throw "Z7ZF6D";
    return pVec[idx];
}

const double& Vektor::operator[](size_t idx) const {
    if(idx < 0 || idx >= nElements)
        throw "Z7ZF6D";
    return pVec[idx];
}

Vektor operator*(double val, const Vektor& vec) {
    Vektor res(vec);
    size_t size = vec.size();
    for(size_t i = 0; i < size; ++i)
        res[i] *= val;
    return res;
}
