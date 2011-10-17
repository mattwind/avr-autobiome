#ifndef AUTOBIOME_WHEATSTONE_HXX
  #define AUTOBIOME_WHEATSTONE_HXX

#include <stdint.h>


namespace Autobiome
{


typedef double      Centigrade ;
typedef double      Kelvin ;
typedef double      Resistance ;
typedef uint16_t    Therm_Beta ;
typedef double      Voltage ;


/**
 * Calculates the balance ratio (2Vb/Vi) of a Wheatstone Bridge
 *
 * @param         bridge
 *    The voltage measured across the bridge
 *
 * @param         input
 *    The input voltage to the Wheatstone loop
 *
 * @return
 *    The ratio  2.0 * bridge / input 
 */
double
bridge_balance( const Voltage bridge , const Voltage input ) ;


/**
 * This calculates the actual temperature of a thermistor given it's measured resistance in
 * Ohms and the beta value (thermistor constant) for the thermistor's family.
 *
 * @param        therm_ohms
 *    The measured resistance of the thermistor
 *
 * @param        base_temp
 *    The temperature at which the base resistance was measured
 *
 * @param        base_ohms
 *    The resistance of the thermistor at the measured base temperature.  So if you tested your
 *    thermistor in pure icewater (well stirred icewater is constant at 275.15'K at sea level)
 *    and measured a resistance of 25K Ohms, the <CODE>base_temp</CODE> argument to this
 *    function would be <CODE>273.15</CODE> and the <CODE>base_ohms</CODE> argument would be
 *    <CODE>2500</CODE>.
 *
 * @param        b_val
 *    The ``beta'' value of the thermistor.  This will usually be given in the manufacturer data
 *    sheet for the thermistor but should be verified by real world data.
 *
 * @return
 *   The temperature in Kelvin  ('C + 273.15)
 */
double
thermistor_temp(
    const Resistance therm_ohms ,
    const Kelvin base_temp ,
    const Resistance base_ohms ,
    const Therm_Beta b_val
    ) ;


/**
 * Calculates the resistance of the fourth leg of a Wheatstone bridge in which the resistances of
 * the other three legs are equal and constant.  This uses the equation:
 *     Unknown_R = Ohms x (1 + 2Vb/Vi)(1 - 2Vb/Vi)
 *
 * where Ohms is the known resistance of the other leg(s) and Vb and Vi are the measured bridge
 * voltage and the input voltage, respectively.  This equation assumes that all 3 resistors in
 * the bridge have the same value.  Note that the units (volts, millivolts, etc.) used as input
 * don't matter as long as they are the same.  I.e. the bridge and input arguments may be volts,
 * millivolts, kilovolts as long as both arguments use the same units.
 *
 * @param         bridge
 *    The voltage measured across the bridge
 *
 * @param         input
 *    The input voltage to the Wheatstone loop
 *
 * @param         ohms
 *   The resistance in Ohms of the individual resistors that make up the 3 legs of the
 *   Wheatstone Bridge.  This is the value of a SINGLE resistor, not the value of the sum of the
 *   resistors.
 *
 * @return
 *   The calculated resistance of the unknown leg of the Wheatstone Bridge.  Again the actual
 *   units returned will be identical to the input units, so if you give an input resistance in
 *   KOhms you will get a return value in KOhms.
 */
Resistance
wheatstone_resistance( const Voltage bridge , const Voltage input , const Resistance ohms ) ;



} /* namespace Autobiome */


#endif  /* #ifndef AUTOBIOME_WHEATSTONE_HXX */

