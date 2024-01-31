#include "zf_common_headfile.h"

//-------------------------------------------------------------------------------------------------------------------
//  ����:      б�뻷��
//  ����:      ���ұ����л�������/����Բ��������
//  ����:      ��
//  ����:      ��˧��
//-------------------------------------------------------------------------------------------------------------------

// ���¶���ΪԲ��ѰԶ���趨
uint8 far_Spts0[120][2];
uint8 far_Spts1[120][2];
uint8 far_Spts0_num, far_Spts1_num;

bool far_Spt0_found, far_Spt1_found;
int far_Spt0_rpts0s_id, far_Spt1_rpts1s_id;

uint8 check_far_S_point(uint8 x,uint8 y,uint8 flag) {
    if(flag==0) {
        //ȫ��far_x1 = 0,�ӱ߽���
        uint8 x1 = begin_x, y1 = y;
        if(mt9v03x_image_Bandw[y1][x1]==0){
            x1 = begin_x + 20;
        }
        far_Spts0_num = sizeof(far_Spts0) / sizeof(far_Spts0[0]);
        for (; x1>0; x1--) if (mt9v03x_image_Bandw[ y1][ x1 - 1] == 0) break;
        if (mt9v03x_image_Bandw[y1][x1] == 255)
            findline_lefthand_adaptive(mt9v03x_image_Bandw[0], x1, y1, far_Spts0, &far_Spts0_num);
        else far_Spts0_num = 0;
//        tft180_show_int(0, 20, far_Spts0_num, 3);
            return far_Spts0_num;

    }else if(flag==1){
        uint8 x2 = begin_x , y2 = y;
        if(mt9v03x_image_Bandw[y2][x2]==0){
            x2 = begin_x - 20;
        }
        far_Spts1_num = sizeof(far_Spts0) / sizeof(far_Spts0[0]);
        for (; x2<MT9V03X_W-1; x2++) if (mt9v03x_image_Bandw[ y2][ x2 + 1] == 0) break;
        if (mt9v03x_image_Bandw[y2][x2] == 255)
            findline_righthand_adaptive(mt9v03x_image_Bandw[0], x2, y2, far_Spts1, &far_Spts1_num);
        else far_Spts1_num = 0;
        tft180_show_int(0, 40, far_Spts1[far_Spts1_num-1][1]-far_Spts1[1][1], 3);
        //    tft180_show_float(0, 110, Lpt0_rpts0s_id, 6 ,2);
//            tft180_show_float(0, 130, Lpt1_rpts1s_id, 6 ,2);
            return far_Spts1_num;

    }
}

enum circle_type_e circle_type = CIRCLE_NONE;
//-------------------------------------------------------------------------------------------------------------------
//  ����:      ����
//  ����:      ���ұ����л�������/����Բ��������
//  ����:      ��
//  ����:      ��˧��
//-------------------------------------------------------------------------------------------------------------------
// �����������ڷ�ֹһЩ�ظ������ȡ�
int64_t circle_encoder;
int16 circle_yaw;

int none_left_line = 0, none_right_line = 0;
int have_left_line = 0, have_right_line = 0;
uint8 circle_num;
bool yunahuan_left,yunahuan_right;
int delay_yuanhuan;

void check_circle() {

    //�ж϶���
    if (rpts0s_num<6) { no_left_line++; }
    if (rpts1s_num<6) { no_right_line++; }
    // ��Բ��ģʽ�£�����L�ǵ�, ���߳�ֱ��
    if (circle_type==CIRCLE_NONE && Lpt0_found && !Lpt1_found && is_straight1) {
        //��ǵ���μ��
        if(Lpt0_rpts0s_id<10)
        circle_type = CIRCLE_LEFT_BEGIN;
    }
    else if (circle_type==CIRCLE_NONE && !Lpt0_found && Lpt1_found && is_straight0) {
        //�ҽǵ���μ��
        if(Lpt1_rpts1s_id<10)
        circle_type = CIRCLE_RIGHT_BEGIN;
    }else if(Lpt1_found && no_left_line>2){
        yunahuan_right = 1;
        track_type = TRACK_LEFT;
    }else if(Lpt0_found && no_right_line>2){
        yunahuan_left = 1;
        track_type = TRACK_RIGHT;
    }else if(circle_type==CIRCLE_NONE && !is_straight0 && is_straight1 && yunahuan_left) {

        if((GUI_ADC_DATE[0]<GUI_ADC_DATE[1]&&GUI_ADC_DATE[0]>67)){

            circle_type = CIRCLE_LEFT_IN;
            circle_yaw = Yaw;
        }
            no_right_line = 0;

    }else if(circle_type==CIRCLE_NONE && is_straight0 && !is_straight1 && yunahuan_right) {

        if((GUI_ADC_DATE[3]<GUI_ADC_DATE[4]&&GUI_ADC_DATE[4]>70)) {
            circle_type = CIRCLE_RIGHT_IN;
            circle_yaw = Yaw;
        }
            no_left_line = 0;
    }
}

