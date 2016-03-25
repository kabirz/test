TARGET		:=14net_04udp
START_OBJ	:=start.o
OBJS		:=main.o dm9000.o net.o pack.o string.o
BIN		:=$(TARGET).bin
ADDR		:=0x00

CC		:=arm-linux-gcc
LD		:=arm-linux-ld
AS		:=arm-linux-as
OBJCOPY		:=arm-linux-objcopy
Q := @
##############################################################

all:$(TARGET)
	@$(OBJCOPY) -O binary $(TARGET) $(ROOT_DIR)/$(BIN)
	@echo "OBJCOPY		 $(TARGET)"

$(TARGET):$(START_OBJ) $(OBJS)
	$(Q)$(LD) $(START_OBJ) $(OBJS) -o $@ -T ld.lds
	$(Q)echo "LD		 $(TARGET)"
%o:%c
	$(Q)$(CC) -c -o $@ $<
	$(Q)echo "CC		 $@"
%o:%s
	$(Q)$(AS) -o $@ $<
	$(Q)echo "AS		 $@"
clean:
	$(Q)rm -fr *.o  $(TARGET)
	$(Q)echo "$(TARGET)		 .CLEARN"
