#include "include/fifo.h"

void clear_fifo(FIFO f);

void init_fifos(void){
  FIFO idx = 0;
  for(;idx<MAXFIFO;idx++){ // iteret over all fifos
    clear_fifo(idx);
  }
}

void clear_fifo(FIFO f){
  FIFO idx = 0;
  for(;idx<FIFOSIZE;idx++){ // iteret over all fifo elements
    fifos_data[f][idx] = 0;
  }
  fifos_first[f] = 0;
  fifos_last[f] = 0;
  fifos_flags[f] = 1;
}

//decleard in os.h
FIFO  OS_InitFiFo(void){
  return INVALIDFIFO;
}
