#include <stdint.h>
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
  volatile uint32_t *seg7_left = (uint32_t*)0x10000030;
  volatile uint32_t *seg7_right = (uint32_t*)0x10000020;
  *(seg7_left) = 0x7106713F; //FIFO
  *(seg7_right) = 0x06540678; //Init

  FIFO idx = 0;
  for(;idx<MAXFIFO;idx++){ // iterat over all fifos
    if(!fifos_flag[idx])
      return (idx+1); // INVALIDFIFO = 0 so we start at one
  }
  return INVALIDFIFO;
}

//decleard in os.h
void  OS_Write( FIFO f, int val ){
  volatile uint32_t *seg7_left = (uint32_t*)0x10000030;
  volatile uint32_t *seg7_right = (uint32_t*)0x10000020;
  *(seg7_left) = 0x7106713F; //FIFO
  *(seg7_right) = 0x795078; //Ert

  fifo_last[f] = (fifo_last[f]++) % FIFOSIZE;
  fifo_flag[f] = FIFO_INUSE_NOT_EMPTY;
  fifos_data[f][fifo_last[f]] = val;
}

//decleard in os.h
BOOL  OS_Read( FIFO f, int *val ){
  if(fifo_flag[f] = FIFO_INUSE_EMPTY) return FALSE;
  val = fifo_first[f];
  fifo_first[f] = (fifo_first[f]++) % FIFOSIZE;
  if(fifo_first[f] == fifo_last[f])
    fifo_flag[f] = FIFO_INUSE_EMPTY;
  fifos_data[f][fifo_last[f]] = val;
  return TRUE;
}
