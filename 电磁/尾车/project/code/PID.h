/*
 * PID.h
 *
 *  Created on: 2023��2��22��
 *      Author: ����ɭ
 */

#ifndef PID_H_
#define PID_H_

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MINMAX(input, low, upper) MIN(MAX(input, low), upper)

extern const float zf_bianmaqi_duqu;
//�ٶ�
extern int my_qiwang_speed;
extern int qiwang_speed_L;
extern int qiwang_speed_R;
extern int shiji_speed_L;
extern int shiji_speed_R;
//���PID����
extern float kp_L;
extern float ki_L;
extern float kd_L;
extern float kp_R;
extern float ki_R;
extern float kd_R;
//���PID����
//����ͷ:
extern float kp_S;
extern float ki_S;
extern float kd_S;
//���:
extern float kp_D;
extern float ki_D;
extern float kd_D;

extern int temp;
extern int pid_shuchu_speed_L;
extern int pid_shuchu_speed_R;

extern float DW_Speed;
extern int64_t DW_Speed_temp;

void dianji_control(void);
void duoji_control(void);
float sport_Point_follow(void);

#endif /* PID_H_ */
