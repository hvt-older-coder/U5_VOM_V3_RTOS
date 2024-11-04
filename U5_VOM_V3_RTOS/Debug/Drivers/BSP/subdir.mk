################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/lm51772_i2c.c \
../Drivers/BSP/z_displ_ILI9XXX.c 

C_DEPS += \
./Drivers/BSP/lm51772_i2c.d \
./Drivers/BSP/z_displ_ILI9XXX.d 

OBJS += \
./Drivers/BSP/lm51772_i2c.o \
./Drivers/BSP/z_displ_ILI9XXX.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/%.o Drivers/BSP/%.su Drivers/BSP/%.cyclo: ../Drivers/BSP/%.c Drivers/BSP/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U545xx -c -I../Core/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../Drivers/CMSIS/Include -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/generated/videos/include -I../TouchGFX/gui/include -I"D:/U5/workspace/U5_VOM_V3_RTOS-main/U5_VOM_V3_RTOS/TouchGFX" -I"D:/U5/workspace/U5_VOM_V3_RTOS-main/U5_VOM_V3_RTOS/Core/Src" -I../Middlewares/Third_Party/FreeRTOS/Source/include/ -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33_NTZ/non_secure/ -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/ -I../Middlewares/Third_Party/CMSIS/RTOS2/Include/ -I"D:/U5/workspace/U5_VOM_V3_RTOS-main/U5_VOM_V3_RTOS/Core/Src/modules" -I"D:/U5/workspace/U5_VOM_V3_RTOS-main/U5_VOM_V3_RTOS/Drivers/BSP" -I"D:/U5/workspace/U5_VOM_V3_RTOS-main/U5_VOM_V3_RTOS/Core/Inc/modules" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP

clean-Drivers-2f-BSP:
	-$(RM) ./Drivers/BSP/lm51772_i2c.cyclo ./Drivers/BSP/lm51772_i2c.d ./Drivers/BSP/lm51772_i2c.o ./Drivers/BSP/lm51772_i2c.su ./Drivers/BSP/z_displ_ILI9XXX.cyclo ./Drivers/BSP/z_displ_ILI9XXX.d ./Drivers/BSP/z_displ_ILI9XXX.o ./Drivers/BSP/z_displ_ILI9XXX.su

.PHONY: clean-Drivers-2f-BSP

