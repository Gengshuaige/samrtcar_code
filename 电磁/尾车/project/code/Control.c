#include "zf_common_headfile.h"

//差速阈值
#define CHASUYUZHI_L 0
#define CHASUYUZHI_R 0

float diy_L = 1;
float diy_R = 0.5;

uint8 Akeman_pit_ms;

//-------------------------------------------------------------------------------------------------------------------
//  主题:      阿克曼转角差速控制
//  功能:      基于阿克曼转角进行差速控制
//  样例:      略
//  作者:      耿帅哥
//-------------------------------------------------------------------------------------------------------------------
float carWidth = 15; // 汽车宽度(越大减速越猛)
float innerRadius; // 内半径
float outerRadius; // 外半径
float wheelBaseLength = 15; // 轮轴长度
float innerWheelSpeed ;
float outerWheelSpeed ;
float angle;
float target_l,target_r;
//float K0=0,K1=0,K2=0;
float K0=0.25,K1=0.17,K2=0.09;

void Akeman_chasu(float outservo, float target) {

    float the_end_target = 0;
    static float Last_S3010_Angle=0,S3010_Angle=0;

    //根据舵机角度计算内外半径
    angle = PI / 180 * (abs(outservo*diy_L));
    if(angle!=0) {
        innerRadius = wheelBaseLength / tan(angle);

        if(shexiangtou_or_dianci==true)
            carWidth = 25;
        else
            carWidth = 15;

        outerRadius = innerRadius + carWidth;
    }

    S3010_Angle = outservo*K0;

        if(S3010_Angle * Last_S3010_Angle>=0)
        {
            the_end_target = target - fabs(S3010_Angle)*K1 - (fabs(S3010_Angle) - fabs(Last_S3010_Angle))*K2;
        }
        else
        {
            the_end_target = target - fabs(S3010_Angle)*K1 - (fabs(S3010_Angle) + fabs(Last_S3010_Angle))*K2;
        }
    //计算内外轮速
    if(angle!=0) {
        innerWheelSpeed = the_end_target * innerRadius / outerRadius;
        outerWheelSpeed = the_end_target;
    }else {
        innerWheelSpeed = the_end_target;
        outerWheelSpeed = the_end_target;
    }

    //控制电机转速
    if (outservo > 0) {
    //向左转

        qiwang_speed_L = innerWheelSpeed;
        qiwang_speed_R = outerWheelSpeed;

    } else if (outservo < 0) {
    //向右转

        qiwang_speed_R = innerWheelSpeed;
        qiwang_speed_L = outerWheelSpeed;

    }else{
        qiwang_speed_L = outerWheelSpeed;
        qiwang_speed_R = outerWheelSpeed;
    }
}

//-------------------------------------------------------------------------------------------------------------------
//  主题:      自定义差速控制
//  功能:      根据舵机转角
//  样例:      略
//  作者:      耿帅哥
//-------------------------------------------------------------------------------------------------------------------
void control_dianji(void) {
    //偏差限幅
//    Duoji_Dianji = clip(Duoji_Dianji,-13,13);
    //电机差速控制
    //右转有问题
//    tft180_show_int(0, 50, CHASUYUZHI_L, 2);
        if(temp < CHASUYUZHI_L){//右转

            qiwang_speed_L = my_qiwang_speed;
            qiwang_speed_R = my_qiwang_speed + temp * 0.5;
            if(ruku_type == RUKU_BEGIN_LEFT) {
                qiwang_speed_L = my_qiwang_speed;
                qiwang_speed_R = my_qiwang_speed;
            } else if(ruku_type == RUKU_BEGIN_RIGHT) {
                qiwang_speed_L = my_qiwang_speed;
                qiwang_speed_R = my_qiwang_speed;
            }
        }else if(temp >= CHASUYUZHI_R){//左转
            qiwang_speed_L = my_qiwang_speed - temp * 0.6;
            qiwang_speed_R = my_qiwang_speed;
        }else {
            if(1) {
                qiwang_speed_L = my_qiwang_speed;
                qiwang_speed_R = my_qiwang_speed;
                }else if(cross_type == CROSS_BEGIN) {
                    //十字可加速
                    qiwang_speed_L = my_qiwang_speed +10;
                    qiwang_speed_R = my_qiwang_speed -10;
                }else if(Shache_flag == 1) {
                    //入库/刹车
                    qiwang_speed_L = 0;
                    qiwang_speed_R = 0;
                }else if(circle_type == CIRCLE_LEFT_BEGIN) {
                    //入左环岛右轮加速
                    qiwang_speed_L = my_qiwang_speed + 0;
                    qiwang_speed_R = my_qiwang_speed - 25;
                }else if(circle_type == CIRCLE_RIGHT_BEGIN) {
                    //入右环岛左轮加速
            //        SHURU1 = shudu_shiyan + 10;
                    qiwang_speed_L =  my_qiwang_speed ;
                    qiwang_speed_R = my_qiwang_speed ;
                }else if(zhidao_type == ZHIDAO_BEGIN) {
                    //直道加速
                    qiwang_speed_L = my_qiwang_speed+40;
                    qiwang_speed_R = my_qiwang_speed-40;
                }else {
                    qiwang_speed_L = my_qiwang_speed;
                    qiwang_speed_R = my_qiwang_speed;
                }
        }

}



//-------------------------------------------------------------------------------------------------------------------
//  主题:      基于CH05的遥控小车
//  功能:      手机端蓝牙控制小车运动
//  样例:      略
//  作者:      耿帅哥
//-------------------------------------------------------------------------------------------------------------------

int16 temp_buletooth;

void buletooth_contrul(void) {
    if(Lanya_xnhao==73) {
        temp_buletooth = -10;
        qiwang_speed_L = 0;
        qiwang_speed_R = 0;
    }else if(Lanya_xnhao==72){//左转
        temp_buletooth = 65;
    }else if(Lanya_xnhao==74){
        temp_buletooth = -65;
    }else if(Lanya_xnhao==71){
        qiwang_speed_L = 10;
        qiwang_speed_R = -10;
    }else if(Lanya_xnhao==75){
        qiwang_speed_L = -10;
        qiwang_speed_R = 10;
    }else if(Lanya_xnhao==65){
        qiwang_speed_L = 90;
        qiwang_speed_R = -90;
    }
}











