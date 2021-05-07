SDCC=sdcc
HEX2BIN=hex2bin
INCLUDES=-I lib/rel/ -I lib/src/
RELS=lib/rel/crt0msx_msxdos_advanced.rel lib/rel/putchar.rel lib/rel/getchar.rel lib/rel/dos.rel lib/rel/conio.rel lib/rel/mem.rel lib/rel/string.rel
CFLAGS=-mz80 --code-loc 0x0178 $(INCLUDES) --data-loc 0 --no-std-crt0 $(RELS)
OPENMSX=/Applications/openMSX.app/Contents/MacOS/openmsx
MACHINE=Panasonic_FS-A1GT

.PHONY: all clean cleanbuild full

all: build link mvbin clean
	echo "Done"

full: build link mvbin clean test
	echo "Done"

clean:
	rm -f *.sym *.rel *.noi *.map *.lst *.lk *.ihx *.asm && echo "Done"

cleanbuild:
	@rm -rf build && echo "Done"

buildlib: lib/build.sh
	cd lib && sh ../$<

build: main.c
	$(SDCC) $(CFLAGS) $<

link: main.ihx
	@$(HEX2BIN) $<

mvbin: main.bin
	mkdir -p build && mv main.bin build/main.com

test: build/main.com
	cp build/main.com MSXDOS && $(OPENMSX) -machine $(MACHINE) -diska MSXDOS/ && rm MSXDOS/main.com && echo "Done"
