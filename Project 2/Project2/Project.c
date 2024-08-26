/*
 * Project.c
 *
 *  Created on: April 11, 2023
 *      Author: Ahmed Summra
 */
#include "project.h"


/*========================FUNCTIONS DEFINITIONS=========================*/

void ext_interrupt0_init(void)   //reset button interrupt
{
	MCUCR|=(1<<ISC01);
	GICR|=(1<<INT0);
	DDRD&=~(1<<PD2);  //make bit 2 of port D as input
	PORTD|=(1<<PD2);  //initialize bit 2 of port D as high
}
/***********************************************************************/
void ext_interrupt1_init(void)   //resume button interrupt
{
	MCUCR|=(1<<ISC10)|(1<<11);
	GICR|=(1<<INT1);
	DDRB&=~(1<<PB2);  //make bit 2 of port B as input
	PORTB|=(1<<PB2);  //initialize bit 2 of port B as high
}
/**********************************************************************/
void ext_interrupt2_init(void)   //pause button interrupt
{
	MCUCSR &= ~(1<<ISC2);
	GICR|=(1<<INT2);
	DDRD&=~(1<<PD3);  //make bit 3 of port D as input
}
/**********************************************************************/
void pins_init(void)
{
	DDRC=0x0f;   //make the least 4 bits of port C as output
	DDRA=0x3f;   //make the least 6 bits of port A as output
}
/**********************************************************************/
ISR(INT0_vect)
{
	a=b=c=d=i=k=0;
TCNT1=0;
GIFR|=(1<<INT0);
}
/**********************************************************************/
ISR(INT1_vect)
{
	TIMSK&=~(1<<OCIE1A);
	TCNT1=0;
	GIFR|=(1<<INT1);
}
/**********************************************************************/
ISR(INT2_vect)
{
	TIMSK|=(1<<OCIE1A);
	TCNT1=0;
	GIFR|=(1<<INT2);
}

/*========================================================================*/
