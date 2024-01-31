################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/移植后车代码/摄像头/libraries/sdk/Core/core_riscv.c 

OBJS += \
./sdk/Core/core_riscv.o 

C_DEPS += \
./sdk/Core/core_riscv.d 


# Each subdirectory must supply rules for building sources it contributes
sdk/Core/core_riscv.o: D:/移植后车代码/摄像头/libraries/sdk/Core/core_riscv.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"D:\移植后车代码\摄像头\Libraries\doc" -I"D:\移植后车代码\摄像头\libraries\sdk\Core" -I"D:\移植后车代码\摄像头\libraries\sdk\Ld" -I"D:\移植后车代码\摄像头\libraries\sdk\Peripheral" -I"D:\移植后车代码\摄像头\libraries\sdk\Startup" -I"D:\移植后车代码\摄像头\project\user\inc" -I"D:\移植后车代码\摄像头\libraries\zf_common" -I"D:\移植后车代码\摄像头\libraries\zf_device" -I"D:\移植后车代码\摄像头\project\code" -I"D:\移植后车代码\摄像头\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

