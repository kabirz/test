
clean:TAR:=clean
all:TAR:=all

all clean:
	@make -j8 $(MAKEFLAGS) -C 01separate $(TAR)
	@make -j8 $(MAKEFLAGS) -C 02auto_pst	$(TAR)
	@make -j8 $(MAKEFLAGS) -C 03interrupt $(TAR)
	@make -j8 $(MAKEFLAGS) -C 04wdt	$(TAR)

