/*
 * project.h
 *
 *  Created on: April 11, 2023
 *      Author: Ahmed Summra
 */

#ifndef PROJECT_H_
#define PROJECT_H_

/*===========================INCLUDES==================================*/
#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>
/*=====================================================================*/

/*===========================EXTERNS===================================*/
extern unsigned char a,b,c,d,i,k;
/*=====================================================================*/

/*===========================FUNCTIONS DECLARATIONS====================*/
void ext_interrupt0_init(void);
void ext_interrupt1_init(void);
void ext_interrupt2_init(void);
void pins_init(void);
ISR(INT0_vect);
ISR(INT1_vect);
ISR(INT2_vect);
/*=====================================================================*/


#endif /* PROJECT_H_ */
