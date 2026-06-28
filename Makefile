SRC_DIR = src
BUILD_DIR = build
include $(N64_INST)/include/n64.mk

# Path to Ares emulator on Windows
ARES_PATH ?= /mnt/c/Users/Gwen/Downloads/ares-v147/ares.exe

N64_ROM_TITLE = "Hello World"


vpath %.h $(SRC_DIR)
vpath %.c $(SRC_DIR)
OBJS = $(BUILD_DIR)/*.o

all: hello.z64

hello.z64: $(BUILD_DIR)/hello.elf

$(BUILD_DIR)/hello.elf: $(OBJS)

clean:
	rm -rf $(BUILD_DIR) hello.z64

upload: all
	sc64deployer.exe upload hello.z64 --reboot

dev: clean upload

ares: all
	$(ARES_PATH) "$$(wslpath -w hello.z64)"

-include $(wildcard $(BUILD_DIR)/*.d)

.PHONY: all clean upload dev ares
