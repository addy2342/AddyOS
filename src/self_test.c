#include "include/os.h"
#include "include/address_map.h"
#include "include/fifo.h"
#include "include/log.h"

/* function prototypes */
void run_self_test(void){
  char *testing_fifos = "Testing FIFOs:";
  char *creating_fifos = "Creating FIFOs: ";
  char *done = "done";

  FIFO fifo_1;
  

    ///////////////////
   ///   F I F O   ///
  ///////////////////
  clear_LCD();
  clear_7seg();
  write_to_LCD(0, 0, testing_fifos);
  write_to_7seg(0x7106713F, 0x0); // FIFO
  fifo_1 = OS_InitFiFo();
  clear_LCD();
  write_to_LCD(0, 0, creating_fifos);
  write_to_LCD(0, 1, done);

}
