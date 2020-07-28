#include <stdlib.h>
#include <msp430.h>
#include "stateMachine.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "triangle.h"

void stateMachine(int state)
{
  switch (state) {
  case 1:
    led_dim();
    //leds_on();
    drawTriangle();
    state = 0;
    break;
  case 2:
    //binary_count();
    //leds_on();
    off();
    //P1OUT = (toggle_red()) ? BIT6 : !LED_RED;
    state = 0;
    break;
  case 3:
    led_alternate();
    //leds_on();
    state = 0;
    break;
  case 4:
    play_song();
    //leds_on();
    
    state = 0;
    break;
  default:
    break;
  }
}
