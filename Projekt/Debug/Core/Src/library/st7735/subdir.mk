################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/library/st7735/fonts.c \
../Core/Src/library/st7735/st7735.c 

OBJS += \
./Core/Src/library/st7735/fonts.o \
./Core/Src/library/st7735/st7735.o 

C_DEPS += \
./Core/Src/library/st7735/fonts.d \
./Core/Src/library/st7735/st7735.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/library/st7735/%.o Core/Src/library/st7735/%.su Core/Src/library/st7735/%.cyclo: ../Core/Src/library/st7735/%.c Core/Src/library/st7735/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-library-2f-st7735

clean-Core-2f-Src-2f-library-2f-st7735:
	-$(RM) ./Core/Src/library/st7735/fonts.cyclo ./Core/Src/library/st7735/fonts.d ./Core/Src/library/st7735/fonts.o ./Core/Src/library/st7735/fonts.su ./Core/Src/library/st7735/st7735.cyclo ./Core/Src/library/st7735/st7735.d ./Core/Src/library/st7735/st7735.o ./Core/Src/library/st7735/st7735.su

.PHONY: clean-Core-2f-Src-2f-library-2f-st7735

