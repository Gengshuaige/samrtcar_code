################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/移植后车代码/摄像头/project/code/Control.c \
D:/移植后车代码/摄像头/project/code/DajinFa.c \
D:/移植后车代码/摄像头/project/code/KEY.c \
D:/移植后车代码/摄像头/project/code/Menu_2.0.c \
D:/移植后车代码/摄像头/project/code/My_PID.c \
D:/移植后车代码/摄像头/project/code/My_huidu.c \
D:/移植后车代码/摄像头/project/code/PID.c \
D:/移植后车代码/摄像头/project/code/TELL_shizi.c \
D:/移植后车代码/摄像头/project/code/Y_stack.c \
D:/移植后车代码/摄像头/project/code/Yuan_huan.c \
D:/移植后车代码/摄像头/project/code/ZHONGXIAN.c \
D:/移植后车代码/摄像头/project/code/charge.c \
D:/移植后车代码/摄像头/project/code/debug.c \
D:/移植后车代码/摄像头/project/code/dianci.c \
D:/移植后车代码/摄像头/project/code/icm20602_chuli.c \
D:/移植后车代码/摄像头/project/code/initialize.c \
D:/移植后车代码/摄像头/project/code/nitoushi.c \
D:/移植后车代码/摄像头/project/code/tof.c \
D:/移植后车代码/摄像头/project/code/utils.c \
D:/移植后车代码/摄像头/project/code/zhangai.c 

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
code/Control.o: D:/移植后车代码/摄像头/project/code/Control.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\移植后车代码\摄像头\Libraries\doc" -I"D:\移植后车代码\摄像头\libraries\sdk\Core" -I"D:\移植后车代码\摄像头\libraries\sdk\Ld" -I"D:\移植后车代码\摄像头\libraries\sdk\Peripheral" -I"D:\移植后车代码\摄像头\libraries\sdk\Startup" -I"D:\移植后车代码\摄像头\project\user\inc" -I"D:\移植后车代码\摄像头\libraries\zf_common" -I"D:\移植后车代码\摄像头\libraries\zf_device" -I"D:\移植后车代码\摄像头\project\code" -I"D:\移植后车代码\摄像头\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/DajinFa.o: D:/移植后车代码/摄像头/project/code/DajinFa.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\移植后车代码\摄像头\Libraries\doc" -I"D:\移植后车代码\摄像头\libraries\sdk\Core" -I"D:\移植后车代码\摄像头\libraries\sdk\Ld" -I"D:\移植后车代码\摄像头\libraries\sdk\Peripheral" -I"D:\移植后车代码\摄像头\libraries\sdk\Startup" -I"D:\移植后车代码\摄像头\project\user\inc" -I"D:\移植后车代码\摄像头\libraries\zf_common" -I"D:\移植后车代码\摄像头\libraries\zf_device" -I"D:\移植后车代码\摄像头\project\code" -I"D:\移植后车代码\摄像头\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/KEY.o: D:/移植后车代码/摄像头/project/code/KEY.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\移植后车代码\摄像头\Libraries\doc" -I"D:\移植后车代码\摄像头\libraries\sdk\Core" -I"D:\移植后车代码\摄像头\libraries\sdk\Ld" -I"D:\移植后车代码\摄像头\libraries\sdk\Peripheral" -I"D:\移植后车代码\摄像头\libraries\sdk\Startup" -I"D:\移植后车代码\摄像头\project\user\inc" -I"D:\移植后车代码\摄像头\libraries\zf_common" -I"D:\移植后车代码\摄像头\libraries\zf_device" -I"D:\移植后车代码\摄像头\project\code" -I"D:\移植后车代码\摄像头\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/Menu_2.0.o: D:/移植后车代码/摄像头/project/code/Menu_2.0.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\移植后车代码\摄像头\Libraries\doc" -I"D:\移植后车代码\摄像头\libraries\sdk\Core" -I"D:\移植后车代码\摄像头\libraries\sdk\Ld" -I"D:\移植后车代码\摄像头\libraries\sdk\Peripheral" -I"D:\移植后车代码\摄像头\libraries\sdk\Startup" -I"D:\移植后车代码\摄像头\project\user\inc" -I"D:\移植后车代码\摄像头\libraries\zf_common" -I"D:\移植后车代码\摄像头\libraries\zf_device" -I"D:\移植后车代码\摄像头\project\code" -I"D:\移植后车代码\摄像头\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/My_PID.o: D:/移植后车代码/摄像头/project/code/My_PID.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\移植后车代码\摄像头\Libraries\doc" -I"D:\移植后车代码\摄像头\libraries\sdk\Core" -I"D:\移植后车代码\摄像头\libraries\sdk\Ld" -I"D:\移植后车代码\摄像头\libraries\sdk\Peripheral" -I"D:\移植后车代码\摄像头\libraries\sdk\Startup" -I"D:\移植后车代码\摄像头\project\user\inc" -I"D:\移植后车代码\摄像头\libraries\zf_common" -I"D:\移植后车代码\摄像头\libraries\zf_device" -I"D:\移植后车代码\摄像头\project\code" -I"D:\移植后车代码\摄像头\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/My_huidu.o: D:/移植后车代码/摄像头/project/code/My_huidu.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\移植后车代码\摄像头\Libraries\doc" -I"D:\移植后车代码\摄像头\libraries\sdk\Core" -I"D:\移植后车代码\摄像头\libraries\sdk\Ld" -I"D:\移植后车代码\摄像头\libraries\sdk\Peripheral" -I"D:\移植后车代码\摄像头\libraries\sdk\Startup" -I"D:\移植后车代码\摄像头\project\user\inc" -I"D:\移植后车代码\摄像头\libraries\zf_common" -I"D:\移植后车代码\摄像头\libraries\zf_device" -I"D:\移植后车代码\摄像头\project\code" -I"D:\移植后车代码\摄像头\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/PID.o: D:/移植后车代码/摄像头/project/code/PID.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\移植后车代码\摄像头\Libraries\doc" -I"D:\移植后车代码\摄像头\libraries\sdk\Core" -I"D:\移植后车代码\摄像头\libraries\sdk\Ld" -I"D:\移植后车代码\摄像头\libraries\sdk\Peripheral" -I"D:\移植后车代码\摄像头\libraries\sdk\Startup" -I"D:\移植后车代码\摄像头\project\user\inc" -I"D:\移植后车代码\摄像头\libraries\zf_common" -I"D:\移植后车代码\摄像头\libraries\zf_device" -I"D:\移植后车代码\摄像头\project\code" -I"D:\移植后车代码\摄像头\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/TELL_shizi.o: D:/移植后车代码/摄像头/project/code/TELL_shizi.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\移植后车代码\摄像头\Libraries\doc" -I"D:\移植后车代码\摄像头\libraries\sdk\Core" -I"D:\移植后车代码\摄像头\libraries\sdk\Ld" -I"D:\移植后车代码\摄像头\libraries\sdk\Peripheral" -I"D:\移植后车代码\摄像头\libraries\sdk\Startup" -I"D:\移植后车代码\摄像头\project\user\inc" -I"D:\移植后车代码\摄像头\libraries\zf_common" -I"D:\移植后车代码\摄像头\libraries\zf_device" -I"D:\移植后车代码\摄像头\project\code" -I"D:\移植后车代码\摄像头\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/Y_stack.o: D:/移植后车代码/摄像头/project/code/Y_stack.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\移植后车代码\摄像头\Libraries\doc" -I"D:\移植后车代码\摄像头\libraries\sdk\Core" -I"D:\移植后车代码\摄像头\libraries\sdk\Ld" -I"D:\移植后车代码\摄像头\libraries\sdk\Peripheral" -I"D:\移植后车代码\摄像头\libraries\sdk\Startup" -I"D:\移植后车代码\摄像头\project\user\inc" -I"D:\移植后车代码\摄像头\libraries\zf_common" -I"D:\移植后车代码\摄像头\libraries\zf_device" -I"D:\移植后车代码\摄像头\project\code" -I"D:\移植后车代码\摄像头\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/Yuan_huan.o: D:/移植后车代码/摄像头/project/code/Yuan_huan.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\移植后车代码\摄像头\Libraries\doc" -I"D:\移植后车代码\摄像头\libraries\sdk\Core" -I"D:\移植后车代码\摄像头\libraries\sdk\Ld" -I"D:\移植后车代码\摄像头\libraries\sdk\Peripheral" -I"D:\移植后车代码\摄像头\libraries\sdk\Startup" -I"D:\移植后车代码\摄像头\project\user\inc" -I"D:\移植后车代码\摄像头\libraries\zf_common" -I"D:\移植后车代码\摄像头\libraries\zf_device" -I"D:\移植后车代码\摄像头\project\code" -I"D:\移植后车代码\摄像头\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/ZHONGXIAN.o: D:/移植后车代码/摄像头/project/code/ZHONGXIAN.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\移植后车代码\摄像头\Libraries\doc" -I"D:\移植后车代码\摄像头\libraries\sdk\Core" -I"D:\移植后车代码\摄像头\libraries\sdk\Ld" -I"D:\移植后车代码\摄像头\libraries\sdk\Peripheral" -I"D:\移植后车代码\摄像头\libraries\sdk\Startup" -I"D:\移植后车代码\摄像头\project\user\inc" -I"D:\移植后车代码\摄像头\libraries\zf_common" -I"D:\移植后车代码\摄像头\libraries\zf_device" -I"D:\移植后车代码\摄像头\project\code" -I"D:\移植后车代码\摄像头\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/charge.o: D:/移植后车代码/摄像头/project/code/charge.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\移植后车代码\摄像头\Libraries\doc" -I"D:\移植后车代码\摄像头\libraries\sdk\Core" -I"D:\移植后车代码\摄像头\libraries\sdk\Ld" -I"D:\移植后车代码\摄像头\libraries\sdk\Peripheral" -I"D:\移植后车代码\摄像头\libraries\sdk\Startup" -I"D:\移植后车代码\摄像头\project\user\inc" -I"D:\移植后车代码\摄像头\libraries\zf_common" -I"D:\移植后车代码\摄像头\libraries\zf_device" -I"D:\移植后车代码\摄像头\project\code" -I"D:\移植后车代码\摄像头\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/debug.o: D:/移植后车代码/摄像头/project/code/debug.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\移植后车代码\摄像头\Libraries\doc" -I"D:\移植后车代码\摄像头\libraries\sdk\Core" -I"D:\移植后车代码\摄像头\libraries\sdk\Ld" -I"D:\移植后车代码\摄像头\libraries\sdk\Peripheral" -I"D:\移植后车代码\摄像头\libraries\sdk\Startup" -I"D:\移植后车代码\摄像头\project\user\inc" -I"D:\移植后车代码\摄像头\libraries\zf_common" -I"D:\移植后车代码\摄像头\libraries\zf_device" -I"D:\移植后车代码\摄像头\project\code" -I"D:\移植后车代码\摄像头\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/dianci.o: D:/移植后车代码/摄像头/project/code/dianci.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\移植后车代码\摄像头\Libraries\doc" -I"D:\移植后车代码\摄像头\libraries\sdk\Core" -I"D:\移植后车代码\摄像头\libraries\sdk\Ld" -I"D:\移植后车代码\摄像头\libraries\sdk\Peripheral" -I"D:\移植后车代码\摄像头\libraries\sdk\Startup" -I"D:\移植后车代码\摄像头\project\user\inc" -I"D:\移植后车代码\摄像头\libraries\zf_common" -I"D:\移植后车代码\摄像头\libraries\zf_device" -I"D:\移植后车代码\摄像头\project\code" -I"D:\移植后车代码\摄像头\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/icm20602_chuli.o: D:/移植后车代码/摄像头/project/code/icm20602_chuli.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\移植后车代码\摄像头\Libraries\doc" -I"D:\移植后车代码\摄像头\libraries\sdk\Core" -I"D:\移植后车代码\摄像头\libraries\sdk\Ld" -I"D:\移植后车代码\摄像头\libraries\sdk\Peripheral" -I"D:\移植后车代码\摄像头\libraries\sdk\Startup" -I"D:\移植后车代码\摄像头\project\user\inc" -I"D:\移植后车代码\摄像头\libraries\zf_common" -I"D:\移植后车代码\摄像头\libraries\zf_device" -I"D:\移植后车代码\摄像头\project\code" -I"D:\移植后车代码\摄像头\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/initialize.o: D:/移植后车代码/摄像头/project/code/initialize.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\移植后车代码\摄像头\Libraries\doc" -I"D:\移植后车代码\摄像头\libraries\sdk\Core" -I"D:\移植后车代码\摄像头\libraries\sdk\Ld" -I"D:\移植后车代码\摄像头\libraries\sdk\Peripheral" -I"D:\移植后车代码\摄像头\libraries\sdk\Startup" -I"D:\移植后车代码\摄像头\project\user\inc" -I"D:\移植后车代码\摄像头\libraries\zf_common" -I"D:\移植后车代码\摄像头\libraries\zf_device" -I"D:\移植后车代码\摄像头\project\code" -I"D:\移植后车代码\摄像头\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/nitoushi.o: D:/移植后车代码/摄像头/project/code/nitoushi.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\移植后车代码\摄像头\Libraries\doc" -I"D:\移植后车代码\摄像头\libraries\sdk\Core" -I"D:\移植后车代码\摄像头\libraries\sdk\Ld" -I"D:\移植后车代码\摄像头\libraries\sdk\Peripheral" -I"D:\移植后车代码\摄像头\libraries\sdk\Startup" -I"D:\移植后车代码\摄像头\project\user\inc" -I"D:\移植后车代码\摄像头\libraries\zf_common" -I"D:\移植后车代码\摄像头\libraries\zf_device" -I"D:\移植后车代码\摄像头\project\code" -I"D:\移植后车代码\摄像头\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/tof.o: D:/移植后车代码/摄像头/project/code/tof.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\移植后车代码\摄像头\Libraries\doc" -I"D:\移植后车代码\摄像头\libraries\sdk\Core" -I"D:\移植后车代码\摄像头\libraries\sdk\Ld" -I"D:\移植后车代码\摄像头\libraries\sdk\Peripheral" -I"D:\移植后车代码\摄像头\libraries\sdk\Startup" -I"D:\移植后车代码\摄像头\project\user\inc" -I"D:\移植后车代码\摄像头\libraries\zf_common" -I"D:\移植后车代码\摄像头\libraries\zf_device" -I"D:\移植后车代码\摄像头\project\code" -I"D:\移植后车代码\摄像头\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/utils.o: D:/移植后车代码/摄像头/project/code/utils.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\移植后车代码\摄像头\Libraries\doc" -I"D:\移植后车代码\摄像头\libraries\sdk\Core" -I"D:\移植后车代码\摄像头\libraries\sdk\Ld" -I"D:\移植后车代码\摄像头\libraries\sdk\Peripheral" -I"D:\移植后车代码\摄像头\libraries\sdk\Startup" -I"D:\移植后车代码\摄像头\project\user\inc" -I"D:\移植后车代码\摄像头\libraries\zf_common" -I"D:\移植后车代码\摄像头\libraries\zf_device" -I"D:\移植后车代码\摄像头\project\code" -I"D:\移植后车代码\摄像头\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/zhangai.o: D:/移植后车代码/摄像头/project/code/zhangai.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\移植后车代码\摄像头\Libraries\doc" -I"D:\移植后车代码\摄像头\libraries\sdk\Core" -I"D:\移植后车代码\摄像头\libraries\sdk\Ld" -I"D:\移植后车代码\摄像头\libraries\sdk\Peripheral" -I"D:\移植后车代码\摄像头\libraries\sdk\Startup" -I"D:\移植后车代码\摄像头\project\user\inc" -I"D:\移植后车代码\摄像头\libraries\zf_common" -I"D:\移植后车代码\摄像头\libraries\zf_device" -I"D:\移植后车代码\摄像头\project\code" -I"D:\移植后车代码\摄像头\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

