/* \\ \\ \\ \\ \\ \\ \\ || || || || || || // // // // // // // //   ������(����):
\\ \\ \\ \\ \\ \\ \\        _ooOoo_          // // // // // // //   2023.6.19   \|/
\\ \\ \\ \\ \\ \\          o8888888o            // // // // // //   2023.6.20    |
\\ \\ \\ \\ \\             88" . "88               // // // // //   2023.6.21    |
\\ \\ \\ \\                (| -_- |)                  // // // //   2023.6.22    |
\\ \\ \\                   O\  =  /O                     // // //
\\ \\                   ____/`---'\____                     // //
\\                    .'  \\|     |//  `.                      //
==                   /  \\|||  :  |||//  \                     ==
==                  /  _||||| -:- |||||-  \                    ==
==                  |   | \\\  -  /// |   |                    ==
==                  | \_|  ''\---/''  |   |                    ==
==                  \  .-\__  `-`  ___/-. /                    ==
==                ___`. .'  /--.--\  `. . ___                  ==
==              ."" '<  `.___\_<|>_/___.'  >'"".               ==
==            | | :  `- \`.;`\ _ /`;.`/ - ` : | |              \\
//            \  \ `-.   \_ __\ /__ _/   .-` /  /              \\
//      ========`-.____`-.___\_____/___.-`____.-'========      \\
//                           `=---='                           \\
// //   ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^  \\ \\
// // //      ���汣��        ����BUG          �����޸�        \ \  \ \  \ \
// // // // // // || || || || || || || || || || \\ \\ \\ \\ \\ */
/*
* �޸ļ�¼
* ����                               ����
* 2022-09-15        ��˧��
************************************************************************************************************************/
#include "zf_common_headfile.h"
/**************************************************��Ҫ�޸ĵĶ���*******************************************************/
enum chuku_fangxiang_e chuku_fangxiang = LEFT;

//Ԥ�������
float aim_distance = 0.6;
//ͼ������־λ
uint8 Tuxiang_flag = 0;
//·��ģʽѡ��
bool RIGHT_LZ = 0;
/**************************************************��������**************************************************************/
//����ͨ��
uint8 send_ceshi;
uint8 read_ceshi;
//����ƫ��+���ƫ��
float pure_angle_far;
float pure_angle_near;
float pure_angle_mid;
float pure_angle;
//��ǰѲ��ģʽ
enum track_type_e track_type = TRACK_RIGHT;
//��ֵ����ֵ
uint8 erzhihuayuzhi;
//�������
uint8 begin_x = MT9V03X_W / 2;
uint8 begin_y = 65;
//��������+����
uint8 ipts0[MY_H][2];
uint8 ipts1[MY_H][2];
uint8 ipts0_num, ipts1_num;
//��͸�ӱ߽�+����
uint8 ipts0y[MY_H][2];
uint8 ipts1y[MY_H][2];
uint8 ipts0_num_y, ipts1_num_y;
//�˲�������+����
uint8 rpts0b[MY_H][2];
uint8 rpts1b[MY_H][2];
uint8 rpts0b_num, rpts1b_num;
//�Ⱦ��������+����
uint8 rpts0s[MY_H][2];//��߽����������!!!!!
uint8 rpts1s[MY_H][2];
int rpts0s_num, rpts1s_num;
//����ÿ����ĽǶ�+����
float rpts0a[MY_H];
float rpts1a[MY_H];
uint8 rpts0a_num, rpts1a_num;
//ͨ���Ǽ���ֵ���Ƽ���õ�������+����
float rpts0an[MY_H];
float rpts1an[MY_H];
uint8 rpts0an_num, rpts1an_num;
//ͨ��ƽ����õ���������+���鳤��
uint8 rptsc0[MY_H][2];
uint8 rptsc1[MY_H][2];
uint8 rptsc0_num, rptsc1_num;
//ͨ����һ���õ���Ψһ��������+����
uint8 rptsn[MY_H][2];
uint8 rptsn_num;
//��������
float thres ;
int block_SIZE = 7;
float clip_value = 2;
float line_blur_kernel = 7;
float pixel_per_meter = 102;
float sample_dist = 0.02;
float angle_dist = 0.2;
uint8 (*rpts)[2];
int rpts_num;
int Element_num;
float gengshuaige = 1;
//Ԫ���ź�
int query_signal;
//��־λ
bool Lpt0_found,Lpt1_found;
bool Spt0_found,Spt1_found;
bool is_straight0,is_straight1;
uint8 Lpt0_rpts0s_id,Lpt1_rpts1s_id;
uint8 Spt0_rpts0s_id,Spt1_rpts1s_id;
uint8 Lpt0_rpts0s_16,Lpt1_rpts1s_16;
uint8 far_Lpt0_rpts0s_16,far_Lpt1_rpts1s_16;
int delay_stop_my_2s;
bool turn_left;
bool turn_right;
bool shexiangtou_or_dianci = false;
bool shexiangtou_or_dianci_away;
bool OFF_motor;
//ԭͼ�ǵ�
int x6,x7,y6,y7;
int far_x6,far_x7,far_y6,far_y7;

