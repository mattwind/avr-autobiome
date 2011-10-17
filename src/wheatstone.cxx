
#include <math.h>

#include "autobiome/wheatstone.hxx"


#define  CHECK_NOT_EQUAL( a , b ) { if ( a == b ) { return  0 ; } }
#define  CHECK_NOT_ZERO( c ) { if ( 0 == c ) { return  0 ; } }


namespace Autobiome
{


double
bridge_balance( const Voltage bridge , const Voltage input )
{
  double  balance_ratio = bridge / input ;

  balance_ratio *= 2 ;

  return  balance_ratio ;

} /* bridge_balance( const Voltage , const Voltage ) */


Kelvin
thermistor_temp(
    const Resistance therm_ohms ,
    const Kelvin base_temp ,
    const Resistance base_ohms ,
    const Therm_Beta b_val
    )
{
  double      resistance_ratio  = therm_ohms / base_ohms ;
  double      kelvin_temp       = log( resistance_ratio ) / b_val ;

  kelvin_temp += 1 / base_temp ;

  return  1 / kelvin_temp ;

} /* thermistor_temp( const Resistance , const Kelvin , const Resistance , const Thermistor_Beta ) */


Resistance
wheatstone_resistance( const Voltage bridge , const Voltage input , const Resistance ohms )
{
  Resistance    unknown_ohms = 0 ;

  // We need to make sure none of our input values are 0
  CHECK_NOT_ZERO( ohms ) ;
  CHECK_NOT_ZERO( input ) ;
  CHECK_NOT_ZERO( bridge ) ;

  // This calculates the 2Vb/Vi constant that repeats in the Wheatstone bridge equation
  const double  bridge_K    = bridge_balance( bridge , input ) ;
  const double  denominator = 1 - bridge_K ;
  const double  numerator   = 1 + bridge_K ;

  // We need to make sure that we don't get a divide by 0 exception
  if( fabs( denominator ) < 1E-6 )
  {
    return  0 ;

  } /* if */

  unknown_ohms = ohms * numerator / denominator ;

  return  unknown_ohms ;

} /* wheatstone_resistance( const Voltage , const Voltage , const Resistance ) */


} /* namespace Autobiome */

