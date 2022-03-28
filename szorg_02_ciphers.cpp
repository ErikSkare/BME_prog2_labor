/**
 * \file ciphers.cpp
 *
 * Ebben a fájlban kell megvalósítania az CaesarCipher, MyCipher, CipherQueue osztályok metódusait.
 *
 * Ezt a fájlt be kell adni (fel kell tölteni) a megoldással.
 */

#include "memtrace.h"
#include "ciphers.h"

std::string CaesarCipher::encode(const std::string& message) {
    std::string result(message);
    int real_shift = shift % 26;
    for(int i = 0; i < (int) result.size(); ++i) {
        if(result[i] != ' ') {
            if(result[i] < 'a' || result[i] > 'z')
                throw "Z7ZF6D";
            result[i] = 'a' + (result[i] - 'a' + real_shift + 26) % 26;
        }
    }
    return result;
}

std::string CaesarCipher::decode(const std::string& ciphertext) {
    std::string result(ciphertext);
    int real_shift = shift % 26;
    for(int i = 0; i < (int) result.size(); ++i) {
        if(result[i] != ' ') {
            if(result[i] < 'a' || result[i] > 'z')
                throw "Z7ZF6D";
            result[i] = 'a' + (result[i] - 'a' - real_shift + 26) % 26;
        }
    }
    return result;
}

std::string MyCipher::encode(const std::string& message) {
    std::string result(message);
    for(int i = 0; i < (int) result.size(); ++i) {
        if(result[i] != ' ') {
            if(result[i] < 'a' || result[i] > 'z')
                throw "Z7ZF6D";
            int real_shift = (offset + i + key[i % key.size()] - 'a') % 26;
            result[i] = 'a' + (result[i] - 'a' + real_shift + 26) % 26;
        }
    }
    return result;
}

std::string MyCipher::decode(const std::string& ciphertext) {
    std::string result(ciphertext);
    for(int i = 0; i < (int) result.size(); ++i) {
        if(result[i] != ' ') {
            if(result[i] < 'a' || result[i] > 'z')
                throw "Z7ZF6D";
            int real_shift = (offset + i + key[i % key.size()] - 'a') % 26;
            result[i] = 'a' + (result[i] - 'a' - real_shift + 26) % 26;
        }
    }
    return result;
}

void CipherQueue::add(Cipher* c) {
    Cipher** uj_eleje = new Cipher*[n + 1];
    for(int i = 0; i < (int) n; ++i)
        uj_eleje[i] = eleje[i];
    uj_eleje[n] = c;
    if(eleje != NULL)
        delete[] eleje;
    eleje = uj_eleje;
    n++;
}

CipherQueue::CipherQueue(const CipherQueue& c) {
    n = c.n;
    eleje = new Cipher*[n];
    for(int i = 0; i < (int) n; ++i)
        eleje[i] = c.eleje[i]->clone();
}

std::string CipherQueue::encode(const std::string& message) {
    std::string result(message);
    for(int i = 0; i < (int) n; ++i)
        result = eleje[i]->encode(result);
    return result;
}

std::string CipherQueue::decode(const std::string& ciphertext) {
    std::string result(ciphertext);
    for(int i = (int) n-1; i >= 0; i--) {
        result = eleje[i]->decode(result);
    }
    return result;
}

Cipher* CipherQueue::clone() const {
    return new CipherQueue(*this);
}

CipherQueue::~CipherQueue() {
    for(int i = 0; i < (int) n; ++i) {
        delete eleje[i];
    }
    delete[] eleje;
}
