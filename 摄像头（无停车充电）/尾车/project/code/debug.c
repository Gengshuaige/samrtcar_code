#include "zf_common_headfile.h"

//上位机相关定义
float Variable[16];
/**************上位机函数************/
void my_putchar(int temp)
{
  uart_write_byte(UART_7,temp); //根据实际的串口号来修改
}
/*用来通知上位机新的一组数据开始，要保存数据必须发送它*/
void Send_Begin()
{
  my_putchar(0x55);
  my_putchar(0xaa);
  my_putchar(0x11);
}

void Testdata_generate()
{
  Variable[0] = cross_type;
  Variable[1] = circle_type;
  Variable[2] = duanlu_type;
  Variable[3] = luzhang_type;
  Variable[4] = slope_type;
  Variable[5] = ruku_type;
  Variable[6] = first_type;
  Variable[7] = 0;
  Variable[8] = aim_distance;
  Variable[9] = shiji_speed_L;
  Variable[10] = shiji_speed_R;
}

void Send_Variable()
{
  uint8 i=0,ch=0;
  float temp=0;
  uint8 Variable_num=11;
  my_putchar(0x55);
  my_putchar(0xaa);
  my_putchar(0xff);
  my_putchar(0x01);
  my_putchar(Variable_num);
  for(i=0;i<Variable_num;i++)
  {
    temp=Variable[i];
    ch=BYTE0(temp);
    my_putchar(ch);
    ch=BYTE1(temp);
    my_putchar(ch);
    ch=BYTE2(temp);
    my_putchar(ch);
    ch=BYTE3(temp);
    my_putchar(ch);
  }
  my_putchar(0x01);
}

void init_debug(void)
{
    Send_Begin();
    Testdata_generate();
    Send_Variable();
}

uint8 Lanya_xnhao;

void uart_accent(void)
{
    //接收蓝牙控制信号
    uart_query_byte(UART_2, &Lanya_xnhao);
}
