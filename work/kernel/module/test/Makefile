
obj-m := globalmem_3.o complete.o comp_all.o
#hostprogs-y :=netevent
always :=$(hostprogs-y)
CFLAGS_exec.o := -D'EXECPATH="$(kbuild-dir)/exe.txt"'
all: 
	@make  -j8 --no-print-directory -C /lib/modules/${shell uname -r}/build/ M=`pwd` modules

clean:
	@rm  $(obj-m) $(hostprogs-y) *mod.*  *.ko  Module.symvers modules.order .tmp_versions/ .*.cmd -fr
