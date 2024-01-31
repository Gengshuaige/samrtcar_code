#include "zf_common_headfile.h"

enum cross_type_e cross_type = CROSS_NONE;
enum chuku_type_e chuku_type = CHUKU_NONE;
enum ruku_type_e ruku_type = RUKU_NONE;
enum zhidao_type_e zhidao_type = ZHIDAO_NONE;

//编码器值，用于防止一些重复触发等。
int64_t cross_encoder;

bool far_Lpt0_found, far_Lpt1_found;
int far_Lpt0_rpts0s_id, far_Lpt1_rpts1s_id;

// 以下定义为十字寻远线设定
uint8 far_ipts0[MY_H-20][2];
uint8 far_ipts1[MY_H-20][2];
uint8 far_ipts0_num, far_ipts1_num;

uint8 far_ipts0y[MY_H][2];
uint8 far_ipts1y[MY_H][2];
uint8 far_ipts0_num_y, far_ipts1_num_y;

uint8 far_rpts0[MY_H][2];
uint8 far_rpts1[MY_H][2];
int far_rpts0_num, far_rpts1_num;

uint8 far_rpts0b[MY_H][2];
uint8 far_rpts1b[MY_H][2];
int far_rpts0b_num, far_rpts1b_num;

uint8 far_rpts0s[MY_H][2];
uint8 far_rpts1s[MY_H][2];
int far_rpts0s_num, far_rpts1s_num;

float far_rpts0a[MY_H];
float far_rpts1a[MY_H];
int far_rpts0a_num, far_rpts1a_num;

float far_rpts0an[MY_H];
float far_rpts1an[MY_H];
int far_rpts0an_num, far_rpts1an_num;

int not_have_line = 0;

int far_x1 = 40, far_x2 = 188 - 40, far_y1, far_y2;
int no_left_line = 0, no_right_line = 0;

uint8 shizi_num;

//-------------------------------------------------------------------------------------------------------------------
//  主题:      十字
//  功能:      略
//  样例:      略
//  作者:      耿帅哥
//-------------------------------------------------------------------------------------------------------------------
bool find_shizi = false;
int16 temp_shizi;
bool shiziORcircle_left,shiziORcircle_right;
int shizi_num_JJJ;

