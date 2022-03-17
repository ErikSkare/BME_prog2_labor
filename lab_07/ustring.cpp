#include "ustring.h"

bool UString::allapot = false;

std::ostream& operator<<(std::ostream& os, const UString& str) {
    const char *content = str.c_str();
    if(UString::UCase())
        for(size_t i = 0; i < str.size(); ++i)
            os << (char)std::toupper(content[i]);
    else
        os << content;
    return os;
}
