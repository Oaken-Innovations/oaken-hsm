# Oaken-HSM

Oaken project hardware secure module (HSM). Seure the ethereum key pair generation, 
sign and verification using dedicated cryptographic hardware and storage.

This project is based on [micro-ecc](https://github.com/shuangjj/micro-ecc) elliptic curve functions.

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


## Usage

## Acknowledgment

## Copyright

[Project Oaken](https://github.com/Project-Oaken)
