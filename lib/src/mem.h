#ifndef  __MEM_H__
#define  __MEM_H__

#include "types.h"

#define poke( address, data )	( *( (volatile unsigned char*)(address) ) = ( (unsigned char)(data) ) )
#define peek( address )			( *( (volatile unsigned char*)(address) ) )
#define pokew( address, data )	( *( (volatile unsigned int*)(address) ) = ( (unsigned int)(data) ) )
#define peekw( address )		( *( (volatile unsigned int*)(address) ) )

extern void memcpy(uint8_t *dest, uint8_t *src, uint16_t n);
extern void memset(uint8_t *s, uint8_t c, uint16_t n);

#endif  // __MEM_H__
