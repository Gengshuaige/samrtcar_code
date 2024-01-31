/*
 * DajinFa.c
 *
 *  Created on: 2022年11月10日
 *      Author: 耿帅哥
 */
#include "zf_common_headfile.h"

//-------------------------------------------------------------------------------------------------------------------
//  主题:      大津法
//  功能:      略
//  样例:      dajinfad(image[0], W, H);
//  作者:      耿帅哥
//-------------------------------------------------------------------------------------------------------------------

uint8 dajinfa(uint8 *image, uint16 col, uint16 row)   //注意计算阈值的一定要是原图像
{
#define GrayScale 256
    uint16 width=col;
    uint16 height=row;
    int16  threshold1=0;
    int pixelCount[GrayScale];
    float pixelPro[GrayScale];
    int i, j, pixelSum = width * height/4;

    uint8* data = image;  //指向像素数据的指针
    for(i=0; i<GrayScale;i++)
    {
        pixelCount[i]=0;
        pixelPro[i]=0;
    }

    uint32 gray_sum=0;
    //统计灰度级中每个像素在整幅图像中的个数
    for(i=0;i<height;i+=2)
    {
        for(j=0;j<width;j+=2)
        {
            pixelCount[(int)data[i*width+j]]++;  //将当前的点的像素值作为计数数组的下标
            gray_sum+=(int)data[i*width+j];       //灰度值总和
        }
    }

    //计算每个像素值的点在整幅图像中的比例

    for(i=0;i<GrayScale;i++)
    {
        pixelPro[i]=(float)pixelCount[i]/pixelSum;

    }

    //遍历灰度级[0,255]
    float w0,w1,u0tmp,u1tmp,u0,u1,u,deltaTmp,deltaMax=0;
    w0=w1=u0tmp=u1tmp=u0=u1=u=deltaTmp=0;
    for(j=0;j< GrayScale; j++)
    {
        w0+=pixelPro[j];  //背景部分每个灰度值的像素点所占比例之和   即背景部分的比例
        u0tmp+= j*pixelPro[j];  //背景部分 每个灰度值的点的比例 *灰度值
        w1=1-w0;
        u1tmp=gray_sum/pixelSum-u0tmp;
        u0=u0tmp/w0;              //背景平均灰度
        u1=u1tmp/w1;              //前景平均灰度
        u=u0tmp+u1tmp;            //全局平均灰度
        deltaTmp = w0 * pow((u0 - u), 2) + w1 * pow((u1 - u), 2);
        if(deltaTmp > deltaMax)
        {
            deltaMax=deltaTmp;
            threshold1=j;
        }
        if(deltaTmp<deltaMax)
        {
            break;
        }
    }
    return threshold1;
}

//-------------------------------------------------------------------------------------------------------------------
//  主题:      大津法(优化版)
//  功能:      略
//  样例:      otsuThreshold(image[0], W, H);
//  作者:      耿帅哥
//-------------------------------------------------------------------------------------------------------------------
uint8 otsuThreshold(uint8 *image, uint16 col, uint16 row)   //注意计算阈值的一定要是原图像
{
   #define GrayScale 256
    uint16 width = col;
    uint16 height = row;
    int pixelCount[GrayScale];
    float pixelPro[GrayScale];
    int i, j, pixelSum = width * height/4;
    uint8 threshold = 0;
    uint8* data = image;  //指向像素数据的指针
    for (i = 0; i < GrayScale; i++)
    {
        pixelCount[i] = 0;
        pixelPro[i] = 0;
    }

    uint32 gray_sum=0;
    //统计灰度级中每个像素在整幅图像中的个数
    for (i = 0; i < height; i+=2)
    {
        for (j = 0; j < width; j+=2)
        {
            pixelCount[(int)data[i * width + j]]++;  //将当前的点的像素值作为计数数组的下标
            gray_sum+=(int)data[i * width + j];       //灰度值总和
        }
    }

    //计算每个像素值的点在整幅图像中的比例

    for (i = 0; i < GrayScale; i++)
    {
        pixelPro[i] = (float)pixelCount[i] / pixelSum;

    }

    //遍历灰度级[0,255]
    float w0, w1, u0tmp, u1tmp, u0, u1, u, deltaTmp, deltaMax = 0;

        w0 = w1 = u0tmp = u1tmp = u0 = u1 = u = deltaTmp = 0;
        for (j = 0; j < GrayScale; j++)
        {
                w0 += pixelPro[j];  //背景部分每个灰度值的像素点所占比例之和   即背景部分的比例
                u0tmp += j * pixelPro[j];  //背景部分 每个灰度值的点的比例 *灰度值

               w1=1-w0;
               u1tmp=gray_sum/pixelSum-u0tmp;

                u0 = u0tmp / w0;              //背景平均灰度
                u1 = u1tmp / w1;              //前景平均灰度
                u = u0tmp + u1tmp;            //全局平均灰度
                deltaTmp = w0 * pow((u0 - u), 2) + w1 * pow((u1 - u), 2);
                if (deltaTmp > deltaMax)
                {
                    deltaMax = deltaTmp;
                    threshold = j;
                }
                if (deltaTmp < deltaMax)
                {
                break;
                }
         }

    return threshold;
}

