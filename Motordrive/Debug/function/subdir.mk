################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/stein/Documents/Eclipsews/Homework/function/flash.c 

OBJS += \
./function/flash.o 

C_DEPS += \
./function/flash.d 


# Each subdirectory must supply rules for building sources it contributes
function/flash.o: C:/Users/stein/Documents/Eclipsews/Homework/function/flash.c function/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\stein\Documents\Eclipsews\Homework" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


