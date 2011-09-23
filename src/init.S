

/* Project Local C Headers */
#include "autobiome/init.h"


init:
  rcall switch_power_led_on

ret


switch_power_led:
  ; Set the direction register so that the LED bit is digital output
  sti   LED_DDR   , 1 << LED_BIT

  ; And set that bit high on the port
  sti   LED_PORT  , 1 << LED_BIT

ret
