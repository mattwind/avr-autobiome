#ifndef AUTOBIOME_WHEATSTONE_HXX
  #define AUTOBIOME_WHEATSTONE_HXX

#include <stdint.h>


namespace Autobiome
{


/**
 * Calculates the resistance of the fourth leg of a Wheatstone bridge in which the resistances of
 * the other three legs are equal and constant.  This uses the equation:
 *     Unknown_R = Ohms x (1 + 2Vb/Vi)(1 - 2Vb/Vi)
 *
 * where Ohms is the known resistance of the other leg(s) and Vb and Vi are the measured bridge voltage and
 * the input voltage, respectively.
 */
uint16_t
wheatstone_resistance( const uint16_t ohms , const uint16_t input_millivolts , const uint16_t bridge_millivolts ) ;


} /* namespace Autobiome */


#endif  /* #ifndef AUTOBIOME_WHEATSTONE_HXX */
