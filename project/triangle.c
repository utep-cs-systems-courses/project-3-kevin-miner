#include "triangle.h"
#include <lcdutils.h>
#include <lcddraw.h>

static int up, down = 0; // Should the shape move up or down?

void drawTriangle(void) {
  int i;
  int j;
  int k = 0;
  int redraw = 0; // Change row position
  clearScreen(COLOR_WHITE);
  drawString8x12(10, 50, "hello, world!", COLOR_BLACK, COLOR_WHITE);
  __delay_cycles(5000000);
  clearScreen(COLOR_BLACK);

  for (j=0; j < 50; j++) {
    for (i=62; i<115; i++) { // col, row
      drawPixel(i, i-30+redraw, COLOR_BLUE);  // triangle right side
      drawPixel(62-(k++), i-30+redraw, COLOR_BLUE);  // triangle left side
    }
    __delay_cycles(2000000);
    clearScreen(COLOR_BLACK);

    // Should it move up or down
    if (redraw > 70) {
      up = 1;
      down = 0;
    } else if (redraw < -10) {
      up = 0;
      down = 1;
    }

    if (down) {
      redraw += 5;
      drawString8x12(10, 5, "down", COLOR_WHITE, COLOR_BLACK);
    }
    else { 
      redraw -= 5;
      drawString8x12(10, 5, "up", COLOR_WHITE, COLOR_BLACK);
    }
    
    k = 0;
  }
}

/* Draws a triangle from the iconic video game series: The Legend of Zelda */
void drawTriforce() {
  clearScreen(COLOR_BLACK);
  int i, j = 0;
  for (i=62; i<82; i++) {
    drawPixel(i, i-30, COLOR_BLUE);
    drawPixel(i-(j*2), i-30, COLOR_BLUE);
    j++;
  }
  for (i=42; i<82; i++)
    drawPixel(i, 52, COLOR_BLUE);
  // Low Right
  j=0;
  for (i=82; i<102; i++) {
    drawPixel(i, i-30, COLOR_BLUE);
    drawPixel(i-(j*2), i-30, COLOR_BLUE);
    j++;
  }
  // Low Left
  j=0;
  for (i=42; i<62; i++) {
    drawPixel(i, i+10, COLOR_BLUE);
    drawPixel(i-(j*2), i+10, COLOR_BLUE);
    j++;
  }
  // Bottom line
  for (i=22; i<102; i++)
    drawPixel(i, 72, COLOR_BLUE);
}

void drawFonts() {
  clearScreen(COLOR_BLACK);
  drawString5x7(10, 10, "5x7 font", COLOR_WHITE, COLOR_BLACK);
  drawString8x12(10, 30, "8x12 font", COLOR_WHITE, COLOR_BLACK);
}