//tft180��Ļ��ʾ
void tft180_show_All(void);
//���������
void find_left(void);
//�����ұ���
void find_right(void);
//�߽���͸��
void nitoushi_bianije(void);
//���ߵȾ����
void dengjucaiyang(void);
//�˲�
void lvbo(void);
//�ҽǵ�
void zhaojiaodian(void);
//�Ǽ���ֵ����
void feijidayizhi(void);
//������
void find_zhongxian(void);
//��L�ǵ�
void find_L_jiaodian(void);
//�Ƚϱ߳��ж�Ѳ�߷�ʽ
void Bijiaobianchang(void);
//���߹�һ��
void zhongxianGuiyihua(void);
//ʶ��
void TELL(void);
void TELL_dianci(void);
//��̬Ԥ���
void aim_distance_sport(float speed,float xishu);
//��ѹ���
void Low_E_check(void);
//Ӧ��ǰ���Ļ�����ѯ
void Yuan_huan_wait(void);

/**************************************************main**************************************************************/
int main (void)
{
    //��ʼ��оƬʱ��,����Ƶ��Ϊ 144MHz
    clock_init(SYSTEM_CLOCK_144M);
    debug_init();
    //��ʼ��
    all_initialize();
    while(1)
    {
        if(mt9v03x_finish_flag){
//            �ϵ�2�����ͼ����
//            bibibi(1);
            if(delay_stop_my_2s==401){
                //������ֵ(��·�̶���ֵ)
                erzhihuayuzhi = my_adapt_threshold(mt9v03x_image[0], MY_W, MY_H);
                //��ֵ��(��·�̶���ֵ)
                Erzhihua(erzhihuayuzhi);
                //�������ұ���
                find_left();
                find_right();
                //�߽���͸��
                nitoushi_bianije();
                //����
                dengjucaiyang();
                //�ǵ�
                zhaojiaodian();
                //����
                feijidayizhi();
                //������
                find_zhongxian();
                //�ҹյ�
                find_L_jiaodian();
                //�Ƚϱ߳��ж�����Ѳ��
                Bijiaobianchang();
                //ʶ�𲿷�
                TELL_dianci();
                //���߹�һ��
                zhongxianGuiyihua();
                //������ѯӦ��
                Yuan_huan_wait();
            }
//            tft180_show_All();
            mt9v03x_finish_flag = 0;
        }
//        init_debug();
    }
}

