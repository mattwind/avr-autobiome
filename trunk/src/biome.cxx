
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
  for( uint16_t i = 0 ; i < 0x70 ; i++ )
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
  const int8_t            sample_size = 16 ;

  // Create our serial port 
  AVR_Comm::Serial_Port   uart_01( baud_rate ) ;

  // Create our IO stream from that serial port
  Comm_Stream             console( uart_01 ) ;

  while( true )
  {
    int32_t               adc_value  = 0 ;
    int16_t               millivolts = 0 ;

    for( int8_t i = 0 ; i < sample_size ; i++ )
    {
      adc_value   += read_data() ;

      delay_loop() ;

    } /* for */

    adc_value   /= sample_size ;
    // We are using an internal reference voltage of 2560 millivolts and a gain of 1.  The actual
    // voltage reading per page 241 of the Atmel Datasheet doc2467.pdf is  adc_value * gain * v_ref / 512
    // or in our case, 1 * 2560 / 512 = 5 
    millivolts  += adc_value * 5 ;

    console << std::hex << adc_value << '\t' << std::dec << (int) adc_value << "\t" << millivolts << "\r\n" ;

  } /* while */

} /* do_work() */


} /* namespace Autobiome */

