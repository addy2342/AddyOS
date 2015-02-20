#include <stdint.h>
#include "include/fifo.h"
#include "include/address_map.h"

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
  fifos_flag[f] = FIFO_NOT_INUSE;
}

/**
* Finds a free fifo and sets it to used
* @return the index of a free fifo or -1
*/
//decleard in os.h
FIFO  OS_InitFiFo(void){
  FIFO idx = 0;
  for(;idx<MAXFIFO;idx++){ // iterat over all fifos
    if(!fifos_flag[idx])
      return (idx+1); // INVALIDFIFO = 0 so we start at one
  }
  return INVALIDFIFO;
}

//decleard in os.h
void  OS_Write( FIFO f, int val ){
  fifos_last[f] = (fifos_last[f]++) % FIFOSIZE;
  fifos_flag[f] = FIFO_INUSE_NOT_EMPTY;
  fifos_data[f][fifos_last[f]] = val;
}

//decleard in os.h
BOOL  OS_Read( FIFO f, int *val ){
  if(fifos_flag[f] = FIFO_INUSE_EMPTY) return FALSE;
  *val = fifos_first[f];
  fifos_first[f] = (fifos_first[f]++) % FIFOSIZE;
  if(fifos_first[f] == fifos_last[f])
    fifos_flag[f] = FIFO_INUSE_EMPTY;
  return TRUE;
}
