#ifndef __DEBUG_H__
#define __DEBUG_H__

#include "zf_common_headfile.h"

#define true  1
#define false 0
//将变量名转化为字符串
#define  VNAME(name) (#name)
//取一个数据的各个位
#define BYTE0(Temp)       (*(char *)(&Temp))     
#define BYTE1(Temp)       (*((char *)(&Temp) + 1))
#define BYTE2(Temp)       (*((char *)(&Temp) + 2))
#define BYTE3(Temp)       (*((char *)(&Temp) + 3))
extern float Variable[16];

extern float  ADC_DATE[5][10] , ADC_SUM[5] , ADC_DATE_1[5][10] , ADC_DATE_2[5] , GUI_ADC_DATE[5] , AD_DATE[5];

void Testdata_generate();
void Send_Begin();
void Send_Variable();
void init_debug();
void uart_accent();
extern uint8 Lanya_xnhao;

#endif 
