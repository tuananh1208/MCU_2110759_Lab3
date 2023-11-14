/*
 * software_timer.h
 *
 *  Created on: Sep 16, 2023
 *      Author: TuanAnh
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer1_flag;
extern int timer2_flag;
extern int timer3_flag;
extern int timer_1s_flag;
extern int timer_2hz_flag;

void setTimer1(int duration);
void setTimer2(int duration);
void setTimer3(int duration);
void setTimer1s();
void setTimer2hz();

void timerRun();


#endif /* INC_SOFTWARE_TIMER_H_ */
