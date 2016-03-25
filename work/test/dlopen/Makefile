# Author : ZhongHuiping
# Email : zhonghuiping@tydtech.com
# Last modified : 2014-11-13 17:17
# Filename : Makefile
# Description : 


SRCL = lib.c
SRC  = bin.c
OBJL = $(SRCL:.c=.so)
OBJ  = $(SRC:.c= )
LIB_PATH = $(shell pwd)
CFLAG +=-DLIB_FILE=\"$(LIB_PATH)/$(OBJL)\"
CC=gcc

all:$(OBJL)
	$(CC)  -rdynamic -ldl -o $(OBJ) $(CFLAG) $(SRC) 

$(OBJL):$(SRCL) 
	$(CC) -fPIC -shared -o $@ $<
	

clean:
	@rm -fr $(OBJL) $(OBJ)

