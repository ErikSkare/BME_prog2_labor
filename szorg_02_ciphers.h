/**
 * \file ciphers.h
 *
 * Ezt a fájlt be kell adni (fel kell tölteni) a megoldással.
 */

#ifndef CipherS_H
#define CipherS_H

#include <string>
#include <vector>
#include "memtrace.h"

/**
 * Az ős osztály interfésze
 */
class Cipher {
public:
    /**
     * Titkosítja a kapott stringet
     * @param   message titkosítandó üzenet
     * @return  a message szöveg titkosított változata
     */
    virtual std::string encode(const std::string& message) = 0;
    /**
     * Dekódolja a kapott stringet
     * @param   ciphertext titkosított üzenet
     * @return  a megfejtett nyílt szöveg
     */
    virtual std::string decode(const std::string& ciphertext) = 0;
    /**
     * Létrehoz egy másolatot dinamikusan
     * @return  a létrehozott objektumra mutató pointer
     */
    virtual Cipher* clone() const = 0;
    /**
     * Alap destruktor
     */
    virtual ~Cipher() { };
};

//Osztályok, amiket meg kell csinálni a leírások és az osztálydiagram alapján
class CaesarCipher: public Cipher {
    int shift;

public:
    CaesarCipher(int shift): shift(shift) {}

    std::string encode(const std::string& message);

    std::string decode(const std::string& ciphertext);

    Cipher* clone() const { return new CaesarCipher(shift); }

    virtual ~CaesarCipher() { }
};

class MyCipher: public Cipher {
    std::string key;
    int offset;

public:
    MyCipher(std::string key, int offset = 0): key(key), offset(offset) { }

    std::string encode(const std::string& message);

    std::string decode(const std::string& ciphertext);

    Cipher* clone() const { return new MyCipher(key, offset); }

    virtual ~MyCipher() { };
};

class CipherQueue: public Cipher {
    size_t n;
    Cipher** eleje;

public:
    CipherQueue(): n(0), eleje(NULL) { }

    CipherQueue(const CipherQueue& c);

    void add(Cipher* c);

    std::string encode(const std::string& message);

    std::string decode(const std::string& ciphertext);

    Cipher* clone() const;

    virtual ~CipherQueue();
};

#endif
