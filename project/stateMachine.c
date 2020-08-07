#include <stdlib.h>
#include <msp430.h>
#include "stateMachine.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "triangle.h"

int redrawScreen;

void stateMachine(int state)
{
  switch (state) {
  case 1:
    redrawScreen = 1;
    drawTriangle();
    state = 0;
    break;
  case 2:
    redrawScreen = 1;
    led_dim();
    state = 0;
    break;
  case 3:
    redrawScreen = 1;
    drawFonts();
    state = 0;
    break;
  case 4:
    redrawScreen = 1;
    play_song();
    state = 0;
    break;
  default:
    break;
  }
}
