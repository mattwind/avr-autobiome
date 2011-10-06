
// Systemwide C Headers
#include <avr/io.h>
#include <uart.h>

// Systemwide C++ Headers
#include <Serial_Port.hxx>
#include <iostream>
#include <serstream>


// Project Local C Headers
#include "autobiome/adc_input.h"
#include "autobiome/init.h"
#include "autobiome/outlogger.h"

// Project Local C++ Headers
#include "autobiome/biome.hxx"
#include "autobiome/startup.hxx"


namespace Autobiome
{


// This type define doesn't add any abstraction to our program, it is just here because the
// actual template data type is nothing but long meaningless text
typedef  std::basic_ioserialstream< char , std::char_traits< char > , AVR_Comm::Serial_Port > Comm_Stream ;


//  This is just a generic delay loop
void
delay_loop() ;



void
delay_loop()
{
  //  This is just a generic delay loop
  for( uint16_t i = 0 ; i < 0x3 ; i++ )
  {
    for( uint16_t j = 0 ; j < 0xFFFF ; j++ )
    {
      //  Do nothing just wait
    } /* for */

  } /* for */

} /* delay_loop() */


void
device_init()
{
  Autobiome::comm_init() ;
  init_avr() ;

} /* device_init() */


void
do_work()
{
  // Create our serial port 
  AVR_Comm::Serial_Port   uart_01( baud_rate ) ;

  // Create our IO stream from that serial port
  Comm_Stream             console( uart_01 ) ;

  // Using "BEEF" as a hex value helps catch endianess errors
  uint16_t                adc_value = 0xBEEF ;

  while( true )
  {
    adc_value = read_data() ;

    console << adc_value << "\r\n" ;

    delay_loop() ;

  } /* while */

} /* do_work() */


} /* namespace Autobiome */

