#ifndef AUTOBIOME_ASM_DEFS_H
  #define AUTOBIOME_ASM_DEFS_H


#include <avr/io.h>



/* This is for the teensy board
#define LED_BIT   6
#define LED_DDR   PORT_DDR
 */


/* This is for the mavric board */


/**
 * The mavric board LED is connected to pin 0
 */
#define LED_BIT 0

/**
 * The direction register for our LED port, this should match the direction register for the LED
 * PORT we define
 */
#define LED_DDR DDRB

/**
 * All of our LED flashing stuff, even the assembly language code, will use this port.  If you
 * want to send output to a different set of pins, this is what you change.
 */
#define LED_PORT PORTB





#endif  /* #ifndef AUTOBIOME_ASM_DEFS_H */
