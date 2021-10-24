/*
 Automation systems and drives department
 */


#include <avr/io.h>


#define F_CPU 12000000UL

#define myLCD_PORT PORTD
#define myLCD_CON PORTB


#define myLCD_PORT_DDR DDRD
#define myLCD_CON_DDR DDRB

#define myLCD_RS 0
#define myLCD_E  1
#define myLCD_D4 2
#define myLCD_D5 3
#define myLCD_D6 4
#define myLCD_D7 5





void myLCD_Init(void);
void myLCD_Put(uint8_t ch);
void myLCD_CLR(void);
void myLCD_SLEEP(uint8_t t);
void myLCD_mSLEEP(uint8_t t);
void myLCD_PRINT(uint8_t *str);
void myLCD_CR(void);
void myLCD_INC(void);
void myLCD_GotoXY(uint8_t x,uint8_t y);
