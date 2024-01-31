#include "zf_common_headfile.h"
#include "assert.h"

/*******************************************************************/
float Mid_W = 0;
float Mid_D = 0;
uint8_t dat = 0;

/*******************************************************************/

uint8 mid_line = 94;

//-------------------------------------------------------------------------------------------------------------------
//  主题:      九宫格画点
//  功能:      略
//  样例:      略
//  作者:      耿帅哥
//-------------------------------------------------------------------------------------------------------------------
void draw_point(uint x,uint8 y,uint16 color)
{
    if(x==0)x+=1;
    if(x==MT9V03X_W/2-1)x-=1;
    if(y==0)y+=1;
    if(y==MT9V03X_H/2-1)y-=1;
    uint8 num[3] = {1,0,-1};

    for(uint8 k=0;k<3;k++){
        uint8 x1 = x+num[k];
        for(uint8 z=0;z<3;z++){
            uint8 y1 = y+num[z];
            tft180_draw_point(x1, y1, color);
        }
    }
}

const int dir_front[4][2] = {{0,  -1},
                             {1,  0},
                             {0,  1},
                             {-1, 0}};
const int dir_frontleft[4][2] = {{-1, -1},
                                 {1,  -1},
                                 {1,  1},
                                 {-1, 1}};
const int dir_frontright[4][2] = {{1,  -1},
                                  {1,  1},
                                  {-1, 1},
                                  {-1, -1}};
//-------------------------------------------------------------------------------------------------------------------
//  主题:      左手迷宫巡线
//  功能:      基于迷宫法(种植生长扫线)寻找边界
//  样例:      略
//  作者:      耿帅哥
//-------------------------------------------------------------------------------------------------------------------
void findline_lefthand_adaptive(uint8 index[][MT9V03X_W], uint8 x, uint8 y, uint8 pts[][2], uint8 *num) {

    int step = 0, dir = 0, turn = 0;

    while(step<*num && x>3 && x<MT9V03X_W-1-3 && y>0+3 && y<MT9V03X_H-1-3 && turn<4) {

        int front_value = index[y+dir_front[dir][1]][x+dir_front[dir][0]];
        int frontleft_value = index[y + dir_frontleft[dir][1]][x + dir_frontleft[dir][0]];
        if (front_value == 0) {
            dir = (dir + 1) % 4;
            turn++;
        } else if (frontleft_value == 0) {
            x += dir_front[dir][0];
            y += dir_front[dir][1];
            pts[step][0] = x;
            pts[step][1] = y;
            step++;
            turn = 0;
        } else {
            x += dir_frontleft[dir][0];
            y += dir_frontleft[dir][1];
            dir = (dir + 3) % 4;
            pts[step][0] = x;
            pts[step][1] = y;
            step++;
            turn = 0;
        }
//        draw_point(x/2,y/2,RGB565_RED);
    }
    *num = step;
//    tft180_show_int(0, 80, step, 3);
}

//-------------------------------------------------------------------------------------------------------------------
//  主题:      右手迷宫巡线
//  功能:      基于迷宫法(种植生长扫线)寻找边界
//  样例:      略
//  作者:      耿帅哥
//-------------------------------------------------------------------------------------------------------------------
void findline_righthand_adaptive(uint8 index[][MT9V03X_W],  uint8 x, uint8 y,uint8 pts[][2],uint8 *num) {

    int step = 0, dir = 0, turn = 0;

    while( step < *num && x > 3 && x < MT9V03X_W  - 1 - 3 && y > 0+3 && y < MT9V03X_H - 1 - 3 && turn < 4) {

        int front_value = index[ y + dir_front[dir][1]][x + dir_front[dir][0]];
        int frontright_value = index[y + dir_frontright[dir][1]][x + dir_frontright[dir][0]];

        if (front_value == 0) {
                    dir = (dir + 3) % 4;
                    turn++;
                } else if (frontright_value == 0) {
                    x += dir_front[dir][0];
                    y += dir_front[dir][1];
                    pts[step][0] = x;
                    pts[step][1] = y;
                    step++;
                    turn = 0;
                } else {
                    x += dir_frontright[dir][0];
                    y += dir_frontright[dir][1];
                    dir = (dir + 1) % 4;
                    pts[step][0] = x;
                    pts[step][1] = y;
                    step++;
                    turn = 0;
                }
//        draw_point(x/2,y/2,RGB565_BLUE);
    }
    *num = step;
    //tft180_show_int(0, 80, step, 3);
}

