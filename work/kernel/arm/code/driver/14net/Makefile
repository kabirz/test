clean:TAR:=clean 
all:TAR:=all 

all clean: $(TAR)
	@make -j8 $(MAKEFLAGS) -C 01recv $(TAR)
	@make -j8 $(MAKEFLAGS) -C 02recv_irq $(TAR)
	@make -j8 $(MAKEFLAGS) -C 03send $(TAR)
	@make -j8 $(MAKEFLAGS) -C 04udp $(TAR)
	@make -j8 $(MAKEFLAGS) -C 05tftp $(TAR)
