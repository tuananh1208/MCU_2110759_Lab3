/*
 * update_7seg.c
 *
 *  Created on: Nov 14, 2023
 *      Author: TuanAnh
 */


#include "update_7seg.h"

static uint8_t LED7_SEG[10] = {
		0b1000000, // 0
	    0b1111001, // 1
	    0b0100100, // 2
	    0b0110000, // 3
	    0b0011001, // 4
	    0b0010010, // 5
	    0b0000010, // 6
	    0b1111000, // 7
	    0b0000000, // 8
	    0b0010000  // 9
		};

int led_buffer0[2];
int led_buffer1[2];

void update_7seg_0(int num) {
	HAL_GPIO_WritePin(LED7_1_SEG0_GPIO_Port, LED7_1_SEG0_Pin, ((LED7_SEG[num] >> 0) & 0x01));
	HAL_GPIO_WritePin(LED7_1_SEG1_GPIO_Port, LED7_1_SEG1_Pin, ((LED7_SEG[num] >> 1) & 0x01));
	HAL_GPIO_WritePin(LED7_1_SEG2_GPIO_Port, LED7_1_SEG2_Pin, ((LED7_SEG[num] >> 2) & 0x01));
	HAL_GPIO_WritePin(LED7_1_SEG3_GPIO_Port, LED7_1_SEG3_Pin, ((LED7_SEG[num] >> 3) & 0x01));
	HAL_GPIO_WritePin(LED7_1_SEG4_GPIO_Port, LED7_1_SEG4_Pin, ((LED7_SEG[num] >> 4) & 0x01));
	HAL_GPIO_WritePin(LED7_1_SEG5_GPIO_Port, LED7_1_SEG5_Pin, ((LED7_SEG[num] >> 5) & 0x01));
	HAL_GPIO_WritePin(LED7_1_SEG6_GPIO_Port, LED7_1_SEG6_Pin, ((LED7_SEG[num] >> 6) & 0x01));
}
void update_7seg_1(int num) {
	HAL_GPIO_WritePin(LED7_2_SEG0_GPIO_Port, LED7_2_SEG0_Pin, ((LED7_SEG[num] >> 0) & 0x01));
	HAL_GPIO_WritePin(LED7_2_SEG1_GPIO_Port, LED7_2_SEG1_Pin, ((LED7_SEG[num] >> 1) & 0x01));
	HAL_GPIO_WritePin(LED7_2_SEG2_GPIO_Port, LED7_2_SEG2_Pin, ((LED7_SEG[num] >> 2) & 0x01));
	HAL_GPIO_WritePin(LED7_2_SEG3_GPIO_Port, LED7_2_SEG3_Pin, ((LED7_SEG[num] >> 3) & 0x01));
	HAL_GPIO_WritePin(LED7_2_SEG4_GPIO_Port, LED7_2_SEG4_Pin, ((LED7_SEG[num] >> 4) & 0x01));
	HAL_GPIO_WritePin(LED7_2_SEG5_GPIO_Port, LED7_2_SEG5_Pin, ((LED7_SEG[num] >> 5) & 0x01));
	HAL_GPIO_WritePin(LED7_2_SEG6_GPIO_Port, LED7_2_SEG6_Pin, ((LED7_SEG[num] >> 6) & 0x01));
}

void setLED7(int n0, int n1) {
	switch (led7_state) {
	case 0:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
		update_7seg_0(n0 / 10);
		update_7seg_1(n1 / 10);
		led7_state = 1;
		setTimer2(500);
		break;
	case 1:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
		update_7seg_0(n0 / 10);
		update_7seg_1(n1 / 10);
		if (timer2_flag == 1) {
			led7_state = 2;
			setTimer2(500);
		}
		break;
	case 2:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
		update_7seg_0(n0 % 10);
		update_7seg_1(n1 % 10);
		if (timer2_flag == 1) {
			led7_state = 1;
			setTimer2(500);
		}
		break;
	default:
		break;
	}
}