//-------------------------------------------------------------------------------------------------------------------
//  主题:      三角滤波
//  功能:      使边线更加平滑
//  样例:      略
//  作者:      耿帅哥
//-------------------------------------------------------------------------------------------------------------------
void blur_points0(uint8 pts_in[][2], uint8 num, uint8 pts_out[][2], int kernel) {
    assert(kernel % 2 == 1);

    int half = kernel / 2;
    for (int i = 0; i < num; i++) {
        pts_out[i][0] = pts_out[i][1] = 0;
        for (int j = -half; j <= half; j++) {
            pts_out[i][0] += pts_in[clip(i + j, 0, num - 1)][0] * (half + 1 - abs(j));
            pts_out[i][1] += pts_in[clip(i + j, 0, num - 1)][1] * (half + 1 - abs(j));
        }
        pts_out[i][0] /= (2 * half + 2) * (half + 1) / 2;
        pts_out[i][1] /= (2 * half + 2) * (half + 1) / 2;
        //测试画点
        draw_point(pts_out[i][0]/2,pts_out[i][1]/2,RGB565_RED);
    }
}

void blur_points1(uint8 pts_in[][2], uint8 num, uint8 pts_out[][2], int kernel) {
    assert(kernel % 2 == 1);

    int half = kernel / 2;
    for (int i = 0; i < num; i++) {
        pts_out[i][0] = pts_out[i][1] = 0;
        for (int j = -half; j <= half; j++) {
            pts_out[i][0] += pts_in[clip(i + j, 0, num - 1)][0] * (half + 1 - abs(j));
            pts_out[i][1] += pts_in[clip(i + j, 0, num - 1)][1] * (half + 1 - abs(j));
        }
        pts_out[i][0] /= (2 * half + 2) * (half + 1) / 2;
        pts_out[i][1] /= (2 * half + 2) * (half + 1) / 2;
        //测试画点
        draw_point(pts_out[i][0]/2,pts_out[i][1]/2,RGB565_BLUE);
    }
}

//-------------------------------------------------------------------------------------------------------------------
//  主题:      等距采样
//  功能:      将数组点间距离相等,间隔为dist
//  样例:      略
//  作者:      耿帅哥
//-------------------------------------------------------------------------------------------------------------------
void resample_points2_R(uint8 pts_in[][2], uint8 num1, uint8 pts_out[][2], int *num2, float dist) {
    if (num1 < 0) {
        *num2 = 0;
        return;
    }

    pts_out[0][0] = pts_in[0][0];
    pts_out[0][1] = pts_in[0][1];
    int len = 1;
    for (int i = 0; i < num1 - 1 && len < *num2; i++) {
        float x0 = pts_in[i][0];
        float y0 = pts_in[i][1];
        float x1 = pts_in[i + 1][0];
        float y1 = pts_in[i + 1][1];

        do {
            float x = pts_out[len - 1][0];
            float y = pts_out[len - 1][1];

            float dx0 = x0 - x;
            float dy0 = y0 - y;
            float dx1 = x1 - x;
            float dy1 = y1 - y;

            float dist0 = sqrt(dx0 * dx0 + dy0 * dy0);
            float dist1 = sqrt(dx1 * dx1 + dy1 * dy1);

            float r0 = (dist1 - dist) / (dist1 - dist0);
            float r1 = 1 - r0;

            if (r0 < 0 || r1 < 0) break;
            x0 = x0 * r0 + x1 * r1;
            y0 = y0 * r0 + y1 * r1;
            pts_out[len][0] = x0;
            pts_out[len][1] = y0;
            //测试画点
            if(BKEY__1)
                tft180_draw_point(x0/2,y0/2,RGB565_BLUE);
            len++;
        } while (len < *num2);
//        tft180_show_int(0, 60, num1, 6 );
    }
    *num2 = len;
}

