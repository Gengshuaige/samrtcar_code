################################################################################
# �Զ����ɵ��ļ�����Ҫ�༭��
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/��ֲ�󳵴���/Seekfree_CH32V307VCT6_Opensource_Library/project/code/Control.c \
D:/��ֲ�󳵴���/Seekfree_CH32V307VCT6_Opensource_Library/project/code/DajinFa.c \
D:/��ֲ�󳵴���/Seekfree_CH32V307VCT6_Opensource_Library/project/code/KEY.c \
D:/��ֲ�󳵴���/Seekfree_CH32V307VCT6_Opensource_Library/project/code/Menu_2.0.c \
D:/��ֲ�󳵴���/Seekfree_CH32V307VCT6_Opensource_Library/project/code/My_PID.c \
D:/��ֲ�󳵴���/Seekfree_CH32V307VCT6_Opensource_Library/project/code/My_huidu.c \
D:/��ֲ�󳵴���/Seekfree_CH32V307VCT6_Opensource_Library/project/code/PID.c \
D:/��ֲ�󳵴���/Seekfree_CH32V307VCT6_Opensource_Library/project/code/TELL_shizi.c \
D:/��ֲ�󳵴���/Seekfree_CH32V307VCT6_Opensource_Library/project/code/Y_stack.c \
D:/��ֲ�󳵴���/Seekfree_CH32V307VCT6_Opensource_Library/project/code/Yuan_huan.c \
D:/��ֲ�󳵴���/Seekfree_CH32V307VCT6_Opensource_Library/project/code/ZHONGXIAN.c \
D:/��ֲ�󳵴���/Seekfree_CH32V307VCT6_Opensource_Library/project/code/charge.c \
D:/��ֲ�󳵴���/Seekfree_CH32V307VCT6_Opensource_Library/project/code/debug.c \
D:/��ֲ�󳵴���/Seekfree_CH32V307VCT6_Opensource_Library/project/code/dianci.c \
D:/��ֲ�󳵴���/Seekfree_CH32V307VCT6_Opensource_Library/project/code/icm20602_chuli.c \
D:/��ֲ�󳵴���/Seekfree_CH32V307VCT6_Opensource_Library/project/code/initialize.c \
D:/��ֲ�󳵴���/Seekfree_CH32V307VCT6_Opensource_Library/project/code/nitoushi.c \
D:/��ֲ�󳵴���/Seekfree_CH32V307VCT6_Opensource_Library/project/code/tof.c \
D:/��ֲ�󳵴���/Seekfree_CH32V307VCT6_Opensource_Library/project/code/utils.c \
D:/��ֲ�󳵴���/Seekfree_CH32V307VCT6_Opensource_Library/project/code/zhangai.c 

OBJS += \
./code/Control.o \
./code/DajinFa.o \
./code/KEY.o \
./code/Menu_2.0.o \
./code/My_PID.o \
./code/My_huidu.o \
./code/PID.o \
./code/TELL_shizi.o \
./code/Y_stack.o \
./code/Yuan_huan.o \
./code/ZHONGXIAN.o \
./code/charge.o \
./code/debug.o \
./code/dianci.o \
./code/icm20602_chuli.o \
./code/initialize.o \
./code/nitoushi.o \
./code/tof.o \
./code/utils.o \
./code/zhangai.o 

C_DEPS += \
./code/Control.d \
./code/DajinFa.d \
./code/KEY.d \
./code/Menu_2.0.d \
./code/My_PID.d \
./code/My_huidu.d \
./code/PID.d \
./code/TELL_shizi.d \
./code/Y_stack.d \
./code/Yuan_huan.d \
./code/ZHONGXIAN.d \
./code/charge.d \
./code/debug.d \
./code/dianci.d \
./code/icm20602_chuli.d \
./code/initialize.d \
./code/nitoushi.d \
./code/tof.d \
./code/utils.d \
./code/zhangai.d 


