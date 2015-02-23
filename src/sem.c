#include <stdint.h>
#include "include/sem.h"
#include "include/address_map.h"


void clear_sem(unsigned int s, int n){
  unsigned int idx = 0;
  sems_data[s].max_access = 0;
  for(;idx<MAXPROCESS;idx++){ // iteret over all fifo elements
    sems_data[s].wait_queue[idx] = 0;
  }
  sems_data[s].sems_first[s] = 0;
  sems_data[s].sems_last[s] = 0;
  sems_flag[s] = SEM_NOT_INUSE;
}

void init_sem(void){
  unsigned int idx = 0;
  for(;idx<MAXSEM;idx++){ // iteret over all fifos
    clear_sem(idx, SEM_CLEAR_DEFAULT);
  }
}

/**
* Overwrites the semaphore "s" and
* sets the property of maximum simultanius access to  n
* decleard in os.h
*/
void OS_InitSem( int s, int n ){
  // 1 to MAXSEM to be consistend  with FIFO access
  if(s>0 && s<=MAXSEM){
    clear_sem(s, n);
  }
}

