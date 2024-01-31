#include "zf_common_headfile.h"

#define TEX 0.5
#define KP_MENU kp_D
#define KI_MENU ki_D
#define KD_MENU kd_D

#define CHASU_L diy_L
#define CHASU_R diy_R

#define VS gengshuaige

int Kalman_judge=0;

  void (*pages)(void);

  //-------------------------------------------------------------------------------------------------------------------
  //  主题:      菜单首页
  //  功能:      当前含PID调节,速度调节
  //  样例:      略
  //  作者:      耿帅哥
  //-------------------------------------------------------------------------------------------------------------------

  int16 Menu_point = 16*10*TEX;

  void Page0()
{
    tft180_show_string(0,Menu_point,"->");

    tft180_show_string(20,16*10*TEX,"pid_page");
    tft180_show_string(20,16*12*TEX,"Speed_page");
    tft180_show_string(20,16*14*TEX,"DIY_chasu");
    tft180_show_string(20,16*16*TEX,"MODE");

    KEY_Add_int_16(KEY__1, &Menu_point);
    if( Menu_point > 16*16*TEX) Menu_point = 16*10*TEX ;
    if( Menu_point < 16*10*TEX) Menu_point = 16*16*TEX ;

    if(Menu_point == 16*10*TEX)
        if(KEY__2 == 0)
        {
            bibibi(1);
            KEY_delay;
            bibibi(0);
            if(KEY__2 == 0)
            {
                tft180_full(RGB565_GREEN);
                pages=PID_page;
            }
        }
    if(Menu_point == 16*12*TEX)
            if(KEY__2 == 0)
            {
                bibibi(1);
                KEY_delay;
                bibibi(0);
                if(KEY__2 == 0)
                {
                    tft180_full(RGB565_GREEN);
                    pages=Speed_page;
                }
            }
    if(Menu_point == 16*14*TEX)
                if(KEY__2 == 0)
                {
                    bibibi(1);
                    KEY_delay;
                    bibibi(0);
                    if(KEY__2 == 0)
                    {
                        tft180_full(RGB565_GREEN);
                        pages=chasu_page;
                    }
                }
    if(Menu_point == 16*16*TEX)
                    if(KEY__2 == 0)
                    {
                        bibibi(1);
                        KEY_delay;
                        bibibi(0);
                        if(KEY__2 == 0)
                        {
                            tft180_full(RGB565_GREEN);
                            pages=mode_page;
                        }
                    }
}

//-------------------------------------------------------------------------------------------------------------------
//  主题:      PID调节
//  功能:      略
//  样例:      略
//  作者:      耿帅哥
//-------------------------------------------------------------------------------------------------------------------

int16 Pid_point=16*10*TEX;

void PID_page(void)
{


    tft180_show_string(0,Pid_point,"->");//菜单指针

    tft180_show_string(20,16*10*TEX,"P");
    tft180_show_string(20,16*12*TEX,"I");
    tft180_show_string(20,16*14*TEX,"D");
    tft180_show_string(20,16*16*TEX,"X");

    tft180_show_float(50,16*10*TEX,KP_MENU,3,3);
    tft180_show_float(50,16*12*TEX,KI_MENU,3,3);
    tft180_show_float(50,16*14*TEX,KD_MENU,3,3);

    KEY_Add_int_16(KEY__1,&Pid_point);
    if( Pid_point > 16*16*TEX) Pid_point = 16*10*TEX ;
    if( Pid_point < 16*10*TEX) Pid_point = 16*16*TEX ;

    if (Pid_point == 16*10*TEX)
    {
        KEY_Add_float_0_1(KEY__3,&KP_MENU);
        KEY_Reduce_float_0_1(KEY__4,&KP_MENU);
     }

    if (Pid_point == 16*12*TEX)
        {
            KEY_Add_float_0_1(KEY__3,&KI_MENU);
            KEY_Reduce_float_0_1(KEY__4,&KI_MENU);
         }
    if (Pid_point == 16*14*TEX)
            {
                KEY_Add_float_0_5(KEY__3,&KD_MENU);
                KEY_Reduce_float_0_5(KEY__4,&KD_MENU);
             }




    if (Pid_point == 16*16*TEX)
    {
        if (KEY__2 == 0)
        {
            bibibi(1);
            KEY_delay;
            bibibi(0);
            if(KEY__2 == 0)
            {
                tft180_full(RGB565_WHITE);
                pages=Page0;
            }
        }
    }
}

//-------------------------------------------------------------------------------------------------------------------
//  主题:      速度调节
//  功能:      略
//  样例:      略
//  作者:      耿帅哥
//-------------------------------------------------------------------------------------------------------------------

int16 Speed_point=16*10*TEX;

