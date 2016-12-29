# Oaken-HSM

Oaken project hardware secure module (HSM). Seure the ethereum key pair generation, 
sign and verification using dedicated cryptographic hardware and storage.

This project is based on [micro-ecc](https://github.com/shuangjj/micro-ecc) elliptic curve functions.
And [here](OakenHSM_Features.md) is the overview of our HSM.

## Build

To compile the project, download the **micro-ecc** first and change the `uECC_ROOT` 
definition in `Makefile` accordingly.   
Make a soft link name `config.mk` to `avr_config.mk` if targeted for avr mcu or `bbb_config.mk` 
if targeted for Beaglebone Black.   

Then you build the project as follows:
```
make clean
make
```
## Flash images (.hex files)

To flash to onboard ATmega128p of CryptoCape, install the `program jumper` first 
to wire BBB UART to ATmega UART. For details, check [CryptoCape Hookup Guide].

After that, download and install the [BBB ATmega328P flasher].

## TODO

- Add RNG to ATmega128p to enable the ECC key generation.
- Implement secp256k1 on NXP Kinetis KL8x platform.

## Copyright

[Project Oaken](https://github.com/Project-Oaken)


[CryptoCape Hookup Guide]:https://learn.sparkfun.com/tutorials/cryptocape-hookup-guide
[BBB ATmega328P flasher]: https://github.com/jbdatko/BBB_ATmega328P_flasher
