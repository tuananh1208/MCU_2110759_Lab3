/*
 * software_timer.c
 *
 *  Created on: Sep 16, 2023
 *      Author: TuanAnh
 */

#include "software_timer.h"

#define TICK 10

int timer1_counter  = 0;
int timer1_flag = 0;
int timer2_counter  = 0;
int timer2_flag = 0;
int timer3_counter  = 0;
int timer3_flag = 0;
int timer_1s_counter = 0;
int timer_1s_flag = 0;
int timer_2hz_counter = 0;
int timer_2hz_flag = 0;


// duration (ms)
void setTimer1(int duration) {
	timer1_flag = 0;
	timer1_counter = duration/TICK;
}

void setTimer2(int duration) {
	timer2_flag = 0;
	timer2_counter = duration/TICK;
}

void setTimer3(int duration) {
	timer3_flag = 0;
	timer3_counter = duration/TICK;
}

void setTimer1s() {
	timer_1s_flag = 0;
	timer_1s_counter = 1000/TICK;
}

void setTimer2hz() {
	timer_2hz_flag = 0;
	timer_2hz_counter = 500/TICK;
}

void timerRun() {
	if (timer1_counter > 0) {
		timer1_counter--;
		if (timer1_counter <= 0) {
			timer1_flag = 1;
		}
	}

	if (timer2_counter > 0) {
		timer2_counter--;
		if (timer2_counter <= 0) {
			timer2_flag = 1;
		}
	}

	if (timer3_counter > 0) {
		timer3_counter--;
		if (timer3_counter <= 0) {
			timer3_flag = 1;
		}
	}

	if (timer_1s_counter > 0) {
		timer_1s_counter--;
		if (timer_1s_counter <= 0) {
			timer_1s_flag = 1;
		}
	}

	if (timer_2hz_counter > 0) {
		timer_2hz_counter--;
		if (timer_2hz_counter <= 0) {
			timer_2hz_flag = 1;
		}
	}
}
