#ifndef LAZY_WALLET_GLOBALS_H
#define LAZY_WALLET_GLOBALS_H

#include <secp256k1.h>

class GlobalContext {
private:
    static secp256k1_context* ctx;

public:
    static void initialize();
    static void cleanup();
    static secp256k1_context* getContext();
};

#endif //LAZY_WALLET_GLOBALS_H