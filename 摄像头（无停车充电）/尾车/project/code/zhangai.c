#include "zf_common_headfile.h"




//-------------------------------------------------------------------------------------------------------------------
//  主题:      坡
//  功能:      略
//  样例:      略
//  作者:      耿帅哥
//-------------------------------------------------------------------------------------------------------------------
int16 luzhang_pitch;
enum slope_type_e slope_type = SLOPE_NONE;

void check_slope(void) {

    bool Sfound = Spt0_found && Spt1_found;
    if(dl1a_distance_mm<1000 && Sfound){
        slope_type = SLOPE_BEGIN;
    }
}

//坡道俯仰角
int16 slope_Pitch;
int64_t encoder_slope;
uint8 have_Pitch;
uint8 not_Pitch;

void run_slope(void) {
    if(slope_type==SLOPE_BEGIN) {
        shexiangtou_or_dianci = false;

            slope_type = SLOPE_IN1;

    }else if(slope_type==SLOPE_IN1) {
        encoder_slope += get_total_encoder();

        if(encoder_slope>3000) {
            slope_type = SLOPE_IN2;
            encoder_slope = 0;
        }
    }else if(slope_type==SLOPE_IN2) {

//        if(abs(Pitch)<2) {
        slope_type = SLOPE_NONE;
        zhangai_type = ZHANGAI_NONE;
        luzhang_pitch = 0;
        shexiangtou_or_dianci = true;
        encoder_slope = 0;
        bibibi(0);
//        }
    }
}

//-------------------------------------------------------------------------------------------------------------------
//  主题:      路障
//  功能:      略
//  样例:      略
//  作者:      耿帅哥
//-------------------------------------------------------------------------------------------------------------------

enum luzhang_type_e luzhang_type = LUZHANG_NONE;


void check_luzhang(void) {
    bool Xfound = Lpt0_found && Lpt1_found;
    if(Xfound && !check_far_whitepoint(x6,y6) && !check_far_whitepoint(x7,y7) && luzhang_type==LUZHANG_NONE
                && Lpt0_found<5 && Lpt1_found<5
                &&dl1a_distance_mm<1000) {
        luzhang_type = LUZHANG_BEGIN;
        bibibi(1);
    }
}

int16 Yaw_luzhang;
int64_t encoder_luzhang;
void run_luzhang_RIGHT(void)
{
    if(luzhang_type == LUZHANG_BEGIN){
        Yaw_luzhang = Yaw;
        if(dl1a_distance_mm<1000)
            luzhang_type = LUZHANG_IN1;
    }else if(luzhang_type==LUZHANG_IN1){
        //开始打角
        if((Yaw-Yaw_luzhang)<=-45){
            luzhang_type = LUZHANG_IN2;
        }
    }else if(luzhang_type==LUZHANG_IN2) {
        //往回打脚
        if(Yaw-Yaw_luzhang>=0) {
            luzhang_type = LUZHANG_MID1;
            encoder_luzhang = 0;

        }
     }else if(luzhang_type==LUZHANG_MID1){
        //回正;编码器积分
         encoder_luzhang += get_total_encoder();
         if(encoder_luzhang>400) {
             luzhang_type = LUZHANG_MID2;
             encoder_luzhang = 0;
         }

    }else if(luzhang_type==LUZHANG_MID2) {
        //打脚
        if(Yaw-Yaw_luzhang>=30){
            luzhang_type = LUZHANG_OUT2;
        }
    }else if(luzhang_type==LUZHANG_OUT2) {
        //打脚
//        if(Yaw-Yaw_luzhang<=10) {
            luzhang_type = LUZHANG_NONE;
            zhangai_type = ZHANGAI_NONE;
            bibibi(0);
            Yaw_luzhang = 0;
//        }
    }
}


void run_luzhang_LEFT(void)
{
    if(luzhang_type == LUZHANG_BEGIN){
        Yaw_luzhang = Yaw;
        if(dl1a_distance_mm<1000)
            luzhang_type = LUZHANG_IN1;
    }else if(luzhang_type==LUZHANG_IN1){
        //开始打角
        if((Yaw-Yaw_luzhang)>=45){
            luzhang_type = LUZHANG_IN2;
        }
    }else if(luzhang_type==LUZHANG_IN2) {
        //往回打脚
        if(Yaw-Yaw_luzhang<=0) {
            luzhang_type = LUZHANG_MID1;
            encoder_luzhang = 0;

        }
     }else if(luzhang_type==LUZHANG_MID1){
        //回正;编码器积分
         encoder_luzhang += get_total_encoder();
         if(encoder_luzhang>400) {
             luzhang_type = LUZHANG_MID2;
             encoder_luzhang = 0;
         }

    }else if(luzhang_type==LUZHANG_MID2) {
        //打脚
        if(Yaw-Yaw_luzhang<=-30){
            luzhang_type = LUZHANG_OUT2;
        }
    }else if(luzhang_type==LUZHANG_OUT2) {
        //打脚
        if(Yaw-Yaw_luzhang>=-28) {
            luzhang_type = LUZHANG_NONE;
            zhangai_type = ZHANGAI_NONE;
            bibibi(0);
        }
    }
}

//-------------------------------------------------------------------------------------------------------------------
//  主题:      障碍(路障+坡道)
//  功能:      略
//  样例:      略
//  作者:      耿帅哥
//-------------------------------------------------------------------------------------------------------------------

enum zhangai_type_e zhangai_type = ZHANGAI_NONE;

void check_zhangai(void) {
    if(dl1a_distance_mm<1000 && zhangai_type==ZHANGAI_NONE) {
        zhangai_type = ZHANGAI_1;
//        bibibi(1);
        luzhang_pitch = Pitch;
    }
    else if(zhangai_type==ZHANGAI_1) {
        if(Lpt0_found && Lpt1_found && !check_far_whitepoint(x6,y6) && !check_far_whitepoint(x7,y7)&&luzhang_type==LUZHANG_NONE) {
            luzhang_type = LUZHANG_BEGIN;
            zhangai_type = ZHANGAI_OVER;
//            bibibi(1);
        }else if(Pitch-luzhang_pitch>5&&slope_type==SLOPE_NONE){
            slope_type = SLOPE_BEGIN;
            slope_Pitch = Pitch;
            zhangai_type = ZHANGAI_OVER;
//            bibibi(1);
        }else if(dl1a_distance_mm>1000) {
            zhangai_type = ZHANGAI_NONE;
            bibibi(0);
        }else {
            ;
        }
    }}




















