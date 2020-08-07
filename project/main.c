#include <msp430.h>
#include <libTimer.h>
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "triangle.h"
#include "stateMachine.h"
#include <lcdutils.h>
#include <lcddraw.h>

//int redrawScreen = 1;

void main(void) 
{  
  configureClocks();
  led_init();
  lcd_init();
  switch_init();
  buzzer_init();
  enableWDTInterrupts();
  clearScreen(COLOR_BLACK);

  u_char width = screenWidth, height = screenHeight; /* Get screen resolution */

  or_sr(0x8);  // Enabling interrupts

  for (;;) {
    while (!redrawScreen) {
      drawTriforce();
      P1OUT &= ~LED_RED;  // Green LED off
      or_sr(0x10);         // CPU off
    }
    P1OUT |= LED_RED;   // Green LED on with CPU on
    __delay_cycles(2000000);
    redrawScreen = 0;
  }
} 

void wdt_c_handler() {
  static char blink_count = 0;
  if (++blink_count == 125) {
    if (state == 1)
      stateMachine(4);
    blink_count = 0;
  }
}
