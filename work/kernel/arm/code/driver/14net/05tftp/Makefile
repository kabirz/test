TARGET		:=14net_05tftp
START_OBJ	:=start.o
OBJS		:=main.o dm9000.o net.o pack.o irq.o unpack.o tftp.o lib.o
BIN		:=$(TARGET).bin
ADDR		:=0x00

CC		:=arm-linux-gcc
LD		:=arm-linux-ld
AS		:=arm-linux-as
OBJCOPY		:=arm-linux-objcopy

##############################################################

all:$(TARGET)
	@$(OBJCOPY) -O binary $(TARGET) $(ROOT_DIR)/$(BIN)
	@echo "OBJCOPY		 $(TARGET)"

$(TARGET):$(START_OBJ) $(OBJS)
	@$(LD) $(START_OBJ) $(OBJS) -o $@ -T ld.lds
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
