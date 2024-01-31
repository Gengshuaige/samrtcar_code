#include "zf_common_headfile.h"

//tof测距配置

uint16 pit_ms_count = 0;

//dl1a_distance_mm可用
void pit_handler (void)
{
    if(0 == pit_ms_count % 40)                                                  // 每 40ms 获取一次测距信息 周期 40 ms 频率 25Hz
    {
        dl1a_get_distance();                                                    // 测距调用频率不应高于 30Hz 周期不应低于 33.33ms
    }
    pit_ms_count = (pit_ms_count == 995) ? (0) : (pit_ms_count + 5);            // 1000ms 周期计数
}
