
obj-m := led_drv.o
all: 
	@make  -j8 --no-print-directory -C /home/zhp/code/linux3.4 M=`pwd` modules

clean:
	@rm  $(obj-m) $(hostprogs-y) *mod.*  .*.o.d *.ko  Module.symvers modules.order .tmp_versions/ .*.cmd -fr
