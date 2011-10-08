
#include <avr/io.h>


.section  .text
.global   extend_sign
.global   read_data


/**
 * This extends a 2 bit signed integer to an 8 bit signed integer.  It is used create a 16 bit
 * signed integer from the 10 bit output of the ADC.  Since the sign bit in the 2 byte ADC
 * result is in bit 1 of the upper register, we really just need to sign extend bit 1.  This
 * operates on register r25 just because we know that's where we are storing the ADCH value.
 */
extend_sign:
  sbrc    r25 , 1               ; Skip the next instruction if bit 1 is clear, if bit 1 is
                                ; clear, then this is not a negative number, no extension needed
  ori     r25 , 0xFE            ; Set every bit but the least one

ret


/**
 * Returns the data in the ADC registers in registers r24:25 like a good C function
 */
read_data:
  ; We need to do this quickly without anything in between the 2 ADC register reads since the ADC
  ; is blocked from the time ADL is read until ADH is read
  lds     r24 , ADCL
  lds     r25 , ADCH

  rcall   extend_sign
ret
