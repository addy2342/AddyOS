#include <stdint.h>
#include "include/os.h"
#include "include/address_map.h"
#include "include/log.h"
#include "include/tests.h"

/* function prototypes */
int main(void);

/* Application prototypes*/
void run_greenlights_app(void);
void run_redlights_app(void);


/* The assembly language code below handles CPU reset processing */
void the_reset (void) __attribute__ ((section (".reset")));
void the_reset (void)
/************************************************************************************
 * Reset code. By giving the code a section attribute with the name ".reset" we     *
 * allow the linker program to locate this code at the proper reset vector address. *
 * This code just calls the main program.                                           *
 ***********************************************************************************/
{
asm (".set    noat");         // Magic, for the C compiler
asm (".set    nobreak");        // Magic, for the C compiler
asm ("movia   r2, main");       // Call the C language main program
asm ("jmp   r2"); 
}

int main(void){
  char * txt = "Hallo Addy!";
  //http://www.uize.com/examples/seven-segment-display.html get hex values from 7-seg-image
  write_to_7seg(0x775E5EEE, 0x5B4FE65B); //AddY 2342
  write_to_LCD(0,0, txt);

  OS_Init(); // Initalise the OS
  OS_InitFiFo();
  run_self_test();
  
  write_to_7seg(0x775E5EEE, 0x5B4FE65B); //AddY 2342
  write_to_LCD(0,0, txt);
  
  OS_Create(run_redlights_app, 1, SPORADIC, 0);
  OS_Create(run_greenlights_app, 1, SPORADIC, 0);
}

void OS_Init(){
  init_fifos();
}