bool check_far_L_point(uint8 x,uint8 y,uint8 flag) {
    bool white_found = false;

    far_ipts0_num = sizeof(far_ipts0) / sizeof(far_ipts0[0]);
    far_ipts1_num = sizeof(far_ipts1) / sizeof(far_ipts1[0]);
    int far_y;

    if(flag==0) {
        //全白far_x1 = 0,从边界找
            for (; y > 0; y--) {
                //先白后黑
                y = clip(y,0,69);
                x = clip(x,0,187);
                if (mt9v03x_image_Bandw[y][x]==255) { white_found = true; }
                if (mt9v03x_image_Bandw[y][x]==0 && white_found) {
                    far_y = y;
                    break;
                }
            }

            //从找到跳变点位置开始搜线
            far_y = clip(far_y,0,68);
            if (mt9v03x_image_Bandw[far_y+1][x]==255)
                findline_lefthand_adaptive(mt9v03x_image_Bandw[0], x, far_y+1, far_ipts0, &far_ipts0_num);
            else far_ipts0_num = 0;
            image_perspective_corrective_Forward2(far_ipts0,far_ipts0_num_y,far_ipts0y);
            far_ipts0_num_y = far_ipts0_num;
            far_rpts0s_num = sizeof(far_ipts0y) / sizeof(far_ipts0y[0]);
            resample_points2_L(far_ipts0y, far_ipts0_num_y, far_rpts0s, &far_rpts0s_num, sample_dist * pixel_per_meter);
            //边线局部角度变化率
            local_angle_points0(far_rpts0s, far_rpts0s_num, far_rpts0a, (int) round(angle_dist / sample_dist));
            far_rpts0a_num = far_rpts0s_num;
            //角度变化率非极大抑制
            nms_angle0(far_rpts0a, far_rpts0a_num, far_rpts0an, (int) round(angle_dist / sample_dist) * 2 + 1);
            far_rpts0an_num = far_rpts0a_num;
            //找远线上的L角点
            far_Lpt0_found = false;
            for (int i=0; i<far_rpts0s_num; i++) {
                    if (far_rpts0an[i]==0) continue;
                    int im1 = clip(i-(int)round(angle_dist/sample_dist), 0, far_rpts0s_num-1);
                    int ip1 = clip(i+(int)round(angle_dist/sample_dist), 0, far_rpts0s_num-1);
                    float conf = fabs(far_rpts0a[i]) - (fabs(far_rpts0a[im1]) + fabs(far_rpts0a[ip1])) / 2;
//                    tft180_show_float(0, 60, conf, 6 ,2);
                    if (1<conf && conf<2 && i<100) {
                        far_Lpt0_rpts0s_id = i;
                        far_x6 = nitou3_col[(int)far_rpts0s[far_Lpt0_rpts0s_id][1]*MT9V03X_W+(int)rpts0s[far_Lpt0_rpts0s_id][0]];
                        far_y6 = nitou4_row[(int)far_rpts0s[far_Lpt0_rpts0s_id][1]*MT9V03X_W+(int)rpts0s[far_Lpt0_rpts0s_id][0]];
                        if(far_y<far_y6)
                            shiziORcircle_left = true;
                        else
                            shiziORcircle_left = false;
                        far_Lpt0_found = true;
                        break;
                        }

                }
            return far_Lpt0_found;
    }else{
        //全白far_x1 = 0,从边界找
             for (; y > 0; y--) {
                 //先白后黑
                 y = clip(y,0,69);
                 x = clip(x,0,187);
                 if (mt9v03x_image_Bandw[y][x]==255) { white_found = true; }
                 if (mt9v03x_image_Bandw[y][x]==0 && white_found) {
                     far_y = y;
                         break;
                     }
                 }

                 far_y = clip(far_y,0,68);
                    //从找到跳变点位置开始搜线
                    if (mt9v03x_image_Bandw[far_y+1][x]==255)
                        findline_righthand_adaptive(mt9v03x_image_Bandw[0], x, far_y+1, far_ipts1, &far_ipts1_num);
                    else far_ipts1_num = 0;
                    //边界逆透视
                    image_perspective_corrective_Forward2(far_ipts1,far_ipts1_num_y,far_ipts1y);
                    far_ipts1_num_y = far_ipts1_num;
                    //边线等距采样
                    far_rpts1s_num = sizeof(far_ipts1y) / sizeof(far_ipts1y[0]);
                    resample_points2_R(far_ipts1y, far_ipts1_num_y, far_rpts1s, &far_rpts1s_num, sample_dist * pixel_per_meter);
                    //边线局部角度变化率
                    local_angle_points1(far_rpts1s, far_rpts1s_num, far_rpts1a, (int) round(angle_dist / sample_dist));
                    far_rpts1a_num = far_rpts1s_num;
                    //角度变化率非极大抑制
                    nms_angle1(far_rpts1a, far_rpts1a_num, far_rpts1an, (int) round(angle_dist / sample_dist) * 2 + 1);
                    far_rpts1an_num = far_rpts1a_num;
                    //找远线上的L角点
                    far_Lpt1_found = false;
                       for (int i=0; i<far_rpts1s_num; i++) {
                           if (far_rpts1an[i]==0) continue;
                           int im1 = clip(i-(int)round(angle_dist/sample_dist), 0, far_rpts1s_num-1);
                           int ip1 = clip(i+(int)round(angle_dist/sample_dist), 0, far_rpts1s_num-1);
                           float conf = fabs(far_rpts1a[i]) - (fabs(far_rpts1a[im1]) + fabs(far_rpts1a[ip1])) / 2;
//                           tft180_show_float(0, 80, conf, 6 ,2);
                           if (1<conf && conf<2 && i<100) {
                               far_Lpt1_rpts1s_id = i;
//                               tft180_show_int(0, 130, far_Lpt1_rpts1s_id, 6);
                               far_x7 = nitou3_col[(int)far_rpts1s[far_Lpt1_rpts1s_id][1]*MT9V03X_W+(int)rpts1s[far_Lpt1_rpts1s_id][0]];
                               far_y7 = nitou4_row[(int)far_rpts1s[far_Lpt1_rpts1s_id][1]*MT9V03X_W+(int)rpts1s[far_Lpt1_rpts1s_id][0]];
                               if(far_y<far_y7)
                                   shiziORcircle_right = true;
                               else
                                   shiziORcircle_right = false;
                               far_Lpt1_found = true;
                               break;
                               }
                       }
                       return far_Lpt1_found;
    }
}