# Each subdirectory must supply rules for building sources it contributes
code/Control.o: D:/��ֲ�󳵴���/Seekfree_CH32V307VCT6_Opensource_Library/project/code/Control.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\Libraries\doc" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Core" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Ld" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Peripheral" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Startup" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\project\user\inc" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_common" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_device" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\project\code" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/DajinFa.o: D:/��ֲ�󳵴���/Seekfree_CH32V307VCT6_Opensource_Library/project/code/DajinFa.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\Libraries\doc" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Core" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Ld" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Peripheral" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Startup" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\project\user\inc" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_common" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_device" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\project\code" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/KEY.o: D:/��ֲ�󳵴���/Seekfree_CH32V307VCT6_Opensource_Library/project/code/KEY.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\Libraries\doc" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Core" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Ld" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Peripheral" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Startup" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\project\user\inc" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_common" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_device" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\project\code" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/Menu_2.0.o: D:/��ֲ�󳵴���/Seekfree_CH32V307VCT6_Opensource_Library/project/code/Menu_2.0.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\Libraries\doc" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Core" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Ld" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Peripheral" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Startup" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\project\user\inc" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_common" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_device" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\project\code" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/My_PID.o: D:/��ֲ�󳵴���/Seekfree_CH32V307VCT6_Opensource_Library/project/code/My_PID.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\Libraries\doc" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Core" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Ld" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Peripheral" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Startup" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\project\user\inc" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_common" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_device" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\project\code" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/My_huidu.o: D:/��ֲ�󳵴���/Seekfree_CH32V307VCT6_Opensource_Library/project/code/My_huidu.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\Libraries\doc" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Core" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Ld" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Peripheral" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Startup" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\project\user\inc" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_common" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_device" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\project\code" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/PID.o: D:/��ֲ�󳵴���/Seekfree_CH32V307VCT6_Opensource_Library/project/code/PID.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\Libraries\doc" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Core" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Ld" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Peripheral" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Startup" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\project\user\inc" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_common" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_device" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\project\code" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/TELL_shizi.o: D:/��ֲ�󳵴���/Seekfree_CH32V307VCT6_Opensource_Library/project/code/TELL_shizi.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\Libraries\doc" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Core" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Ld" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Peripheral" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Startup" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\project\user\inc" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_common" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_device" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\project\code" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/Y_stack.o: D:/��ֲ�󳵴���/Seekfree_CH32V307VCT6_Opensource_Library/project/code/Y_stack.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\Libraries\doc" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Core" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Ld" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Peripheral" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Startup" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\project\user\inc" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_common" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_device" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\project\code" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/Yuan_huan.o: D:/��ֲ�󳵴���/Seekfree_CH32V307VCT6_Opensource_Library/project/code/Yuan_huan.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\Libraries\doc" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Core" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Ld" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Peripheral" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Startup" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\project\user\inc" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_common" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_device" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\project\code" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/ZHONGXIAN.o: D:/��ֲ�󳵴���/Seekfree_CH32V307VCT6_Opensource_Library/project/code/ZHONGXIAN.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\Libraries\doc" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Core" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Ld" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Peripheral" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Startup" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\project\user\inc" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_common" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_device" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\project\code" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/charge.o: D:/��ֲ�󳵴���/Seekfree_CH32V307VCT6_Opensource_Library/project/code/charge.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\Libraries\doc" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Core" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Ld" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Peripheral" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Startup" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\project\user\inc" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_common" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_device" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\project\code" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/debug.o: D:/��ֲ�󳵴���/Seekfree_CH32V307VCT6_Opensource_Library/project/code/debug.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\Libraries\doc" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Core" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Ld" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Peripheral" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Startup" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\project\user\inc" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_common" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_device" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\project\code" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/dianci.o: D:/��ֲ�󳵴���/Seekfree_CH32V307VCT6_Opensource_Library/project/code/dianci.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\Libraries\doc" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Core" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Ld" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Peripheral" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Startup" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\project\user\inc" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_common" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_device" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\project\code" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/icm20602_chuli.o: D:/��ֲ�󳵴���/Seekfree_CH32V307VCT6_Opensource_Library/project/code/icm20602_chuli.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\Libraries\doc" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Core" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Ld" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Peripheral" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Startup" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\project\user\inc" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_common" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_device" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\project\code" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/initialize.o: D:/��ֲ�󳵴���/Seekfree_CH32V307VCT6_Opensource_Library/project/code/initialize.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\Libraries\doc" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Core" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Ld" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Peripheral" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Startup" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\project\user\inc" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_common" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_device" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\project\code" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/nitoushi.o: D:/��ֲ�󳵴���/Seekfree_CH32V307VCT6_Opensource_Library/project/code/nitoushi.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\Libraries\doc" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Core" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Ld" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Peripheral" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Startup" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\project\user\inc" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_common" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_device" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\project\code" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/tof.o: D:/��ֲ�󳵴���/Seekfree_CH32V307VCT6_Opensource_Library/project/code/tof.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\Libraries\doc" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Core" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Ld" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Peripheral" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Startup" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\project\user\inc" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_common" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_device" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\project\code" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/utils.o: D:/��ֲ�󳵴���/Seekfree_CH32V307VCT6_Opensource_Library/project/code/utils.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\Libraries\doc" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Core" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Ld" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Peripheral" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Startup" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\project\user\inc" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_common" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_device" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\project\code" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/zhangai.o: D:/��ֲ�󳵴���/Seekfree_CH32V307VCT6_Opensource_Library/project/code/zhangai.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\Libraries\doc" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Core" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Ld" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Peripheral" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\sdk\Startup" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\project\user\inc" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_common" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_device" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\project\code" -I"D:\��ֲ�󳵴���\Seekfree_CH32V307VCT6_Opensource_Library\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

