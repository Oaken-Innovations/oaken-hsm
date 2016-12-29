/*******************************************************************************
 * Oaken Project HSM Implementation on CryptoCape.
 *
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <avr/io.h>
#include <util/delay.h>

#include "uECC.h"

#define LED_BUILTIN PB5

void blink(uint8_t times);
void vli_print(char *str, uint8_t *vli, unsigned int size);

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
        blink(2);
        exit(-1);
    }

    blink(3);
    vli_print("Generated ECC private key = ", private, sizeof(private));
    vli_print("Generated ECC public key = ", public, sizeof(public));

    if(!uECC_compute_public_key(private, public_computed, curve)) {
        printf("uECC_compute_public_key() failed.\n");
        blink(5);
    }
    vli_print("Computed ECC public key = ", public_computed, sizeof(public_computed));

    uECC_compress(public_computed, public_compressed, curve);
    vli_print("Compressed ECC public key = ", public_compressed, sizeof(public_compressed));

    blink(10); 
    return 0;
}


/*
 * Blink onboard green led.
 * (times): How many blink times.
 */
void blink(uint8_t times) {
    DDRB |= 1 << LED_BUILTIN;
    for(uint8_t i = 0; i < times; i++) {
        PORTB &= ~(1 << LED_BUILTIN);   // turn the LED on (HIGH is the voltage level)
        _delay_ms(1000);                       // wait for a second
        PORTB |= 1 << LED_BUILTIN;    // turn the LED off by making the voltage LOW
        _delay_ms(1000);   
    }
}

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



