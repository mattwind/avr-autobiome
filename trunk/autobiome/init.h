#ifndef AUTOBIOME_INIT_H
  #define AUTOBIOME_INIT_H


/* Systemwide C Headers */
#include <avr/io.h>


#define  LED_BIT  6
#define  LED_DDR  DDRD
#define  LED_PORT PORTD


unsigned
init( void ) ;

void
led_switch( const bool on ) ;


#endif  /* #ifndef AUTOBIOME_INIT_H */
