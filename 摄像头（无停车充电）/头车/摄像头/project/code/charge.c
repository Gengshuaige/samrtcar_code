#include "zf_common_headfile.h"

enum first_chongdian_type_e first_type = FIRST_NONE;

//-------------------------------------------------------------------------------------------------------------------
//  主题:      前车充电
//  功能:      略
//  样例:      略
//  作者:      耿帅哥
//-------------------------------------------------------------------------------------------------------------------

int16 chongdian_Yaw;
int64_t chongdian_encoder;

void check_chongdian(void) {
    if(first_type==FIRST_NONE) {
        first_type = FIRST_BEGIN;
        chongdian_Yaw = Yaw;
    }
}

//方案1,出库倒车
void run_chongdian1(void) {
    if(first_type==FIRST_BEGIN) {
        track_type = TRACK_RIGHT;
//        aim_distance = 0.1;
//        chongdian_encoder += get_total_encoder();
        if(chongdian_Yaw-Yaw>50) {
//            chongdian_encoder = 0;
            first_type = FIRST_IN1;
        }
    }else if(first_type==FIRST_IN1) {
        aim_distance = 0.5;
        //停车向后车发送允许测距信号
        wireless_ch573_send_byte(1);
        //后车"收到"
        if(read_ceshi==11)
            //开始倒车
            first_type = FIRST_IN2;
    }else if(first_type==FIRST_IN2) {
        //倒车ing...

        //后车:距离小,请前车停车
        if(read_ceshi==2)
            first_type = FIRST_IN3;
    }else if(first_type==FIRST_IN3) {
        //前车停车,并且回复"收到"
        wireless_ch573_send_byte(21);
        //后车:请求充电
        if(read_ceshi==3) {
            first_type = CHARGE_BEGIN;
        }
    }else if(first_type==CHARGE_BEGIN) {
        //前车开始充电,并且回复"收到"
        wireless_ch573_send_byte(31);
//        charge(1);
        //充电ing...
        bibibi(1);

        //后车:电量已满
        if(read_ceshi==4) {
            system_delay_ms(3000);
            first_type = CHARGE_IN;
        }
    }else if(first_type==CHARGE_IN) {
        //前车停止充电,并且回复"收到"
//        charge(0);
        wireless_ch573_send_byte(41);
        if(read_ceshi==5) {
            first_type = CHARGE_OVER;
        }
    }
}


int chongdian_delay;
void run_chongdian2(void) {
    if(first_type==FIRST_BEGIN) {
            track_type = TRACK_RIGHT;
            if(chongdian_Yaw-Yaw>83 || chongdian_Yaw-Yaw<-85) {
    //            chongdian_encoder = 0;
                first_type = FIRST_IN1;
            }
        }else if (first_type==FIRST_IN1) {

            chongdian_delay++;
            if(chongdian_delay>=50) {
                first_type = FIRST_IN2;
                chongdian_delay = 0;
            }

        }else if(first_type==FIRST_IN2) {
            //倒车ing...
            chongdian_encoder += get_total_encoder();
            //编码器积分停车
            if(chongdian_encoder<-1000) {
                first_type = FIRST_IN3;
                chongdian_encoder = 0;
            }

        }else if(first_type==FIRST_IN3) {
            //倒车ing...
            chongdian_encoder += get_total_encoder();
            //编码器积分停车
            if(chongdian_encoder<-500) {
                first_type = CHARGE_BEGIN;
                chongdian_encoder = 0;
            }
        }else if(first_type==CHARGE_BEGIN) {

            if(!BKEY__4) {
                charge(0);
            }else
                charge(1);
            //充电ing...

            bibibi(1);

            //后车:电量已满
            if(read_ceshi==4) {
                first_type = CHARGE_IN;
            }
        }else if(first_type==CHARGE_IN) {
            //前车停止充电,并且回复"收到"
            charge(0);
            wireless_ch573_send_byte(41);
            if(read_ceshi==5) {
                first_type = CHARGE_OVER;
            }
        }
}

void run_chongdian3(void) {
    if(first_type==FIRST_BEGIN) {
        shexiangtou_or_dianci = true;
            track_type = TRACK_RIGHT;
            if(chongdian_Yaw-Yaw>76 || chongdian_Yaw-Yaw<-76) {
                first_type = FIRST_IN3;
            }
        }else if(first_type==FIRST_IN3) {
            //倒车ing...
            chongdian_encoder += get_total_encoder();
            //编码器积分停车
            if(chongdian_encoder<-300) {
                first_type = CHARGE_BEGIN;
                chongdian_encoder = 0;
            }
        }else if(first_type==CHARGE_BEGIN) {

            if(!BKEY__4) {
                charge(0);
            }else
                charge(1);
            //充电ing...

//            bibibi(1);

            //后车:电量已满
            if(read_ceshi==4) {
                first_type = CHARGE_IN;
                bibibi(0);
            }
        }else if(first_type==CHARGE_IN) {
            //前车停止充电,并且回复"收到"
            charge(0);
            wireless_ch573_send_byte(41);
            if(read_ceshi==5) {
                first_type = CHARGE_OVER;
            }
        }
}


//-------------------------------------------------------------------------------------------------------------------
//  主题:      前车补电
//  功能:      略
//  样例:      略
//  作者:      耿帅哥
//-------------------------------------------------------------------------------------------------------------------

enum chongdian_low_e chongdian_low_type = CW_NONE;
int64_t chongdian_low_encoder;
int chongdian_low_num;
int chongdian_low_num_CISHI;

void check_charge_low(void) {
    if((read_ceshi/100==2)&&(read_ceshi%100==duanlu_num) && chongdian_low_type==CW_NONE && ruku_type==RUKU_NONE && first_type==CHARGE_OVER
            &&chongdian_low_num==0
            ) {
        chongdian_low_type = CW_BEGIN1;
        chongdian_low_num_CISHI++;
    }
}

void run_charge_low(void) {
    if(chongdian_low_type==CW_BEGIN1) {
        chongdian_low_encoder += get_total_encoder();
        if(chongdian_low_encoder>Low_encoder) {
            chongdian_low_type = CW_BEGIN2;
            chongdian_low_encoder = 0;
        }
    }
    else if(chongdian_low_type==CW_BEGIN2) {
        wireless_ch573_send_byte(8);
        if(read_ceshi==9){
            chongdian_low_type = CW_IN;
        }
    }else if(chongdian_low_type==CW_IN) {
        wireless_ch573_send_byte(91);
        if(!BKEY__4) {
            charge(0);
        }else
            charge(1);
        //充电ing...

//        bibibi(1);

        //后车:电量已满
        if(read_ceshi==10) {
            charge(0);
            chongdian_low_num++;
            chongdian_low_type = CW_NONE;
            bibibi(0);
            Shache_flag = 0;
        }
    }
}


