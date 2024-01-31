#ifndef ZHANGAI_H_
#define ZHANGAI_H_

enum luzhang_type_e {
    LUZHANG_NONE,
    LUZHANG_BEGIN,
    LUZHANG_IN1,
    LUZHANG_IN2,
    LUZHANG_MID1,
    LUZHANG_MID2,
    LUZHANG_OUT1,
    LUZHANG_OUT2,
};

enum slope_type_e {
    SLOPE_NONE,
    SLOPE_BEGIN,
    SLOPE_IN1,
    SLOPE_IN2,
    SLOPE_IN3,
};

enum zhangai_type_e {
    ZHANGAI_NONE,
    ZHANGAI_1,
    ZHANGAI_OVER,
    ZHANGAI_2,
};

extern enum zhangai_type_e zhangai_type;
extern enum luzhang_type_e luzhang_type;
extern enum slope_type_e slope_type;
extern int slope_num;
extern int luzhang_num;

void run_luzhang_RIGHT(void);
void run_luzhang_LEFT(void);
void run_luzhang(void);
void check_slope(void);
void run_slope(void);
void check_zhangai(void);

#endif /* ZHANGAI_H_ */
