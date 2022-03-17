#ifndef EMBER_H
#define EMBER_H

class Ember {
protected:
    char *nev;
    int szulEv;

public:
    Ember(): szulEv(2002) {
        nev = new char[7];
        nev[0] = 'Z';
        nev[1] = '7';
        nev[2] = 'Z';
        nev[3] = 'F';
        nev[4] = '6';
        nev[5] = 'D';
        nev[6] = '\0';
    }
    Ember(const char*, int);
    Ember(const Ember&);

    Ember& operator=(const Ember&);

    const char* getNev() const;

    virtual int getKor(int ev) const;

    virtual const char* foglalkozas() const;

    virtual ~Ember();
};

#endif
