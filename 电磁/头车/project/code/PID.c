#include "zf_common_headfile.h"

const float zf_bianmaqi_duqu = 2;

//速度
int my_qiwang_speed = 70*zf_bianmaqi_duqu;
int qiwang_speed_L = 70*zf_bianmaqi_duqu;
int qiwang_speed_R = 70*zf_bianmaqi_duqu;
//电机PID参数
float kp_L = 50;
float ki_L = 5;
float kd_L = 0;
float kp_R = 50;
float ki_R = 5;
float kd_R = 0;
//舵机PID参数
//摄像头:
float kp_S = 3;
float ki_S = 0;
float kd_S = 3;
//电磁:
float kp_D = 0.87;
float ki_D = 0;
float kd_D = 11;

//-------------------------------------------------------------------------------------------------------------------
//  主题:      电机控制
//  功能:      略
//  样例:      略
//  作者:      耿帅哥
//-------------------------------------------------------------------------------------------------------------------

int temp;
int shiji_speed_L;
int shiji_speed_R;
int pid_shuchu_speed_L;
int pid_shuchu_speed_R;
void dianji_control(void){

    shiji_speed_L = encoder_get_count(TIM1_ENCOEDER);
    shiji_speed_R = encoder_get_count(TIM9_ENCOEDER);
    encoder_clear_count(TIM1_ENCOEDER);
    encoder_clear_count(TIM9_ENCOEDER);

    //路障速度
    if(luzhang_type != LUZHANG_NONE) {
        my_qiwang_speed = 60*zf_bianmaqi_duqu;
    }

    //出库速度
    else if(first_type!=FIRST_NONE && first_type!=CHARGE_OVER) {
        if(first_type==FIRST_BEGIN) {
            my_qiwang_speed = -40;
        }else if(first_type==FIRST_IN1) {
            my_qiwang_speed = 0;
        }else if(first_type==FIRST_IN2) {
            my_qiwang_speed = -40;
        }else if(first_type==FIRST_IN3) {
            my_qiwang_speed = -10;
        }else if(first_type==CHARGE_BEGIN) {
            my_qiwang_speed = 0;
        }else if(first_type==CHARGE_IN) {
            my_qiwang_speed = 0;
        }
    }

    //补电
    else if(chongdian_low_type!=CW_NONE) {
        if(chongdian_low_type==CW_BEGIN2) {
            my_qiwang_speed = 0;
        }else if(chongdian_low_type==CW_IN) {
            my_qiwang_speed = -10;
        }else if(chongdian_low_type==CW_CHARGE) {
            my_qiwang_speed = 0;
        }
    }

    //断路
    else if(duanlu_type!=DUANLU_NONE) {
        my_qiwang_speed = 60*zf_bianmaqi_duqu;
    }

    //坡
    else if(slope_type!=SLOPE_NONE) {

        if(slope_type==SLOPE_IN2)
            my_qiwang_speed = 70*zf_bianmaqi_duqu;
        else{
            my_qiwang_speed = 70*zf_bianmaqi_duqu;
        }
    }

    //障碍一级减速
    else if(zhangai_type==ZHANGAI_1) {
        my_qiwang_speed = 60*zf_bianmaqi_duqu;
    }

    //十字
    else if(cross_type!=CROSS_NONE){
        my_qiwang_speed = 70*zf_bianmaqi_duqu;
    }

    //检查长直道
    else if(is_straight0&&is_straight1) {
        my_qiwang_speed = 70*zf_bianmaqi_duqu;
    }

    //检查环岛
    else if(circle_type!=CIRCLE_NONE) {

        if (circle_type==CIRCLE_LEFT_BEGIN||circle_type==CIRCLE_RIGHT_BEGIN) {
            my_qiwang_speed = 65*zf_bianmaqi_duqu;
        }else {
            my_qiwang_speed = 65*zf_bianmaqi_duqu;
        }
    }

    else {
        my_qiwang_speed = 62.5*zf_bianmaqi_duqu;
    }

    //出赛道停车
    if(Shache_flag==1 && luzhang_type==LUZHANG_NONE ) {
            my_qiwang_speed = 0;
    }

    //停车pid
    if(Shache_flag==1){
        kp_L = 70;
        ki_L = 7;
        kd_L = 0;
        kp_R = 70;
        ki_R = 7;
        kd_R = 0;
    }else {
        kp_L = 50;
        ki_L = 5;
        kd_L = 0;
        kp_R = 50;
        ki_R = 5;
        kd_R = 0;
    }

    //差速控制
    Akeman_chasu(temp, my_qiwang_speed);

    pid_shuchu_speed_L = Speed_L_PID(qiwang_speed_L,shiji_speed_L,kp_L,ki_L,kd_L);
    pid_shuchu_speed_R = Speed_R_PID(qiwang_speed_R,(-shiji_speed_R),kp_R,ki_R,kd_R);

    if(pid_shuchu_speed_L>6000) pid_shuchu_speed_L = 6000;
    if(pid_shuchu_speed_L<-6000) pid_shuchu_speed_L = -6000;
    if(pid_shuchu_speed_R<-6000) pid_shuchu_speed_R = -6000;
    if(pid_shuchu_speed_R>6000) pid_shuchu_speed_R = 6000;

    if(pid_shuchu_speed_L>=0) {
        gpio_set_level(D15, GPIO_HIGH );
        pwm_set_duty(TIM4_PWM_MAP1_CH3_D14, pid_shuchu_speed_L/2);
    }else if(pid_shuchu_speed_L<0) {
        gpio_set_level(D15, GPIO_LOW);
        pwm_set_duty(TIM4_PWM_MAP1_CH3_D14, -pid_shuchu_speed_L/2);
    }

    if(pid_shuchu_speed_R>=0) {
        gpio_set_level(D12, GPIO_HIGH );
        pwm_set_duty(TIM4_PWM_MAP1_CH2_D13, pid_shuchu_speed_R/2);
    }else if(pid_shuchu_speed_L<0) {
        gpio_set_level(D12, GPIO_LOW);
        pwm_set_duty(TIM4_PWM_MAP1_CH2_D13, -pid_shuchu_speed_R/2);
    }

    if(OFF_MOTOR) {
        gpio_set_level(D12, GPIO_HIGH);
        pwm_set_duty(TIM4_PWM_MAP1_CH2_D13, 0);
        gpio_set_level(D15, GPIO_HIGH );
        pwm_set_duty(TIM4_PWM_MAP1_CH3_D14, 0);
    }

}