/**************************************************��������**************************************************************/
void tft180_show_All(void){
    if(BKEY__1)
        tft180_displayimage03x(mt9v03x_image_Bandw[0], MT9V03X_W/2, MT9V03X_H/2);//IMG/mt9v03x_image/mt9v03x_image_Bandw
    //��������ֵ
//    tft180_show_float(0, 120, temp, 4 ,2);charge_Yuzhi
//    tft180_show_int(0, 120, Yaw, 6 );
//    tft180_show_int(0, 140, Pitch, 6 );
//    tft180_show_float(0, 90, conf, 6 , 2);
//    tft180_show_int(0, 20, pid_shuchu_speed_L, 6);
//    tft180_show_int(0, 0, pid_shuchu_speed_R, 6);
//    tft180_show_float(0, 80, pure_angle, 6 ,2);
//    tft180_show_float(0, 10, far_Lpt1_rpts1s_id, 6 ,2);Lpt0_rpts0s_id
//    tft180_show_float(0, 110, Lpt0_rpts0s_id, 6 ,2);
//    tft180_show_float(0, 130, Lpt1_rpts1s_id, 6 ,2);
//        tft180_show_int(0, 110, rpts0s_num, 2);
//        tft180_show_int(0, 130, Lpt1_found, 2);
//    tft180_show_float(0, 90, shiji_speed_L, 6 ,2);
//    tft180_show_float(0, 110, shiji_speed_R, 6 ,2);
//        tft180_show_float(0, 40, qiwang_speed_L, 6 ,2);
//        tft180_show_float(0, 60, qiwang_speed_R, 6 ,2);
//    tft180_show_float(0, 130, track_type, 6 ,2);
    tft180_show_string(0,0,"charge:");
    tft180_show_float(0, 20, charge_Yuzhi, 4 ,2 );

//    tft180_show_int(0, 0, query_signal, 4);
    //Ԫ�ر�־λ
//      tft180_show_string(0,0,"circle:");
//      tft180_show_int(71, 0, circle_type, 2);
      tft180_show_string(0,40,"first:");
       tft180_show_int(71, 40, first_type, 6 );
//      tft180_show_string(0,20,"ruku:");
//      tft180_show_int(71, 20, ruku_type, 6 );
////      tft180_show_string(0,40,"cross:");
////      tft180_show_int(71, 40, cross_type, 2);
//      tft180_show_string(0,60,"duanlu:");
//      tft180_show_int(71, 60, duanlu_type, 2);
//      tft180_show_string(0,80,"zhangai:");
//      tft180_show_int(71, 80, zhangai_type, 2);
//      tft180_show_string(0,100,"luzhang:");
//      tft180_show_int(71, 100, luzhang_type, 2);
//      tft180_show_string(0,120,"slope:");
//      tft180_show_int(71, 120, slope_type, 2);
    //���γ��
//          tft180_show_string(0,0,"Cw:");
//          tft180_show_int(71, 0, chongdian_low, 2);

//    tft180_show_int(0, 0,delay_stop_my_2s, 6);
//    tft180_show_float(0, 50, shiji_speed_L, 6 , 2);
//    tft180_show_float(0, 0, shiji_speed_R, 6 , 2);
//    tft180_show_float(0, 80, GUI_ADC_DATE[0], 6 , 2);
//    tft180_show_float(0, 100, GUI_ADC_DATE[1], 6 , 2);
//    tft180_show_float(0, 120, GUI_ADC_DATE[3], 6 , 2);
//    tft180_show_float(0, 140, GUI_ADC_DATE[4], 6 , 2);
//            tft180_show_int(0, 0,adc_convert(ADC1_IN14_C4), 6);
//            tft180_show_int(0, 20,adc_convert(ADC1_IN13_C3), 6);
//            tft180_show_int(0, 40,adc_convert(ADC1_IN12_C2), 6);
//            tft180_show_int(0, 60,adc_convert(ADC1_IN11_C1), 6);
    //ͼ��
//    camera_send_image(DEBUG_UART_INDEX, (const uint8 *)mt9v03x_image, MT9V03X_IMAGE_SIZE);
    //ͨ��
//    wireless_ch573_send_byte(101);
//    tft180_show_string(0, 20, "from one:");
//    tft180_show_int(0, 40, read_ceshi,3);
}

