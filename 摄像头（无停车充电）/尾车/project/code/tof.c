#include "zf_common_headfile.h"

//tof�������

uint16 pit_ms_count = 0;

//dl1a_distance_mm����
void pit_handler (void)
{
    if(0 == pit_ms_count % 40)                                                  // ÿ 40ms ��ȡһ�β����Ϣ ���� 40 ms Ƶ�� 25Hz
    {
        dl1a_get_distance();                                                    // ������Ƶ�ʲ�Ӧ���� 30Hz ���ڲ�Ӧ���� 33.33ms
    }
    pit_ms_count = (pit_ms_count == 995) ? (0) : (pit_ms_count + 5);            // 1000ms ���ڼ���
}
