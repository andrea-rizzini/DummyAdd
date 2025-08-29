#include <stdio.h>
#include <sgx_urts.h>
#include "Enclave_u.h"

void ocall_print(const char* s) {   // deve chiamarsi come nell'EDL
    printf("[OCALL] %s\n", s);
}

int main() {
    sgx_enclave_id_t eid = 0;
    sgx_status_t st = SGX_SUCCESS;
    int sum = -1;

    const char* so = "enclave.signed.so";
    st = sgx_create_enclave(so, SGX_DEBUG_FLAG, NULL, NULL, &eid, NULL);
    if (st != SGX_SUCCESS) {
        printf("sgx_create_enclave failed: 0x%04x\n", st);
        return 1;
    }

    st = add(eid, &sum, 40, 2);  // ECALL generata da edger8r
    if (st == SGX_SUCCESS)
        printf("40 + 2 = %d (from enclave)\n", sum);
    else
        printf("ECALL add() failed: 0x%04x\n", st);

    sgx_destroy_enclave(eid);
    return 0;
}
