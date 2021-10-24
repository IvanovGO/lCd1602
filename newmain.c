/* 
 * File:   newmain.c
 * Author: gri
 *
 * Created on 21 ??????? 2021 ?., 22:49
 */

#include <stdio.h>
#include <stdlib.h>

#include "mylcd.h"

/*
 * 
 */
int main(int argc, char** argv) {
    myLCD_Init();
 
 start:
    // for (uint8_t i=0;i<0xff;i++) myLCD_Put(i);
    myLCD_CLR();
    myLCD_Put('h');
    myLCD_Put('e');
    myLCD_Put('l');
    myLCD_Put('l');
    myLCD_Put('o');
    myLCD_Put(' ');
    myLCD_Put('k');
    myLCD_Put('i');
    myLCD_Put('t');
    myLCD_Put('t');
    myLCD_Put('y');
    myLCD_SLEEP(1);
    myLCD_CLR();
    
    myLCD_SLEEP(1);
  //    myLCD_INC();
       myLCD_SLEEP(1);
    uint8_t str[]="AS&DD the best!!\n";
   myLCD_PRINT(str);
    myLCD_SLEEP(2);
    myLCD_CLR();
    myLCD_GotoXY(4,0);
    myLCD_Put('t');
       myLCD_SLEEP(1);
    myLCD_GotoXY(2,1);
    myLCD_Put('w');
       myLCD_SLEEP(1);
    

       
       uint8_t i=0;
       char di=1;
       
       for (uint8_t j=0;j<0x1f;j++)
       {
           myLCD_CLR();
           myLCD_GotoXY(i,1);
           myLCD_Put('*');
           myLCD_GotoXY(0xf-i,0);
           myLCD_Put('+');
           
           i+=di;
           if((i>0xe)|(i==0))di*=-1;
           myLCD_mSLEEP(25);
                 }
        
       uint8_t str2[]="<<SAIEP RULES>>\n";
       uint8_t str3[]="glory to robots\n";
   
       for (uint8_t k=0;k<0xa;k++)
         for (uint8_t j=0;j<0x1f;j++)
       {
           myLCD_CLR();
           if (j>0xf) {myLCD_GotoXY(0x1f-j,0);}
           else {myLCD_GotoXY(j,0);}
           myLCD_PRINT(str2);
           if (j>0xf) {myLCD_GotoXY(j-0xf,1);}
           else {myLCD_GotoXY(0xf-j,1);}
           myLCD_PRINT(str3);
           myLCD_mSLEEP(15);
                 }
     
       
     goto start;  
    
    return (EXIT_SUCCESS);
}

