/*
 * My_PID.h
 *
 *  Created on: 2022年11月14日
 *      Author: 耿先森
 */

#ifndef MY_PID_H_
#define MY_PID_H_
#include "zf_common_headfile.h"

#define SMOTOR_RATE     (2.4)

extern float JIFEN_WEIZHI_R;
extern float error_R;
extern float BILI_DR;
extern float WEIFEN_DR;
extern float error_away2;
extern float JIFEN_WEIZHI_L;
extern float error_L;
extern float BILI_DL;
extern float WEIFEN_DL;
extern float error_away1;

int16 My_PID_ZENGLIANG1(int16 Shiji,int16 Qiwang,int16 kP,int16 kI,int16 kD);
int16 My_PID_ZENGLIANG2(int16 Shiji,int16 Qiwang,int16 kP,int16 kI,int16 kD);
int My_PID_WEIZHI(float Shiji,int Qiwang,float kP,float kI,float kD);
int64_t get_total_encoder(void);
int Speed_L_PID(int speed_L_now,int speed_L_want,float Speed_L_Kp,float Speed_L_Ki,float Speed_L_Kd);
int Speed_R_PID(int speed_R_now,int speed_R_want,float Speed_R_Kp,float Speed_R_Ki,float Speed_R_Kd);
int My_PID_WEIZHI_R(int Shiji,int Qiwang,float kP,float kI,float kD);
int My_PID_WEIZHI_L(int Shiji,int Qiwang,float kP,float kI,float kD);
float PID_R(float setpoint,float now_speed,float Kp,float Ki,float Kd);
float PID_L(float setpoint,float now_speed,float Kp,float Ki,float Kd);

#endif /* MY_PID_H_ */
