###############################################
CROSS_COMPILE	:= arm-linux-
CC				:= $(CROSS_COMPILE)gcc
AS				:= $(CROSS_COMPILE)as
LD				:= $(CROSS_COMPILE)ld
OBJCOPY			:= $(CROSS_COMPILE)objcopy
Q 				:= @
###############################################
ROOT_DIR :=$(shell pwd)
ROOT_OBJ :=/tmp/arm
ifeq ($(ROOT_OBJ),)
	ROOT_OBJ :=$(ROOT_DIR)
	DEL_DIR:=
else
	ifneq ($(ROOT_DIR),$(ROOT_OBJ))
	DEL_DIR:=$(ROOT_OBJ)
	endif
endif

all : BBB
clean: AAA
clean:TAR:=clean
all:TAR:=all
MAKEFLAGS += --no-print-directory 

export ROOT_DIR ROOT_OBJ MAKEFLAGS CROSS_COMPILE CC AS LD OBJCOPY Q
all clean:
	@make -j8 $(MAKEFLAGS) -C bootloader/ $(TAR) 
	@make $(MAKEFLAGS) -C driver/ 	$(TAR)
	@make -j8 $(MAKEFLAGS) -C picture/ 	$(TAR)
	@make  $(MAKEFLAGS) -C test/ 	$(TAR)

AAA:
	@rm -fr $(ROOT_OBJ)/snder $(ROOT_OBJ)/bin $(ROOT_OBJ)/play $(DEL_DIR)
BBB:$(ROOT_OBJ)/bin $(ROOT_OBJ)/snder 
	@echo >/dev/null

$(ROOT_OBJ)/bin:
	@mkdir -p  $(DEL_DIR) $(ROOT_OBJ)/bin
	@echo "ECHO		 $(ROOT_OBJ)/bin"

$(ROOT_OBJ)/snder:
	@gcc -o $(ROOT_OBJ)/snder snder.c
	@echo "LD		 snder"
