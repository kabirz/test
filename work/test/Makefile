###############################################################
# Author : ZhongHuiping
# Email : zhonghuiping@tydtech.com
# Last modified : 2014-02-24 19:53
# Filename : Makefile
# Description : build the application code
###############################################################

###############################################################
CC 				:= gcc
HOST_COMPILE	:=  
CROSS_COMPILE 	:= arm-linux-
TARTET		:= $(basename $(wildcard *.c))
CROSS_TARGET 	:= t$(TARTET)
HOST_TARGET 	:= h$(TARTET)
###############################################################

all: $(HOST_TARGET) $(CROSS_TARGET)

$(HOST_TARGET):h%:%.c 
	@$(HOST_COMPILE)$(CC) -o $@ $<
	@echo -e "\033[34m$(HOST_COMPILE)$(CC)	 		\033[32m$@ \033[0m"


$(CROSS_TARGET):t%:%.c 
	@$(CROSS_COMPILE)$(CC) -o $@ $<
	@echo -e "\033[34m$(CROSS_COMPILE)$(CC) 		\033[32m$@ \033[0m"


clean :
	@rm -fr $(HOST_TARGET) $(CROSS_TARGET) 

