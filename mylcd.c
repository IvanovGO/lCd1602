
/*
#define myLCD_Port PORTD
#define myLCD_CON PORTD
#define myLCD_DDR DDRD
#define myLCD_RE 0
#define myLCD_ES 1
#define myLCD_D4 2
#define myLCD_D5 3
#define myLCD_D6 4
#define myLCD_D7 5
*/



#include "mylcd.h"

#include <stdarg.h>
#include <stdio.h>
#include <util/delay.h>

#define LCD_E_TIME 10
#define DPD myLCD_PORT=0x00;
#define P myLCD_PORT
#define EU myLCD_CON|=  _BV(myLCD_E);
#define ED myLCD_CON&=~ _BV(myLCD_E);
#define RU myLCD_CON |=   _BV(myLCD_RS);
#define RD myLCD_CON &=~  _BV(myLCD_RS);
#define EN ED _delay_us(LCD_E_TIME); EU _delay_us(LCD_E_TIME); ED _delay_us(LCD_E_TIME);
#define d15 _delay_ms(15);
#define d45 _delay_ms(4);_delay_us(240);_delay_us(240);
#define d25 _delay_ms(2);_delay_us(240);_delay_us(240);
#define du150 _delay_us(150);
#define du250 _delay_us(250);
#define du40 _delay_us(40);

void myLCD_Init(){
  
        myLCD_CON_DDR |= _BV(myLCD_RS);
	myLCD_CON_DDR |= _BV(myLCD_E); //control ports is out
	myLCD_PORT_DDR = 0xff; //data port is all on out

        d15
                
        P=0b00110000;//2
        EN
        d45
        
        P=0b00110000;//3
        EN
        d45
        
        P=0b00110000;//4
        EN
        d25
        
        P=0b00100000;//5
        EN
        du150
        
        
        P=0b00100000;//6
        EN
        du150
        
                
        P=0b00000000;//7
        EN
        du150
        
                
        P=0b11000000;//8
        EN
        du150
        
                
        P=0b11000000;//9
        EN
        du150
        
              
        P=0b00000000;//10
        EN
        du150
                
                
	P=0b00010000;//11
        EN
        d25
        
        P=0b00000000;//12
        EN
        du150 
        
        P=0b01100000;//13
        EN
        _delay_ms(1);
        
        P=0b11000000;//14
        EN
        d45
        
        P=0b00110000;//15
        EN
        d45
        
        
        P=0b00110000;//16
        EN
        du250
        
                
        P=0b00100000;//17
        EN
        du150
        
                
        P=0b00100000;//18
        EN
        du150
        
                
        P=0b10000000;//19
        EN
        du150
        
              
        P=0b00000000;//20
        EN
        du150
        
        P=0b11000000;//21
        EN
        du150
        
                
        P=0b00000000;//22
        EN
        du150
        
                
        P=0b00010000;//23
        EN
        d25
        
              
        P=0b00000000;//24
        EN
        du150
        
        P=0b01100000;//25
        EN
        du150
        
}  

void myLCD_Put(uint8_t ch){
  RU
  P=ch;
  EN
  du40
  P=ch*0xf;
  EN
  du40
  RD
  
}