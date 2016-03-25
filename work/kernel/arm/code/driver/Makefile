clean:TAR:=clean
all:TAR:=all
all clean : 
	@make -j8 $(MAKEFLAGS) -C 01module $(TAR)
	@make  $(MAKEFLAGS) -C 02gpio $(TAR)
	@make -j8 $(MAKEFLAGS) -C 03clock_nak $(TAR)
	@make -j8 $(MAKEFLAGS) -C 04uart $(TAR)
	@make -j8 $(MAKEFLAGS) -C 05uart_nak $(TAR)
	@make -j8 $(MAKEFLAGS) -C 06ddr_nak $(TAR)
	@make  $(MAKEFLAGS) -C 07exce $(TAR)
	@make  $(MAKEFLAGS) -C 08irq $(TAR)
	@make -j8 $(MAKEFLAGS) -C 09nand $(TAR)
	@make -j8 $(MAKEFLAGS) -C 10adc $(TAR)
	@make  $(MAKEFLAGS) -C 11ts $(TAR)
	@make -j8 $(MAKEFLAGS) -C 12lcd $(TAR)
	@make  $(MAKEFLAGS) -C 13audio $(TAR)
	@make  $(MAKEFLAGS) -C 14net $(TAR)
	@make  $(MAKEFLAGS) -C 15rtc $(TAR)
	@make  $(MAKEFLAGS) -C 16mmu $(TAR)
