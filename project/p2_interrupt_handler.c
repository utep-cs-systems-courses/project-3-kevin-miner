#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "stateMachine.h"

void
__interrupt_vec(PORT2_VECTOR) Port_2(){
  if (P2IFG & SWITCHES) {	      /* did a button cause this interrupt? */
    P2IFG &= ~SWITCHES;		      /* clear pending sw interrupts */
    switch_interrupt_handler();	/* single handler for all switches */
  }
}

/* void */
/* __interrupt_vec(WDT_VECTOR) WDT() { */
/*   stateMachine(); */
/* } */

