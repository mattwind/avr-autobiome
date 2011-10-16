
#include <math.h>

#include "autobiome/wheatstone.hxx"


#define  CHECK_NOT_EQUAL( a , b ) { if ( a == b ) { return  0 ; } }
#define  CHECK_NOT_ZERO( c ) { if ( 0 == c ) { return  0 ; } }


namespace Autobiome
{


uint16_t
wheatstone_resistance( const uint16_t ohms , const uint16_t input_millivolts , const uint16_t bridge_millivolts )
{
  uint16_t      unknown_ohms = 0 ;

  // We need to make sure none of our input values are 0
  CHECK_NOT_ZERO( ohms ) ;
  CHECK_NOT_ZERO( input_millivolts ) ;
  CHECK_NOT_ZERO( bridge_millivolts ) ;

  // This calculates the 2Vb/Vi constant that repeats in the Wheatstone bridge equation
  const double  bridge_K    = 2.0L * bridge_millivolts / (double) input_millivolts ;
  const double  denominator = 1 - bridge_K ;
  const double  numerator   = 1 + bridge_K ;

  // We need to make sure that we don't get a divide by 0 exception
  if( fabs( denominator ) < 1E-6 )
  {
    return  0 ;

  } /* if */

  unknown_ohms = static_cast< uint16_t > ( round ( ohms * numerator / denominator ) ) ;

  return  unknown_ohms ;

} /* wheatstone_resistance( const uint16_t , const uint16_t , const uint16_t ) */


} /* namespace Autobiome */

