
#include <avr/io.h>


.section  .text
.global   read_data


/**
 * Returns the data in the ADC registers in registers r24:25 like a good C function
 */
read_data:
  ; We need to do this quickly without anything in between the 2 ADC register reads since the ADC
  ; is blocked from the time ADL is read until ADH is read
  lds   r24 , ADCL
  lds   r25 , ADCH

ret

