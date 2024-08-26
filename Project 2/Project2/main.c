/*
 * main.c
 *
 *  Created on: April 11, 2023
 *      Author: Ahmed Summra
 */
#include "seven_segment.h"
#include "project.h"


int main(void)
{
	pins_init();
	ext_interrupt0_init();
	ext_interrupt1_init();
	ext_interrupt2_init();
	timer1_init();
	SREG|=(1<<7);   //enable the global interrupts
	while(1)
	{
		LCD_showTime();
	}
return 0;
}

