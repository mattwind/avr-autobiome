

/* Project Local C Headers */
#include "autobiome/asm_defs.h"


.section  .text
.global   init_avr
.global   init_avr_regs
.global   led_switch


init_avr:
  rcall init_avr_regs
  rcall led_switch
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


