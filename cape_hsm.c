/*******************************************************************************
 * Oaken Project HSM Implementation on CryptoCape.
 *
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "uECC.h"

/*
 * Print very large integer with prefix message.
 * (str): The message string.
 * (vli): Pointer to the integer data.
 * (size): Size of the data.
 */
void vli_print(char *str, uint8_t *vli, unsigned int size) {                    
    printf("%s ", str);                                                                                       
    for(unsigned i=0; i<size; ++i) {                                                                          
        printf("%02X ", (unsigned)vli[i]);                                                                    
    }                                                                                                         
    printf("\n");                                                                                             
}   

int main() {
    uint8_t private[32];
    uint8_t public[64];
    uint8_t public_computed[64];
    uint8_t public_compressed[33];
    const struct uECC_Curve_t *curve;

    curve = uECC_secp256k1();
    printf("Hardware Secure Module of Oaken Porject Using CryptoCape.\n");
    memset(private, 0, sizeof(private));
    memset(public, 0, sizeof(public));

    if(!uECC_make_key(private, public, curve)) {
        printf("uECC_make_key() failed!\n");
        exit(-1);
    }
    vli_print("Generated ECC private key = ", private, sizeof(private));
    vli_print("Generated ECC public key = ", public, sizeof(public));

    if(!uECC_compute_public_key(private, public_computed, curve)) {
        printf("uECC_compute_public_key() failed.\n");
    }
    vli_print("Computed ECC public key = ", public_computed, sizeof(public_computed));

    uECC_compress(public_computed, public_compressed, curve);
    vli_print("Compressed ECC public key = ", public_compressed, sizeof(public_compressed));
    return 0;
}

