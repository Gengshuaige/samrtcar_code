################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/移植后车代码/摄像头/libraries/zf_common/zf_common_clock.c \
D:/移植后车代码/摄像头/libraries/zf_common/zf_common_debug.c \
D:/移植后车代码/摄像头/libraries/zf_common/zf_common_fifo.c \
D:/移植后车代码/摄像头/libraries/zf_common/zf_common_font.c \
D:/移植后车代码/摄像头/libraries/zf_common/zf_common_function.c \
D:/移植后车代码/摄像头/libraries/zf_common/zf_common_interrupt.c 

OBJS += \
./zf_common/zf_common_clock.o \
./zf_common/zf_common_debug.o \
./zf_common/zf_common_fifo.o \
./zf_common/zf_common_font.o \
./zf_common/zf_common_function.o \
./zf_common/zf_common_interrupt.o 

C_DEPS += \
./zf_common/zf_common_clock.d \
./zf_common/zf_common_debug.d \
./zf_common/zf_common_fifo.d \
./zf_common/zf_common_font.d \
./zf_common/zf_common_function.d \
./zf_common/zf_common_interrupt.d 


# Each subdirectory must supply rules for building sources it contributes
zf_common/zf_common_clock.o: D:/移植后车代码/摄像头/libraries/zf_common/zf_common_clock.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\移植后车代码\摄像头\Libraries\doc" -I"D:\移植后车代码\摄像头\libraries\sdk\Core" -I"D:\移植后车代码\摄像头\libraries\sdk\Ld" -I"D:\移植后车代码\摄像头\libraries\sdk\Peripheral" -I"D:\移植后车代码\摄像头\libraries\sdk\Startup" -I"D:\移植后车代码\摄像头\project\user\inc" -I"D:\移植后车代码\摄像头\libraries\zf_common" -I"D:\移植后车代码\摄像头\libraries\zf_device" -I"D:\移植后车代码\摄像头\project\code" -I"D:\移植后车代码\摄像头\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_common/zf_common_debug.o: D:/移植后车代码/摄像头/libraries/zf_common/zf_common_debug.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\移植后车代码\摄像头\Libraries\doc" -I"D:\移植后车代码\摄像头\libraries\sdk\Core" -I"D:\移植后车代码\摄像头\libraries\sdk\Ld" -I"D:\移植后车代码\摄像头\libraries\sdk\Peripheral" -I"D:\移植后车代码\摄像头\libraries\sdk\Startup" -I"D:\移植后车代码\摄像头\project\user\inc" -I"D:\移植后车代码\摄像头\libraries\zf_common" -I"D:\移植后车代码\摄像头\libraries\zf_device" -I"D:\移植后车代码\摄像头\project\code" -I"D:\移植后车代码\摄像头\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_common/zf_common_fifo.o: D:/移植后车代码/摄像头/libraries/zf_common/zf_common_fifo.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\移植后车代码\摄像头\Libraries\doc" -I"D:\移植后车代码\摄像头\libraries\sdk\Core" -I"D:\移植后车代码\摄像头\libraries\sdk\Ld" -I"D:\移植后车代码\摄像头\libraries\sdk\Peripheral" -I"D:\移植后车代码\摄像头\libraries\sdk\Startup" -I"D:\移植后车代码\摄像头\project\user\inc" -I"D:\移植后车代码\摄像头\libraries\zf_common" -I"D:\移植后车代码\摄像头\libraries\zf_device" -I"D:\移植后车代码\摄像头\project\code" -I"D:\移植后车代码\摄像头\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_common/zf_common_font.o: D:/移植后车代码/摄像头/libraries/zf_common/zf_common_font.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\移植后车代码\摄像头\Libraries\doc" -I"D:\移植后车代码\摄像头\libraries\sdk\Core" -I"D:\移植后车代码\摄像头\libraries\sdk\Ld" -I"D:\移植后车代码\摄像头\libraries\sdk\Peripheral" -I"D:\移植后车代码\摄像头\libraries\sdk\Startup" -I"D:\移植后车代码\摄像头\project\user\inc" -I"D:\移植后车代码\摄像头\libraries\zf_common" -I"D:\移植后车代码\摄像头\libraries\zf_device" -I"D:\移植后车代码\摄像头\project\code" -I"D:\移植后车代码\摄像头\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_common/zf_common_function.o: D:/移植后车代码/摄像头/libraries/zf_common/zf_common_function.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\移植后车代码\摄像头\Libraries\doc" -I"D:\移植后车代码\摄像头\libraries\sdk\Core" -I"D:\移植后车代码\摄像头\libraries\sdk\Ld" -I"D:\移植后车代码\摄像头\libraries\sdk\Peripheral" -I"D:\移植后车代码\摄像头\libraries\sdk\Startup" -I"D:\移植后车代码\摄像头\project\user\inc" -I"D:\移植后车代码\摄像头\libraries\zf_common" -I"D:\移植后车代码\摄像头\libraries\zf_device" -I"D:\移植后车代码\摄像头\project\code" -I"D:\移植后车代码\摄像头\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
zf_common/zf_common_interrupt.o: D:/移植后车代码/摄像头/libraries/zf_common/zf_common_interrupt.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\移植后车代码\摄像头\Libraries\doc" -I"D:\移植后车代码\摄像头\libraries\sdk\Core" -I"D:\移植后车代码\摄像头\libraries\sdk\Ld" -I"D:\移植后车代码\摄像头\libraries\sdk\Peripheral" -I"D:\移植后车代码\摄像头\libraries\sdk\Startup" -I"D:\移植后车代码\摄像头\project\user\inc" -I"D:\移植后车代码\摄像头\libraries\zf_common" -I"D:\移植后车代码\摄像头\libraries\zf_device" -I"D:\移植后车代码\摄像头\project\code" -I"D:\移植后车代码\摄像头\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

