/*
 * DajinFa.h
 *
 *  Created on: 2022Äê11ÔÂ10ÈÕ
 *      Author: ¹¢Ë§¸ç
 */

#ifndef DAJINFA_H_
#define DAJINFA_H_
#include "zf_common_headfile.h"

uint8 dajinfa(uint8 *image, uint16 col, uint16 row);
uint8 otsuThreshold(uint8 *image, uint16 col, uint16 row);
int my_adapt_threshold(uint8 *image, uint16 col, uint16 row);

#endif /* DAJINFA_H_ */
