/*
 * nitoushi.h
 *
 *  Created on: 2023��1��15��
 *      Author: ��˧��
 */

#ifndef NITOUSHI_H_
#define NITOUSHI_H_

#include "zf_common_headfile.h"

extern unsigned char const nitou3_col[188*70];
extern unsigned char const nitou4_row[188*70];
extern uint8 IMG[MT9V03X_H][MT9V03X_W];

void image_perspective_corrective_Forward2(uint8 pts_in[][2], uint8 num , uint8 pts_out[][2]);//������͸��
void image_perspective_corrective_Forward(void);//������͸��(ȫ��)

#endif /* NITOUSHI_H_ */
