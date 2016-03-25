ROOT_DIR :=$(shell pwd)/bin
all : BBB
clean: AAA
clean:TAR:=clean
all:TAR:=all
MAKEFLAGS += --no-print-directory 
export ROOT_DIR MAKEFLAGS
all clean:
	@make -j8 $(MAKEFLAGS) -C bootloader/ $(TAR) 
	@make $(MAKEFLAGS) -C driver/ 	$(TAR)
	@make -j8 $(MAKEFLAGS) -C picture/ 	$(TAR)
	@make  $(MAKEFLAGS) -C test/ 	$(TAR)

AAA:
	@rm -fr snder bin
	@echo "snder		 .CLEARN"
BBB:
	@mkdir -p $(ROOT_DIR)
	@echo "ECHO		 $(ROOT_DIR)"
	@gcc -o snder snder.c
	@echo "LD		 snder"
