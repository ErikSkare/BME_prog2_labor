// Fájl: fuggvenyeim.cpp
// Ebben valósítom meg a gyakran használt függvényeket.

#include <cmath>
#include <limits>
#include "fuggvenyeim.h"

// Két int adat felcserélése
void csere(int& a, int& b) {
   int tmp = a;
   a =  b;
   b = tmp;
}

/// Segédfüggvény double pontosságú számok összehasonlításához
/// Nem bombabiztos, de nekünk most jó lesz
/// Elméleti hátér:
/// http://www.cygnus-software.com/papers/comparingfloats/comparingfloats.htm
bool almostEQ(double a, double  b) {
    // eps: ha a relatív, vagy abszolút hiba ettől kisebb, akkor elfogadjuk
    double eps = 50 * std::numeric_limits<double>::epsilon(); // 50-szer a legkisebb absz. (!=0) érték: ~1e-14
    if (a == b) return true;
    if (fabs(a - b) < eps)
       return true;
    double aa = fabs(a);
    double ba = fabs(b);
    if (aa < ba) {
        aa = ba;
        ba = fabs(a);
    }
    return (aa - ba) < aa * eps;
}

double polinom(const double x, double *egyutthatok, const int fokszam) {
    double eredmeny = 0;
    for(int i = fokszam; i >= 1; i--) {
        eredmeny += egyutthatok[i];
        eredmeny *= x;
    }
    return eredmeny + egyutthatok[0];
}
