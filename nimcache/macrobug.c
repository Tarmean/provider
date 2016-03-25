/* Generated by Nim Compiler v0.13.0 */
/*   (c) 2015 Andreas Rumpf */
/* The generated code is subject to the original license. */
/* Compiled for: Linux, amd64, gcc */
/* Command for C compiler:
   gcc -c  -w -pthread  -I/usr/lib/nim -o /home/cyril/Projects/provider/nimcache/macrobug.o /home/cyril/Projects/provider/nimcache/macrobug.c */
#define NIM_INTBITS 64

#include "nimbase.h"
#include <stdio.h>
#include <string.h>
typedef struct TGenericSeq TGenericSeq;
typedef struct NimStringDesc NimStringDesc;
typedef struct TY153007 TY153007;
struct  TGenericSeq  {
NI len;
NI reserved;
};
struct  NimStringDesc  {
  TGenericSeq Sup;
NIM_CHAR data[SEQ_DECL_SIZE];
};
struct  TY153007  {
char dummy;
};
typedef N_NIMCALL_PTR(void, Workerproc148228) (void* thread, void* args);
N_NIMCALL(void, test_153001)(void);
static N_INLINE(void, nimFrame)(TFrame* s);
N_NOINLINE(void, stackoverflow_28801)(void);
static N_INLINE(void, popFrame)(void);
N_NIMCALL(void, nimSpawn3)(Workerproc148228 fn, void* data);
N_NIMCALL(void, testwrapper_153011)(void* thread, void* args);
N_NIMCALL(void, nimArgsPassingDone)(void* p);
N_NIMCALL(void, sync_152624)(void);
static N_INLINE(void, initStackBottomWith)(void* locals);
N_NOINLINE(void, setStackBottom)(void* thestackbottom);
NIM_EXTERNC N_NOINLINE(void, systemInit000)(void);
NIM_EXTERNC N_NOINLINE(void, systemDatInit000)(void);
NIM_EXTERNC N_NOINLINE(void, stdlib_parseutilsInit000)(void);
NIM_EXTERNC N_NOINLINE(void, stdlib_parseutilsDatInit000)(void);
NIM_EXTERNC N_NOINLINE(void, stdlib_strutilsInit000)(void);
NIM_EXTERNC N_NOINLINE(void, stdlib_strutilsDatInit000)(void);
NIM_EXTERNC N_NOINLINE(void, stdlib_timesInit000)(void);
NIM_EXTERNC N_NOINLINE(void, stdlib_timesDatInit000)(void);
NIM_EXTERNC N_NOINLINE(void, stdlib_posixInit000)(void);
NIM_EXTERNC N_NOINLINE(void, stdlib_posixDatInit000)(void);
NIM_EXTERNC N_NOINLINE(void, stdlib_osInit000)(void);
NIM_EXTERNC N_NOINLINE(void, stdlib_osDatInit000)(void);
NIM_EXTERNC N_NOINLINE(void, stdlib_linuxInit000)(void);
NIM_EXTERNC N_NOINLINE(void, stdlib_linuxDatInit000)(void);
NIM_EXTERNC N_NOINLINE(void, stdlib_cpuinfoInit000)(void);
NIM_EXTERNC N_NOINLINE(void, stdlib_cpuinfoDatInit000)(void);
NIM_EXTERNC N_NOINLINE(void, stdlib_cpuloadInit000)(void);
NIM_EXTERNC N_NOINLINE(void, stdlib_cpuloadDatInit000)(void);
NIM_EXTERNC N_NOINLINE(void, stdlib_locksInit000)(void);
NIM_EXTERNC N_NOINLINE(void, stdlib_locksDatInit000)(void);
NIM_EXTERNC N_NOINLINE(void, stdlib_threadpoolInit000)(void);
NIM_EXTERNC N_NOINLINE(void, stdlib_threadpoolDatInit000)(void);
NIM_EXTERNC N_NOINLINE(void, macrobugInit000)(void);
NIM_EXTERNC N_NOINLINE(void, macrobugDatInit000)(void);
STRING_LITERAL(TMP628, "bla", 3);
extern NIM_THREADVAR TFrame* frameptr_26036;

