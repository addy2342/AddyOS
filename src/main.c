#include <stdint.h>
#include "include/os.h"
#include "include/address_map.h"

/* function prototypes */
int main(void);

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
    volatile uint32_t * seg7_left = (uint32_t *)HEX7_HEX4_BASE;
    volatile uint32_t * seg7_right = (uint32_t*)HEX3_HEX0_BASE;
    //http://www.uize.com/examples/seven-segment-display.html get hex values from 7-seg-image
    *(seg7_left) = 0x775E5EEE; //AddY
    *(seg7_right) = 0x5B4FE65B; //2342

  OS_Init(); // Initalise the OS
  OS_InitFiFo();
}

void OS_Init(){
  init_fifos();
}
