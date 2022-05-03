#include "pstring.h"

void PString::write(std::ostream& os) const {
    os << size() << ',';
    os.write(c_str(), size());
    os << '\n';
}

void PString::read(std::istream& is) {
    size_t len;
    (is >> len).ignore(1);
    char *p = new char[len+1];
    is.read(p,len).ignore(1);
    p[len] = 0;
    *this = String(p);
    delete[] p;
}
