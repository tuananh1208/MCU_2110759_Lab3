/*
 * fsm_manual.c
 *
 *  Created on: Nov 14, 2023
 *      Author: TuanAnh
 */


#include "fsm_manual.h"

void fsm_manual_run() {
	switch (state) {
		case MAN_RED:
			// todo
			// red leds blink 2hz & turn off others
			HAL_GPIO_WritePin(GPIOA, MAIN_GREEN_Pin|MAIN_YELLOW_Pin|SIDE_GREEN_Pin|SIDE_YELLOW_Pin|SIDE_RED_Pin, GPIO_PIN_RESET);
			if (timer_2hz_flag == 1) {
				setTimer2hz();
				HAL_GPIO_TogglePin(MAIN_RED_GPIO_Port, MAIN_RED_Pin);
			}

			// display value on led7
			led7_0 = 2;
			led7_1 = red_counter;

			if (isButtonPressed(0)) {
				state = MAN_YELLOW;
			}
			if (isButtonPressed(1)) { // increase
				red_counter++;
				if (red_counter >= 100) { // red: 5-99s
					red_counter = 5;
				}
				green_counter = red_counter - yellow_counter;
			}
			if (isButtonPressed(2)) { // set value
				state = INIT;
			}

			break;
		case MAN_YELLOW:
			// todo
			// YELLOW leds blink 2hz & turn off others
			HAL_GPIO_WritePin(GPIOA, MAIN_GREEN_Pin|MAIN_RED_Pin|SIDE_GREEN_Pin|SIDE_YELLOW_Pin|SIDE_RED_Pin, GPIO_PIN_RESET);
			if (timer_2hz_flag == 1) {
				setTimer2hz();
				HAL_GPIO_TogglePin(MAIN_YELLOW_GPIO_Port, MAIN_YELLOW_Pin);
			}

			// display value on led7
			led7_0 = 3;
			led7_1 = yellow_counter;

			if (isButtonPressed(0)) {
				state = MAN_GREEN;
			}
			if (isButtonPressed(1)) { // increase
				yellow_counter++;
				if (yellow_counter >= 97) { // red: 2-96s
					yellow_counter = 2;
				}
				red_counter++;
			}
			if (isButtonPressed(2)) { // set value
				state = INIT;
			}

			break;
		case MAN_GREEN:
			// todo
			// GREEN leds blink 2hz & turn off others
			HAL_GPIO_WritePin(GPIOA, MAIN_YELLOW_Pin|MAIN_RED_Pin|SIDE_GREEN_Pin|SIDE_YELLOW_Pin|SIDE_RED_Pin, GPIO_PIN_RESET);
			if (timer_2hz_flag == 1) {
				setTimer2hz();
				HAL_GPIO_TogglePin(MAIN_GREEN_GPIO_Port, MAIN_GREEN_Pin);
			}

			// display value on led7
			led7_0 = 4;
			led7_1 = green_counter;

			if (isButtonPressed(0)) {
				// reset initial state
				green_counter = 3;
				yellow_counter = 2;
				red_counter = 5;
				state = INIT;
			}
			if (isButtonPressed(1)) { // increase
				green_counter++;
				if (green_counter >= 98) { // red: 2-96s
					green_counter = 3;
				}
				red_counter++;
			}
			if (isButtonPressed(2)) { // set value
				state = INIT;
			}
			break;
		default:
			break;

	}
}