void resample_points2_L(uint8 pts_in[][2], uint8 num1, uint8 pts_out[][2], uint8 *num2, float dist) {
    if (num1 < 0) {
        *num2 = 0;
        return;
    }

    pts_out[0][0] = pts_in[0][0];
    pts_out[0][1] = pts_in[0][1];
    int len = 1;
    for (int i = 0; i < num1 - 1 && len < *num2; i++) {
        float x0 = pts_in[i][0];
        float y0 = pts_in[i][1];
        float x1 = pts_in[i + 1][0];
        float y1 = pts_in[i + 1][1];

        do {
            float x = pts_out[len - 1][0];
            float y = pts_out[len - 1][1];

            float dx0 = x0 - x;
            float dy0 = y0 - y;
            float dx1 = x1 - x;
            float dy1 = y1 - y;

            float dist0 = sqrt(dx0 * dx0 + dy0 * dy0);
            float dist1 = sqrt(dx1 * dx1 + dy1 * dy1);

            float r0 = (dist1 - dist) / (dist1 - dist0);
            float r1 = 1 - r0;

            if (r0 < 0 || r1 < 0) break;
            x0 = x0 * r0 + x1 * r1;
            y0 = y0 * r0 + y1 * r1;
            pts_out[len][0] = x0;
            pts_out[len][1] = y0;
            //测试画点
            if(BKEY__1)
                tft180_draw_point(x0/2,y0/2,RGB565_RED);
            len++;
        } while (len < *num2);
    }
    *num2 = len;
}



//-------------------------------------------------------------------------------------------------------------------
//  主题:      算角
//  功能:      计算各个边线点的角度
//  样例:      略
//  作者:      耿帅哥
//-------------------------------------------------------------------------------------------------------------------
void local_angle_points0(uint8 pts_in[][2], int num, float angle_out[], int dist) {
    for (int i = 0; i < num; i++) {
        if (i <= 0 || i >= num - 1) {
            angle_out[i] = 0;
            continue;
        }
        float dx1 = pts_in[i][0] - pts_in[clip(i - dist, 0, num - 1)][0];
        float dy1 = pts_in[i][1] - pts_in[clip(i - dist, 0, num - 1)][1];
        float dn1 = sqrtf(dx1 * dx1 + dy1 * dy1);
        float dx2 = pts_in[clip(i + dist, 0, num - 1)][0] - pts_in[i][0];
        float dy2 = pts_in[clip(i + dist, 0, num - 1)][1] - pts_in[i][1];
        float dn2 = sqrtf(dx2 * dx2 + dy2 * dy2);
        float c1 = dx1 / dn1;
        float s1 = dy1 / dn1;
        float c2 = dx2 / dn2;
        float s2 = dy2 / dn2;
        angle_out[i] = atan2f(c1 * s2 - c2 * s1, c2 * c1 + s2 * s1);
    }
}

void local_angle_points1(uint8 pts_in[][2], int num, float angle_out[], int dist) {
    for (int i = 0; i < num; i++) {
        if (i <= 0 || i >= num - 1) {
            angle_out[i] = 0;
            continue;
        }
        float dx1 = pts_in[i][0] - pts_in[clip(i - dist, 0, num - 1)][0];
        float dy1 = pts_in[i][1] - pts_in[clip(i - dist, 0, num - 1)][1];
        float dn1 = sqrtf(dx1 * dx1 + dy1 * dy1);
        float dx2 = pts_in[clip(i + dist, 0, num - 1)][0] - pts_in[i][0];
        float dy2 = pts_in[clip(i + dist, 0, num - 1)][1] - pts_in[i][1];
        float dn2 = sqrtf(dx2 * dx2 + dy2 * dy2);
        float c1 = dx1 / dn1;
        float s1 = dy1 / dn1;
        float c2 = dx2 / dn2;
        float s2 = dy2 / dn2;
        angle_out[i] = atan2f(c1 * s2 - c2 * s1, c2 * c1 + s2 * s1);
    }
}

//-------------------------------------------------------------------------------------------------------------------
//  主题:      角度变化率非极大抑制
//  功能:      去掉小角(置0)保留最大角
//  样例:      略
//  作者:      耿帅哥
//-------------------------------------------------------------------------------------------------------------------

void nms_angle0(float angle_in[], int num, float angle_out[], int kernel) {
//    assert(kernel % 2 == 1);
    int half = kernel / 2;
    for (int i = 0; i < num; i++) {
        angle_out[i] = angle_in[i];
        for (int j = -half; j <= half; j++) {
            if (fabs(angle_in[clip(i + j, 0, num - 1)]) > fabs(angle_out[i])) {
                angle_out[i] = 0;
                break;
            }
        }
    }
    //Maxpoint(angle_out,num);
}

