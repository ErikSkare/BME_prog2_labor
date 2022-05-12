/**
 * \file pirodistak.h
 * Minden származtatott irodista osztály perzisztens változatának deklarációját ebbe a fájlba tegye!
 * Az egyszerűség kedvéért minden tagfüggvényt inline valósítson meg!
 *
 */
#ifndef PIRODISTAK_H
#define PIRODISTAK_H

#include <stdexcept>
#include "palkalmazott.h"
#include "irodistak.h"


/**
 * Perzisztens csoportvezető
 */
class PCsopVez : public CsopVez, public Serializable {
public:
    PCsopVez(const std::string& n, double f, csop_t cs) : Alkalmazott(n, f), CsopVez(n, f, cs) {}
    PCsopVez(const CsopVez& csopvez) : Alkalmazott(csopvez.getNev(), csopvez.getFiz()), CsopVez(csopvez) { }

    void write(std::ostream& os) const {
        os << "PCsopVez" << std::endl;
        os << getNev() << std::endl;
        os << getFiz() << std::endl;
        os << getCs() << std::endl;
    }
    void read(std:: istream& is) {
        std::string tmp;
        (is >> tmp).ignore(1);
        if (tmp != "PCsopVez") throw std::out_of_range("PCsopVez_R: "+tmp);
        std::string n;
        getline(is, n);
        setNev(n);
        double f;
        (is >> f).ignore(1);
        setFiz(f);
        csop_t csop;
        is >> csop;
        setCs(csop);
    }
};

/**
 * Perzisztens Határozott idejű alkalmazott
 */
class PHatIdeju : public HatIdeju, public Serializable {
public:
    PHatIdeju(const std::string& n, double f, time_t t)
        : Alkalmazott(n, f), HatIdeju(n, f, t) { }
    PHatIdeju(const HatIdeju& hatideju)
        : Alkalmazott(hatideju.getNev(), hatideju.getFiz()), HatIdeju(hatideju) { }

    void write(std::ostream& os) const {
        os << "PHatIdeju" << std::endl;
        os << getNev() << std::endl;
        os << getFiz() << std::endl;
        os << getIdo() << std::endl;
    }

    void read(std:: istream& is) {
        std::string tmp;
        (is >> tmp).ignore(1);
        if (tmp != "PHatIdeju") throw std::out_of_range("PHatIdeju_R: "+tmp);
        std::string n;
        getline(is, n);
        setNev(n);
        double f;
        (is >> f).ignore(1);
        setFiz(f);
        time_t ido;
        is >> ido;
        setIdo(ido);
    }
};

/**
 * Perzisztens Határozott idejű csoportvezető
 */
class PHatIdCsV : public HatIdCsV, public Serializable {
public:
    PHatIdCsV(const  std::string& n, double f, csop_t cs, time_t t)
        : Alkalmazott(n, f), HatIdCsV(n, f, cs, t) { }
    PHatIdCsV(const HatIdCsV& hatid)
        : Alkalmazott(hatid.getNev(), hatid.getFiz()), HatIdCsV(hatid) { }

    void write(std::ostream& os) const {
        os << "PHatIdCsV" << std::endl;
        os << getNev() << std::endl;
        os << getFiz() << std::endl;
        os << getCs() << std::endl;
        os << getIdo() << std::endl;
    }

    void read(std:: istream& is) {
        std::string tmp;
        (is >> tmp).ignore(1);
        if (tmp != "PHatIdCsV") throw std::out_of_range("PHatIdCsV_R: "+tmp);
        std::string n;
        getline(is, n);
        setNev(n);
        double f;
        (is >> f).ignore(1);
        setFiz(f);
        csop_t csop;
        is >> csop;
        setCs(csop);
        time_t ido;
        is >> ido;
        setIdo(ido);
    }
};

/**
 * Perzisztens Határozott idejű csoportvezető helyettes
 */
class PHatIdCsVezH : public HatIdCsVezH, public Serializable {
public:
    PHatIdCsVezH(const std::string& n, double f, time_t t, CsopVez& kit)
        : Alkalmazott(n, f), HatIdCsVezH(n, f, t, kit) { }
    PHatIdCsVezH(const HatIdCsVezH& hatid)
        : Alkalmazott(hatid.getNev(), hatid.getFiz()), HatIdCsVezH(hatid) { }

    void write(std::ostream& os) const {
        os << "PHatIdCsVezH" << std::endl;
        os << getNev() << std::endl;
        os << getFiz() << std::endl;
        os << getCs() << std::endl;
        os << getIdo() << std::endl;
    }

    void read(std:: istream& is) {
        std::string tmp;
        (is >> tmp).ignore(1);
        if (tmp != "PHatIdCsVezH") throw std::out_of_range("PHatIdCsVezH_R: "+tmp);
        std::string n;
        getline(is, n);
        setNev(n);
        double f;
        (is >> f).ignore(1);
        setFiz(f);
        csop_t csop;
        is >> csop;
        setCs(csop);
        time_t ido;
        is >> ido;
        setIdo(ido);
    }
};

#endif // IRODISTAK_H

