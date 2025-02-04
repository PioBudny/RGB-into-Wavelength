################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/library/apds9960/apds9960.c 

OBJS += \
./Core/Src/library/apds9960/apds9960.o 

C_DEPS += \
./Core/Src/library/apds9960/apds9960.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/library/apds9960/%.o Core/Src/library/apds9960/%.su Core/Src/library/apds9960/%.cyclo: ../Core/Src/library/apds9960/%.c Core/Src/library/apds9960/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-library-2f-apds9960

clean-Core-2f-Src-2f-library-2f-apds9960:
	-$(RM) ./Core/Src/library/apds9960/apds9960.cyclo ./Core/Src/library/apds9960/apds9960.d ./Core/Src/library/apds9960/apds9960.o ./Core/Src/library/apds9960/apds9960.su

.PHONY: clean-Core-2f-Src-2f-library-2f-apds9960

