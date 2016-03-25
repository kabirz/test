
hostprogs-y := test_app
obj-m := led_dev.o led_drv.o
always += $(hostprogs-y)
all: $(ROOT_OBJ)/test/led_driver/ $(ROOT_OBJ)/bin/led_dev.ko $(ROOT_OBJ)/bin/led_drv.ko 
	@echo >/dev/null
$(ROOT_OBJ)/test/led_driver/:
	@mkdir -p $(ROOT_OBJ)/test/led_driver/


$(ROOT_OBJ)/bin/led_dev.ko $(ROOT_OBJ)/bin/led_drv.ko:
	@make  -j8 --no-print-directory -C /home/zhp/code/linux3.4  M=`pwd` modules >/dev/null
	@cp $(obj-m:.o=.ko) $(ROOT_OBJ)/bin
	@rm $(obj-m) $(hostprogs-y) *mod.*  *.ko  Module.symvers modules.order .tmp_versions/ .*.cmd -fr
	@echo "INSTALL		 $(obj-m:.o=.ko)" 

clean:
	@rm  $(obj-m) $(hostprogs-y) *mod.*  *.ko  Module.symvers modules.order .tmp_versions/ .*.cmd -fr
	@echo "clean		led_driver"