void find_left(void){
    uint8 x1 = begin_x, y1 = begin_y;
    if(mt9v03x_image_Bandw[y1][x1]==0){
        x1 = begin_x + 20;
    }
    ipts0_num = sizeof(ipts0) / sizeof(ipts0[0]);
    for (; x1>0; x1--) if (mt9v03x_image_Bandw[ y1][ x1 - 1] == 0) break;
    if (mt9v03x_image_Bandw[y1][x1] == 255)
        findline_lefthand_adaptive(mt9v03x_image_Bandw[0], x1, y1, ipts0, &ipts0_num);
    else ipts0_num = 0;
//  tft180_show_gray_image(0, 0, mt9v03x_image_Bandw[0], 188, 70, 188/2, 70/2,0);//IMG/mt9v03x_image_dvp/mt9v03x_image_Bandw
}

void find_right(void){
    uint8 x2 = begin_x , y2 = begin_y;
    if(mt9v03x_image_Bandw[y2][x2]==0){
        x2 = begin_x - 20;
    }
    ipts1_num = sizeof(ipts1) / sizeof(ipts1[0]);
    for (; x2<MT9V03X_W-1; x2++) if (mt9v03x_image_Bandw[ y2][ x2 + 1] == 0) break;
    if (mt9v03x_image_Bandw[y2][x2] == 255)
        findline_righthand_adaptive(mt9v03x_image_Bandw[0], x2, y2, ipts1, &ipts1_num);
    else ipts1_num = 0;
//  tft180_show_gray_image(0, 0, mt9v03x_image_Bandw[0], 188, 70, 188/2, 70/2,0);
}

void nitoushi_bianije(void){
    image_perspective_corrective_Forward2(ipts0[0],ipts0_num,ipts0y[0]);
    image_perspective_corrective_Forward2(ipts1[0],ipts1_num,ipts1y[0]);
    ipts0_num_y = ipts0_num;
    ipts1_num_y = ipts1_num;
}

void lvbo(void)
{
    blur_points0(ipts0y, ipts0_num_y, rpts0b, (int) round(line_blur_kernel));
    rpts0b_num = ipts0_num_y;

    blur_points1(ipts1y, ipts1_num_y, rpts1b, (int) round(line_blur_kernel));
    rpts1b_num = ipts1_num_y;
}

void dengjucaiyang(void){
    rpts0s_num = sizeof(ipts0y) / sizeof(ipts0y[0]);
    resample_points2_L(ipts0y, ipts0_num_y, rpts0s, &rpts0s_num, sample_dist * pixel_per_meter);

    rpts1s_num = sizeof(ipts1y) / sizeof(ipts1y[0]);
    resample_points2_R(ipts1y, ipts1_num_y, rpts1s, &rpts1s_num, sample_dist * pixel_per_meter);
}

void zhaojiaodian(void){
    local_angle_points0(rpts0s, rpts0s_num, rpts0a, (int) round(angle_dist / sample_dist));
    rpts0a_num = rpts0s_num;

    local_angle_points1(rpts1s, rpts1s_num, rpts1a, (int) round(angle_dist / sample_dist));
    rpts1a_num = rpts1s_num;
}

//round:��������ȡ��
void feijidayizhi(void){
    nms_angle0(rpts0a, rpts0a_num, rpts0an, (int) round(angle_dist / sample_dist) * 2 + 1);
    rpts0an_num = rpts0a_num;

    nms_angle1(rpts1a, rpts1a_num, rpts1an, (int) round(angle_dist / sample_dist) * 2 + 1);
    rpts1an_num = rpts1a_num;
}

void find_zhongxian(void){
    track_leftline(rpts0s, rpts0s_num, rptsc0, (int) round(angle_dist / sample_dist), pixel_per_meter * (ROAD_WIDTH+0.04) / 2);//40.95
    rptsc0_num = rpts0s_num;

    track_rightline(rpts1s, rpts1s_num, rptsc1, (int) round(angle_dist / sample_dist), pixel_per_meter * (ROAD_WIDTH) / 2);
    rptsc1_num = rpts1s_num;
}

