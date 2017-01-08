# Oaken-HSM

This is the `Project Oaken` hardware secure module (HSM), which is used to secure key generation, 
signing and verification using dedicated cryptographic hardware and secure storage.

This project is based on [micro-ecc](https://github.com/shuangjj/micro-ecc) elliptic curve implementation on constrained devices.
[Here](OakenHSM_Features.md) are the features of our HSM. We have fully evaluated the eliptic curve (secp256k1) for ethereum secure key management and signature verification on both Beaglebone Black (BBB) platform and AVR platform.

For the complete integration of the HSM module with Project Oakens ACORN devices, we also built a [nodejs library](https://github.com/Project-Oaken/zymkey) for the [zymbit trusted module](https://zymbit.com/zymkey/) and we are in the process of further integrating our micro-ecc and nodejs client to their platform.

The final HSM integration with our ACORN devices is shown as the following figure:
<img src="/imgs/SecurityGateway.png" width="500" alt="Hardware Secure Module of ACORN node">

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

## Copyright

[Project Oaken](https://github.com/Project-Oaken)


[CryptoCape Hookup Guide]:https://learn.sparkfun.com/tutorials/cryptocape-hookup-guide
[BBB ATmega328P flasher]: https://github.com/jbdatko/BBB_ATmega328P_flasher
