#ifndef ZHONGXIAN_H_
#define ZHONGXIAN_H_
#include "zf_common_headfile.h"
#define AT_IMAGE(img, x, y)          ((img)->data[(y)*(img)->step+(x)])
#define DEF_IMAGE(ptr, w, h)         {.data=ptr, .width=w, .height=h, .step=w}
#define AT                  AT_IMAGE

extern uint8 mid_line;
extern float Mid_W;
extern float Mid_D;

typedef struct image {
    uint8_t *data;
    uint32_t width;
    uint32_t height;
    uint32_t step;
} image_t;

#define CHECK_WHITE(x,y)      (mt9v03x_image_Bandw[(y)][(x)] == 255)

void draw_point(uint x,uint8 y,uint16 color);
void findline_lefthand_adaptive(uint8 index[][MT9V03X_W], uint8 x, uint8 y, uint8 pts[][2], uint8 *num);
void findline_righthand_adaptive(uint8 index[][MT9V03X_W], uint8 x, uint8 y,uint8 pts[][2],uint8 *num);
void blur_points0(uint8 pts_in[][2], uint8 num, uint8 pts_out[][2], int kernel);
void blur_points1(uint8 pts_in[][2], uint8 num, uint8 pts_out[][2], int kernel);
void resample_points2_R(uint8 pts_in[][2], uint8 num1, uint8 pts_out[][2], int *num2, float dist);
void resample_points2_L(uint8 pts_in[][2], uint8 num1, uint8 pts_out[][2], uint8 *num2, float dist);
void local_angle_points0(uint8 pts_in[][2], int num, float angle_out[], int dist);
void local_angle_points1(uint8 pts_in[][2], int num, float angle_out[], int dist);
void nms_angle0(float angle_in[], int num, float angle_out[], int kernel);
void nms_angle1(float angle_in[], int num, float angle_out[], int kernel);
void Maxpoint(float pts[],int pts_num);
void track_leftline(uint8 pts_in[][2], int num, uint8 pts_out[][2], int approx_num, float dist);
void track_rightline(uint8 pts_in[][2], int num, uint8 pts_out[][2], int approx_num, float dist);
void Erfen(uint8 index[][MT9V03X_W], uint8 x1, uint8 y1,uint8 x2, uint8 y2);
bool check_far_whitepoint(int x,int y);
void buxian(float slope, int i, uint8 pts[][2], int pts_num ,int flag);
void add_line(int16 *data, uint8 aa, uint16 data_a,uint8 bb, uint16 data_b);
void slope_add_line(float slope, uint16 aa, int16 *data);
float piancha_points(uint8 pts_in[][2], uint8 num);

#endif /* ZHONGXIAN_H_ */
