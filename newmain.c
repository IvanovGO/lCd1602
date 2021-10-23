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
    for (uint8_t i=0;i<0xff;i++) myLCD_Put(i);

    
    return (EXIT_SUCCESS);
}

