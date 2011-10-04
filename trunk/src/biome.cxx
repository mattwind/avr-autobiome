
// Systemwide C Headers
#include <avr/io.h>

// Project Local C Headers
#include "autobiome/init.h"


//const   Baud_Register  baud_reg_val =  baud_38400 ;

void
device_init() ;


void
do_work() ;


int
main()
{
  device_init() ;
  do_work() ;
 
  return  0 ;

} /* main() */


void
device_init()
{
  comm_init() ;
  init_avr() ;

} /* device_init() */


void
do_work()
{
  // Using "BEEF" as a hex value helps catch endianess errors
  uint16_t  adc_value = 0xBEEF ;

  while( 1 )
  {
    adc_value = read_data() ;

    write_data( adc_value ) ;

  } /* while */

} /* do_work() */
