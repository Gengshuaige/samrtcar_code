#ifndef CHARGE_H_
#define CHARGE_H_

enum first_chongdian_type_e {
    FIRST_NONE,
    FIRST_BEGIN,
    FIRST_IN1,
    FIRST_IN2,
    FIRST_IN3,
    FIRST_IN4,
    FIRST_OUT,
    FIRST_FAR,
    FIRST_NEAR,
    CHARGE_BEGIN,
    CHARGE_IN,
    CHARGE_OVER,
};

enum chongdian_low_e {
    CW_NONE,
    CW_BEGIN1,
    CW_BEGIN2,
    CW_IN,
    CW_CHARGE,
    CW_OVER,
};

#define charge(x)   gpio_set_level(C5, x)

extern int64_t chongdian_encoder;
extern enum first_chongdian_type_e first_type;
extern enum chongdian_low_e chongdian_low_type;
void check_chongdian();
void run_charge_low(void);
void run_chongdian1(void);
void run_chongdian2(void);
void run_chongdian3(void);

#endif /* CHARGE_H_ */

