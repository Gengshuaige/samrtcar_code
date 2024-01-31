/*
 * charge.h
 *
 *  Created on: 2023年4月9日
 *      Author: 耿先森
 */

#ifndef CHARGE_H_
#define CHARGE_H_

enum first_chongdian_type_e {
    FIRST_NONE,
    FIRST_BEGIN,    //检测到后车在前
    CHARGE_BEGIN,
    CHARGE_WAIT,
    CHARGE_IN0,
    CHARGE_IN1,
    CHARGE_IN2,
    CHARGE_IN3,
    CHARGE_GO,
    CHARGE_OVER,    //结束
};

enum chongdian_low_e {
    CW_NONE,
    CW_BEGIN,
    CW_FAR,
    CW_NEAR,
    CW_IN,
    CW_CHARGE,
    CW_OVER,
};

extern int64_t chongdian_encoder;
extern int charge_val_houche;
extern enum first_chongdian_type_e first_type;
extern enum chongdian_low_e chongdian_low;
void check_chongdian();
void run_charge_low(void);
void check_charge_low(void);
void run_chongdian1(void);
void run_chongdian2(void);
void check_low(void);
void run_low(void);

#endif /* CHARGE_H_ */
