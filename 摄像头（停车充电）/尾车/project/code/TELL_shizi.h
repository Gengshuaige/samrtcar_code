#ifndef TELL_SHIZI_H_
#define TELL_SHIZI_H_

#include "zf_common_headfile.h"
#include "main.h"

enum cross_type_e {
    CROSS_NONE,     // 非十字模式
    CROSS_BEGIN,        //找到左右两个L角点
    CROSS_BEGIN_LEFT,   //找到左角点
    CROSS_BEGIN_RIGHT,  //找到右角点
    CROSS_IN,           //两个L角点很近，即进入十字内部(此时切换远线控制)
    CROSS_IN_LEFT,
    CROSS_IN_RIGHT,
    CROSS_NUM,
};

enum chuku_type_e {
    CHUKU_NONE,
    CHUKU_BEGIN,
    CHUKU_LEFT_BEGIN,
    CHUKU_RIGHT_BEGIN,
    CHUKU_OVER,
};

enum ruku_type_e {
    RUKU_NONE,
    RUKU_BEGIN_LEFT,
    RUKU_IN_LEFT,
    RUKU_BEGIN_RIGHT,
    RUKU_IN_RIGHT,
    RUKU_OVER,
};

enum zhidao_type_e {
    ZHIDAO_NONE,
    ZHIDAO_BEGIN,
};

enum duanlu_type_e {
    DUANLU_NONE,
    DUANLU_BEGIN,
    DUANLU_IN1,
    DUANLU_IN2,
};



extern bool find_shizi;
extern int16 temp_shizi;
extern bool shiziORcircle_left,shiziORcircle_right;

extern enum cross_type_e cross_type;
extern enum chuku_type_e chuku_type;
extern enum ruku_type_e ruku_type;
extern enum zhidao_type_e zhidao_type;
extern enum duanlu_type_e duanlu_type;
extern uint8 erzhihuayuzhi_duanlu;
extern int duanlu_num;

extern int far_Lpt0_rpts0s_id, far_Lpt1_rpts1s_id;

extern bool far_Lpt0_found, far_Lpt1_found;
extern int far_Lpt0_rpts0s_id, far_Lpt1_rpts1s_id;

// 以下定义为十字寻远线设定
extern uint8 far_ipts0[MY_H-20][2];
extern uint8 far_ipts1[MY_H-20][2];
extern uint8 far_ipts0_num, far_ipts1_num;

extern uint8 far_ipts0y[MY_H][2];
extern uint8 far_ipts1y[MY_H][2];
extern uint8 far_ipts0_num_y, far_ipts1_num_y;

extern uint8 far_rpts0[MY_H][2];
extern uint8 far_rpts1[MY_H][2];
extern int far_rpts0_num, far_rpts1_num;

extern uint8 far_rpts0b[MY_H][2];
extern uint8 far_rpts1b[MY_H][2];
extern int far_rpts0b_num, far_rpts1b_num;

extern uint8 far_rpts0s[MY_H][2];
extern uint8 far_rpts1s[MY_H][2];
extern int far_rpts0s_num, far_rpts1s_num;

extern float far_rpts0a[MY_H];
extern float far_rpts1a[MY_H];
extern int far_rpts0a_num, far_rpts1a_num;

extern float far_rpts0an[MY_H];
extern float far_rpts1an[MY_H];
extern int far_rpts0an_num, far_rpts1an_num;

extern int not_have_line;

extern int far_x1, far_x2, far_y1, far_y2;
extern int no_left_line, no_right_line;
extern uint8 shizi_num;
extern uint8 erzhihuayuzhi_dhuanlu;

extern uint8 Shache_flag;

void check_cross(void);
void run_cross();
void cross_farline();
void check_chuku(void);
void run_chuku(void);
bool check_banmaxian0(uint8 x,uint8 y,uint8 d);
bool check_banmaxian1(uint8 x,uint8 y,uint8 d);
void check_ruku(void);
void run_ruku(void);
void check_duanlu1(void);
void check_duanlu2(void);
void run_duanlu(void);
void check_luzhang(void);
bool check_bianjie_H(uint8 pts_in0[][2],uint8 pts_in1[][2],uint8 num,float x);

#endif /* TELL_SHIZI_H_ */
