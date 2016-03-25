
clean:TAR:=clean
all:TAR:=all
all clean:
	@make -j8 $(MAKEFLAGS) -C 01led	$(TAR)
	@make -j8 $(MAKEFLAGS) -C 02button $(TAR)
	@make -j8 $(MAKEFLAGS) -C 04led_nak $(TAR)
