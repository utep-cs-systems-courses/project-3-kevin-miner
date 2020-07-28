#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

void buzzer_init()
{
    /* 
       Direct timer A output "TA0.1" to P2.6.  
        According to table 21 from data sheet:
          P2SEL2.6, P2SEL2.7, anmd P2SEL.7 must be zero
          P2SEL.6 must be 1
        Also: P2.6 direction must be output
    */
    timerAUpmode();		/* used to drive speaker */
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7; 
    P2SEL |= BIT6;
    P2DIR = BIT6;		/* enable output to speaker (P2.6) */
}

void buzzer_set_period(short cycles) /* buzzer clock = 2MHz.  (period of 1k results in 2kHz tone) */
{
  CCR0 = cycles; 
  CCR1 = cycles >> 1;		/* one half cycle */
}

// play Harry Potter's theme
void play_song()
{
  float B = 2024.76;
  float E = 1516.86;
  float G = 1275.59;
  float F = 1431.73;
  float B2 = 1012.38;
  float A = 1136.36;
  float Ds = 1607.06;

  
  float notes[30] = {B, E, G, F, E, B2, A, F, E, G, F, Ds, F, B};
  for (int i = 0; i < 30; i++) {
    buzzer_set_period(notes[i]);
    __delay_cycles(10000000);
  }
  buzzer_set_period(0);
}


    
    
  

