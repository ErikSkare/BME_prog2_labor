#ifndef BICIKLI_H
#define BICIKLI_H

class Kerek {
    int atmero;

public:
    Kerek(int atmero): atmero(atmero) { std::cout << "\tKerek ctor\n"; }

    Kerek(const Kerek& k): atmero(k.atmero) { std::cout << "\tKerek copy\n"; }

    virtual ~Kerek() { std::cout << "\tKerek dtor\n"; }

    void kiir() { std::cout << "atmero=" << atmero << std::endl; }
};

class Monocikli {
    Kerek k;

public:
    Monocikli(): k(16) { std::cout << "\tMonocikli ctor\n"; }

    Monocikli(const Monocikli& m): k(m.k) { std::cout << "\tMonocikli copy\n"; }

    void kiir() { std::cout << "\tk."; k.kiir(); }
};

class Jarmu {
    double vMax;

public:
    Jarmu(double v): vMax(v) { std::cout << "\tJarmu ctor vMax=" << vMax << "\n"; }

    Jarmu(const Jarmu& j): vMax(j.vMax) {  std::cout << "\tJarmu copy vMax=" << vMax << "\n"; }

    virtual ~Jarmu() { std::cout << "\tJarmu dtor vMax=" << vMax << "\n";  }
};

class Szan: public Jarmu {
    int kutyakSzama;

public:
    Szan(double v = 0, int n = 0): Jarmu(v), kutyakSzama(n) {
        std::cout << "\tSzan ctor kutyakSzama=" << kutyakSzama << "\n";
    }

    Szan(const Szan& sz): Jarmu(sz), kutyakSzama(sz.kutyakSzama) { std::cout << "\tSzan copy kutyakSzama=" << kutyakSzama << "\n"; }

    virtual ~Szan() { std::cout << "\tSzan dtor kutyakSzama=" << kutyakSzama << "\n"; }
};

class Bicikli: public Jarmu {
    Kerek elso, hatso;

public:
    Bicikli(double v, int d): Jarmu(v), elso(d), hatso(d) {
        std::cout << "\tBicikli ctor "; elso.kiir();
    }

    Bicikli(const Bicikli& b): Jarmu(b), elso(b.elso), hatso(b.hatso) {
        std::cout << "\tBicikli copy "; elso.kiir();
    }

    virtual ~Bicikli() {
        std::cout << "\tBicikli dtor "; elso.kiir();
    }
};

#endif
