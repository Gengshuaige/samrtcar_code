#include "zf_common_headfile.h"

//上位机初始化
void Upper_computer_initialize(void)
{
//    uart_init(UART_2,115200,UART2_TX_P10_5,UART2_RX_P10_6);
}

//电机及PID初始化
void motor_initialize()
{
    gpio_init(D12,GPO, GPIO_HIGH, GPO_PUSH_PULL);
    pwm_init(TIM4_PWM_MAP1_CH2_D13,17000,0);
    gpio_init(D15,GPO, GPIO_HIGH, GPO_PUSH_PULL);
    pwm_init(TIM4_PWM_MAP1_CH3_D14,17000,0);
}

//舵机初始化
void Servo_initialize()
{
    pwm_init(TIM2_PWM_MAP1_CH1_A15, 50, 662);
//	pid_rest_servo(&Servo_key,50,0,0);
//	enter_servo_judge=1;
}

//蜂鸣器初始化
void buzzer_initialize()
{
    gpio_init(C13, GPO, GPIO_LOW, GPO_PUSH_PULL);
}

//编码器初始化
void Encoder_initialize()
{
    encoder_dir_init(TIM1_ENCOEDER, TIM1_ENCOEDER_MAP3_CH1_E9, TIM1_ENCOEDER_MAP3_CH2_E11);
    encoder_dir_init(TIM9_ENCOEDER, TIM9_ENCOEDER_MAP3_CH1_D9, TIM9_ENCOEDER_MAP3_CH2_D11);
}

//屏幕初始化
void isp200_initialize()
{
	ips200_init(IPS200_TYPE_PARALLEL8);
//    lcd_init();
}

void tft180_initialize()
{
    tft180_init();
}

//摄像头初始化
void Camera_initialize()
{
	if(mt9v03x_init())
	    bibibi(1);
}

//电感初始化
void adc_initialize()
{
    adc_init(ADC1_IN12_C2, ADC_12BIT);
    adc_init(ADC1_IN13_C3, ADC_12BIT);
    adc_init(ADC1_IN11_C1, ADC_12BIT);
    adc_init(ADC1_IN14_C4, ADC_12BIT);
    adc_init(ADC1_IN15_C5, ADC_12BIT);
}

//定时器初始化
void timer_initialize()
{
    pit_ms_init(TIM7_PIT,5);
}

//按键初始化
void key_initialize()
{
    gpio_init(B0,GPI,GPIO_HIGH,GPI_PULL_UP);//KEYA5
    gpio_init(B12,GPI,GPIO_HIGH,GPI_PULL_UP);//KEY
    gpio_init(D8,GPI,GPIO_HIGH,GPI_PULL_UP);//KEY
    gpio_init(A8,GPI,GPIO_HIGH,GPI_PULL_UP);//KEY
    gpio_init(E0,GPI,GPIO_HIGH,GPI_PULL_UP);//拨码开关
    gpio_init(E1,GPI,GPIO_HIGH,GPI_PULL_UP);//拨码开关
    gpio_init(E2,GPI,GPIO_HIGH,GPI_PULL_UP);//拨码开关
    gpio_init(E3,GPI,GPIO_HIGH,GPI_PULL_UP);//拨码开关
    pages = Page0 ;
}

//陀螺仪icm20602初始化
void icm20602_initialize()
{
    icm20602_init();
}

//陀螺仪imu660初始化
void imu660ra_initialize()
{
    imu660ra_init();
}

void tof_initialize()
{
    dl1a_init();
}

void uart_initialize()
{
    uart_init(UART_2, 115200, UART2_MAP1_TX_D5, UART2_MAP1_RX_D6);
}

void ch573_initialize()
{
    wireless_ch573_init();
}

//所有初始化
void all_initialize()
{
    Upper_computer_initialize();  //上位机初始化
	motor_initialize();//电机及PID初始化
	Servo_initialize();//舵机初始化
	key_initialize();  //按键初始化
	imu660ra_initialize();//陀螺仪初始化
	tft180_initialize();//屏幕初始化
	Camera_initialize();//摄像头初始化
	adc_initialize();//电感初始化
	Encoder_initialize();//编码器初始化
	buzzer_initialize();//蜂鸣器初始化
    timer_initialize();//定时器初始化
    tof_initialize();//tof初始化
    ch573_initialize();//ch573初始化
}











