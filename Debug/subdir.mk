################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../event.cpp \
../main.cpp \
../road.cpp \
../semaphore.cpp \
../vehicle.cpp 

OBJS += \
./event.o \
./main.o \
./road.o \
./semaphore.o \
./vehicle.o 

CPP_DEPS += \
./event.d \
./main.d \
./road.d \
./semaphore.d \
./vehicle.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