void find_L_jiaodian(void) {
    Lpt0_found = Lpt1_found = false;
    Spt0_found = Spt1_found = false;
    is_straight0 = rpts0s_num > 15;
    is_straight1 = rpts1s_num > 15;

    for (int i=0; i<rpts0s_num; i++) {
        if(rpts0an[i]==0) continue;
        int im1 = clip(i-(int)round(angle_dist/sample_dist), 0, rpts0s_num-1);
        int ip1 = clip(i+(int)round(angle_dist/sample_dist), 0, rpts0s_num-1);
        float conf = fabs(rpts0a[i]) - (fabs(rpts0a[im1]) + fabs(rpts0a[ip1])) / 2;
//        tft180_show_float(0, 130, conf, 6 , 2);
        //L�ǵ���ֵ
        if (Lpt0_found==false && 1.2<conf && conf<2 && i<15) {
            Lpt0_rpts0s_id = i;
            Lpt0_found = true;

            x6 = nitou3_col[(int)rpts0s[Lpt0_rpts0s_id][1]*MT9V03X_W+(int)rpts0s[Lpt0_rpts0s_id][0]];
            y6 = nitou4_row[(int)rpts0s[Lpt0_rpts0s_id][1]*MT9V03X_W+(int)rpts0s[Lpt0_rpts0s_id][0]];
            Lpt0_rpts0s_16 = check_16point(x6,y6);
        }

        //�������
        if (Spt0_found==false && 0.4<conf && conf<0.8 && i<15) {
            Spt0_rpts0s_id = i;
            Spt0_found = true;
        }

        //��ֱ����ֵ
        if(conf>0.3 && i<27) is_straight0 = false;
        if(Lpt0_found==true && is_straight0==false) break;
    }
    for(int i=0; i<rpts1s_num; i++) {
        if(rpts1an[i]==0) continue;
        int im1 = clip(i - (int) round(angle_dist/sample_dist), 0, rpts1s_num-1);
        int ip1 = clip(i + (int) round(angle_dist/sample_dist), 0, rpts1s_num-1);
        float conf = fabs(rpts1a[i]) - (fabs(rpts1a[im1]) + fabs(rpts1a[ip1])) / 2;
//        tft180_show_float(0, 110, conf, 6 , 2);
        if(Lpt1_found==false && 1.2<conf && conf<2 && i<15) {
            Lpt1_rpts1s_id = i;
            Lpt1_found = true;

            x7 = nitou3_col[(int)rpts1s[Lpt1_rpts1s_id][1]*MT9V03X_W+(int)rpts1s[Lpt1_rpts1s_id][0]];
            y7 = nitou4_row[(int)rpts1s[Lpt1_rpts1s_id][1]*MT9V03X_W+(int)rpts1s[Lpt1_rpts1s_id][0]];
            Lpt1_rpts1s_16 = check_16point(x7,y7);
        }

        //�������
        if (Spt1_found==false && 0.4<conf && conf<0.8 && i<15) {
            Spt1_rpts1s_id = i;
            Spt1_found = true;
        }

        if(conf>0.3 && i<27) is_straight1 = false;
        if(Lpt1_found==true && is_straight1==false) break;
    }
}

void Bijiaobianchang(void){
    if(ipts0_num<ipts1_num) {
        track_type = TRACK_RIGHT;
    }else if(ipts1_num<ipts0_num) {
        track_type = TRACK_LEFT;
    }else {
        if(ipts0[ipts0_num-1][1]<ipts1[ipts1_num-1][1]){
            track_type = TRACK_LEFT;
        }else{
            track_type = TRACK_RIGHT;
        }
    }
}

