
#include <uart.h>

#include "autobiome/startup.hxx"



namespace Autobiome
{


void
comm_init()
{
  uart1_init( baud_rate ) ;

} /* comm_init() */


} /* namespace Autobiome */

