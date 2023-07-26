#ifndef LLK_API_H
#define LLK_API_H

/*Serial Port*/
int llk_init_serial(void);
void llk_serial_putc(const char c);

/*CPU*/
void llk_hcf(void);

#endif