void zhongxianGuiyihua(void) {

//    track_type = TRACK_LEFT;

    // ���߸���
    if (track_type == TRACK_LEFT) {
        rpts = rptsc0;
        rpts_num = rptsc0_num;
    } else {
        rpts = rptsc1;
        rpts_num = rptsc1_num;
    }

    //���ֶ�Ӧ��(��������ʼ��)
    float cx = MT9V03X_W / 2;
    float cy = (int)(MT9V03X_H * 0.9f);
    //�������(��ʼ�����߹�һ��)
    float min_dist = 1e10;
    int begin_id = -1;
    for(int i=0; i<rpts_num; i++) {
        float dx = rpts[i][0] - cx;
        float dy = rpts[i][1] - cy;
        float dist = sqrt(dx * dx + dy * dy);
        if(dist<min_dist) {
            min_dist = dist;
            begin_id = i;
        }
    }

    //�����е㣬ͬʱ����㲻����󼸸���
    if (begin_id>=0 && rpts_num-begin_id>=3) {
        //��һ������
        rpts[begin_id][0] = cx;
        rpts[begin_id][1] = cy;
        rptsn_num = sizeof(rptsn) / sizeof(rptsn[0]);
        resample_points2_L(rpts+begin_id, rpts_num-begin_id, rptsn, &rptsn_num, sample_dist*pixel_per_meter);

        //ԶԤê��λ��
        int aim_idx = clip(round(25), 0, rptsn_num-1);
        //��Ԥê��λ��
        int aim_idx_near = clip(round(3), 0, rptsn_num-1);
        //����Ԥê��λ��
        int aim_idx_mid = clip(round(aim_distance*rptsn_num), 0, rptsn_num-1);

        //����Զê��ƫ��ֵ
        float dx1 = rptsn[aim_idx][0] - cx;
        float dy1 = cy - rptsn[aim_idx][1] + 0.2 * pixel_per_meter;
        float dn1 = sqrt(dx1 * dx1 + dy1 * dy1);
        //�����ê��ƫ��ֵ
        float dx2 = rptsn[aim_idx_near][0] - cx;
        float dy2 = cy - rptsn[aim_idx_near][1] + 0.2 * pixel_per_meter;
        float dn2 = sqrt(dx2 * dx2 + dy2 * dy2);
        //��������ê��ƫ��ֵ
        float dx3 = rptsn[aim_idx_mid][0] - cx;
        float dy3 = cy - rptsn[aim_idx_mid][1] + 0.2 * pixel_per_meter / gengshuaige;
        float dn3 = sqrt(dx3 * dx3 + dy3 * dy3);

        //�������㷨(����ƫ��)
        pure_angle_far = -atanf(pixel_per_meter * 2 * 0.2 * dx1 / dn1 / dn1) / PI * 180 / SMOTOR_RATE;
        pure_angle_near = -atanf(pixel_per_meter * 2 * 0.2 * dx2 / dn2 / dn2) / PI * 180 / SMOTOR_RATE;
        pure_angle_mid = -atanf(pixel_per_meter * 2 * 0.2 * dx3 / dn3 / dn3) / PI * 180 / SMOTOR_RATE ;

        if(circle_type!=CIRCLE_NONE) {
            if(circle_type == CIRCLE_LEFT_IN) pure_angle_mid*=1.2;
            if(circle_type == CIRCLE_RIGHT_IN) pure_angle_mid*=1.6;
//            if(circle_type == CIRCLE_LEFT_OUT) pure_angle_mid+=5;

        }

        if(ruku_type!=RUKU_NONE) {
            if(ruku_type==RUKU_BEGIN_RIGHT) pure_angle_mid-=10;
            if(ruku_type==RUKU_BEGIN_LEFT) pure_angle_mid+=10;
//            if(circle_type==CIRCLE_LEFT_OUT) pure_angle_mid+=5;

        }

        pure_angle = pure_angle_mid;
    }
}

void aim_distance_sport(float speed,float xishu){
//    aim_distance = 0.6+0.2*speed/220;
    if(track_type==TRACK_LEFT) {
        if(speed<=100) {
            aim_distance = 0.65;
        }else;
//            aim_distance = (speed>180)?1:0.65*speed/180;

    }
    else if(track_type==TRACK_RIGHT) {
        if(speed<=100) {
            aim_distance = 0.6;
        }else;
//            aim_distance = (speed>180)?1:0.6*speed/180;
    }
}

