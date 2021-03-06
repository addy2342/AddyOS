#include <stdint.h>
#include "include/address_map.h"

void clear_LCD(){
  volatile char * LCD_display_ptr = (char *)LCD;
  *(LCD_display_ptr) = 1; //clear display
}

void write_to_LCD(int x, int y, char *text_ptr){
  volatile char * LCD_display_ptr = (char *)LCD;
  char instruction = x;
  
  if (y != 0)
    instruction |= 0x40; // set bit 6 for bottom row
  instruction |= 0x80; // need to set bit 7 to set the cursor location
  *(LCD_display_ptr) = instruction; // write to the LCD instruction register
  
  while ( *(text_ptr) ){
    *(LCD_display_ptr + 1) = *(text_ptr); // write to the LCD Data register
    ++text_ptr;
  }
}

void clear_7seg(){
  volatile uint32_t * seg7_left = (uint32_t *)HEX7_HEX4_BASE;
  volatile uint32_t * seg7_right = (uint32_t*)HEX3_HEX0_BASE;

  *(seg7_left) = 0x0;
  *(seg7_right) = 0x0;
}

void write_to_7seg(int left, int right){
  volatile uint32_t * seg7_left = (uint32_t *)HEX7_HEX4_BASE;
  volatile uint32_t * seg7_right = (uint32_t*)HEX3_HEX0_BASE;

  *(seg7_left) = left;
  *(seg7_right) = right;
}

void write_to_LEDR(int number){
  volatile uint32_t *ledr = (uint32_t *)LEDR;
  *(ledr) = number; 
}
void clear_LEDR(){
  write_to_LEDR(0);
}

void write_to_LEDG(int number){
  volatile uint32_t *ledg = (uint32_t *)LEDG;
  *(ledg) = number; 
}

void clear_LEDG(){
  write_to_LEDG(0);
}
