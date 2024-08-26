/*
 * 7_segment.c
 *
 *  Created on: April 11, 2023
 *      Author: ahmed Summra
 */
#include "seven_segment.h"

/*===========================GLOBAL VARIABLES==========================*/
unsigned char a=0,b=0,c=0,d=0,i=0,k=0;
/*=====================================================================*/

/*=============================FUNCTIONS DEFINITIONS====================*/
void LCD_showTime(void)
{
	PORTC=(PORTC&0x0f)|a;
	PORTA|=(1<<PA0);
    _delay_ms(2);
    PORTA&=~(1<<PA0);
	PORTC&=0xf0;
    PORTC=(PORTC&0x0f)|b;
	PORTA|=(1<<PA1);
    _delay_ms(2);
	PORTA&=~(1<<PA1);
	PORTC&=0xf0;
	PORTC=(PORTC&0x0f)|c;
	PORTA|=(1<<PA2);
    _delay_ms(2);
    PORTA&=~(1<<PA2);
    PORTC&=0xf0;
    PORTC=(PORTC&0x0f)|d;
    PORTA|=(1<<PA3);
    _delay_ms(2);
    PORTA&=~(1<<PA3);
    PORTC&=0xf0;
    PORTC=(PORTC&0x0f)|i;
    PORTA|=(1<<PA4);
    _delay_ms(2);
    PORTA&=~(1<<PA4);
    PORTC&=0xf0;
    PORTC=(PORTC&0x0f)|k;
    PORTA|=(1<<PA5);
    _delay_ms(2);
    PORTA&=~(1<<PA5);
    PORTC&=0xf0;
}
/************************************************************************/

void timer1_init(void)
{
 TCCR1B=(1<<WGM12)|(1<<CS10)|(1<<CS12);
 TCNT1=0;
 OCR1A=977;
 TIMSK|=(1<<OCIE1A);
}
/************************************************************************/

ISR(TIMER1_COMPA_vect)
{
	a++;
if(a==10){
b++;
a=0;
}
if(b==6&&a==0){
c++;
b=0;
}
if(c==10&&b==0){
d++;
c=0;
}
if(d==6&&c==0){
i++;
d=0;
}
if(i==10&&d==0){
k++;
i=0;
}
if(k==10&&i==0){
a=b=c=d=i=k=0;
}

}
/*======================================================================*/

