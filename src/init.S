

/* Project Local C Headers */
#include "autobiome/asm_defs.h"


.section  .text
.global   init_avr


/**
 * This sets up our ADC registers and gets everything ready to do an ADC
 * conversion.  See page 242 of the Atmega 128 sheet to see how these
 * registers are set.
 * 
 * @precondition
 *    r31 is 0 so that we can address the lower 256 addresses via r31:r30
 *    without having to clear r31
 */
init_adc:
  ; Load the Z (indirect addressing) register with the address of the admux register
  ldi   r30 , ADMUX
  ; Setup the admux to use internal 2.56 reference voltage and compare the
  ; differential between pins ADC0 and ADC1, bit pattern 11010000 = 0x0D
  ldi   r24 , 0xD0
  st    Z , r24

  ; We want to set the ADCSRA register to E7.  The high nibble enables ADC
  ; and Free Running mode while disabling the interrupts.  The bottom three
  ; set the ADC prescaler to 128 so we get an ADC F of 16MHz/128 = 125KHz
  ldi   r30 , ADCSRA
  ldi   r24 , 0xE7
  st    Z , r24
ret


init_avr:
  rcall   init_avr_regs
  rcall   init_adc
  rcall   led_switch
ret


init_avr_regs:
  ; Usually r1 is constant 0 by convention on the AVR.  The startup code from
  ; avr-libc will clear r1 as well but who knows if we are using avr-libc? :)
  clr   r1 
  clr   r31
ret


led_switch:
  ; Set the direction register so that the LED bit is digital output
  ; Note we are using incremented addressing (Z+) so this depends on the 
  ; LED port being the next register after the direction port (DDR)
  ldi   r30 , LED_DDR
  ldi   r24 , 1 << LED_BIT
  st    Z+ , r24
  st    Z , r24
ret

