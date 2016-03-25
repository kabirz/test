clean:TAR:=clean
all:TAR:=all
all clean:  
	@make -j8 $(MAKEFLAGS) -C 01soft $(TAR)
	@make -j8 $(MAKEFLAGS) -C 02wdt $(TAR)
	@make -j8 $(MAKEFLAGS) -C 03button $(TAR)
	@make -j8 $(MAKEFLAGS) -C 04soft_nak $(TAR)
	@make -j8 $(MAKEFLAGS) -C 05wdt_nak $(TAR)
	@make -j8 $(MAKEFLAGS) -C 06soft_vec $(TAR)
	@make -j8 $(MAKEFLAGS) -C 07wdt_vec $(TAR)
	@make -j8 $(MAKEFLAGS) -C 08button_vec $(TAR)
