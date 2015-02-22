#ifndef _PROCESS_H_
#define _PROCESS_H_

#include "os.h"

typedef struct process_t{
  void (*run)(void);
  int arg;
  unsigned int level;
  unsigned int n;
}process_t;

process_t process[MAXPROCESS]; // the process map
unsigned int free_processes_slot[MAXPROCESS]; // idx of not used processes slots

#endif /* _PROCESS_H_ */
