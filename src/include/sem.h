#ifndef _SEM_H_
#define _SEM_H_

#define SEM_CLEAR_DEFAULT 0
#define SEM_NOT_INUSE 0
#define SEM_INUSE 1

#include "os.h"

struct semaphore_t{
  unsigned int max_access; //simultanius to critical section
  PID wait_queue[MAXPROCESS];
  unsigned int sems_first[MAXSEM]; // idx of first p in queue
  unsigned int sems_last[MAXSEM]; // idx of last p in queue
};

struct semaphore_t sems_data[MAXSEM];// the semaphores
char sems_flag[MAXSEM]; // is set to 1  if sem at number idx is free

/**
* sets all values in the structure to zero and marks all semaphores to free.
*/
void init_sem(void);

#endif /* _SEM_H_  */
