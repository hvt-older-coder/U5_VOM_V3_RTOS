################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/modules/adc_module.c \
../Core/Src/modules/i2c_module.c \
../Core/Src/modules/isr_module.c \
../Core/Src/modules/queue_module.c \
../Core/Src/modules/rotary_switch_module.c \
../Core/Src/modules/semaphore_module.c \
../Core/Src/modules/tasks_module.c \
../Core/Src/modules/ui_module.c 

C_DEPS += \
./Core/Src/modules/adc_module.d \
./Core/Src/modules/i2c_module.d \
./Core/Src/modules/isr_module.d \
./Core/Src/modules/queue_module.d \
./Core/Src/modules/rotary_switch_module.d \
./Core/Src/modules/semaphore_module.d \
./Core/Src/modules/tasks_module.d \
./Core/Src/modules/ui_module.d 

OBJS += \
./Core/Src/modules/adc_module.o \
./Core/Src/modules/i2c_module.o \
./Core/Src/modules/isr_module.o \
./Core/Src/modules/queue_module.o \
./Core/Src/modules/rotary_switch_module.o \
./Core/Src/modules/semaphore_module.o \
./Core/Src/modules/tasks_module.o \
./Core/Src/modules/ui_module.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/modules/%.o Core/Src/modules/%.su Core/Src/modules/%.cyclo: ../Core/Src/modules/%.c Core/Src/modules/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U545xx -c -I../Core/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../Drivers/CMSIS/Include -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/generated/videos/include -I../TouchGFX/gui/include -I"D:/U5/workspace/U5_VOM_V3_RTOS-main/U5_VOM_V3_RTOS/TouchGFX" -I"D:/U5/workspace/U5_VOM_V3_RTOS-main/U5_VOM_V3_RTOS/Core/Src" -I../Middlewares/Third_Party/FreeRTOS/Source/include/ -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -I../Middlewares/Third_Party/CMSIS/RTOS2/Include/ -I"D:/U5/workspace/U5_VOM_V3_RTOS-main/U5_VOM_V3_RTOS/Core/Src/modules" -I"D:/U5/workspace/U5_VOM_V3_RTOS-main/U5_VOM_V3_RTOS/Drivers/BSP" -I"D:/U5/workspace/U5_VOM_V3_RTOS-main/U5_VOM_V3_RTOS/Core/Inc/modules" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-modules

clean-Core-2f-Src-2f-modules:
	-$(RM) ./Core/Src/modules/adc_module.cyclo ./Core/Src/modules/adc_module.d ./Core/Src/modules/adc_module.o ./Core/Src/modules/adc_module.su ./Core/Src/modules/i2c_module.cyclo ./Core/Src/modules/i2c_module.d ./Core/Src/modules/i2c_module.o ./Core/Src/modules/i2c_module.su ./Core/Src/modules/isr_module.cyclo ./Core/Src/modules/isr_module.d ./Core/Src/modules/isr_module.o ./Core/Src/modules/isr_module.su ./Core/Src/modules/queue_module.cyclo ./Core/Src/modules/queue_module.d ./Core/Src/modules/queue_module.o ./Core/Src/modules/queue_module.su ./Core/Src/modules/rotary_switch_module.cyclo ./Core/Src/modules/rotary_switch_module.d ./Core/Src/modules/rotary_switch_module.o ./Core/Src/modules/rotary_switch_module.su ./Core/Src/modules/semaphore_module.cyclo ./Core/Src/modules/semaphore_module.d ./Core/Src/modules/semaphore_module.o ./Core/Src/modules/semaphore_module.su ./Core/Src/modules/tasks_module.cyclo ./Core/Src/modules/tasks_module.d ./Core/Src/modules/tasks_module.o ./Core/Src/modules/tasks_module.su ./Core/Src/modules/ui_module.cyclo ./Core/Src/modules/ui_module.d ./Core/Src/modules/ui_module.o ./Core/Src/modules/ui_module.su

.PHONY: clean-Core-2f-Src-2f-modules

