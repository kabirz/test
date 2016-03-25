include $(ROOT_DIR)/clear.mk
TARGET		:= bootloader
START_OBJ	:= start.o
OBJS		:= main.o boot.o clock.o ddr.o led.o nand.o dm9000.o irq.o wdt.o uart.o lib.o
ADDR		:= 0x57000000
include $(ROOT_DIR)/rule.mk