//-------------------------------------------------------------------------------------------------------------------
//  主题:      阳光算法
//  功能:      略
//  样例:      略
//  作者:      偷的
//-------------------------------------------------------------------------------------------------------------------
int16 Gray_min = 75;
int Reflec_point = 0;
int16 Reflec_Gray = 0xf0;
int my_adapt_threshold(uint8 *image, uint16 col, uint16 row)   //注意计算阈值的一定要是原图像
{
   #define GrayScale 256
    uint16 width = col;
    uint16 height = row;
    int pixelCount[GrayScale];
    float pixelPro[GrayScale];
    int i, j, pixelSum;
    uint8 threshold = 0;
    uint8* data = image;  //指向像素数据的指针
    Reflec_point = 0;
    for (i = 0; i < GrayScale; i++)
    {
        pixelCount[i] = 0;
        pixelPro[i] = 0;
    }

    uint32 gray_sum=0;
    //统计灰度级中每个像素在整幅图像中的个数
    for (i = 0; i < height; i+=2)
    {
        for (j = 0; j < width; j+=2)
        {
          if(data[i * width + j] < Reflec_Gray){ //直接去掉反光点，不再参与大津法阈值计算
            pixelCount[(int)data[i * width + j]]++;  //将当前的点的像素值作为计数数组的下标
            gray_sum+=(int)data[i * width + j];       //灰度值总和
          }//
          else{//
             Reflec_point++;//反光点个数
          }//
        }
    }
             pixelSum = width * height/4 - Reflec_point;
    //计算每个像素值的点在整幅图像中的比例

    for (i = 0; i < GrayScale; i++)
    {
        pixelPro[i] = (float)pixelCount[i] / pixelSum;

    }

    //遍历灰度级[0,255]
    float w0, w1, u0tmp, u1tmp, u0, u1, u, deltaTmp, deltaMax = 0;



        w0 = w1 = u0tmp = u1tmp = u0 = u1 = u = deltaTmp = 0;
        for (j = 0; j < GrayScale; j++)
        {

                w0 += pixelPro[j];  //背景部分每个灰度值的像素点所占比例之和   即背景部分的比例
                u0tmp += j * pixelPro[j];  //背景部分 每个灰度值的点的比例 *灰度值

               w1=1-w0;
               u1tmp=gray_sum/pixelSum-u0tmp;

                u0 = u0tmp / w0;              //背景平均灰度
                u1 = u1tmp / w1;              //前景平均灰度
                u = u0tmp + u1tmp;            //全局平均灰度
                deltaTmp = w0 * pow((u0 - u), 2) + w1 * pow((u1 - u), 2);
                if (deltaTmp > deltaMax)
                {
                    deltaMax = deltaTmp;
                    threshold = j;
                }
                if (deltaTmp < deltaMax)
                {
                break;
                }

         }
        if(threshold < Gray_min)
          threshold = Gray_min;

    return threshold;

}
