/*
 * fsm_mid.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Admin
 */
#include "fsm_mid.h"
int KeyReginc0 = NORMAL_STATE;
int KeyReginc1 = NORMAL_STATE;
int KeyReginc2 = NORMAL_STATE;
int KeyReginc3 = NORMAL_STATE;

int KeyRegreset0 = NORMAL_STATE;
int KeyRegreset1 = NORMAL_STATE;
int KeyRegreset2 = NORMAL_STATE;
int KeyRegreset3 = NORMAL_STATE;

int KeyRegdec0 = NORMAL_STATE;
int KeyRegdec1 = NORMAL_STATE;
int KeyRegdec2 = NORMAL_STATE;
int KeyRegdec3 = NORMAL_STATE;
int TimeForKeyPressInc =  300;
int TimeForKeyPressDec =  300;
int button1_flag = 0;
int counter =0;

int inc_ac =0;
int dec_ac =0;
statusbut = init;
void display7SEG(int num){
if (num == 0)
	  {
		  HAL_GPIO_WritePin(GPIOB, LED7_0_Pin|LED7_1_Pin|LED7_2_Pin|LED7_3_Pin|LED7_4_Pin|LED7_5_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, LED7_6_Pin, GPIO_PIN_SET);
	  }
	  else if (num == 1)
	  {
		  HAL_GPIO_WritePin(GPIOB, LED7_1_Pin|LED7_2_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, LED7_0_Pin|LED7_3_Pin |LED7_4_Pin|LED7_5_Pin|LED7_6_Pin, GPIO_PIN_SET);
	  }
	  else if (num == 2)
	  {
		  HAL_GPIO_WritePin(GPIOB, LED7_0_Pin|LED7_1_Pin|LED7_3_Pin|LED7_4_Pin|LED7_6_Pin, GPIO_PIN_RESET);
		  		  HAL_GPIO_WritePin(GPIOB, LED7_2_Pin|LED7_5_Pin, GPIO_PIN_SET);
	  }
	  else if (num == 3)
	  {
		  HAL_GPIO_WritePin(GPIOB, LED7_0_Pin|LED7_1_Pin|LED7_2_Pin|LED7_3_Pin|LED7_6_Pin, GPIO_PIN_RESET);
		  		  HAL_GPIO_WritePin(GPIOB, LED7_4_Pin|LED7_5_Pin, GPIO_PIN_SET);
	  }
	  else if (num == 4)
	  {
		  HAL_GPIO_WritePin(GPIOB, LED7_1_Pin|LED7_2_Pin|LED7_5_Pin|LED7_6_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, LED7_4_Pin|LED7_0_Pin|LED7_3_Pin, GPIO_PIN_SET);
	  }
	  else if (num == 5)
	  {
		  HAL_GPIO_WritePin(GPIOB, LED7_0_Pin|LED7_2_Pin|LED7_5_Pin|LED7_3_Pin|LED7_6_Pin, GPIO_PIN_RESET);
		  		  HAL_GPIO_WritePin(GPIOB, LED7_4_Pin|LED7_1_Pin, GPIO_PIN_SET);
	  }
	  else if (num == 6)
	  {
		  HAL_GPIO_WritePin(GPIOB, LED7_0_Pin|LED7_2_Pin|LED7_5_Pin|LED7_4_Pin|LED7_3_Pin|LED7_6_Pin, GPIO_PIN_RESET);
		  		  		  HAL_GPIO_WritePin(GPIOB, LED7_1_Pin, GPIO_PIN_SET);
	  }
	  else if (num == 7)
	  {
		  HAL_GPIO_WritePin(GPIOB, LED7_0_Pin|LED7_1_Pin|LED7_2_Pin, GPIO_PIN_RESET);
		  		  HAL_GPIO_WritePin(GPIOB, LED7_3_Pin|LED7_4_Pin|LED7_5_Pin|LED7_6_Pin, GPIO_PIN_SET);
	  }
	  else if (num == 8)
	  {
		  HAL_GPIO_WritePin(GPIOB, LED7_0_Pin|LED7_1_Pin|LED7_2_Pin|LED7_3_Pin|LED7_4_Pin|LED7_5_Pin|LED7_6_Pin, GPIO_PIN_RESET);
	  }
	  else if (num == 9)
	  {
		  HAL_GPIO_WritePin(GPIOB, LED7_0_Pin|LED7_1_Pin|LED7_2_Pin|LED7_3_Pin
		                            |LED7_5_Pin|LED7_6_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB,
		                            LED7_4_Pin, GPIO_PIN_SET);
	  }
}
void isResetNor(){
	KeyRegreset0 = KeyRegreset1;
			  			KeyRegreset1 = KeyRegreset2;
			  			KeyRegreset2 = HAL_GPIO_ReadPin(RESET_GPIO_Port, RESET_Pin);
			  			if ((KeyRegreset0 == KeyRegreset1)&&(KeyRegreset1 == KeyRegreset2)){
			  			if (KeyRegreset2 != KeyRegreset3){
			  					  KeyRegreset3 = KeyRegreset2;

			  			if (KeyRegreset2 == PRESSED_STATE){

			  				statusbut = reset;
			  				counter =0;
			  				display7SEG(counter);
			  				Settimer1(1000);
			  				}}}
}
void isIncNor(){
	KeyReginc0 = KeyReginc1;
			  			KeyReginc1 = KeyReginc2;
			  			KeyReginc2 = HAL_GPIO_ReadPin(INC_GPIO_Port, INC_Pin);
			  			if ((KeyReginc0 == KeyReginc1)&&(KeyReginc1 == KeyReginc2)){
			  			if (KeyReginc2 != KeyReginc3){
			  					  KeyReginc3 = KeyReginc2;

			  			if (KeyReginc2 == PRESSED_STATE){
			  					  // counter =0;
			  				if(statusbut != buttonLonginc){
			  				statusbut = inc;}
			  				if(counter == 9){counter = 0;}
			  				else{counter = counter +1;}
			  				display7SEG(counter);
			  				Settimer1(1000);
			  				if(!inc_ac)
			  				{TimeForKeyPressInc =  300;
			  				inc_ac =1;}
			  				}}}
}
void isDecNor(){
	KeyRegdec0 = KeyRegdec1;
				  			KeyRegdec1 = KeyRegdec2;
				  			KeyRegdec2 = HAL_GPIO_ReadPin(DEC_GPIO_Port, DEC_Pin);
				  			if ((KeyRegdec0 == KeyRegdec1)&&(KeyRegdec1 == KeyRegdec2)){
				  			if (KeyRegdec2 != KeyRegdec3){
				  					  KeyRegdec3 = KeyRegdec2;

				  			if (KeyRegdec2 == PRESSED_STATE){
				  					  if(statusbut != buttonLongdec)
				  				{statusbut = dec;}
				  				if(counter == 0){counter = 9;}
				  				else{counter = counter -1;}
				  				display7SEG(counter);
				  				Settimer1(1000);
				  				if(!dec_ac)
				  					{TimeForKeyPressDec =  300;
				  					dec_ac =1;}
				  				}}}
}
void long_press_inc(){




	if((inc_ac)&&(flag_inc)){

		flag_inc =0;
	}
}
void long_press_dec(){


	if((dec_ac)&&(flag_dec)){

			flag_dec =0;
		}
}

void timer_out(){
	 if(Timer1_flag == 1){
		 statusbut = time_out;
		 Settimer1(50);
		 if(counter == 0){counter = 9;}
		 else{counter = counter -1;}
		 display7SEG(counter);
	 }
 }
