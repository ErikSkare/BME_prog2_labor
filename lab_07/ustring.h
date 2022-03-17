#ifndef USTRING_H
#define USTRING_H
#include "string5.h"

class UString : public String {
    static bool allapot;

public:
    UString(): String() {}
    UString(char& c): String(c) {}
    UString(const char *str): String(str) {}
    UString(const String& str): String(str) {}

    static void UCase(bool c) { UString::allapot = c; }
    static bool UCase() { return UString::allapot; }
};

std::ostream& operator<<(std::ostream&, const UString&);

#endif // USTRING_H
