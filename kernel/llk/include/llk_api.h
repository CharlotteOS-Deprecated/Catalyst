#ifndef LLK_API_H
#define LLK_API_H

/*CPU*/
void llk_hcf(void);

/*Serial Port*/
int llk_init_serial(void);
void llk_serial_putc(const char c);

#endif