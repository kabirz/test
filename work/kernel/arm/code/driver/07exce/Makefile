clean:TAR:=clean 
all:TAR:=all 
all clean: $(TAR)
	@make -j8 $(MAKEFLAGS) -C 01svc $(TAR)
	@make -j8 $(MAKEFLAGS) -C 02unde $(TAR)
	@make -j8 $(MAKEFLAGS) -C 03swi $(TAR)