void check_cross(void) {
    bool Xfound = Lpt0_found && Lpt1_found;
    //判断丢线
    if (rpts0s_num<6) { no_left_line++; }
    if (rpts1s_num<6) { no_right_line++; }

    if(Xfound){
        //L角点的二次检查
        if(Lpt1_rpts1s_id<10 && Lpt0_rpts0s_id<10 && check_far_whitepoint(x6,y6) && check_far_whitepoint(x7,y7))
        {
            cross_type = CROSS_BEGIN;

//            bibibi(1);
        }


    } else if ((Lpt0_found  && no_right_line>2 )) {//&& Lpt0_rpts0s_16>8
        if(Lpt0_rpts0s_id<15 && check_far_L_point(x6,y6-1,0)&& check_far_whitepoint(x6,y6)) {
//            draw_point(far_ipts0[Lpt0_rpts0s_id][0]/2, far_ipts0[Lpt0_rpts0s_id][1]/2, RGB565_RED);
            if(shiziORcircle_left == true){
//                bibibi(1);
                cross_type = CROSS_BEGIN_LEFT;

            }else {
//                circle_type = CIRCLE_LEFT_BEGIN;
                ;
//                bibibi(1);
            }
            no_right_line = 0;

        }
    }else if(Lpt1_found&&no_left_line>2) {//&&Lpt1_rpts1s_16!=111&&Lpt1_rpts1s_16>8
        if(Lpt1_rpts1s_id<15 && check_far_L_point(x7,y7-1,1) && check_far_whitepoint(x7,y7)) {
//            draw_point(far_ipts1[Lpt1_rpts1s_id][0]/2, far_ipts1[Lpt1_rpts1s_id][1]/2, RGB565_RED);
            if(shiziORcircle_right == true){
            cross_type = CROSS_BEGIN_RIGHT;

//            bibibi(1);
            }else {
//                circle_type = CIRCLE_RIGHT_BEGIN;
                ;
//                bibibi(1);
            }
            no_left_line = 0;
        }
    }
}

void run_cross() {
    //截断处理
    if (cross_type == CROSS_BEGIN || cross_type == CROSS_BEGIN_LEFT || cross_type == CROSS_BEGIN_RIGHT) {
//        bibibi(1);
        if (Lpt0_found) {
                    rptsc0_num = rpts0s_num = Lpt0_rpts0s_id-3;
                }
                if (Lpt1_found) {
                    rptsc1_num = rpts1s_num = Lpt1_rpts1s_id-5;
                }
        shexiangtou_or_dianci = false;
        if (( (Lpt0_rpts0s_id < 3 || Lpt1_rpts1s_id < 3)) || (rpts1s_num <5 && rpts0s_num<5)) {
            cross_type = CROSS_IN;
            if(cross_type==CROSS_BEGIN_LEFT)
                cross_type = CROSS_IN_LEFT;
            if(cross_type==CROSS_BEGIN_RIGHT)
                cross_type = CROSS_IN_RIGHT;
        }
    }
        if (cross_type == CROSS_IN || cross_type==CROSS_IN_RIGHT || cross_type==CROSS_IN_LEFT) {
        if (rpts1s_num < 3 && rpts0s_num < 3) { not_have_line++; }
        if((rpts1s_num > 3 && rpts0s_num > 3) && not_have_line > 2) {
            cross_type = CROSS_NONE;
            shexiangtou_or_dianci = true;
            bibibi(0);
            not_have_line = 0;
        }
    }
}

//-------------------------------------------------------------------------------------------------------------------
//  主题:      出库+入库
//  功能:      略
//  样例:      略
//  作者:      耿帅哥
//-------------------------------------------------------------------------------------------------------------------
int16 chuku_Yaw;
//首次双L角点,出库
void check_chuku(void) {
    bool Xfound = Lpt0_found && Lpt1_found;
    if (Xfound){
        chuku_type = CHUKU_BEGIN;
        chuku_Yaw = Yaw;
    }
}

void run_chuku(void) {
    if(chuku_fangxiang==RIGHT) {
        track_type = TRACK_RIGHT;
    }else {
        track_type = TRACK_LEFT;
    }
    if(is_straight1 && is_straight1 && !Lpt0_found && !Lpt1_found && ipts0_num>50)
        chuku_type = CHUKU_OVER;
}