//������һ��
void Yuan_huan_wait(void) {
    //���յ�ǰ����ѯ�ź�
    if(read_ceshi==6){
        if(circle_type>=5) {
            wireless_ch573_send_byte(61);
        }else {
            wireless_ch573_send_byte(60);
        }
    }
}

void TELL(void){

    //������
     if(ruku_type==RUKU_NONE) {
//    if(first_type==FIRST_NONE)
//    check_chongdian();
//    if(first_type==CHARGE_OVER) {
        //�����Ͻ���Ԫ���б�
    if(slope_type==SLOPE_NONE&&luzhang_type==LUZHANG_NONE) {
        if(duanlu_type==DUANLU_NONE && duanlu_type==DUANLU_NONE && slope_type==SLOPE_NONE)
        check_ruku();
        if(duanlu_type==DUANLU_NONE && luzhang_type==LUZHANG_NONE && cross_type==CROSS_NONE)
            check_duanlu2();
        if(cross_type==CROSS_NONE && duanlu_type==DUANLU_NONE && luzhang_type==LUZHANG_NONE &&circle_type==CIRCLE_NONE&&ruku_type==RUKU_NONE)
            check_cross();
        if(circle_type==CIRCLE_NONE && duanlu_type==DUANLU_NONE && cross_type==CROSS_NONE)
            check_circle();
    }
        if(luzhang_type==LUZHANG_NONE && duanlu_type==DUANLU_NONE && slope_type==SLOPE_NONE)
            check_zhangai();
    }
//    }

    //������ȼ����
    if(circle_type!=CIRCLE_NONE && ruku_type!=RUKU_NONE ) {
        circle_type = CIRCLE_NONE;
    }


    if(cross_type!=CROSS_NONE&&ruku_type!=RUKU_NONE) {
        cross_type=CROSS_NONE;
        shexiangtou_or_dianci = true;
    }

    //����
    if(first_type != FIRST_NONE && first_type!=CHARGE_OVER) run_chongdian2();
    if(duanlu_type != DUANLU_NONE) run_duanlu();
    if(chuku_type != CHUKU_NONE) run_chuku();
    if(slope_type != SLOPE_NONE) run_slope();
    if (cross_type!=CROSS_NONE)  run_cross();
    if (circle_type != CIRCLE_NONE) run_circle();
    if (ruku_type != RUKU_NONE)  run_ruku();
    if (luzhang_type != LUZHANG_NONE)  {
        if(RIGHT_LZ)
            run_luzhang_RIGHT();
        else run_luzhang_LEFT();
    }
}

void TELL_dianci(void){

    //������
     if(ruku_type==RUKU_NONE) {
    if(first_type==FIRST_NONE)
    check_chongdian();
    if(first_type==CHARGE_OVER) {
    //�����Ͻ���Ԫ���б�
    //���γ�粻�ɽ�������Ԫ��ʶ��
    if (chongdian_low==CW_NONE){
    if(slope_type==SLOPE_NONE&&luzhang_type==LUZHANG_NONE) {
        check_ruku();
        if(circle_type==CIRCLE_NONE)
            check_circle();
    }
        if(luzhang_type==LUZHANG_NONE && slope_type==SLOPE_NONE)
            check_zhangai();
        check_charge_low();
    }
    }
    }

    //������ȼ����
    if(circle_type!=CIRCLE_NONE && ruku_type!=RUKU_NONE ) {
        circle_type = CIRCLE_NONE;
        shexiangtou_or_dianci = true;
    }

    //����
    if(first_type != FIRST_NONE && first_type!=CHARGE_OVER) run_chongdian2();
    if(slope_type != SLOPE_NONE) run_slope();
    if (circle_type != CIRCLE_NONE) run_circle();
    if (ruku_type != RUKU_NONE)  run_ruku();
    if (chongdian_low != CW_NONE)  run_charge_low();
    if (luzhang_type != LUZHANG_NONE)  {
        if(RIGHT_LZ)
            run_luzhang_RIGHT();
        else run_luzhang_LEFT();
    }
}
