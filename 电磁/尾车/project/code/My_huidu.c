#include "zf_common_headfile.h"

//��¼��ֵ��������,��0Ϊ��
//-------------------------------------------------------------------------------------------------------------------
//  ����:      ��ֵ��
//  ����:      ��
//  ����:      Erzhihua(value); //����ֵ
//  ����:      ��˧��
//-------------------------------------------------------------------------------------------------------------------
uint8 mt9v03x_image_Bandw[MT9V03X_H][MT9V03X_W];
//��ͨ��ֵ�� 0-255
void Erzhihua(uint8 value)
{
    uint8 temp_value;
    for(uint8 i=0;i<MT9V03X_H;i++){
        for(uint8 j=0;j<MT9V03X_W;j++){
            temp_value = mt9v03x_image[i][j];//mt9v03x_image_dvp
            if(temp_value < value)
                mt9v03x_image_Bandw[i][j] = 0;
            else
                mt9v03x_image_Bandw[i][j] = 255;
        }
    }
}

