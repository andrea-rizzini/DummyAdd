#include "Enclave_t.h"

int add(int a, int b) {
    ocall_print("Hello from enclave, computing a+b...");
    return a + b;
}
