#include "zf_common_headfile.h"

enum first_chongdian_type_e first_type = FIRST_NONE;
enum chongdian_low_e chongdian_low = CW_NONE;

//-------------------------------------------------------------------------------------------------------------------
//  主题:      后车充电
//  功能:      略
//  样例:      略
//  作者:      耿帅哥
//-------------------------------------------------------------------------------------------------------------------

int16 chongdian_Yaw;
int64_t chongdian_encoder;

void check_chongdian(void) {
    if(1) {
        first_type = FIRST_BEGIN;
    }
}

//方案1,出库倒车
void run_chongdian1(void) {
    if(first_type==FIRST_BEGIN) {
        //前车：允许测距
        if(read_ceshi==1) {
            first_type = CHARGE_BEGIN;
        }
    }else if(first_type==CHARGE_BEGIN) {
        //后车"收到"
        wireless_ch573_send_byte(11);
        if(dl1a_distance_mm<400) {//接受到前车"收到"信号
            first_type = CHARGE_IN0;
        }
    }else if(first_type==CHARGE_IN0) {
        wireless_ch573_send_byte(2);
        //前车"收到"
        if(read_ceshi==21) {
            first_type = CHARGE_IN1;
        }
    }else if(first_type==CHARGE_IN1) {
        //后车请求充电
        wireless_ch573_send_byte(3);
        //前车"收到"
        if(read_ceshi==31) {
            first_type = CHARGE_IN2;
        }
    }else if(first_type==CHARGE_IN2) {
        //充电ing...

        //电压高于设定值
        if(charge_Yuzhi>2200) {
            first_type = CHARGE_IN3;
        }
    }else if(first_type==CHARGE_IN3){
        wireless_ch573_send_byte(4);
        if(read_ceshi==41) {
            first_type = CHARGE_GO;
        }
    }else if(first_type==CHARGE_GO) {
        wireless_ch573_send_byte(5);
        if(dl1a_distance_mm>600) {
            first_type = CHARGE_OVER;
        }
    }
}

int charge_val_houche;
//方案2,首次路障识别
void run_chongdian2(void) {
    if(first_type==FIRST_BEGIN) {
            first_type = CHARGE_BEGIN;
        }else if(first_type==CHARGE_BEGIN) {
            first_type = CHARGE_IN2;
        }else if(first_type==CHARGE_IN2) {
            //充电ing...
            if(dl1a_distance_mm>300)
                charge_val_houche = 5;
            else
                charge_val_houche = 0;
            //电压高于设定值
            if(charge_Yuzhi>1280) {
                first_type = CHARGE_IN3;
            }
        }else if(first_type==CHARGE_IN3){
                wireless_ch573_send_byte(4);
            if(read_ceshi==41) {
                first_type = CHARGE_GO;
            }
        }else if(first_type==CHARGE_GO) {
            wireless_ch573_send_byte(5);
            if(dl1a_distance_mm>600) {
                first_type = CHARGE_WAIT;
            }
        }else if(first_type==CHARGE_WAIT) {
            chongdian_encoder += get_total_encoder();
            if(chongdian_encoder>=600) {
                first_type = CHARGE_OVER;
            }
        }
}


//-------------------------------------------------------------------------------------------------------------------
//  主题:      后车补电
//  功能:      略
//  样例:      略
//  作者:      耿帅哥
//-------------------------------------------------------------------------------------------------------------------
//补电次数
int charge_low_num;
//低压检查
void Low_E_check(void) {
    //向前车发送低压信号charge_Yuzhi<0
    if(duanlu_num>=1 &&
            duanlu_type==DUANLU_NONE&&ruku_type==RUKU_NONE&&cross_type==CROSS_NONE
            &&luzhang_type==LUZHANG_NONE&&slope_type==SLOPE_NONE&&circle_type==CIRCLE_NONE
            &&charge_low_num==0
            ) {
        //查询信号
//           Shache_flag = 1;

        int query_signal = 200 + duanlu_num;
        wireless_ch573_send_byte(query_signal);
    }
}

void check_charge_low(void) {
    Low_E_check();
    if(read_ceshi==8&&charge_low_num<1) {
        chongdian_low = CW_BEGIN;
//        Shache_flag = 1;
    }
}

void run_charge_low(void) {
    if(chongdian_low==CW_BEGIN) {
        wireless_ch573_send_byte(0);
        if(dl1a_distance_mm>100){
            chongdian_low = CW_NEAR;
//            Shache_flag = 1;
        }
    }else if(chongdian_low==CW_NEAR) {
        if(dl1a_distance_mm<200) {

            chongdian_low = CW_CHARGE;
        }
    }else if(chongdian_low==CW_CHARGE) {
        wireless_ch573_send_byte(9);
        Shache_flag = 1;

        //前车应答收到
        if(read_ceshi==91) {
            chongdian_low = CW_IN;
        }

    }else if(chongdian_low==CW_IN) {

        //电压高
        if(charge_Yuzhi>1250) {//
            chongdian_low = CW_OVER;
        }
    }if(chongdian_low==CW_OVER) {
        //充电完毕
        wireless_ch573_send_byte(10);

        if(dl1a_distance_mm>600){
            Shache_flag = 0;
            chongdian_low = CW_NONE;
            charge_low_num++;
        }
    }
}


