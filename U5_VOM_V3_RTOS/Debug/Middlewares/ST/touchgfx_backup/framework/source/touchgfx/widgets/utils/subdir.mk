################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Middlewares/ST/touchgfx_backup/framework/source/touchgfx/widgets/utils/qrcodegen.cpp 

OBJS += \
./Middlewares/ST/touchgfx_backup/framework/source/touchgfx/widgets/utils/qrcodegen.o 

CPP_DEPS += \
./Middlewares/ST/touchgfx_backup/framework/source/touchgfx/widgets/utils/qrcodegen.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/ST/touchgfx_backup/framework/source/touchgfx/widgets/utils/%.o Middlewares/ST/touchgfx_backup/framework/source/touchgfx/widgets/utils/%.su Middlewares/ST/touchgfx_backup/framework/source/touchgfx/widgets/utils/%.cyclo: ../Middlewares/ST/touchgfx_backup/framework/source/touchgfx/widgets/utils/%.cpp Middlewares/ST/touchgfx_backup/framework/source/touchgfx/widgets/utils/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m33 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U545xx -DUSE_NUCLEO_64 -c -I../Core/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../Drivers/CMSIS/Include -I../Drivers/BSP/STM32U5xx_Nucleo -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/generated/videos/include -I../TouchGFX/gui/include -I"C:/Users/Admin/Documents/GitHub/vom_v1/U5_VOM_V3_RTOS_4.24.0/TouchGFX" -I"C:/Users/Admin/Documents/GitHub/vom_v1/U5_VOM_V3_RTOS_4.24.0/Core/Src" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-ST-2f-touchgfx_backup-2f-framework-2f-source-2f-touchgfx-2f-widgets-2f-utils

clean-Middlewares-2f-ST-2f-touchgfx_backup-2f-framework-2f-source-2f-touchgfx-2f-widgets-2f-utils:
	-$(RM) ./Middlewares/ST/touchgfx_backup/framework/source/touchgfx/widgets/utils/qrcodegen.cyclo ./Middlewares/ST/touchgfx_backup/framework/source/touchgfx/widgets/utils/qrcodegen.d ./Middlewares/ST/touchgfx_backup/framework/source/touchgfx/widgets/utils/qrcodegen.o ./Middlewares/ST/touchgfx_backup/framework/source/touchgfx/widgets/utils/qrcodegen.su

.PHONY: clean-Middlewares-2f-ST-2f-touchgfx_backup-2f-framework-2f-source-2f-touchgfx-2f-widgets-2f-utils

