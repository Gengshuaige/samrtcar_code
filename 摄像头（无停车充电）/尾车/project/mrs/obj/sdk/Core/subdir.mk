################################################################################
# �Զ����ɵ��ļ�����Ҫ�༭��
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/��ֲ�󳵴���/����ͷ/libraries/sdk/Core/core_riscv.c 

OBJS += \
./sdk/Core/core_riscv.o 

C_DEPS += \
./sdk/Core/core_riscv.d 


# Each subdirectory must supply rules for building sources it contributes
sdk/Core/core_riscv.o: D:/��ֲ�󳵴���/����ͷ/libraries/sdk/Core/core_riscv.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\��ֲ�󳵴���\����ͷ\Libraries\doc" -I"D:\��ֲ�󳵴���\����ͷ\libraries\sdk\Core" -I"D:\��ֲ�󳵴���\����ͷ\libraries\sdk\Ld" -I"D:\��ֲ�󳵴���\����ͷ\libraries\sdk\Peripheral" -I"D:\��ֲ�󳵴���\����ͷ\libraries\sdk\Startup" -I"D:\��ֲ�󳵴���\����ͷ\project\user\inc" -I"D:\��ֲ�󳵴���\����ͷ\libraries\zf_common" -I"D:\��ֲ�󳵴���\����ͷ\libraries\zf_device" -I"D:\��ֲ�󳵴���\����ͷ\project\code" -I"D:\��ֲ�󳵴���\����ͷ\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

