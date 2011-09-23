
// Systemwide C Headers
#include <avr/io.h>

// Project Local C Headers
#include "autobiome/init.h"


enum Switches
{

  on  = true ,
  off = false

} /* enum Switches */


//const   Baud_Register  baud_reg_val =  baud_38400 ;

void
init() ;
  
int
main()
{
  // init( baud_reg_val ) ;
  init() ;

  while( true )
  {

  } /* while */

  return  0 ;

} /* main() */

void
init()
{
  led_switch( on )

} /* init() */
