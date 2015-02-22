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

