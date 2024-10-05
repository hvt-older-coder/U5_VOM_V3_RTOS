################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../TouchGFX/assets/App/app_touchgfx.c 

C_DEPS += \
./TouchGFX/assets/App/app_touchgfx.d 

OBJS += \
./TouchGFX/assets/App/app_touchgfx.o 


# Each subdirectory must supply rules for building sources it contributes
TouchGFX/assets/App/%.o TouchGFX/assets/App/%.su TouchGFX/assets/App/%.cyclo: ../TouchGFX/assets/App/%.c TouchGFX/assets/App/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U545xx -DUSE_NUCLEO_64 -c -I../Core/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../Drivers/CMSIS/Include -I../Drivers/BSP/STM32U5xx_Nucleo -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/generated/videos/include -I../TouchGFX/gui/include -I"D:/U5/U5_VOM_V3_RTOS_4.24.1/TouchGFX" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-TouchGFX-2f-assets-2f-App

clean-TouchGFX-2f-assets-2f-App:
	-$(RM) ./TouchGFX/assets/App/app_touchgfx.cyclo ./TouchGFX/assets/App/app_touchgfx.d ./TouchGFX/assets/App/app_touchgfx.o ./TouchGFX/assets/App/app_touchgfx.su

.PHONY: clean-TouchGFX-2f-assets-2f-App

