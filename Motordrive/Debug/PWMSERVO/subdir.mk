################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../PWMSERVO/delay.c \
../PWMSERVO/serial.c \
../PWMSERVO/servo.c 

OBJS += \
./PWMSERVO/delay.o \
./PWMSERVO/serial.o \
./PWMSERVO/servo.o 

C_DEPS += \
./PWMSERVO/delay.d \
./PWMSERVO/serial.d \
./PWMSERVO/servo.d 


# Each subdirectory must supply rules for building sources it contributes
PWMSERVO/%.o: ../PWMSERVO/%.c PWMSERVO/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\stein\Documents\Eclipsews\Homework" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


