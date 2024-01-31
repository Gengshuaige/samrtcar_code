#include "zf_common_headfile.h"

//-------------------------------------------------------------------------------------------------------------------
//  brief      ��������+16
//  author     ����ԽҰ
//  date       
//  return     void
//  since      v1.0
//  Sample usage:���ڲ�����ҳ
//-------------------------------------------------------------------------------------------------------------------
int16 KEY_Add_int_16(int16 key, int16* flag)
{
        if (key == 0)
    {
//        bibibi(1);
        KEY_delay;
        bibibi(0);
        if (key == 0)
                {(*flag) += 16;
                tft180_full(RGB565_WHITE);
                }
    }
    return (*flag);
}
//-------------------------------------------------------------------------------------------------------------------
//  brief      ��������-16
//  author     ����ԽҰ
//  date
//  return     void
//  since      v1.0
//  Sample usage:
//-------------------------------------------------------------------------------------------------------------------
int16 KEY_Reduce_int_16(int16 key, int16* flag)
{
        if (key == 0)
        {
//          bibibi(1);
          KEY_delay;
          bibibi(0);
          if (key == 0)
            (*flag) -= 16;
        }
        return (*flag);
}



//-------------------------------------------------------------------------------------------------------------------
//  brief      ��������+1
//  author     ����ԽҰ
//  date
//  return     void
//  since      v1.0
//  Sample usage:���ڲ�����ҳ
//-------------------------------------------------------------------------------------------------------------------
int16 KEY_Add_int_1(int16 key, int16* flag)
{
        if (key == 0)
	{
//		bibibi(1);
		KEY_delay;
		bibibi(0);
		if (key == 0)
                {(*flag) += 1;
                tft180_full(RGB565_WHITE);
                }
	}
	return (*flag);
}
//-------------------------------------------------------------------------------------------------------------------
//  brief      ��������-1
//  author     ����ԽҰ
//  date       
//  return     void
//  since      v1.0
//  Sample usage:
//-------------------------------------------------------------------------------------------------------------------
int16 KEY_Reduce_int_1(int16 key, int16* flag)
{
        if (key == 0)
        {
//          bibibi(1);
          KEY_delay;
          bibibi(0);
          if (key == 0)
            (*flag) -= 1;
        }
        return (*flag);
}




//-------------------------------------------------------------------------------------------------------------------
//  brief     float��1
//  author   ����ԽҰ
//  date       
//  return     void
//  since      v1.0
//  Sample usage:
//-------------------------------------------------------------------------------------------------------------------
float KEY_Add_float_1(int16 key, float* flag)
{
  if (key == 0)
        {
        bibibi(1);
		KEY_delay;
		bibibi(0);
		if (key == 0)
			(*flag) += 1;
	}
	return (float)(*flag);
}

float KEY_Add_float_1_t(int16 key, float flag)
{
  if (key == 0)
        {
        bibibi(1);
        KEY_delay;
        bibibi(0);
        if (key == 0)
            flag+=5;
    }
    return (float)flag;
}

float KEY_Reduce_float_1_t(int16 key, float flag)
{
  if (key == 0)
        {
        bibibi(1);
        KEY_delay;
        bibibi(0);
        if (key == 0)
            flag -= 5;
    }
    return flag;
}

//-------------------------------------------------------------------------------------------------------------------
//  brief     float��1
//  author   ����ԽҰ
//  date       
//  return     void
//  since      v1.0
//  Sample usage:
//-------------------------------------------------------------------------------------------------------------------
float KEY_Reduce_float_1(int16 key, float* flag)
{
  if (key == 0)
        {
        bibibi(1);
		KEY_delay;
		bibibi(0);
		if (key == 0)
			(*flag) -= 1;
	}
	return (*flag);
}

//-------------------------------------------------------------------------------------------------------------------
//  brief     float��0.1
//  author   ����ԽҰ
//  date
//  return     void
//  since      v1.0
//  Sample usage:
//-------------------------------------------------------------------------------------------------------------------

