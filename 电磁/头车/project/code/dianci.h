/*
 * dianci.h
 *
 *  Created on: 2023��5��6��
 *      Author: ����ɭ
 */

#ifndef DIANCI_H_
#define DIANCI_H_

#include "zf_common_headfile.h"

/********��й�һ�����ֵ*********/
#define ADC_MAX_L 2370
#define ADC_MAX_LM 2290
#define ADC_MAX_MM 1
#define ADC_MAX_RM 2310
#define ADC_MAX_R 2451

extern float ad_sum_wai;
extern float ad_sum_nei;
extern float ad_sum;
extern float pure_diangan;

void diangan_guiyihua(void);
void chabihe(void);

#endif
