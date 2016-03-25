clean:TAR:=clean 
all:TAR:=all 

all clean:
	@make -j8 $(MAKEFLAGS) -C 01time $(TAR)
	@make -j8 $(MAKEFLAGS) -C 02alarm $(TAR) 
	@make -j8 $(MAKEFLAGS) -C 03tic $(TAR)