void nms_angle1(float angle_in[], int num, float angle_out[], int kernel) {
//    assert(kernel % 2 == 1);
    int half = kernel / 2;
    for (int i = 0; i < num; i++) {
        angle_out[i] = angle_in[i];
        for (int j = -half; j <= half; j++) {
            if (fabs(angle_in[clip(i + j, 0, num - 1)]) > fabs(angle_out[i])) {
                angle_out[i] = 0;
                break;
            }
        }
    }
    //Maxpoint(angle_out,num);
}

//-------------------------------------------------------------------------------------------------------------------
//  主题:      计算最大角点
//  功能:      保留边线点的最大角度,其他置零
//  样例:      略
//  作者:      耿帅哥
//-------------------------------------------------------------------------------------------------------------------
void Maxpoint(float pts[],int pts_num) {
    uint8 i,mas;
    for(i=0;i<pts_num;i++){
        if(pts[i]!=0)
            draw_point(rpts1s[i][0]/2,rpts1s[i][1]/2,RGB565_RED);
    }

}

//-------------------------------------------------------------------------------------------------------------------
//  主题:      平移边线
//  功能:      平移距离为dist,找到赛道中线
//  样例:      略
//  作者:      耿帅哥
//-------------------------------------------------------------------------------------------------------------------
void track_leftline(uint8 pts_in[][2], int num, uint8 pts_out[][2], int approx_num, float dist) {
    for (int i = 0; i < num; i++) {
        float dx = pts_in[clip(i + approx_num, 0, num - 1)][0] - pts_in[clip(i - approx_num, 0, num - 1)][0];
        float dy = pts_in[clip(i + approx_num, 0, num - 1)][1] - pts_in[clip(i - approx_num, 0, num - 1)][1];
        float dn = sqrt(dx * dx + dy * dy);
        dx /= dn;
        dy /= dn;
        pts_out[i][0] = pts_in[i][0] - dy * dist;
        pts_out[i][1] = pts_in[i][1] + dx * dist;
        if(BKEY__1)
        if(pts_out[i][0]/2>0&&pts_out[i][0]/2<188&&pts_out[i][1]/2>0&&pts_out[i][1]/2<70)
            tft180_draw_point(pts_out[i][0]/2,pts_out[i][1]/2,RGB565_RED);
    }
}

void track_rightline(uint8 pts_in[][2], int num, uint8 pts_out[][2], int approx_num, float dist) {
    for (int i = 0; i < num; i++) {
        float dx = pts_in[clip(i + approx_num, 0, num - 1)][0] - pts_in[clip(i - approx_num, 0, num - 1)][0];
        float dy = pts_in[clip(i + approx_num, 0, num - 1)][1] - pts_in[clip(i - approx_num, 0, num - 1)][1];
        float dn = sqrt(dx * dx + dy * dy);
        dx /= dn;
        dy /= dn;
        pts_out[i][0] = pts_in[i][0] + dy * dist;
        pts_out[i][1] = pts_in[i][1] - dx * dist;
        if(BKEY__1)
        if(pts_out[i][0]/2>0&&pts_out[i][0]/2<188&&pts_out[i][1]/2>0&&pts_out[i][1]/2<70)
            tft180_draw_point(pts_out[i][0]/2,pts_out[i][1]/2,RGB565_BLUE);
    }
}

//-------------------------------------------------------------------------------------------------------------------
//  主题:      补线合集
//  功能:      含二分补线(耿帅哥原创),斜率补线(耿帅哥原创),偷来的补线,偷来的斜率补线
//  样例:      略
//  作者:      耿帅哥
//-------------------------------------------------------------------------------------------------------------------
void Erfen(uint8 index[][MT9V03X_W], uint8 x1, uint8 y1,uint8 x2, uint8 y2) {
    if(fabs(x1-x2)<=1&&fabs(y1-y2)<=1) return;
    uint8 midpost_x = x1+x2>>1;
    uint8 midpost_y = y1+y2>>1;
    mt9v03x_image_Bandw[midpost_y][midpost_x] = 0;

    Erfen(mt9v03x_image_Bandw,x1,y1,midpost_x,midpost_y);    Erfen(mt9v03x_image_Bandw,midpost_x,midpost_y,x2,y2);
}

