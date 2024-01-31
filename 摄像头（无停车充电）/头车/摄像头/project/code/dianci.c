/*
 * dianci.c
 *
 *  Created on: 2023年5月6日
 *      Author: 姚帅哥
 */
#include "zf_common_headfile.h"

//电磁循迹
//-------------------------------------------------------------------------------------------------------------------
//  主题：      adc转换，电感值归一化
//
//  功能：     略
//
//  样例:   略
//-------------------------------------------------------------------------------------------------------------------

float  ADC_DATE[5][10] , ADC_SUM[5] , ADC_DATE_1[5][10] , ADC_DATE_2[5] , GUI_ADC_DATE[5] , AD_DATE[5];

void diangan_guiyihua(void)
{
    int16 temp;
    int16 i,j,k;
    for(i=0 ; i<10 ; i++)
    {
        ADC_DATE[0][i] = adc_convert(ADC1_IN14_C4);
        ADC_DATE[1][i] = adc_convert(ADC1_IN13_C3);
//        ADC_DATE[2][i] = adc_convert(ADC1_IN11_C1);
        ADC_DATE[3][i] = adc_convert(ADC1_IN12_C2);
        ADC_DATE[4][i] = adc_convert(ADC1_IN11_C1);
    }

    for (i = 0; i < 5; i++)                                                                  //将每个电感采集十次的结果冒泡排序
     {
         for (j = 0; j < 9; j++)
         {
             for (k = 0; k < 9 - j; k++)
             {
                 if (ADC_DATE[i][k] > ADC_DATE[i][k + 1])
                 {
                     temp = ADC_DATE[i][k + 1];
                     ADC_DATE[i][k + 1] = ADC_DATE[i][k];
                     ADC_DATE[i][k] = temp;
                 }
             }
         }
     }
    for (i = 0; i < 5; i++)                                                                //取冒泡排序后中间四个数求平均数
    {
      ADC_SUM[i] = ADC_DATE[i][3] + ADC_DATE[i][4] + ADC_DATE[i][5]+ADC_DATE[i][6];
      AD_DATE[i] = ADC_SUM[i] / 4;
     }

    for(i = 0; i < 5; i++)                                                                 //移动平均滤波器
    {
       for(j = 0; j < 5; j++)
       {
           ADC_DATE_1[i][j]=ADC_DATE_1[i][j+1];
       }
       ADC_DATE_1[i][j]=AD_DATE[i];
    }

    for(i = 0; i < 5; i++)
       {

         ADC_DATE_2[i]=(ADC_DATE_1[i][0]+ADC_DATE_1[i][1]+ADC_DATE_1[i][2]+ADC_DATE_1[i][3]+ADC_DATE_1[i][4]+ADC_DATE_1[i][5])/6;

        }
        if(ADC_DATE_2[0]>ADC_MAX_L) ADC_DATE_2[0]=ADC_MAX_L;
        if(ADC_DATE_2[1]>ADC_MAX_LM) ADC_DATE_2[1]=ADC_MAX_LM;
        //if(ADC_DATE_2[2]>ADC_MAX_MM) ADC_DATE_2[2]=ADC_MAX_MM;
        if(ADC_DATE_2[3]>ADC_MAX_RM) ADC_DATE_2[3]=ADC_MAX_RM;
        if(ADC_DATE_2[4]>ADC_MAX_R) ADC_DATE_2[4]=ADC_MAX_R;

        GUI_ADC_DATE[0] = 100 * ADC_DATE_2[0]/ADC_MAX_L;
        GUI_ADC_DATE[1] = 100 * ADC_DATE_2[1]/ADC_MAX_LM;
        //GUI_ADC_DATE[2] = 100 * ADC_DATE_2[2]/ADC_MAX_MM;
        GUI_ADC_DATE[3] = 100 * ADC_DATE_2[3]/ADC_MAX_RM;
        GUI_ADC_DATE[4] = 100 * ADC_DATE_2[4]/ADC_MAX_R;

//        if(GUI_ADC_DATE[1]+GUI_ADC_DATE[3]+GUI_ADC_DATE[4]<20 && delay_stop_my_2s==401 && zhangai_type==ZHANGAI_NONE
//                && (first_type==FIRST_NONE || first_type==CHARGE_OVER)
//                )
//            Shache_flag=1
//            ;
//        else if(first_type!=FIRST_NONE&&first_type!=CHARGE_OVER){
//            Shache_flag=0;
//        }
}

//-------------------------------------------------------------------------------------------------------------------
//  主题：      差比和
//
//  功能：     略
//
//  样例:   略
//-------------------------------------------------------------------------------------------------------------------
float ad_sum_wai;
float ad_sum_nei;
float ad_sum;
float pure_diangan;
void chabihe(void)
{
    ad_sum_wai =(float)(GUI_ADC_DATE[0]-GUI_ADC_DATE[4])/(GUI_ADC_DATE[0]+GUI_ADC_DATE[4])*100;
    ad_sum_nei =(float)(GUI_ADC_DATE[1]-GUI_ADC_DATE[3])/(GUI_ADC_DATE[1]+GUI_ADC_DATE[3])*100;
    if(cross_type!=CROSS_NONE) {
        ad_sum = 0.99*ad_sum_wai+0.01*ad_sum_nei;
        if(cross_type==CROSS_IN) {
            kp_D = 0.75; ki_D = 0; kd_D = 12;
        }else if(cross_type==CROSS_IN_LEFT||cross_type==CROSS_IN_RIGHT){
            if(pure_diangan<1.15) {
                kp_D = 0.45; ki_D = 0; kd_D = 12;
            }else {
                kp_D = 0.75; ki_D = 0; kd_D = 12;
            }

        }
    } else {

        ad_sum = 0.9*ad_sum_wai + 0.1 * ad_sum_nei;
        kp_D = 1.1; ki_D = 0; kd_D = 12;
        //测试：
}
    pure_diangan = ad_sum;
}
