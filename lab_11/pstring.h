#ifndef PSTRING_H
#define PSTRING_H

#include <iostream>
#include "serializable.h"
#include "string5.h"

class PString : public Serializable, public String {
public:
    PString() : String() { }
    PString(char ch) : String(ch) {}
    PString(const char *p) : String(p) {}
    PString(const String& s) : String(s) {}
    void write(std::ostream& os) const;
    void read(std::istream& is);
};

#endif
