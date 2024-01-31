/*
 * Control.h
 *
 *  Created on: 2023年3月24日
 *      Author: 耿先森
 */

extern float target_l,target_r;
extern int16 temp_buletooth;
extern float innerWheelSpeed ;
extern float outerWheelSpeed ;
extern float angle;
extern float carWidth;
extern float innerRadius;
extern float outerRadius;
extern float wheelBaseLength;
extern uint8 Akeman_pit_ms;

enum control_duoji_type_e {
    ZHONGXIAN,
    MYSELF,
};
extern enum control_duoji_type_e control_duoji_type;

extern float diy_L;
extern float diy_R;

void Akeman_chasu(float outservo,float target);
void buletooth_contrul(void);
void control_dianji(void);


