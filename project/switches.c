#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "stateMachine.h"
#include "libTimer.h"
#include "buzzer.h"
#include "triangle.h"

char state, switch_state_down, switch_state_changed; /* effectively boolean */
char sw_1, sw_2, sw_3, sw_4, CURRENT_STATE;

static char 
switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);	/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);	/* if switch down, sense up */
  return p2val;
}

void 
switch_init()			/* setup switch */
{  
  P2REN |= SWITCHES;		/* enables resistors for switches */
  P2IE |= SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */
  switch_update_interrupt_sense();
  switch_interrupt_handler();
}

void
switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();
  P1OUT |= LED_RED;
  sw_1 = (p2val & SW1) ? 0 : 1;
  sw_2 = (p2val & SW2) ? 0 : 1;
  sw_3 = (p2val & SW3) ? 0 : 1;
  sw_4 = (p2val & SW4) ? 0 : 1;
  switch_state_changed = 1;
  if (sw_1) {
    stateMachine(1);
    switch_state_changed = 0;
  }
  else if (sw_2) {
    stateMachine(2);
    switch_state_changed = 0;
  }
  else if (sw_3) {
    stateMachine(3);
    switch_state_changed = 0;
  }
  else if (sw_4) {
    stateMachine(4);
    switch_state_changed = 0;
  }
}
