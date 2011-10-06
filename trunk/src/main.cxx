
// Project Local C++ Headers
#include "autobiome/biome.hxx"


int
main()
{
  //  This should be self documenting but it may be worth mentioning that do_work will probably
  //  be implemented as some sort of infinite loop or state machine.
  Autobiome::device_init() ;
  Autobiome::do_work() ;
 
  return  0 ;

} /* main() */

