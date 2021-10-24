
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
	myLCD_PORT_DDR = 0xf0; //data port D7-D4 is on out
        d15
        P=0b00100000; EN d45 //2
        P=0b00100000; EN d45 //3
        P=0;  EN du250
        P=0;  EN du250 //4
        P=0b11100000; EN du150
        P=0; EN du150 //5
        P=0b01100000; EN du150
   

}       



void myLCD_Put(uint8_t ch){
  
  RU
  P=ch;
  EN du40
  P=ch<<4;       
  EN du40 
  RD
  d45
}

void myLCD_CLR(){
  RD
  P=0b0;EN du40
  P=0b00010000;EN du40

}
void myLCD_CR(){
  RD
  P=0b0;EN du40
  P=0b00110000;EN du40

}

void myLCD_INC(){
  RD
  P=0b10000000;EN du40
  P=0b00010000;EN du40
  
}

void myLCD_GotoXY(uint8_t x,uint8_t y){
  uint8_t tmp;
  if (y!=0) x+=40;
  tmp=x; 
  tmp|=_BV(7);
  P=tmp;
  EN du40
  P=tmp<<4;       
  EN d45 
}


void myLCD_SLEEP(uint8_t t){
  for (uint8_t i=0;i<t;i++){
    _delay_ms(250);_delay_ms(250);_delay_ms(250);_delay_ms(250);
    }
  }

void myLCD_mSLEEP(uint8_t t){    
for (uint8_t i=0;i<t;i++){
    _delay_ms(10);
    } }

void myLCD_PRINT(uint8_t *str){
  uint8_t i =0;
  while (str[i]!='\n'){
  myLCD_Put(str[i]);
    i++;}
}