
#include <avr/io.h>
#include <uart.h>

#include "autobiome/startup.hxx"



namespace Autobiome
{


void
comm_init()
{
  // Set the direction register on port D pin 3 to output (The UART 1 TX pin)
  DDRD = -1 ;

  uart1_init( baud_rate ) ;

} /* comm_init() */


} /* namespace Autobiome */

