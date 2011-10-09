#ifndef AUTOBIOME_STEINHART_HXX
  #define AUTOBIOME_STEINHART_HXX


#include <vector>


namespace Autobiome
{


/**
 * Our measured laboratory data points are Temperature as the independant variable and
 * resistance as the dependant variable.
 */
struct
Temperature_Point
{
  int   kelvin ;
  int   ohms ;

} ; /* struct Temperature_Point */


/**
 * We need some kind of container to hold data points in memory, for now a simple array will do.
 * Later if we want them sorted we can change this to a set.
 */
typedef std::vector< Temperature_Point > Data_Set ;


/**
 * This is the data type that gets returned from the equation that calculates the
 * Steinhart constants given a set of data points.  The Steinhart-Hart
 * equation is actually an infinite series of polynomials.  If you desire to use more than the
 * the three common A B C terms you can modify the equation to calculate and return extra
 * Steinhart Constants.
 */
typedef std::vector< double >  Steinhart_Constants ; 


/**
 * This function actually retreives (calculates) the Steinhart Constants "A", "B" and "C" given
 * a set of input data containing the actual measured temperature/resistance curve.
 *
 * @param         input
 *    A container with at least 3 measured data points (Kelvin/Ohms).  This will be used as the
 *    data curve to calculate the Steinhart constants.
 *
 * @return
 *    An array containing at least three Steinhart Constants calculated from the given input
 *    data set.  As a check, these constants and the input temperatures should yield the input
 *    resistances when plugged into the Steinhart-Hart equation.
 */
Steinhart_Constants
calc_steinhart_constants( const Data_Set & input ) ;

} /* namespace Autobiome */


#endif  /* #ifndef AUTOBIOME_STEINHART_HXX */
