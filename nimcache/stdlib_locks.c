/* Generated by Nim Compiler v0.13.0 */
/*   (c) 2015 Andreas Rumpf */
/* The generated code is subject to the original license. */
/* Compiled for: Linux, amd64, gcc */
/* Command for C compiler:
   gcc -c  -w -pthread  -I/usr/lib/nim -o /home/cyril/Projects/provider/nimcache/stdlib_locks.o /home/cyril/Projects/provider/nimcache/stdlib_locks.c */
#define NIM_INTBITS 64

#include "nimbase.h"
#include <pthread.h>
#include <sys/types.h>
static N_INLINE(NIM_BOOL, tryacquiresys_186218)(pthread_mutex_t* L);
static N_INLINE(void, nimFrame)(TFrame* s);
N_NOINLINE(void, stackoverflow_28801)(void);
static N_INLINE(void, popFrame)(void);
static N_INLINE(void, initlock_186256)(pthread_mutex_t* lock);
static N_INLINE(void, deinitlock_186260)(pthread_mutex_t* lock);
N_NIMCALL(NIM_BOOL, tryacquire_186264)(pthread_mutex_t* lock);
N_NIMCALL(void, acquire_186269)(pthread_mutex_t* lock);
N_NIMCALL(void, release_186273)(pthread_mutex_t* lock);
static N_INLINE(void, initcond_186277)(pthread_cond_t* cond);
static N_INLINE(void, deinitcond_186281)(pthread_cond_t* cond);
static N_INLINE(void, wait_186285)(pthread_cond_t* cond, pthread_mutex_t* lock);
static N_INLINE(void, signal_186291)(pthread_cond_t* cond);
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

static N_INLINE(NIM_BOOL, tryacquiresys_186218)(pthread_mutex_t* L) {
	NIM_BOOL result;
	int LOC1;
	nimfr("tryAcquireSys", "syslocks.nim")
	result = 0;
	nimln(90, "syslocks.nim");
	LOC1 = 0;
	LOC1 = pthread_mutex_trylock(L);
	result = (LOC1 == ((NI32) 0));
	popFrame();
	return result;
}

static N_INLINE(void, initlock_186256)(pthread_mutex_t* lock) {
	nimfr("initLock", "locks.nim")
	nimln(23, "locks.nim");
	pthread_mutex_init(lock, NIM_NIL);
	popFrame();
}

static N_INLINE(void, deinitlock_186260)(pthread_mutex_t* lock) {
	nimfr("deinitLock", "locks.nim")
	nimln(27, "locks.nim");
	pthread_mutex_destroy(lock);
	popFrame();
}

N_NIMCALL(NIM_BOOL, tryacquire_186264)(pthread_mutex_t* lock) {
	NIM_BOOL result;
	nimfr("tryAcquire", "locks.nim")
	result = 0;
	nimln(31, "locks.nim");
	result = tryacquiresys_186218(lock);
	popFrame();
	return result;
}

N_NIMCALL(void, acquire_186269)(pthread_mutex_t* lock) {
	nimfr("acquire", "locks.nim")
	nimln(35, "locks.nim");
	pthread_mutex_lock(lock);
	popFrame();
}

N_NIMCALL(void, release_186273)(pthread_mutex_t* lock) {
	nimfr("release", "locks.nim")
	nimln(39, "locks.nim");
	pthread_mutex_unlock(lock);
	popFrame();
}

static N_INLINE(void, initcond_186277)(pthread_cond_t* cond) {
	nimfr("initCond", "locks.nim")
	nimln(44, "locks.nim");
	pthread_cond_init(cond, NIM_NIL);
	popFrame();
}

static N_INLINE(void, deinitcond_186281)(pthread_cond_t* cond) {
	nimfr("deinitCond", "locks.nim")
	nimln(48, "locks.nim");
	pthread_cond_destroy(cond);
	popFrame();
}

static N_INLINE(void, wait_186285)(pthread_cond_t* cond, pthread_mutex_t* lock) {
	nimfr("wait", "locks.nim")
	nimln(52, "locks.nim");
	pthread_cond_wait(cond, lock);
	popFrame();
}

static N_INLINE(void, signal_186291)(pthread_cond_t* cond) {
	nimfr("signal", "locks.nim")
	nimln(56, "locks.nim");
	pthread_cond_signal(cond);
	popFrame();
}
NIM_EXTERNC N_NOINLINE(void, stdlib_locksInit000)(void) {
	nimfr("locks", "locks.nim")
	popFrame();
}

NIM_EXTERNC N_NOINLINE(void, stdlib_locksDatInit000)(void) {
}

