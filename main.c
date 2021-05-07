#include "conio.h"
#include "dos.h"
#include "mem.h"
#include "string.h"
#include <stdlib.h>

int main(char** argv, int argc) {
    puts("Hello, world :-) YEY\r\n");
    if(argc>0){ puts(argv[0]); puts("\r\n"); }

	char * fufufu=malloc(6);

	/*
	uint8_t aaa = strLen("qwert\0");
	itoa(argc,fufufu,5);
	puts(fufufu); puts("\r\n");
	*/
	poke(0xFCAB,0xFF);
	puts("poking with 255");
	uint8_t memoria = peek(0xFCAB);
    itoa(memoria,fufufu,5);
    puts(fufufu); puts("\r\n");

    /* poke(0xFD9F,0xC7); */
    exit(0);
}