//斑马线判别
bool check_banmaxian0(uint8 x,uint8 y,uint8 d) {
    uint8 i,j;
    uint8 banmaxian0_num = 0;
    //矩形区包含全部斑马线
//    draw_point((x-30)/2,(y-30)/2,RGB565_RED);
//    draw_point((x-d)/2,(y-40)/2,RGB565_RED);
//    draw_point((x-30)/2,(y-40)/2,RGB565_RED);
//    draw_point((x-d)/2,(y-30)/2,RGB565_RED);
    if(x<MT9V03X_W && x-d>0 && y<MT9V03X_H && y>40) {
        for(i=x-30;i>x-d;i--){
            for(j=y-30;j>y-40;j--) {
                if(mt9v03x_image_Bandw[j][i]!=mt9v03x_image_Bandw[j][i-1]){
//                    tft180_draw_point(i/2, j/2, RGB565_BLUE);
                    banmaxian0_num++;
                    }
                }
            }

//        tft180_show_int(0, 120, banmaxian0_num, 4);
        if(banmaxian0_num>20){
            banmaxian0_num = 0;
              return true;
        }else {
              banmaxian0_num = 0;
              return false;
        }
    }
    return false;
}

bool check_banmaxian1(uint8 x,uint8 y,uint8 d) {
    uint8 i,j;
    uint8 banmaxian1_num = 0;
    //矩形区包含全部斑马线
//    draw_point((x+30)/2,(y-30)/2,RGB565_GREEN);
//    draw_point((x+30)/2,(y-40)/2,RGB565_GREEN);
//    draw_point((x+d)/2,(y-30)/2,RGB565_GREEN);
//    draw_point((x+d)/2,(y-40)/2,RGB565_GREEN);
    if(x>-30 && x+d<MT9V03X_W && y<MT9V03X_H && y>40) {
        for(i=x+30;i<x+d;i++){
            for(j=y-30;j>y-40;j--) {
                if(mt9v03x_image_Bandw[j][i]!=mt9v03x_image_Bandw[j][i-1]) {
                    banmaxian1_num++;
//                    tft180_draw_point(i/2, j/2, RGB565_BLUE);
                }
            }
        }
//        tft180_show_int(0, 120, banmaxian1_num, 4);
        if(banmaxian1_num>20){
            banmaxian1_num = 0;
              return true;
        }else {
            banmaxian1_num = 0;
            return false;
        }
    }
    return false;
}

int16 ruku_yaw;
int64_t encoder_ruku;

void check_ruku(void) {
    if(is_straight0 && Lpt1_found && ruku_type==RUKU_NONE){
        uint8 Lpt1_rpts1s_id_cope = Lpt1_rpts1s_id;
        int x0,y0;
//        draw_point(ipts0y[Lpt1_rpts1s_id_cope][0]/2,ipts0y[Lpt1_rpts1s_id_cope][1]/2,RGB565_BLUE);
        x0 = nitou3_col[(int)ipts1y[Lpt1_rpts1s_id_cope][1]*MT9V03X_W+(int)ipts1y[Lpt1_rpts1s_id_cope][0]];
        y0 = nitou4_row[(int)ipts1y[Lpt1_rpts1s_id_cope][1]*MT9V03X_W+(int)ipts1y[Lpt1_rpts1s_id_cope][0]];
//        draw_point(x0/2,y0/2,RGB565_RED);
        if(check_banmaxian0(x0,y0,90) && Lpt1_rpts1s_id_cope<10){
//            bibibi(1);
            ruku_type = RUKU_BEGIN_RIGHT;
            aim_distance = 0.1;
            ruku_yaw = Yaw;
        }
    } else if(is_straight1 && Lpt0_found && ruku_type==RUKU_NONE){
        uint8 Lpt0_rpts0s_id_cope = Lpt0_rpts0s_id;
        int x1,y1;
//        draw_point(ipts0y[Lpt1_rpts1s_id_cope][0]/2,ipts0y[Lpt1_rpts1s_id_cope][1]/2,RGB565_BLUE);
        x1 = nitou3_col[(int)ipts0y[Lpt0_rpts0s_id_cope][1]*MT9V03X_W+(int)ipts0y[Lpt0_rpts0s_id_cope][0]];
        y1 = nitou4_row[(int)ipts0y[Lpt0_rpts0s_id_cope][1]*MT9V03X_W+(int)ipts0y[Lpt0_rpts0s_id_cope][0]];
//        draw_point(x0/2,y0/2,RGB565_RED);
        if(check_banmaxian1(x1,y1,90)&& Lpt0_rpts0s_id_cope<10){
            ruku_type = RUKU_BEGIN_LEFT;
            aim_distance = 0.1;
            ruku_yaw = Yaw;
        }
    }
}

