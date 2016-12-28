include config.mk

PROJECT=cape_hsm

## Cross-compile tools
CC=$(CROSS_COMPILE)gcc
AR=$(CROSS_COMPILE)ar
OBJCOPY=$(CROSS_COMPILE)objcopy

## micro-ecc configs
uECC_ROOT=/home/lexon/Workspace/micro-ecc
ECC_SELECTION=-DuECC_SUPPORTS_secp160r1=0 \
              -DuECC_SUPPORTS_secp192r1=0 \
              -DuECC_SUPPORTS_secp224r1=0 \
              -DuECC_SUPPORTS_secp256r1=0 \
              -DuECC_SUPPORTS_secp256k1=1 \
              -DuECC_SUPPORT_COMPRESSED_POINT=1

## options, flags
INCLUDES=-I$(uECC_ROOT)
CFLAGS+=$(INCLUDES) \
		$(ECC_SELECTION) \
		-std=c99 -O1
LDFLAGS=$(MCU) -O1

OBJS=cape_hsm.o \
     $(uECC_ROOT)/uECC.o

## Rules
all: $(PROJECT).hex
	@echo "Finished."

$(PROJECT).elf: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^                                                     
		                                                                                
%.hex: %.elf                                                                    
	$(OBJCOPY) -Oihex -R .eeprom $< $@
		                                                                                
%.o: %.c                                                                        
	$(CC) -c $(CFLAGS) $< -o $@                                                  
		                                                                                
clean:                                                                          
	rm -rf *.o *.elf *.hex
	make -C $(uECC_ROOT) clean
