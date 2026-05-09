SRC_DIR = src
BUILD_DIR = build
include $(N64_INST)/include/n64.mk

N64_ROM_TITLE = "Hello World"

vpath %.c $(SRC_DIR)
OBJS = $(BUILD_DIR)/main.o

all: hello.z64

hello.z64: $(BUILD_DIR)/hello.elf

$(BUILD_DIR)/hello.elf: $(OBJS)

clean:
	rm -rf $(BUILD_DIR) hello.z64

upload: all
	sc64deployer.exe upload hello.z64 --reboot

dev: clean upload

-include $(wildcard $(BUILD_DIR)/*.d)

.PHONY: all clean upload dev
