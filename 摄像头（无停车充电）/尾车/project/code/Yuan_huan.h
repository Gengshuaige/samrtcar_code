#ifndef YUAN_HUAN_H_
#define YUAN_HUAN_H_

enum circle_type_e {
    CIRCLE_NONE = 0,                            // 非圆环模式
    CIRCLE_LEFT_BEGIN, CIRCLE_RIGHT_BEGIN,      // 圆环开始，识别到单侧L角点另一侧长直道。
    CIRCLE_LEFT_IN0, CIRCLE_RIGHT_IN0,            // 圆环进入，即走到一侧直道，一侧圆环的位置。
    CIRCLE_LEFT_IN, CIRCLE_RIGHT_IN,            // 圆环进入，即走到一侧直道，一侧圆环的位置。
    CIRCLE_LEFT_RUNNING, CIRCLE_RIGHT_RUNNING,  // 圆环内部。
    CIRCLE_LEFT_OUT, CIRCLE_RIGHT_OUT,          // 准备出圆环，即识别到出环处的L角点。
    CIRCLE_LEFT_END, CIRCLE_RIGHT_END,          // 圆环结束，即再次走到单侧直道的位置。
    CIRCLE_NUM,                                 //
};

extern const char *circle_type_name[CIRCLE_NUM];

extern enum circle_type_e circle_type;
extern float sample_dist;
extern uint8 circle_num_Y;
extern bool far_Spt0_found, far_Spt1_found;
extern int far_Spt0_rpts0s_id, far_Spt1_rpts1s_id;
extern bool yunahuan_left,yunahuan_right;
extern int delay_yuanhuan;

void check_circle();
void run_circle();

#endif /* YUAN_HUAN_H_ */
