ROM_NAME = game1
SOURCE_DIR = src
BUILD_DIR = build
N64_ROM_TITLE = "Game1!"
# N64_MKDFS_ROOT = filesystem
# N64_ROM_REGIONFREE = 1
# N64_ROM_ELFCOMPRESS = 1
# N64_ROM_DSOCOMPRESS = 1
# N64_GCCPREFIX = $(N64_INST)
# N64_TARGET = mips64-elf

include $(N64_INST)/include/n64.mk

# Path to Ares emulator on Windows
ARES_PATH ?= /mnt/c/Users/Gwen/Downloads/ares-v147/ares.exe

SRCS = $(shell find $(SOURCE_DIR) -name '*.c')
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

-include $(shell find $(BUILD_DIR) -name '*.d' 2>/dev/null)

.PHONY: all clean upload dev ares
