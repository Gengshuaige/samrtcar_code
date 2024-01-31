#ifndef YUAN_HUAN_H_
#define YUAN_HUAN_H_

enum circle_type_e {
    CIRCLE_NONE = 0,                            // ��Բ��ģʽ
    CIRCLE_LEFT_BEGIN, CIRCLE_RIGHT_BEGIN,      // Բ����ʼ��ʶ�𵽵���L�ǵ���һ�೤ֱ����
    CIRCLE_LEFT_IN0, CIRCLE_RIGHT_IN0,            // Բ�����룬���ߵ�һ��ֱ����һ��Բ����λ�á�
    CIRCLE_LEFT_IN, CIRCLE_RIGHT_IN,            // Բ�����룬���ߵ�һ��ֱ����һ��Բ����λ�á�
    CIRCLE_LEFT_RUNNING, CIRCLE_RIGHT_RUNNING,  // Բ���ڲ���
    CIRCLE_LEFT_OUT, CIRCLE_RIGHT_OUT,          // ׼����Բ������ʶ�𵽳�������L�ǵ㡣
    CIRCLE_LEFT_END, CIRCLE_RIGHT_END,          // Բ�����������ٴ��ߵ�����ֱ����λ�á�
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
