
clean:TAR:=clean
all:TAR:=all
all clean:
	@make -j8 $(MAKEFLAGS) -C 01pio $(TAR)
	@make -j8 $(MAKEFLAGS) -C 02dma $(TAR)
	@make -j8 $(MAKEFLAGS) -C 03user $(TAR)
