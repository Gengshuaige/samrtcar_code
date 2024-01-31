/*
 * nitoushi.h
 *
 *  Created on: 2023年1月15日
 *      Author: 耿帅哥
 */

#ifndef NITOUSHI_H_
#define NITOUSHI_H_

#include "zf_common_headfile.h"

extern unsigned char const nitou3_col[188*70];
extern unsigned char const nitou4_row[188*70];
extern uint8 IMG[MT9V03X_H][MT9V03X_W];

void image_perspective_corrective_Forward2(uint8 pts_in[][2], uint8 num , uint8 pts_out[][2]);//矩阵逆透视
void image_perspective_corrective_Forward(void);//矩阵逆透视(全局)

#endif /* NITOUSHI_H_ */