static N_INLINE(void, nimFrame)(TFrame* s) {
	NI LOC1;
	LOC1 = 0;
	{
		if (!(frameptr_26036 == NIM_NIL)) goto LA4;
		LOC1 = ((NI) 0);
	}
	goto LA2;
	LA4: ;
	{
		LOC1 = ((NI) ((NI16)((*frameptr_26036).calldepth + ((NI16) 1))));
	}
	LA2: ;
	(*s).calldepth = ((NI16) (LOC1));
	(*s).prev = frameptr_26036;
	frameptr_26036 = s;
	{
		if (!((*s).calldepth == ((NI16) 2000))) goto LA9;
		stackoverflow_28801();
	}
	LA9: ;
}

static N_INLINE(void, popFrame)(void) {
	frameptr_26036 = (*frameptr_26036).prev;
}

N_NIMCALL(void, test_153001)(void) {
	nimfr("test", "macrobug.nim")
	nimln(3, "macrobug.nim");
	printf("%s\012", ((NimStringDesc*) &TMP628)? (((NimStringDesc*) &TMP628))->data:"nil");
	fflush(stdout);
	popFrame();
}

N_NIMCALL(void, testwrapper_153011)(void* thread, void* args) {
	nimfr("testWrapper", "macrobug.nim")
	nimln(4, "macrobug.nim");
	nimArgsPassingDone(thread);
	test_153001();
	popFrame();
}

static N_INLINE(void, initStackBottomWith)(void* locals) {
	setStackBottom(locals);
}
void PreMainInner() {
	systemInit000();
	stdlib_parseutilsDatInit000();
	stdlib_strutilsDatInit000();
	stdlib_timesDatInit000();
	stdlib_posixDatInit000();
	stdlib_osDatInit000();
	stdlib_linuxDatInit000();
	stdlib_cpuinfoDatInit000();
	stdlib_cpuloadDatInit000();
	stdlib_locksDatInit000();
	stdlib_threadpoolDatInit000();
	macrobugDatInit000();
	stdlib_parseutilsInit000();
	stdlib_strutilsInit000();
	stdlib_timesInit000();
	stdlib_posixInit000();
	stdlib_osInit000();
	stdlib_linuxInit000();
	stdlib_cpuinfoInit000();
	stdlib_cpuloadInit000();
	stdlib_locksInit000();
	stdlib_threadpoolInit000();
}

void PreMain() {
	void (*volatile inner)();
	systemDatInit000();
	inner = PreMainInner;
	initStackBottomWith((void *)&inner);
	(*inner)();
}

int cmdCount;
char** cmdLine;
char** gEnv;
N_CDECL(void, NimMainInner)(void) {
	macrobugInit000();
}

N_CDECL(void, NimMain)(void) {
	void (*volatile inner)();
	PreMain();
	inner = NimMainInner;
	initStackBottomWith((void *)&inner);
	(*inner)();
}

int main(int argc, char** args, char** env) {
	cmdLine = args;
	cmdCount = argc;
	gEnv = env;
	NimMain();
	return nim_program_result;
}

NIM_EXTERNC N_NOINLINE(void, macrobugInit000)(void) {
	TY153007 scratch_153009;
	nimfr("macrobug", "macrobug.nim")
	nimln(4, "macrobug.nim");
	memset((void*)(&scratch_153009), 0, sizeof(scratch_153009));
	nimSpawn3(testwrapper_153011, (&scratch_153009));
	nimln(5, "macrobug.nim");
	sync_152624();
	popFrame();
}

NIM_EXTERNC N_NOINLINE(void, macrobugDatInit000)(void) {
}

