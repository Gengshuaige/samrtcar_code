#ifndef MAIN_H_
#define MAIN_H_
#include "zf_common_headfile.h"

#define RETEEE1      TIM4_PWM_MAP1_CH1_D12
#define RETEEE2      TIM4_PWM_MAP1_CH3_D14
#define RETEEE3      TIM4_PWM_MAP1_CH4_D15
#define RETEEE4      TIM4_PWM_MAP1_CH2_D13

//����ͼƬ�ߴ�
#define MY_H  MT9V03X_H
#define MY_W  MT9V03X_W
#define MY_e  2.71828
#define ROAD_WIDTH      (0.3)

enum TELL_ {
    TELL_SHIZI,
    TELL_DUANLU,
    TELL_YUANHUAN,
    TELL_PODAO,
    TELL_LUZHANG,
    TELL_S,
    TELL_ZHIDAO,
    TELL_CHUKU,
    TELL_RUKU
};

extern enum TELL_ Y_tell;

enum track_type_e {
    TRACK_LEFT,
    TRACK_RIGHT,
};

enum search_type_e {
    SEARCH_MIGONG,
    SEARCH_QUNANTU
};

enum chuku_fangxiang_e {
    LEFT,
    RIGHT,
};

extern enum chuku_fangxiang_e chuku_fangxiang;
//ͨ��
extern uint8 send_ceshi;
extern uint8 read_ceshi;
//Ԥ�������
extern float aim_distance;
//ͼ������־
extern uint8 Tuxiang_flag;
//��·ģʽѡ��
extern bool RIGHT_LZ;
//����ƫ��+���ƫ��
extern float pure_angle_far;
extern float pure_angle_near;
extern float pure_angle_mid;
extern float pure_angle;
//��ǰѲ��ģʽ
extern enum track_type_e track_type;
//��ֵ����ֵ
extern uint8 erzhihuayuzhi;
//�������
extern uint8 begin_x;
extern uint8 begin_y;
//��������+����
extern uint8 ipts0[MY_H][2];
extern uint8 ipts1[MY_H][2];
extern uint8 ipts0_num, ipts1_num;
//��͸�ӱ߽�+����
extern uint8 ipts0y[MY_H][2];
extern uint8 ipts1y[MY_H][2];
extern uint8 ipts0_num_y, ipts1_num_y;
//�˲�������+����
extern uint8 rpts0b[MY_H][2];
extern uint8 rpts1b[MY_H][2];
extern uint8 rpts0b_num, rpts1b_num;
//�Ⱦ��������+����
extern uint8 rpts0s[MY_H][2];//��߽����������!!!!!
extern uint8 rpts1s[MY_H][2];
extern int rpts0s_num, rpts1s_num;
//����ÿ����ĽǶ�+����
extern float rpts0a[MY_H];
extern float rpts1a[MY_H];
extern uint8 rpts0a_num, rpts1a_num;
//ͨ���Ǽ���ֵ���Ƽ���õ�������+����
extern float rpts0an[MY_H];
extern float rpts1an[MY_H];
extern uint8 rpts0an_num, rpts1an_num;
//ͨ��ƽ����õ���������+���鳤��
extern uint8 rptsc0[MY_H][2];
extern uint8 rptsc1[MY_H][2];
extern uint8 rptsc0_num, rptsc1_num;
//ͨ����һ���õ���Ψһ��������+����
extern uint8 rptsn[MY_H][2];
extern uint8 rptsn_num;
//��������
extern float thres ;
extern int block_SIZE;
extern float clip_value;
extern float line_blur_kernel;
extern float pixel_per_meter;
extern float sample_dist;
extern float angle_dist;
extern uint8 (*rpts)[2];
extern int rpts_num;
//��־λ
extern bool Lpt0_found,Lpt1_found;
extern bool Spt0_found,Spt1_found;
extern bool is_straight0,is_straight1;
extern uint8 Lpt0_rpts0s_id,Lpt1_rpts1s_id;
extern uint8 Lpt0_rpts0s_16,Lpt1_rpts1s_16;
extern uint8 far_Lpt0_rpts0s_16,far_Lpt1_rpts1s_16;
extern uint8 Spt0_rpts0s_id,Spt1_rpts1s_id;
extern int delay_stop_my_2s;
extern bool turn_left;
extern bool turn_right;
extern bool shexiangtou_or_dianci;
extern bool shexiangtou_or_dianci_away;
extern float gengshuaige;
extern bool OFF_motor;
//ԭͼ�ǵ�
extern int x6,x7,y6,y7;
extern int far_x6,far_x7,far_y6,far_y7;

#endif /* MAIN_H_ */
