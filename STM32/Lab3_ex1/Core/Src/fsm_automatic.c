/*
 * fsm_automatic.c
 *
 *  Created on: Nov 14, 2023
 *      Author: TuanAnh
 */

#include "fsm_automatic.h"



void fsm_automatic_run() {
	switch (state) {
		case INIT:
			// TODO
			led7_0 = green_counter;
			led7_1 = red_counter;
			HAL_GPIO_WritePin(GPIOA, MAIN_GREEN_Pin|SIDE_RED_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, MAIN_YELLOW_Pin|MAIN_RED_Pin|SIDE_GREEN_Pin|SIDE_YELLOW_Pin, GPIO_PIN_RESET);


			setTimer1s();
			setTimer1(green_counter*1000);
			state = GREEN_RED;
			break;
		case GREEN_RED:
			// TODO
			HAL_GPIO_WritePin(GPIOA, MAIN_GREEN_Pin|SIDE_RED_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, MAIN_YELLOW_Pin|MAIN_RED_Pin|SIDE_GREEN_Pin|SIDE_YELLOW_Pin, GPIO_PIN_RESET);

			if (isButtonPressed(0)) {
				setTimer2hz();
				state = MAN_RED;
			}
			if (timer_1s_flag == 1) {
				setTimer1s();
				led7_0--;
				led7_1--;
			}
			if (timer1_flag == 1) {
				setTimer1(yellow_counter*1000);
				led7_0 = yellow_counter;
				led7_1 = yellow_counter;
				state = YELLOW_RED;
			}
			break;
		case YELLOW_RED:
			// TODO
			HAL_GPIO_WritePin(GPIOA, MAIN_YELLOW_Pin|SIDE_RED_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, MAIN_GREEN_Pin|MAIN_RED_Pin|SIDE_GREEN_Pin|SIDE_YELLOW_Pin, GPIO_PIN_RESET);

			if (isButtonPressed(0)) {
				setTimer2hz();
				state = MAN_RED;
			}
			if (timer_1s_flag == 1) {
				setTimer1s();
				led7_0--;
				led7_1--;
			}
			if (timer1_flag == 1) {
				setTimer1(green_counter*1000);
				led7_0 = red_counter;
				led7_1 = green_counter;
				state = RED_GREEN;
			}
			break;
		case RED_GREEN:
			// TODO
			HAL_GPIO_WritePin(GPIOA, MAIN_RED_Pin|SIDE_GREEN_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, MAIN_GREEN_Pin|MAIN_YELLOW_Pin|SIDE_YELLOW_Pin|SIDE_RED_Pin, GPIO_PIN_RESET);


			if (isButtonPressed(0)) {
				setTimer2hz();
				state = MAN_RED;
			}
			if (timer_1s_flag == 1) {
				setTimer1s();
				led7_0--;
				led7_1--;
			}
			if (timer1_flag == 1) {
				led7_0 = yellow_counter;
				led7_1 = yellow_counter;
				setTimer1(yellow_counter*1000);
				state = RED_YELLOW;
			}
			break;
		case RED_YELLOW:
			// TODO
			HAL_GPIO_WritePin(GPIOA, MAIN_RED_Pin|SIDE_YELLOW_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, MAIN_GREEN_Pin|MAIN_YELLOW_Pin|SIDE_GREEN_Pin|SIDE_RED_Pin, GPIO_PIN_RESET);



			if (isButtonPressed(0)) {
				setTimer2hz();
				state = MAN_RED;
			}
			if (timer_1s_flag == 1) {
				setTimer1s();
				led7_0--;
				led7_1--;
			}
			if (timer1_flag == 1) {
				setTimer1(green_counter*1000);
				led7_0 = green_counter;
				led7_1 = red_counter;
				state = GREEN_RED;
			}
			break;
		default:
			break;

	}
}
