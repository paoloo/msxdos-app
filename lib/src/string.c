#include "types.h"
#include "string.h"


int	strLen(char *adr) __naked
{
adr;
    __asm

	push ix
	ld ix,#0
	add ix,sp
	ld l,4(ix)
	ld h,5(ix)
	pop ix
	xor	a
	ld	b,a
	ld	c,a
	push	hl
	cpir
	pop	de
	scf
	sbc	hl,de
	ret
    __endasm;
}



char *strReverse(char *str){
    char tmp;
    uint16_t i;
    uint16_t j;
    i = 0;
    j = strLen(str) - 1;
    while (i < j){
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        j--;
        i++;
    }
    return (str);
}


char* itoa(int16_t num, char* str, uint8_t base){
    uint16_t i = 0;
    char isNegative = 0;
    /* Handle 0 explicitely, otherwise empty string is printed for 0 */
    if (num == 0){
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
    // In standard itoa(), negative numbers are handled only with
    // base 10. Otherwise numbers are considered unsigned.
    if (num < 0 && base == 10) {
        isNegative = 1;
        num = -num;
    }
    // Process individual digits
    while (num != 0) {
        uint16_t rem = num % base;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/base;
    }
    // If number is negative, append '-'
    if (isNegative) { str[i++] = '-'; }
    str[i] = '\0'; // Append string terminator
    // Reverse the string
    strReverse(str);
    return str;
}
