################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/stein/Documents/Eclipsews/Homework/main.c 

OBJS += \
./Homework/main.o 

C_DEPS += \
./Homework/main.d 


# Each subdirectory must supply rules for building sources it contributes
Homework/main.o: C:/Users/stein/Documents/Eclipsews/Homework/main.c Homework/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


