
SRCL = lib.c
SRC  = bin.c
OBJL = $(SRCL:.c=.so)
OBJ  = $(SRC:.c= )
LIB_PATH = $(shell pwd)
CFLAG +=-DLIB_FILE=\"$(LIB_PATH)/$(OBJL)\"
CC=gcc

all:$(OBJL)
	@#$(CC)  -o $(OBJ) $(CFLAG) $(SRC) -rdynamic  -static-libdl  -ldl 
	$(CC)   -o $(OBJ) $(CFLAG) $(SRC) -ldl 

$(OBJL):$(SRCL) 
	$(CC) -fPIC -shared -o $@ $<
	

clean:
	@rm -fr $(OBJL) $(OBJ)
