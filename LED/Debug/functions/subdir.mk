################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../functions/delay.c \
../functions/drive.c \
../functions/encoder.c \
../functions/pwm.c \
../functions/serial.c 

OBJS += \
./functions/delay.o \
./functions/drive.o \
./functions/encoder.o \
./functions/pwm.o \
./functions/serial.o 

C_DEPS += \
./functions/delay.d \
./functions/drive.d \
./functions/encoder.d \
./functions/pwm.d \
./functions/serial.d 


# Each subdirectory must supply rules for building sources it contributes
functions/%.o: ../functions/%.c functions/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


