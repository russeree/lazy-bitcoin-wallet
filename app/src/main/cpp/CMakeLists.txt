cmake_minimum_required(VERSION 3.22.1)
project("lazy_wallet")

# Add Android STL
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

# Find OpenSSL package
find_package(openssl REQUIRED CONFIG)

# Your existing libraries
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/secp256k1 ${CMAKE_CURRENT_BINARY_DIR}/secp256k1)

add_library(${CMAKE_PROJECT_NAME} SHARED
        native-lib.cpp)

find_library(log-lib log)

target_link_libraries(${CMAKE_PROJECT_NAME}
        android
        log
        secp256k1
        openssl::ssl
        openssl::crypto
        ${log-lib})

# Add include directories for OpenSSL headers
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
        ${OPENSSL_INCLUDE_DIR}
        ${CMAKE_ANDROID_NDK}/sysroot/usr/include)

target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
        ENABLE_MODULE_RECOVERY
        ENABLE_MODULE_ECDH)