void Speed_page(void)
{

    tft180_show_string(0,Speed_point,"->");//菜单指针

    tft180_show_string(20,16*10*TEX,"V:");
    tft180_show_string(20,16*12*TEX,"X");

    tft180_show_float(50,16*10*TEX,VS,3,3);

    KEY_Add_int_16(KEY__1,&Speed_point);
    if( Speed_point > 16*12*TEX) Speed_point = 16*10*TEX ;
    if( Speed_point < 16*10*TEX) Speed_point = 16*12*TEX ;

    if (Speed_point == 16*10*TEX)
    {
        KEY_Add_float_1(KEY__3,&VS);
        KEY_Reduce_float_1(KEY__4,&VS);
     }

    if (Speed_point == 16*12*TEX)
    {
        if (KEY__2 == 0)
        {
            bibibi(1);
            KEY_delay;
            bibibi(0);
            if(KEY__2 == 0)
            {
                tft180_full(RGB565_WHITE);
                pages=Page0;
            }
        }
    }
}

//-------------------------------------------------------------------------------------------------------------------
//  主题:      差速调节
//  功能:      略
//  样例:      略
//  作者:      耿帅哥
//-------------------------------------------------------------------------------------------------------------------

int16 diy_chasu_point=16*10*TEX;

void chasu_page(void)
{
    tft180_show_string(0,diy_chasu_point,"->");//菜单指针

    tft180_show_string(20,16*10*TEX,"L");
    tft180_show_string(20,16*12*TEX,"R");
    tft180_show_string(20,16*14*TEX,"X");

    tft180_show_float(50,16*10*TEX,CHASU_L,3,3);
    tft180_show_float(50,16*12*TEX,CHASU_R,3,3);

    KEY_Add_int_16(KEY__1,&diy_chasu_point);
    if( diy_chasu_point > 16*14*TEX) diy_chasu_point = 16*10*TEX ;
    if( diy_chasu_point < 16*10*TEX) diy_chasu_point = 16*14*TEX ;

    if (diy_chasu_point == 16*10*TEX)
    {
        KEY_Add_float_0_1(KEY__3,&CHASU_L);
        KEY_Reduce_float_0_1(KEY__4,&CHASU_L);
     }

    if (diy_chasu_point == 16*12*TEX)
        {
            KEY_Add_float_0_01(KEY__3,&CHASU_R);
            KEY_Reduce_float_0_01(KEY__4,&CHASU_R);
         }

    if (diy_chasu_point == 16*14*TEX)
    {
        if (KEY__2 == 0)
        {
            bibibi(1);
            KEY_delay;
            bibibi(0);
            if(KEY__2 == 0)
            {
                tft180_full(RGB565_WHITE);
                pages=Page0;
            }
        }
    }
}

//-------------------------------------------------------------------------------------------------------------------
//  主题:      模式选择
//  功能:      略
//  样例:      略
//  作者:      耿帅哥
//-------------------------------------------------------------------------------------------------------------------

int16 mode_point=16*10*TEX;

void mode_page(void)
{
    tft180_show_string(0,mode_point,"->");//菜单指针

    tft180_show_string(20,16*10*TEX,"CHUKU");
    tft180_show_string(20,16*12*TEX,"NONE");
    tft180_show_string(20,16*14*TEX,"X");

    tft180_show_float(50,16*10*TEX,chuku_fangxiang,3,3);
    tft180_show_float(50,16*12*TEX,0,3,3);

    KEY_Add_int_16(KEY__1,&mode_point);
    if( mode_point > 16*14*TEX) mode_point = 16*10*TEX ;
    if( mode_point < 16*10*TEX) mode_point = 16*14*TEX ;

    if (mode_point == 16*10*TEX)
    {
        KEY_Add_int_1(KEY__3,&chuku_fangxiang);
        KEY_Reduce_int_1(KEY__4,&chuku_fangxiang);
    }

    if (mode_point == 16*12*TEX)
        {
//            KEY_Add_float_0_01(KEY__3,&CHASU_R);
//            KEY_Reduce_float_0_01(KEY__4,&CHASU_R);
         }

    if (mode_point == 16*14*TEX)
    {
        if (KEY__2 == 0)
        {
            bibibi(1);
            KEY_delay;
            bibibi(0);
            if(KEY__2 == 0)
            {
                tft180_full(RGB565_WHITE);
                pages=Page0;
            }
        }
    }
}


void Menu(void)
{
//  if((Switch_Key_1 == 0)&&(Switch_Key_2==0))    //测试调参
//  {
    pages();                            //菜单显示
//    Camera_Control_test();              //显示图像的摄像头控制
//    draw_line_test();                        //画出扫线范围
//  }
//  if((Switch_Key_1 == 1)&&(Switch_Key_2==1))
//  {
//      Camera_Control_test();              //显示图像的摄像头控制
//      draw_line_test();                        //画出扫线范围
//  }
}
