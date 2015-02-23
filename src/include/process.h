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
// 1 if slot  of not used processes slots
unsigned int free_processes_slot[MAXPROCESS];

#endif /* _PROCESS_H_ */
