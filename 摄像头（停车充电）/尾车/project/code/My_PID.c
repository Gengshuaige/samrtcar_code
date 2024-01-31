#include "My_PID.h"
//-------------------------------------------------------------------------------------------------------------------
//  ����:      λ��ʽPID����
//  ����:      �������+���
//  ����:      My_PID_WEIZHI(Shiji,Qiwang,kP,kI,kD);
//  ����:      ��˧��
//-------------------------------------------------------------------------------------------------------------------
float JIFEN_WEIZHI_L;
float error_L;
float BILI_DL;
float WEIFEN_DL;
float error_away1;
int My_PID_WEIZHI_L(int Shiji,int Qiwang,float kP,float kI,float kD)//λ��ʽ
{

    error_L = Qiwang - Shiji;
    BILI_DL = error_L * kP;//���������
    JIFEN_WEIZHI_L += error_L*kI;//���������
    if(JIFEN_WEIZHI_L>5000)JIFEN_WEIZHI_L = 5000;
    if(JIFEN_WEIZHI_L<-5000)JIFEN_WEIZHI_L = -5000;
    WEIFEN_DL = (error_L - error_away1)*kD;//����΢����
    error_away1 = error_L;
    int ZUIZHONGJIEGUO = (int)(BILI_DL + JIFEN_WEIZHI_L + WEIFEN_DL);
    return ZUIZHONGJIEGUO;
}



//λ��ʽ
float JIFEN_WEIZHI_R;
float error_R;
float BILI_DR;
float WEIFEN_DR;
float error_away2;

int My_PID_WEIZHI_R(int Shiji,int Qiwang,float kP,float kI,float kD)//λ��ʽ
{
    error_R = Qiwang - Shiji;
    BILI_DR = error_R * kP;//���������
    JIFEN_WEIZHI_R += error_R*kI;//���������
    if(JIFEN_WEIZHI_R>5000)JIFEN_WEIZHI_R = 5000;
    if(JIFEN_WEIZHI_R<-5000)JIFEN_WEIZHI_R = -5000;
    WEIFEN_DR = (error_R - error_away2)*kD;//����΢����
    error_away2 = error_R;
    int ZUIZHONGJIEGUO = (int)(BILI_DR + JIFEN_WEIZHI_R + WEIFEN_DR);
    return ZUIZHONGJIEGUO;
}

//λ��ʽ
float JIFEN_WEIZHI;
float error_away;

int My_PID_WEIZHI(float Shiji,int Qiwang,float L_kP,float kI,float kD)//λ��ʽ
{
    float kP;
    float error;
    float BILI;
    float WEIFEN;
    error = Qiwang - Shiji;
    //��̬P

    if(shexiangtou_or_dianci==false) {
        kP = (fabs((pow(MY_e,-fabs(error))-1)/(pow(MY_e,-fabs(error))+1))/2+0.5)*L_kP;
    }else {
        kP = L_kP*(fabs((pow(MY_e,-fabs(error))-1)/(pow(MY_e,-fabs(error))+1))/2+0.5);
    }
    BILI = error*kP;//���������
    JIFEN_WEIZHI += error*kI;//���������
    WEIFEN = (error - error_away)*kD;//����΢����
    error_away = error;
    int ZUIZHONGJIEGUO = (int)(BILI + JIFEN_WEIZHI + WEIFEN);
    return ZUIZHONGJIEGUO;
}

int64_t get_total_encoder(void) {
    return (int64_t) ((shiji_speed_L - shiji_speed_R) / 2);
}

//-------------------------------------------------------------------------------------------------------------------
//  ����:      Ģ��PID
//  ����:      ��
//  ����:      ��
//  ����:      Ģ��
//-------------------------------------------------------------------------------------------------------------------

int Speed_L_PID(int speed_L_want,int speed_L_now,float Speed_L_Kp,float Speed_L_Ki,float Speed_L_Kd)
{
    static int P_L_PID=0;
    static int I_L_PID=0;
    static int D_L_PID=0;

    static int speed_L_duty=0;
    static int speed_L_error=0;
    static int speed_L_error_pre=0;
    static int speed_L_error_pre_pre=0;

    speed_L_error=speed_L_want-speed_L_now;

    P_L_PID=Speed_L_Kp*(speed_L_error-speed_L_error_pre);
    I_L_PID=Speed_L_Ki*(speed_L_error);
    D_L_PID=Speed_L_Kd*(speed_L_error-2*speed_L_error_pre+speed_L_error_pre_pre);

    speed_L_duty+=P_L_PID+I_L_PID+D_L_PID;
            //���������޷�
        if(speed_L_duty>6000) speed_L_duty = 6000;
        if(speed_L_duty<-6000) speed_L_duty = -6000;

    speed_L_error_pre_pre=speed_L_error_pre;
    speed_L_error_pre=speed_L_error;

      return (int)speed_L_duty;
}

int Speed_R_PID(int speed_R_want,int speed_R_now,float Speed_R_Kp,float Speed_R_Ki,float Speed_R_Kd)
{

  static int P_R_PID=0;
  static int I_R_PID=0;
  static int D_R_PID=0;

    static int speed_R_duty=0;
    static int speed_R_error=0;
    static int speed_R_error_pre=0;
    static int speed_R_error_pre_pre=0;

      speed_R_error=speed_R_want-speed_R_now;

      P_R_PID=Speed_R_Kp*(speed_R_error-speed_R_error_pre);
      I_R_PID=Speed_R_Ki*(speed_R_error);
      D_R_PID=Speed_R_Kd*(speed_R_error-2*speed_R_error_pre+speed_R_error_pre_pre);

      speed_R_duty+=P_R_PID+I_R_PID+D_R_PID;
                  //���������޷�
                  if(speed_R_duty>6000) speed_R_duty = 6000;
                  if(speed_R_duty<-6000) speed_R_duty = -6000;

      speed_R_error_pre_pre=speed_R_error_pre;
      speed_R_error_pre=speed_R_error;

      return (int)speed_R_duty;
}





//-------------------------------------------------------------------------------------------------------------------
//  ����:      ����ʽPID����
//  ����:      �������
//  ����:      ��
//  ����:      ��˧��
//-------------------------------------------------------------------------------------------------------------------

float l_speed_err1=0;//�󱾴����
float l_speed_err2=0;//���ϴ����
float l_speed_err3=0;//�����ϴ����
float l_jisuan=0;
float l_out=0;
float PID_L(float setpoint,float now_speed,float Kp,float Ki,float Kd)
{
    l_speed_err1=setpoint-now_speed;
    l_jisuan=Kp*(l_speed_err1-l_speed_err2)+Ki*l_speed_err1+Kd*(l_speed_err1+l_speed_err3-2*l_speed_err2);
    l_out=l_jisuan;
    l_speed_err3=l_speed_err2;
    l_speed_err2=l_speed_err1;
    return l_out;
}

 float r_speed_err1=0;//�ұ������
 float r_speed_err2=0;//���ϴ����
 float r_speed_err3=0;//�����ϴ����
 float r_jisuan=0;
 float r_out=0;
float PID_R(float setpoint,float now_speed,float Kp,float Ki,float Kd)
{
    r_speed_err1 = setpoint - now_speed;
    r_jisuan=Kp*(r_speed_err1-r_speed_err2)+Ki*r_speed_err1+Kd*(r_speed_err1+r_speed_err3-2*r_speed_err2);
    r_out=r_jisuan;
    r_speed_err3=r_speed_err2;
    r_speed_err2=r_speed_err1;
    return r_out;
}
