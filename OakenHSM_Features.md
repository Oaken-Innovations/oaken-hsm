
## Oaken-HSM

We reassure device security by building our own hardware security module (HSM). 
The ethereum private keys never leaves the HSM and the HSM also supports:

- Ethereum key pair generation
- Sign transactions / messages
- Verify transactions / messages

### Main Features of Our HSM

- True Random Number Generator (TRNG)
- Anti-tamper circuits to erase private keys upon detecting tamper attempts (**optional**)
- Secure EEPROM to store private keys safely
- Low power ARM Cortex M0+ to process transactions fast
