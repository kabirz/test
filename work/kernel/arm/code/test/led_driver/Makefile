
hostprogs-y := test_app
obj-m := led_dev.o led_drv.o
always += $(hostprogs-y)
all: 
	@make  -j8 --no-print-directory -C /home/zhp/code/linux3.4  M=`pwd` modules >/dev/null
	@cp $(obj-m:.o=.ko) $(ROOT_DIR)
	@echo "INSTALL		 $(obj-m:.o=.ko)" 

clean:
	@rm  $(obj-m) $(hostprogs-y) *mod.*  *.ko  Module.symvers modules.order .tmp_versions/ .*.cmd -fr
	@echo "led_driver		 .CLEARN"