float KEY_Add_float_0_1(int16 key, float* flag)
{
  if (key == 0)
        {
//                bibibi(1);
        KEY_delay;
        bibibi(0);
        if (key == 0)
            (*flag) += 0.1;
    }
    return (float)(*flag);
}
//-------------------------------------------------------------------------------------------------------------------
//  brief     float��1
//  author   ����ԽҰ
//  date
//  return     void
//  since      v1.0
//  Sample usage:
//-------------------------------------------------------------------------------------------------------------------
float KEY_Reduce_float_0_1(int16 key, float* flag)
{
  if (key == 0)
        {
//                bibibi(1);
        KEY_delay;
        bibibi(0);
        if (key == 0)
            (*flag) -= 0.1;
    }
    return (*flag);
}

//-------------------------------------------------------------------------------------------------------------------
//  brief     float��0.01
//  author   ����ԽҰ
//  date
//  return     void
//  since      v1.0
//  Sample usage:
//-------------------------------------------------------------------------------------------------------------------

float KEY_Add_float_0_01(int16 key, float* flag)
{
  if (key == 0)
        {
//                bibibi(1);
        KEY_delay;
        bibibi(0);
        if (key == 0)
            (*flag) += 0.01;
    }
    return (float)(*flag);
}
//-------------------------------------------------------------------------------------------------------------------
//  brief     float��0.01
//  author   ����ԽҰ
//  date
//  return     void
//  since      v1.0
//  Sample usage:
//-------------------------------------------------------------------------------------------------------------------
float KEY_Reduce_float_0_01(int16 key, float* flag)
{
  if (key == 0)
        {
//                bibibi(1);
        KEY_delay;
        bibibi(0);
        if (key == 0)
            (*flag) -= 0.01;
    }
    return (*flag);
}

//-------------------------------------------------------------------------------------------------------------------
//  brief     float��0.01
//  author   ����ԽҰ
//  date
//  return     void
//  since      v1.0
//  Sample usage:
//-------------------------------------------------------------------------------------------------------------------

float KEY_Add_float_0_001(int16 key, float* flag)
{
  if (key == 0)
        {
//                bibibi(1);
        KEY_delay;
        bibibi(0);
        if (key == 0)
            (*flag) += 0.001;
    }
    return (float)(*flag);
}
//-------------------------------------------------------------------------------------------------------------------
//  brief     float��1
//  author   ����ԽҰ
//  date
//  return     void
//  since      v1.0
//  Sample usage:
//-------------------------------------------------------------------------------------------------------------------
float KEY_Reduce_float_0_001(int16 key, float* flag)
{
  if (key == 0)
        {
//                bibibi(1);
        KEY_delay;
        bibibi(0);
        if (key == 0)
            (*flag) -= 0.001;
    }
    return (*flag);
}

float KEY_Add_float_10(int16 key, float* flag)
{
  if (key == 0)
        {
         bibibi(1);
        KEY_delay;
        bibibi(0);
        if (key == 0)
            (*flag) += 10;
    }
    return (*flag);
}

float KEY_Reduce_float_10(int16 key, float* flag)
{
  if (key == 0)
        {
        bibibi(1);
        KEY_delay;
        bibibi(0);
        if (key == 0)
            (*flag) -= 10;
    }
    return (*flag);
}

float KEY_Add_float_0_5(int16 key, float* flag)
{
  if (key == 0)
        {
        bibibi(1);
        KEY_delay;
        bibibi(0);
        if (key == 0)
            (*flag) += 0.5;
    }
    return (float)(*flag);
}

float KEY_Reduce_float_0_5(int16 key, float* flag)
{
  if (key == 0)
        {
        bibibi(1);
        KEY_delay;
        bibibi(0);
        if (key == 0)
            (*flag) -= 0.5;
    }
    return (float)(*flag);
}
