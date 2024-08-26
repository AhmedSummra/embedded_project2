/*
 * 7_segment.h
 *
 *  Created on: April 11, 2023
 *      Author: Ahmed summra
 */

#ifndef seven_SEGMENT_H_
#define seven_SEGMENT_H_

/*===========================INCLUDES==================================*/
#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>
/*=====================================================================*/

/*===========================FUNCTIONS DECLARATION=====================*/
void LCD_showTime(void);
void timer1_init(void);
ISR(TIMER1_COMPA_vect);
/*=====================================================================*/



#endif /* 7_SEGMENT_H_ */