uint8 Shache_flag;
int no_ku_left_line, no_ku_right_line;

void run_ruku(void) {
    //右库
    if(ruku_type == RUKU_BEGIN_RIGHT) {
        track_type = TRACK_LEFT;
        if(rpts1s_num<5)
            no_ku_right_line++;
        if(no_ku_right_line>2) {
            ruku_type = RUKU_IN_RIGHT;
        }

    }else if(ruku_type==RUKU_IN_RIGHT) {
//        encoder_ruku += get_total_encoder();
        if(Yaw-ruku_yaw<-55)
            ruku_type = RUKU_OVER;
    }

    //左库
    else if(ruku_type == RUKU_BEGIN_LEFT) {
        track_type = TRACK_RIGHT;
        if(rpts0s_num<5)
            no_ku_left_line++;
        if(no_ku_left_line>2) {
            ruku_type = RUKU_IN_LEFT;
            no_ku_left_line = 0;
        }
    }else if(ruku_type==RUKU_IN_LEFT) {
//        encoder_ruku += get_total_encoder();
        if(Yaw-ruku_yaw>60)
            ruku_type = RUKU_OVER;
    }else if(ruku_type==RUKU_OVER) {
        Shache_flag = 1;
        system_delay_ms(1000);
        OFF_motor = true;
    }
}

bool STOP_stop_flag = false;

//-------------------------------------------------------------------------------------------------------------------
//  主题:      断路
//  功能:      略
//  样例:      略
//  作者:      耿帅哥
//-------------------------------------------------------------------------------------------------------------------

int64_t encoder_duanlu;
enum duanlu_type_e duanlu_type;
uint8 erzhihuayuzhi_duanlu;
int duanlu_num;

bool check_bianjie_H(uint8 pts_in0[][2],uint8 pts_in1[][2],uint8 num,float x) {
    if(ipts0_num_y>num+1&&ipts1_num_y>num+1) {
        for(uint8 i=1;i<num;i++) {
            if(fabs(fabs(pts_in1[i][0]-pts_in0[i][0])-x)>3)
                return false;
        }
        return true;
    }
    else return false;
}

void check_duanlu1(void) {
    if(ipts0_num>20&&ipts1_num>20) {
        if(ipts0[ipts0_num-1][0]>ipts1[ipts1_num-1][0]
            &&dl1a_distance_mm>1000)
            //截断处理
//            if (Lpt0_found) {
//                rptsc0_num = rpts0s_num = Lpt0_rpts0s_id-3;
//            }
//            if (Lpt1_found) {
//                rptsc1_num = rpts1s_num = Lpt1_rpts1s_id-5;
//            }
            duanlu_type = DUANLU_BEGIN;
    }
}

void check_duanlu2(void) {
    bool Xfound = Lpt0_found && Lpt1_found;
    if(Xfound && !check_far_whitepoint(x6,y6) && !check_far_whitepoint(x7,y7) && duanlu_type==DUANLU_NONE
            && ((Lpt0_rpts0s_id<10 && Lpt1_rpts1s_id<10)||(x6==x7&&y6==y7))
            &&dl1a_distance_mm>1000) {

        duanlu_type = DUANLU_BEGIN;
        erzhihuayuzhi_duanlu = erzhihuayuzhi;
    }
}

void run_duanlu(void) {
    if(duanlu_type==DUANLU_BEGIN ) {

        shexiangtou_or_dianci = false;
        duanlu_type = DUANLU_IN1;
//        bibibi(1);
    }else if(duanlu_type==DUANLU_IN1) {
        if(rpts0s_num<10 && rpts1s_num<10)
            duanlu_type=DUANLU_IN2;
    }else if (duanlu_type==DUANLU_IN2){
        encoder_duanlu += get_total_encoder();
        if(check_bianjie_H(ipts0y,ipts1y,15,31)&& encoder_duanlu>7000) {
            encoder_duanlu = 0;
            shexiangtou_or_dianci = true;
            duanlu_type = DUANLU_NONE;
            duanlu_num++;
        }
    }
}

















