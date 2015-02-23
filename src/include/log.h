#ifndef _LOG_H_
#define _LOG_H_

void clear_LCD(void);
void write_to_LCD(int x, int y, char *text_ptr);

void clear_7seg();
void write_to_7seg(int left, int right);

void write_to_LEDR(int number);
void clear_LEDR();

void write_to_LEDG(int number);
void clear_LEDG();

#endif /* _LOG_H_  */
