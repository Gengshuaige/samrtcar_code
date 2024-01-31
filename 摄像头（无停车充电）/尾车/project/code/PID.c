#include "zf_common_headfile.h"

const float zf_bianmaqi_duqu = 2;

//速度
int my_qiwang_speed = 100*zf_bianmaqi_duqu;
int qiwang_speed_L = 100*zf_bianmaqi_duqu;
int qiwang_speed_R = 100*zf_bianmaqi_duqu;
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
float kp_D = 0.57;
float ki_D = 0;
float kd_D = 9.5;

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

    //充电发车
    else if(first_type!=FIRST_NONE && first_type!=CHARGE_OVER) {

            if(first_type==CHARGE_IN2)
                my_qiwang_speed = charge_val_houche;
            else if(first_type==CHARGE_WAIT)
                my_qiwang_speed = 60;
            else
                my_qiwang_speed = 0;
    }

    //防撞保护
    else if(0) {
        my_qiwang_speed = 53*zf_bianmaqi_duqu;
    }

    //断路
    else if(duanlu_type!=DUANLU_NONE) {
        my_qiwang_speed = 60*zf_bianmaqi_duqu;
    }

    //坡
    else if(slope_type != SLOPE_NONE) {
        my_qiwang_speed = 60*zf_bianmaqi_duqu;
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
        my_qiwang_speed = 80*zf_bianmaqi_duqu;
    }

    //检查环岛
    else if(circle_type!=CIRCLE_NONE) {

        if (circle_type==CIRCLE_LEFT_BEGIN||circle_type==CIRCLE_RIGHT_BEGIN) {
            my_qiwang_speed = 70*zf_bianmaqi_duqu;
        }else {
            my_qiwang_speed = 70*zf_bianmaqi_duqu;
        }
    }

    //入库
    else if(ruku_type!=RUKU_NONE) {
        my_qiwang_speed = 60*zf_bianmaqi_duqu;
    }

    //低压
//    else if(chongdian_low==CW_BEGIN){
//        ;
//    }

    else {
        my_qiwang_speed = 70*zf_bianmaqi_duqu;
    }

    //出赛道停车
    if(Shache_flag==1 && duanlu_type==DUANLU_NONE) {
            my_qiwang_speed = 0;
        }

    //差速控制
        Akeman_chasu(temp, my_qiwang_speed);

    pid_shuchu_speed_L = Speed_L_PID(qiwang_speed_L,shiji_speed_L,kp_L,ki_L,kd_L);
    pid_shuchu_speed_R = Speed_R_PID(qiwang_speed_R,(-shiji_speed_R),kp_R,ki_R,kd_R);

    if(pid_shuchu_speed_L>=0) {
        gpio_set_level(D15, GPIO_HIGH);
        pwm_set_duty(TIM4_PWM_MAP1_CH3_D14, pid_shuchu_speed_L);
    }else if(pid_shuchu_speed_L<0) {
        gpio_set_level(D15, GPIO_LOW);
        pwm_set_duty(TIM4_PWM_MAP1_CH3_D14, -pid_shuchu_speed_L);
    }

    if(pid_shuchu_speed_R>=0) {
        gpio_set_level(D12, GPIO_HIGH );
        pwm_set_duty(TIM4_PWM_MAP1_CH2_D13, pid_shuchu_speed_R);
    }else if(pid_shuchu_speed_L<0) {
        gpio_set_level(D12, GPIO_LOW);
        pwm_set_duty(TIM4_PWM_MAP1_CH2_D13, -pid_shuchu_speed_R);
    }

    if(OFF_motor) {
        gpio_set_level(D12, GPIO_HIGH );
        pwm_set_duty(TIM4_PWM_MAP1_CH2_D13, 0);
        gpio_set_level(D15, GPIO_HIGH);
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
            if(luzhang_type == LUZHANG_IN1)pure_angle = -40;
            if(luzhang_type == LUZHANG_IN2)pure_angle = 20;
            if(luzhang_type == LUZHANG_MID1)pure_angle = 0;
            if(luzhang_type == LUZHANG_MID2)pure_angle = 40;
            if(luzhang_type == LUZHANG_OUT2)pure_angle = -10;
        }else {
            if(luzhang_type == LUZHANG_IN1)pure_angle = 40;
            if(luzhang_type == LUZHANG_IN2)pure_angle = -20;
            if(luzhang_type == LUZHANG_MID1)pure_angle = 0;
            if(luzhang_type == LUZHANG_MID2)pure_angle = -40;
            if(luzhang_type == LUZHANG_OUT2)pure_angle = 10;
        }
    }

    if(ruku_type != RUKU_NONE) {
        if(ruku_type == RUKU_IN_RIGHT) {
            pure_angle = -60;
        } else if(ruku_type == RUKU_IN_LEFT) {
            pure_angle = 60;
        }
    }

    if(first_type!=CHARGE_OVER && first_type!=FIRST_NONE)
        pure_angle = 0;

    if(ruku_type==RUKU_OVER)
        pure_angle = 0;

    if(circle_type != CIRCLE_NONE) {
        if(circle_type == CIRCLE_LEFT_OUT) pure_angle = 10;
        if(circle_type == CIRCLE_RIGHT_OUT) pure_angle = -12;
        if(circle_type == CIRCLE_LEFT_IN) pure_angle = 30;
        if(circle_type == CIRCLE_RIGHT_IN) pure_angle = -30;
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
    if(temp<-65) temp = -65;

//    if (cross_type!=CROSS_NONE) {
//        if (cross_type==CROSS_BEGIN) {
//            if(temp>10) temp = 10;
//            if(temp<-10) temp = -10;
//        }else if (cross_type==CROSS_BEGIN_LEFT)  {
//            if(temp>5) temp = 5;
//            if(temp<-10) temp = -10;
//        }else if(cross_type==CROSS_BEGIN_RIGHT) {
//            if(temp>10) temp = 10;
//            if(temp<-5) temp = -5;
//        }
//     }

    pwm_set_duty(TIM2_PWM_MAP3_CH1_A15,(662 + temp));
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



