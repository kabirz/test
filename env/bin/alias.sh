alias abcd='make -C `get_build_var TARGET_OUT_INTERMEDIATES`/KERNEL_OBJ \
		KBUILD_SRC=`gettop`/`get_build_var LINUX_KERNEL_VERSION` \
			KBUILD_EXTMOD="" -f `gettop`/`get_build_var LINUX_KERNEL_VERSION`/Makefile \
				`get_build_var KERNEL_DEFCONFIG`'

alias abco='make -C kernel-3.10 O=`gettop`/`get_build_var TARGET_OUT_INTERMEDIATES`/KERNEL_OBJ \
	ARCH=`get_build_var TARGET_ARCH` MTK_TARGET_PROJECT=`get_build_var TARGET_DEVICE` \
	CROSS_COMPILE=`gettop`/`get_build_var KERNEL_CROSS_COMPILE`  ROOTDIR=`gettop` menuconfig && \
	cp `gettop`/`get_build_var TARGET_OUT_INTERMEDIATES`/KERNEL_OBJ/.config \
	`get_build_var LINUX_KERNEL_VERSION`/arch/`get_build_var TARGET_ARCH`/configs/`get_build_var KERNEL_DEFCONFIG`'

alias abk='make -j8 -C `get_build_var LINUX_KERNEL_VERSION` O=`gettop`/`get_build_var TARGET_OUT_INTERMEDIATES`/KERNEL_OBJ ARCH=`get_build_var TARGET_ARCH` MTK_TARGET_PROJECT=`get_build_var TARGET_DEVICE` CROSS_COMPILE=`gettop`/`get_build_var KERNEL_CROSS_COMPILE` ROOTDIR=`gettop`'

alias abb='`get_build_var ANDROID_BUILD_PATHS`/acp  -fp `get_build_var TARGET_OUT_INTERMEDIATES`/KERNEL_OBJ/arch/arm64/boot/Image.gz-dtb \
	`get_build_var PRODUCT_OUT`/kernel ; \
	`get_build_var ANDROID_BUILD_PATHS`/mkbootimg --kernel `get_build_var PRODUCT_OUT`/kernel  \
	--ramdisk `get_build_var PRODUCT_OUT`/ramdisk.img --cmdline 'bootopt=64S3,32N2,64N2' \
	--base 0x40000000  --ramdisk_offset 0x04000000 --kernel_offset 0x00080000 --tags_offset 0xE000000 \
	--board 1421928847  --kernel_offset 0x00080000 --ramdisk_offset 0x04000000 --tags_offset 0xE000000 \
	--output `get_build_var PRODUCT_OUT`/boot.img'