void buxian(float slope, int i, uint8 pts[][2], int pts_num ,int flag) {
    int j = i;
    for(;j<pts_num-1;j++){
        if(!flag) {
            pts[j+1][0] = pts[j][0] - 1;
            pts[j+1][1] = (pts[i][1] - (pts[i][0] - pts[j+1][0])*slope);
            if(pts[j+1][0]/2>0&&pts[j+1][0]/2<188&&pts[j+1][1]/2>0&&pts[j+1][1]/2<70)
                tft180_draw_point(pts[j+1][0]/2,pts[j+1][1]/2,RGB565_BLUE);
        }else{

        }
    }
}

void add_line(int16 *data, uint8 aa, uint16 data_a,uint8 bb, uint16 data_b)
{
  uint8 i;
  float slope;      //斜率
  slope = data_b - data_a;
  slope = slope/(bb-aa);
  if(data_b - data_a > 0)
  {
    for(i = 0; i <= bb - aa; i++)
      data[i] = data[0]+ (int16)(i*slope);
  }
 else if(data_b - data_a == 0)
  {
    for(i = 0; i <= bb - aa; i++)
      data[i] = data[0];
  }
  else
  {
    for(i = 0;i <= bb - aa; i++)
      data[i] = data[0]+(int16)(i*slope);
  }
}

//参数：1.所要补线的斜率 2.补线的起点与行号,3.所要补线的数组的补线起点的地址....这里自己设置补线的终止
void slope_add_line(float slope, uint16 aa, int16 *data)
{
  uint16 i;
  for(i = 0; i < MT9V03X_H-aa; i++)
  {
    data[i] = data[0] + (int16)(i*slope);
    if(data[i] < 0) {data[i] = 0; break;}
    if(data[i] > MT9V03X_W) {data[i] = MT9V03X_W; break;}
  }
}

//-------------------------------------------------------------------------------------------------------------------
//  主题:      16点黑白检测
//  功能:      返回白点数量
//  样例:      略
//  作者:      耿帅哥
//-------------------------------------------------------------------------------------------------------------------

int point_16[16][2] = {
        {-2,0},{-2,1},{-2,2},{-2,-1},{-2,-2},{-1,2},{-1,-2},{0,2},
        {0,-2},{1,2},{1,-2},{2,0},{2,1},{2,-1},{2,2},{2,-2},
};

int check_16point(int x,int y) {
    int8 i;

    if(x>3 && x<MY_W && y>3 && y<MY_H) {
        int j=0;
            for(i=0;i<16;i++) {
                if(CHECK_WHITE(x+point_16[i][0],y+point_16[i][1])) {
                    j++;
                }
            }
            return j;
    }
    return 111;
}

bool check_far_whitepoint(int x,int y) {
    if(y-5>0 && x>0 && x<MT9V03X_W && y-5<MT9V03X_H) {
        if(CHECK_WHITE(x,y-5))
            return true;
        else {
            return false;
        }
    }
    else return false;
}


//-------------------------------------------------------------------------------------------------------------------
//  主题:      权重计算偏差
//  功能:      略
//  样例:      略
//  作者:      耿帅哥
//-------------------------------------------------------------------------------------------------------------------

float quanzhong[10] = {
        1,30,20,10,5,6,4,3,2,1
};

float piancha_points(uint8 pts_in[][2], uint8 num) {
    float qz = 0;
    float prue_angle_sum = 0;
    for (int i=0; i<10 ; i++) {
        int aim_idx = clip(round((i+1.)/10*num), 0, num-1);
        float dx = pts_in[aim_idx][0] - MT9V03X_W / 2;
        float dy = MT9V03X_H * 0.9f - pts_in[aim_idx][1] + 0.2 * pixel_per_meter;
        float dn = sqrt(dx * dx + dy * dy);

        float prue_ge = -atanf(pixel_per_meter * 2 * 0.2 * dx / dn / dn) / PI * 180 / SMOTOR_RATE ;
        prue_angle_sum += prue_ge*quanzhong[i];
        qz += quanzhong[i];
    }
    prue_angle_sum /= qz;
    qz = 0;
    return prue_angle_sum;
}






















