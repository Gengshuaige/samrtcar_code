#include "zf_common_headfile.h"

enum first_chongdian_type_e first_type = FIRST_NONE;
enum chongdian_low_e chongdian_low = CW_NONE;

//-------------------------------------------------------------------------------------------------------------------
//  ����:      �󳵳��
//  ����:      ��
//  ����:      ��
//  ����:      ��˧��
//-------------------------------------------------------------------------------------------------------------------

int16 chongdian_Yaw;
int64_t chongdian_encoder;

void check_chongdian(void) {
    if(1) {
        first_type = FIRST_BEGIN;
    }
}

//����1,���⵹��
void run_chongdian1(void) {
    if(first_type==FIRST_BEGIN) {
        //ǰ����������
        if(read_ceshi==1) {
            first_type = CHARGE_BEGIN;
        }
    }else if(first_type==CHARGE_BEGIN) {
        //��"�յ�"
        wireless_ch573_send_byte(11);
        if(dl1a_distance_mm<400) {//���ܵ�ǰ��"�յ�"�ź�
            first_type = CHARGE_IN0;
        }
    }else if(first_type==CHARGE_IN0) {
        wireless_ch573_send_byte(2);
        //ǰ��"�յ�"
        if(read_ceshi==21) {
            first_type = CHARGE_IN1;
        }
    }else if(first_type==CHARGE_IN1) {
        //��������
        wireless_ch573_send_byte(3);
        //ǰ��"�յ�"
        if(read_ceshi==31) {
            first_type = CHARGE_IN2;
        }
    }else if(first_type==CHARGE_IN2) {
        //���ing...

        //��ѹ�����趨ֵ
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
//����2,�״�·��ʶ��
void run_chongdian2(void) {
    if(first_type==FIRST_BEGIN) {
            first_type = CHARGE_BEGIN;
        }else if(first_type==CHARGE_BEGIN) {
            first_type = CHARGE_IN2;
        }else if(first_type==CHARGE_IN2) {
            //���ing...
            if(dl1a_distance_mm>300)
                charge_val_houche = 5;
            else
                charge_val_houche = 0;
            //��ѹ�����趨ֵ
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
