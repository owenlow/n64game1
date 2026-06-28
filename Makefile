SOURCE_DIR = src
BUILD_DIR = build
N64_ROM_TITLE = "Hello World"
# N64_MKDFS_ROOT = filesystem
# N64_ROM_REGIONFREE = 1
# N64_ROM_ELFCOMPRESS = 1
# N64_ROM_DSOCOMPRESS = 1
# N64_GCCPREFIX = $(N64_INST)
# N64_TARGET = mips64-elf

include $(N64_INST)/include/n64.mk

# Path to Ares emulator on Windows
ARES_PATH ?= /mnt/c/Users/Gwen/Downloads/ares-v147/ares.exe

ROM_NAME = game1

SRCS = $(wildcard $(SOURCE_DIR)/*.c)
OBJS = $(SRCS:$(SOURCE_DIR)/%.c=$(BUILD_DIR)/%.o)

all: $(ROM_NAME).z64

$(ROM_NAME).z64: $(BUILD_DIR)/$(ROM_NAME).elf

$(BUILD_DIR)/$(ROM_NAME).elf: $(OBJS)

clean:
	rm -rf $(BUILD_DIR) $(ROM_NAME).z64

upload: all
	sc64deployer.exe upload $(ROM_NAME).z64 --reboot

dev: clean upload

ares: all
	$(ARES_PATH) "$$(wslpath -w $(ROM_NAME).z64)"

-include $(wildcard $(BUILD_DIR)/*.d)

.PHONY: all clean upload dev ares
