TARGET		:=15rtc_01time
START_OBJ	:=start.o
OBJS		:=main.o rtc.o
BIN		:=$(TARGET).bin
ADDR		:=0x50000000

CC		:=arm-linux-gcc
LD		:=arm-linux-ld
OBJCOPY		:=arm-linux-objcopy
AS		:=arm-linux-as

#########################################################

all:$(TARGET)
	@$(OBJCOPY) -O binary $(TARGET) $(ROOT_DIR)/$(BIN)
	@echo "OBJCOPY		 $(TARGET)"
$(TARGET):$(START_OBJ) $(OBJS)
	@$(LD) $(START_OBJ) $(OBJS) -o $(TARGET) -Ttext $(ADDR)
	@echo "LD		 $(TARGET)"
%o:%c
	@$(CC) -c -o $@ $<
	@echo "CC		 $@"
%o:%s
	@$(AS) -o $@ $<
	@echo "AS		 $@"
clean:
	@rm $(TARGET) $(START_OBJ) $(OBJS) -rf
	@echo "$(TARGET)		 .CLEARN"
