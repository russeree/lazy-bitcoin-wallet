#include <jni.h>
#include <string>
#include <fcntl.h>
#include <unistd.h>
#include <secp256k1.h>
#include <openssl/rand.h>

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_lazy_1wallet_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    secp256k1_context* ctx = secp256k1_context_create(SECP256K1_CONTEXT_NONE);

    // Generate 32 bytes of random data (suitable for a private key)
    unsigned char random_bytes[32];
    if (RAND_bytes(random_bytes, sizeof(random_bytes)) != 1) {
        return env->NewStringUTF("Failed to generate random number");
    }

    // Convert to hex string for display
    char hex_string[65];
    for(int i = 0; i < 32; i++) {
        sprintf(&hex_string[i*2], "%02x", random_bytes[i]);
    }
    hex_string[64] = 0;

    std::string hello = "Random bytes: " + std::string(hex_string);
    return env->NewStringUTF(hello.c_str());
}