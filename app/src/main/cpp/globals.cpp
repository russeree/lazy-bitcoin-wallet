#include "globals.h"

secp256k1_context* GlobalContext::ctx = nullptr;

void GlobalContext::initialize() {
    if (!ctx) {
        ctx = secp256k1_context_create(SECP256K1_CONTEXT_NONE);
    }
}

void GlobalContext::cleanup() {
    if (ctx) {
        secp256k1_context_destroy(ctx);
        ctx = nullptr;
    }
}

secp256k1_context* GlobalContext::getContext() {
    return ctx;
}