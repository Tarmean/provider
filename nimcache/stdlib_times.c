/* Generated by Nim Compiler v0.13.0 */
/*   (c) 2015 Andreas Rumpf */
/* The generated code is subject to the original license. */
/* Compiled for: Linux, amd64, gcc */
/* Command for C compiler:
   gcc -c  -w -O3 -fno-strict-aliasing  -I/usr/lib/nim -o /home/cyril/Projects/provider/nimcache/stdlib_times.o /home/cyril/Projects/provider/nimcache/stdlib_times.c */
#define NIM_INTBITS 64

#include "nimbase.h"
#include <time.h>
#include <sys/select.h>
#include <string.h>
#include <sys/time.h>

N_NIMCALL(NF, ntepochTime)(void) {
	NF result;
	struct timeval a;
	result = 0;
	memset((void*)(&a), 0, sizeof(a));
	gettimeofday((&a), NIM_NIL);
	result = ((NF)(((double) (a.tv_sec))) + (NF)(((NF)(((double) (a.tv_usec))) * (NF)(9.9999999999999995e-07))));
	return result;
}
NIM_EXTERNC N_NOINLINE(void, stdlib_timesInit000)(void) {
	tzset();
}

NIM_EXTERNC N_NOINLINE(void, stdlib_timesDatInit000)(void) {
}

