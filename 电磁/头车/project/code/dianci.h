/*
 * dianci.h
 *
 *  Created on: 2023年5月6日
 *      Author: 耿先森
 */

#ifndef DIANCI_H_
#define DIANCI_H_

#include "zf_common_headfile.h"

/********电感归一化最大值*********/
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
