#include <stdint.h>
#include "include/address_map.h"

void write_to_LCD(int x, int y, char *text_ptr){
  volatile char * LCD_display_ptr = (char *)LCD;
  char instruction = x;
  *(LCD_display_ptr) = 1; //clear display
  if (y != 0)
    instruction |= 0x40; // set bit 6 for bottom row
  instruction |= 0x80; // need to set bit 7 to set the cursor location
  *(LCD_display_ptr) = instruction; // write to the LCD instruction register
  
  while ( *(text_ptr) ){
    *(LCD_display_ptr + 1) = *(text_ptr); // write to the LCD Data register
    ++text_ptr;
  }
}

void write_to_7seg(int left, int right){
  volatile uint32_t * seg7_left = (uint32_t *)HEX7_HEX4_BASE;
  volatile uint32_t * seg7_right = (uint32_t*)HEX3_HEX0_BASE;

  *(seg7_left) = left;
  *(seg7_right) = right;
}
