
// Systemwide C Headers
#include <avr/io.h>

// Project Local C Headers
#include "autobiome/init.h"


//const   Baud_Register  baud_reg_val =  baud_38400 ;

void
teensy_usb_init() ;


int
main()
{
  // init( baud_reg_val ) ;
  teensy_usb_init() ;
 
  return  0 ;

} /* main() */


void
led_on()
{
  DDRD  = -1 ;
  PORTD = -1 ;

} /* led_on() */


void
teensy_usb_init()
{
  //led_on() ;
  init_avr() ;

} /* teensy_usb_init() */