void run_circle() {
    // �󻷿�ʼ��Ѱ��ֱ������
    if (circle_type==CIRCLE_LEFT_BEGIN) {
        track_type = TRACK_RIGHT;
//        bibibi(1);
        //�ȶ����ߺ�����
        if (rpts0s_num < 5) { none_left_line++; }
        if (rpts0s_num > 5 && none_left_line > 2) {
            have_left_line++;
            if (have_left_line > 2) {
                circle_type = CIRCLE_LEFT_IN0;
                none_left_line = 0;
                have_left_line = 0;
                circle_yaw = Yaw;
            }
        }
    }

    else if (circle_type == CIRCLE_LEFT_IN0) {
        if (rpts0s_num < 5) { none_left_line++; }
        if(none_left_line>2) {
            circle_type = CIRCLE_LEFT_IN;
            none_left_line = 0;
        }
    }

    //�뻷��Ѱ��Բ����
    else if (circle_type == CIRCLE_LEFT_IN) {
        track_type = TRACK_LEFT;

//        bibibi(0);
        //����������1/4Բ   Ӧ����Ϊ����Ϊת���޹յ�
        if (Yaw-circle_yaw>30) { circle_type = CIRCLE_LEFT_RUNNING; }//
    }
    //����Ѳ�ߣ�Ѱ��Բ����
    else if (circle_type == CIRCLE_LEFT_RUNNING) {
        track_type = TRACK_RIGHT;
        shexiangtou_or_dianci = false;
        if (Lpt1_found) rpts1s_num = rptsc1_num = Lpt1_rpts1s_id;
        //�⻷�յ�(��L��)
        if (Lpt1_found && Lpt1_rpts1s_id < 10) {
            shexiangtou_or_dianci = true;
            circle_type = CIRCLE_LEFT_OUT;
            circle_yaw = Yaw;
        }
    }
    //������Ѱ��Բ
    else if (circle_type == CIRCLE_LEFT_OUT) {
        track_type = TRACK_LEFT;

        //��ѯ��Բ��״̬
//        wireless_ch573_send_byte(6);
//
//        if(read_ceshi==60) {
//            Shache_flag = 1;
//        }else if(read_ceshi==61) {
//            Shache_flag = 0;
//            OFF_MOTOR = 0;
//        }


        //����Ϊ��ֱ��
        if (Yaw-circle_yaw>45&&read_ceshi!=60) {//&& is_straight1
            circle_type = CIRCLE_LEFT_END;
        }
    }
    //�߹�Բ����Ѱ����
    else if (circle_type == CIRCLE_LEFT_END) {
        track_type = TRACK_RIGHT;

        //�����ȶ�����
        if (rpts0s_num < 5) { none_left_line++; }
        if (rpts0s_num > 5 && none_left_line > 2) {
            circle_type = CIRCLE_NONE;
            bibibi(0);
            none_left_line = 0;
            circle_num++;
            circle_yaw = 0;
        }
    }

    //�һ����ƣ�ǰ��Ѱ��ֱ��
    else if (circle_type==CIRCLE_RIGHT_BEGIN) {
        track_type = TRACK_LEFT;
//        bibibi(1);
        //�ȶ����ߺ�����
        if (rpts1s_num < 5) { none_right_line++; }
        if (rpts1s_num > 5 && none_right_line > 2) {
            have_right_line++;
            if (have_right_line > 2) {
                circle_type = CIRCLE_RIGHT_IN0;
                none_right_line = 0;
                have_right_line = 0;
                circle_yaw = Yaw;
            }
        }
    }


    else if (circle_type==CIRCLE_RIGHT_IN0) {
        if (rpts1s_num < 5) { none_right_line++; }
        if(none_right_line>2) {
            none_right_line = 0;
            circle_type = CIRCLE_RIGHT_IN;
        }
    }
    //���һ���Ѱ����Բ��
    else if (circle_type==CIRCLE_RIGHT_IN) {
        track_type = TRACK_RIGHT;

        if (Yaw-circle_yaw<-30) { circle_type = CIRCLE_RIGHT_RUNNING; }
    }
    //����Ѳ�ߣ�Ѱ��Բ����
    else if (circle_type == CIRCLE_RIGHT_RUNNING) {
        track_type = TRACK_LEFT;
        shexiangtou_or_dianci = false;
        //�⻷���ڹյ�,���ټӹյ�����о�(��L��)
        if (Lpt0_found) rpts0s_num = rptsc0_num = Lpt0_rpts0s_id;
        if (Lpt0_found && Lpt0_rpts0s_id < 10) {
            circle_yaw = Yaw;
            shexiangtou_or_dianci = true;
            circle_type = CIRCLE_RIGHT_OUT;
        }
    }
    //������Ѱ��Բ
    else if (circle_type == CIRCLE_RIGHT_OUT) {
        track_type = TRACK_RIGHT;

        //��ѯ��Բ��״̬
//        wireless_ch573_send_byte(6);
//
//        if(read_ceshi==60) {
//            Shache_flag = 1;
//        }else if(read_ceshi==61) {
//            Shache_flag = 0;
//            OFF_MOTOR = 0;
//        }

        if (Yaw-circle_yaw<-45&&read_ceshi!=60) {
            circle_type = CIRCLE_RIGHT_END;
        }
    }
        //�߹�Բ����Ѱ����
    else if (circle_type == CIRCLE_RIGHT_END) {
        track_type = TRACK_LEFT;

        //�����ȶ�����
        if (rpts1s_num < 5) { none_right_line++; }
        if (rpts1s_num > 5 && none_right_line > 2) {
            circle_type = CIRCLE_NONE;
//            bibibi(0);
            circle_yaw = 0;
            circle_num++;
            none_right_line = 0;
            have_right_line = 0;
        }
    }
}


