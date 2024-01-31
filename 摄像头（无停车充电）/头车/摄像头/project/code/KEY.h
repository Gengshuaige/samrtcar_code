#ifndef _KEY_H_
#define _KEY_H_

#define bibibi(x)   gpio_set_level(C13, x)//蜂鸣器
#define KEY_delay   system_delay_ms(200)// 按键延时

#define KEY__1   gpio_get_level(B0)//换行  A5
#define KEY__2   gpio_get_level(B12)//确定  C4
#define KEY__3   gpio_get_level(D8)//返回  A3
#define KEY__4   gpio_get_level(A8)//参数+ A4
#define BKEY__1   gpio_get_level(E0)
#define BKEY__2   gpio_get_level(E1)
#define BKEY__3   gpio_get_level(E2)
#define BKEY__4   gpio_get_level(E3)

//#define Switch_Key_1  gpio_get_level(P33_12)
//#define Switch_Key_2   gpio_get_level(P33_13)  //开关菜单             拨码开关3
/***按键操作***/
int16 KEY_Add_int_16(int16 key, int16* flag);
int16 KEY_Reduce_int_16(int16 key, int16* flag);
int16 KEY_Add_int_1(int16 key, int16* flag);
int16 KEY_Reduce_int_1(int16 key, int16* flag);
float KEY_Add_float_1(int16 key, float* flag);
float KEY_Reduce_float_1(int16 key, float* flag);
float KEY_Add_float_0_1(int16 key, float* flag);
float KEY_Reduce_float_0_1(int16 key, float* flag);
float KEY_Add_float_0_5(int16 key, float* flag);
float KEY_Reduce_float_0_5(int16 key, float* flag);
float KEY_Add_float_0_01(int16 key, float* flag);
float KEY_Reduce_float_0_01(int16 key, float* flag);
float KEY_Add_float_0_001(int16 key, float* flag);
float KEY_Reduce_float_0_001(int16 key, float* flag);
float KEY_Add_float_10(int16 key, float* flag);
float KEY_Reduce_float_10(int16 key, float* flag);
float KEY_Add_float_1_t(int16 key, float flag);
float KEY_Reduce_float_1_t(int16 key, float flag);

#endif











