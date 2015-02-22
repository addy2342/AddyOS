#include "include/os.h"
#include "include/address_map.h"
#include "include/fifo.h"
#include "include/log.h"
#include "math.h"
#include "stdlib.h"

void binary_led_count(volatile char * LED_ptr) {
  
  int idx, jdx = 0;
  int max_binary_value_for_fifosize = pow(2,FIFOSIZE);
  int tmp;
  srand(4);
  for(;idx<max_binary_value_for_fifosize;){
    *LED_ptr = idx;
    for(jdx=0;jdx<1000;jdx++) // no time.h sleep()
    {
      tmp = rand();
    }
    idx++;
  }
  *LED_ptr = 0;
}

void run_redlights_app(void){
  volatile char * LED_ptr = (char *)LEDR;
  binary_led_count(LED_ptr);
}

void run_greenlights_app(void){
  volatile char * LED_ptr = (char *)LEDG;
  binary_led_count(LED_ptr);
}
