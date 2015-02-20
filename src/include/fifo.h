#ifndef _FIFO_H_
#define _FIFO_H_

#define FIFO_NOT_INUSE 0
#define FIFO_INUSE_EMPTY 1
#define FIFO_INUSE_NOT_EMPTY 0
#include "os.h"

FIFO fifos_data[MAXFIFO][FIFOSIZE]; // the fifos
unsigned int fifos_first[MAXFIFO]; // idx of first fifo value
unsigned int fifos_last[MAXFIFO]; // idx of last fifo value
/**
* using the definitions above
* 0 = not in use
* 1 = in use empty
* 2 = in use not empty
*     to distinguisch full and empty when both indecies are equal
*/
char fifos_flag[MAXFIFO]; // is set to 1  if fifo at number idx is free

/**
* sets all values in the structure to zero and marks all fifos to free.
*/
void init_fifos(void);

#endif /* _FIFO_H_  */