//-------------------------------------------------------------------------------------------------------------------
//  主题:      舵机控制
//  功能:      略
//  样例:      略
//  作者:      耿帅哥
//-------------------------------------------------------------------------------------------------------------------
void duoji_control(void)
{
    //路障进行特殊控制
    if(luzhang_type != LUZHANG_NONE)
    {
        if(RIGHT_LZ) {
            if(luzhang_type == LUZHANG_IN1)pure_angle = -35;
            if(luzhang_type == LUZHANG_IN2)pure_angle = 20;
            if(luzhang_type == LUZHANG_MID1)pure_angle = 0;
            if(luzhang_type == LUZHANG_MID2)pure_angle = 45;
            if(luzhang_type == LUZHANG_OUT2)pure_angle = -20;
        }else {
            if(luzhang_type == LUZHANG_IN1)pure_angle = 35;
            if(luzhang_type == LUZHANG_IN2)pure_angle = -20;
            if(luzhang_type == LUZHANG_MID1)pure_angle = 0;
            if(luzhang_type == LUZHANG_MID2)pure_angle = -45;
            if(luzhang_type == LUZHANG_OUT2)pure_angle = 20;
        }
    }

    //出库姿态矫正
        if(first_type!=FIRST_NONE && first_type!=CHARGE_OVER) {
            if(first_type==FIRST_BEGIN) {
                if(RIGHT_CHUKU)
                    pure_angle = 50;
                else
                    pure_angle = -50;
            }else {
                pure_angle = 0;
            }
        }

    if(circle_type!=CIRCLE_NONE) {
        if(circle_type == CIRCLE_LEFT_OUT) pure_angle = 16;
        if(circle_type == CIRCLE_RIGHT_OUT) pure_angle = -16;
        if(circle_type == CIRCLE_LEFT_IN) pure_angle = 26;
        if(circle_type == CIRCLE_RIGHT_IN) pure_angle = -26;
    }
/*************************************************************/
    //别tm开这个!!!
    //调试用的!!!

//    shexiangtou_or_dianci = false;

/*************************************************************/
    //大于0左转
    if(shexiangtou_or_dianci==true && shexiangtou_or_dianci_away==true)
        temp = -My_PID_WEIZHI(pure_angle, Mid_W, kp_S, ki_S, kd_S);
    else if(shexiangtou_or_dianci==true && shexiangtou_or_dianci_away==false)
        temp = -My_PID_WEIZHI(pure_diangan, Mid_D, kp_D, ki_D, kd_D);
    else if(shexiangtou_or_dianci==false && shexiangtou_or_dianci_away==false)
        temp = -My_PID_WEIZHI(pure_diangan, Mid_D, kp_D, ki_D, kd_D);
    else if(shexiangtou_or_dianci==false && shexiangtou_or_dianci_away==true)
        temp = -My_PID_WEIZHI(pure_angle, Mid_W, kp_S, ki_S, kd_S);

    shexiangtou_or_dianci_away = shexiangtou_or_dianci;

    if(temp>65) temp = 65;
    if(temp<-70) temp = -70;

    if (cross_type!=CROSS_NONE) {
        if (cross_type==CROSS_BEGIN) {
            if(temp>20) temp = 20;
            if(temp<-20) temp = -20;
        }else if (cross_type==CROSS_BEGIN_LEFT)  {
            if(temp>5) temp = 5;
            if(temp<-20) temp = -20;
        }else if(cross_type==CROSS_BEGIN_RIGHT) {
            if(temp>20) temp = 20;
            if(temp<-5) temp = -5;
        }
     }

    pwm_set_duty(TIM2_PWM_MAP3_CH1_A15,(658 + temp));
}

//-------------------------------------------------------------------------------------------------------------------
//  主题:      动态前瞻
//  功能:      根据速度计算预瞄点
//  样例:      略
//  作者:      耿帅哥
//-------------------------------------------------------------------------------------------------------------------

int64_t DW_Speed_temp;
int64_t DW_Speed_last[25];
int64_t DW_Speed_sum;
float DW_Speed;
float sport_Point_follow(void) {
    DW_Speed_temp = get_total_encoder();
//
//    //20次滑动滤波
//    for(int i=19;i>0;i--) {
//        DW_Speed_last[i] = DW_Speed_last[i-1];
//    }
//    DW_Speed_last[0] = DW_Speed_temp;
//    for(int i=19;i>=0;i--) {
//        DW_Speed_sum += DW_Speed_last[i];
//    }
//    DW_Speed = (float)DW_Speed_sum/20;

    DW_Speed = DW_Speed_temp;

    if(DW_Speed>170) DW_Speed = 170;
    if(DW_Speed<100) DW_Speed = 100;

    if(DW_Speed==100) {
        aim_distance = 0.4;
    }else{
         aim_distance = (DW_Speed==170)?1:(0.4+0.3*DW_Speed/170);
    }
}



