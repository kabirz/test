BUILD_DIR:=$(subst $(ROOT_DIR)/,,$(shell pwd))
ATARGET :=$(addprefix $(ROOT_OBJ)/$(BUILD_DIR)/,$(TARGET))
AOBJS:=$(addprefix $(ROOT_OBJ)/$(BUILD_DIR)/,$(OBJS))
ASTART_OBJ:=$(addprefix $(ROOT_OBJ)/$(BUILD_DIR)/,$(START_OBJ))
all:$(ROOT_OBJ)/bin/$(TARGET).bin
	@echo >/dev/null 

$(ROOT_OBJ)/bin/$(TARGET).bin:$(ROOT_OBJ)/$(BUILD_DIR) $(ATARGET)
	$(Q)$(OBJCOPY) -O binary $(ATARGET) $(ROOT_OBJ)/bin/$(TARGET).bin
	$(Q)echo "OBJCOPY		 $(TARGET)"
$(ATARGET):$(ASTART_OBJ) $(AOBJS)
	$(Q)$(LD) $(ASTART_OBJ) $(AOBJS) -o $(ATARGET) -Ttext $(ADDR)
	$(Q)echo "LD		 $(TARGET)"

##########################################
$(ROOT_OBJ)/$(BUILD_DIR):
	$(Q)mkdir -p $@

$(ROOT_OBJ)/$(BUILD_DIR)/%.o:$(ROOT_DIR)/$(BUILD_DIR)/%.c $(ROOT_DIR)/$(BUILD_DIR)/regs.h $(ROOT_DIR)/$(BUILD_DIR)/common.h
	$(Q)$(CC) $(CFLAGS) -c -o $@ $<
	$(Q)echo "CC		 $(BUILD_DIR)/$(notdir $@)"
$(ROOT_OBJ)/$(BUILD_DIR)/%.o:$(ROOT_DIR)/$(BUILD_DIR)/%.s
	$(Q)$(AS) -o $@ $<
	$(Q)echo "AS		 $(BUILD_DIR)/$(notdir $@)"
										     
#########################################

clean:
	$(Q)rm $(ASTART_OBJ) $(AOBJS) $(ATARGET) -rf
	$(Q)echo "clean		$(BUILD_DIR)"

