/*
 * global.h
 *
 *  Created on: Nov 14, 2023
 *      Author: TuanAnh
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "button.h"
#include "main.h"
#include "fsm_automatic.h"
#include "fsm_manual.h"

typedef enum { // MAIN_SIDE
	INIT,
	GREEN_RED,
	YELLOW_RED,
	RED_GREEN,
	RED_YELLOW,
	MAN_GREEN,
	MAN_RED,
	MAN_YELLOW,
} FSM_State;

extern FSM_State state;
extern int led7_state;

extern int red_counter;
extern int green_counter;
extern int yellow_counter;

extern int led7_0;
extern int led7_1;


#endif /* INC_GLOBAL_H_ */
