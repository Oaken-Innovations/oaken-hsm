CROSS_COMPILE=avr-
MCU=-mmcu=atmega328p
CPU_SPEED=-DF_CPU=8000000UL
CFLAGS:=$(MCU) $(CPU_SPEED)

