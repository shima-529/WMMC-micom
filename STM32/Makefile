# http://vorfee.hatenablog.jp/entry/2015/03/17/173635
# https://www.chihayafuru.jp/tech/index.php/archives/1707
# http://blog.kmckk.com/archives/2601869.html
ARCH=arm-none-eabi
TARGET=output
OUTDIR=Debug

CC=$(ARCH)-gcc
OBJCOPY=$(ARCH)-objcopy
OBJSIZE=$(ARCH)-size

CSRC=$(wildcard src/*.c)
STARTUP=$(wildcard startup/*.s)

INCLUDES=-I./$(OUTDIR) -I./inc -I./CMSIS/core -I./CMSIS/device -I./HAL_Driver/Inc -I./HAL_Driver/Inc/Legacy
DEFINES=-DSTM32F30 -DSTM32F303K8Tx -DSTM32F3 -DSTM32 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303x8
CFLAGS=-Wall $(INCLUDES) -g -Os -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -lm $(DEFINES) -ffunction-sections -fdata-sections
LDFLAGS=-T./LinkerScript.ld -L. -larm_cortexM4lf_math -Wl,--gc-sections

ELF=$(OUTDIR)/$(TARGET).elf
BIN=$(OUTDIR)/$(TARGET).bin

.PHONY: all clean

all: $(ELF) $(BIN)

$(ELF): $(addprefix $(OUTDIR)/,$(subst .c,.o,$(CSRC))) $(addprefix $(OUTDIR)/,$(subst .s,.o,$(STARTUP)))
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	@echo -e '\e[40;37m===========================\e[m'
	@echo -e '\e[40;31m All object files created! \e[m'
	@echo -e '\e[40;37m===========================\e[m'
	$(OBJSIZE) $@

$(BIN): $(ELF)
	$(OBJCOPY) -O binary $< $@

$(OUTDIR)/startup/%.o: startup/%.s
	@mkdir $(dir $@) 1>/dev/null 2>&1 || true
	$(CC) $(CFLAGS) -c -o $@ $<

$(OUTDIR)/src/%.o: src/%.c
	@mkdir $(dir $@) 1>/dev/null 2>&1 || true
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OUTDIR)/src/*.o $(OUTDIR)/startup/*.o $(ELF) $(BIN)
