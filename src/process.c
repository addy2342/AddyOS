#include "include/process.h"
#include "include/os.h"

PID OS_Create(void (*f)(void), int arg, unsigned int level, unsigned int n){
  int idx = 0;
  for(;idx<MAXPROCESS;idx++){
    if(free_processes_slot[idx] == 0){
      free_processes_slot[idx] = 1;
      process[idx].run = f;
      process[idx].arg = arg;
      process[idx].level = level;
      process[idx].n = n;
      process[idx].run();
      return idx;
    }

  }
  return INVALIDPID;
}

void OS_Terminate(void){
 
}

void OS_Yield(void){

}

int  OS_GetParam(void){

}
