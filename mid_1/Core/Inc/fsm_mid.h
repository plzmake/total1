/*
 * fsm_mid.h
 *
 *  Created on: Nov 5, 2022
 *      Author: Admin
 */

#ifndef INC_FSM_MID_H_
#define INC_FSM_MID_H_

#include "main.h"
#include "software_timer.h"
#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

extern int statusbut;
extern int KeyReginc0 ;
extern int KeyReginc1 ;
extern int KeyReginc2 ;
extern int KeyReginc3 ;

extern int KeyRegreset0 ;
extern int KeyRegreset1 ;
extern int KeyRegreset2 ;
extern int KeyRegreset3 ;

extern int KeyRegdec0 ;
extern int KeyRegdec1 ;
extern int KeyRegdec2 ;
extern int KeyRegdec3 ;
extern int TimeForKeyPressInc ;
extern int TimeForKeyPressDec ;
extern int inc_ac ;
extern int dec_ac ;

#define reset 2
#define inc   3
#define dec   4
#define init		5
#define buttonLonginc 6
#define buttonLongdec 7
#define time_out		8
void isResetNor();
void isIncNor();
void isDecNor();
void long_press_dec();
void long_press_inc();
void timer_out();
void display7SEG(int num);
#endif /* INC_FSM_MID_H_ */
