/* Generated by Nim Compiler v0.13.0 */
/*   (c) 2015 Andreas Rumpf */
/* The generated code is subject to the original license. */
/* Compiled for: Linux, amd64, gcc */
/* Command for C compiler:
   gcc -c  -w  -I/usr/lib/nim -o /home/cyril/Projects/provider/nimcache/stdlib_queues.o /home/cyril/Projects/provider/nimcache/stdlib_queues.c */
#define NIM_INTBITS 64

#include "nimbase.h"
static N_INLINE(void, nimFrame)(TFrame* s);
N_NOINLINE(void, stackoverflow_22201)(void);
static N_INLINE(void, popFrame)(void);
extern TFrame* frameptr_19436;

static N_INLINE(void, nimFrame)(TFrame* s) {
	NI LOC1;
	LOC1 = 0;
	{
		if (!(frameptr_19436 == NIM_NIL)) goto LA4;
		LOC1 = ((NI) 0);
	}
	goto LA2;
	LA4: ;
	{
		LOC1 = ((NI) ((NI16)((*frameptr_19436).calldepth + ((NI16) 1))));
	}
	LA2: ;
	(*s).calldepth = ((NI16) (LOC1));
	(*s).prev = frameptr_19436;
	frameptr_19436 = s;
	{
		if (!((*s).calldepth == ((NI16) 2000))) goto LA9;
		stackoverflow_22201();
	}
	LA9: ;
}

static N_INLINE(void, popFrame)(void) {
	frameptr_19436 = (*frameptr_19436).prev;
}
NIM_EXTERNC N_NOINLINE(void, stdlib_queuesInit000)(void) {
	nimfr("queues", "queues.nim")
	popFrame();
}

NIM_EXTERNC N_NOINLINE(void, stdlib_queuesDatInit000)(void) {
}

