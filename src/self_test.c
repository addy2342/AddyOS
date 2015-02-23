#include "include/os.h"
#include "include/address_map.h"
#include "include/fifo.h"
#include "include/sem.h"
#include "include/log.h"
#include "math.h"

/* function prototypes */
void run_write_fifo(void);
void run_read_fifo(void);
void run_write_to_LED(int bits);

void run_self_test(void){
  int idx;
  int tmp;
  FIFO fifo_1;
  
  srand(4);
  
    /////////////////
   ///   L O G   ///
  /////////////////

  run_write_to_LED(7);
  clear_LCD();
  write_to_LCD(0, 0, "Self Test");
  write_to_LCD(0, 1, "...");
  write_to_7seg(0x775E5EEE, 0x5B4FE65B); //AddY 2342
  for(idx = 0;idx<1000000;idx++)
    tmp = rand();
  
    ///////////////////
   ///   F I F O   ///
  ///////////////////

  clear_LCD();
  clear_7seg();
  write_to_LCD(0, 0, "Testing FIFOs:");
  write_to_7seg(0x7106713F, 0x0); // FIFO
  fifo_1 = OS_InitFiFo();
  write_to_LCD(0, 1, "Created");
  for(idx = 0;idx<1000000;idx++)
    tmp = rand();

  clear_LCD();
  run_write_fifo();
  run_read_fifo();
  write_to_LCD(0, 0, "Testing FIFOs:");
  write_to_LCD(0, 1, "RW: done");
  for(idx = 0;idx<1000000;idx++)
    tmp = rand();

    /////////////////
   ///   S E M   ///
  /////////////////

  clear_LCD();
  clear_7seg();
  write_to_LCD(0, 0, "Testing SEMs:");
  write_to_7seg(0x6d795454, 0x0); // SEnn
  OS_InitSem(1, 1);
  write_to_LCD(0, 1, "Created Mutex");
  for(idx = 0;idx<1000000;idx++)
    tmp = rand();


  OS_InitSem(1, 3);
  clear_LCD();
  write_to_LCD(0, 0, "Testing SEMs:");
  write_to_LCD(0, 1, "Created SEM");
  for(idx = 0;idx<1000000;idx++)
    tmp = rand();

  clear_LCD();
  write_to_LCD(0, 0, "Self Test:");
  write_to_LCD(0, 1, "Fine! :)");
  for(idx = 0;idx<1000000;idx++)
    tmp = rand();

  clear_LCD();
  clear_7seg();
  clear_LEDR();
  clear_LEDG();
}

void run_write_fifo(void){
  FIFO fifo = 1;
  write_to_7seg(0x7106713F, 0x6); // FIFO
  OS_Write(fifo, 1);
}

void run_read_fifo(void){
  FIFO fifo = 1;
  int fifo_value;
  write_to_7seg(0x7106713F, 0x600); // FIFO
  //OS_Read(fifo, &fifo_value);
  if(OS_Read(fifo, &fifo_value)){
    write_to_LCD(0, 0, "FIFO READ: win");
  }
  else{
    write_to_LCD(0, 0, "FIFO READ: fail");
  }
}

void run_write_to_LED(int bits){
  write_to_LEDR(bits);
  write_to_LEDG(bits);
}
