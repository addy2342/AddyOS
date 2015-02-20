#ifndef _FIFO_H_
#define _FIFO_H_

#include "os.h"

FIFO fifos_data[MAXFIFO][FIFOSIZE]; // the fifos
unsigned int fifos_first[MAXFIFO]; // idx of first fifo value
unsigned int fifos_last[MAXFIFO]; // idx of last fifo value
char fifos_flag[MAXFIFO]; // is set to 1  if fifo at number idx is free

/**
* sets all values in the structure to zero and marks all fifos to free.
*/
void init_fifos(void);

#endif /* _FIFO_H_  */
