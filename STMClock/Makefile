APP = stm32_peripherals
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
OBJCOPY = arm-none-eabi-objcopy
OBJDUMP = arm-none-eabi-objdump
OBJSIZE = arm-none-eabi-size
LDFILE = flashboot.ld

C_FLAGS = -march=armv7 -mthumb -c -I ../include/ -I .
L_FLAGS = -Map=$(APP).map

C_OBJ = main.o
A_OBJ = startup.o

all: $(C_OBJ) $(A_OBJ) $(LIB)
	$(LD) -T $(LDFILE) -o $(APP).elf $(A_OBJ) $(C_OBJ) $(L_FLAGS) 
	$(OBJCOPY) -O ihex $(APP).elf $(APP).hex
	$(OBJDUMP) -D $(APP).elf > $(APP)_dump.txt
	$(OBJSIZE) $(APP).elf

main.o: stm32f103.h

%.o: %.c 
	$(CC) $(C_FLAGS) $< 

%.o: %.s
	$(CC) $(C_FLAGS) $< 

clean:
	rm -f *.o *~ $(APP).elf $(APP).map $(APP).hex $(APP)_dump.txt
