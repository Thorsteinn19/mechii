################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../PWMSERVO/delay.c \
../PWMSERVO/drive.c \
../PWMSERVO/encoder.c \
../PWMSERVO/pwm.c \
../PWMSERVO/serial.c 

OBJS += \
./PWMSERVO/delay.o \
./PWMSERVO/drive.o \
./PWMSERVO/encoder.o \
./PWMSERVO/pwm.o \
./PWMSERVO/serial.o 

C_DEPS += \
./PWMSERVO/delay.d \
./PWMSERVO/drive.d \
./PWMSERVO/encoder.d \
./PWMSERVO/pwm.d \
./PWMSERVO/serial.d 


# Each subdirectory must supply rules for building sources it contributes
PWMSERVO/%.o: ../PWMSERVO/%.c PWMSERVO/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


