/* Generated by Nim Compiler v0.13.0 */
/*   (c) 2015 Andreas Rumpf */
/* The generated code is subject to the original license. */
/* Compiled for: Linux, amd64, gcc */
/* Command for C compiler:
   gcc -c  -w  -I/usr/lib/nim -o /home/cyril/Projects/provider/nimcache/stdlib_oids.o /home/cyril/Projects/provider/nimcache/stdlib_oids.c */
#define NIM_INTBITS 64

#include "nimbase.h"
#include <string.h>
#include <time.h>
#include <stdlib.h>
typedef struct Oid175005 Oid175005;
typedef struct TGenericSeq TGenericSeq;
typedef struct NimStringDesc NimStringDesc;
struct  Oid175005  {
NI32 time;
NI32 fuzz;
NI32 count;
};
struct  TGenericSeq  {
NI len;
NI reserved;
};
struct  NimStringDesc  {
  TGenericSeq Sup;
NIM_CHAR data[SEQ_DECL_SIZE];
};
N_NIMCALL(NIM_BOOL, HEX3DHEX3D_175010)(Oid175005 oid1, Oid175005 oid2);
static N_INLINE(void, nimFrame)(TFrame* s);
N_NOINLINE(void, stackoverflow_22201)(void);
static N_INLINE(void, popFrame)(void);
N_NIMCALL(NI, hexbyte_175015)(NIM_CHAR hex);
static N_INLINE(NI, subInt)(NI a, NI b);
N_NOINLINE(void, raiseOverflow)(void);
static N_INLINE(NI, addInt)(NI a, NI b);
N_NIMCALL(Oid175005, parseoid_175074)(NCSTRING str);
N_NIMCALL(NI, mulInt)(NI a, NI b);
static N_INLINE(NI, chckRange)(NI i, NI a, NI b);
N_NOINLINE(void, raiseRangeError)(NI64 val);
N_NIMCALL(void, oidtostring_175092)(Oid175005 oid, NCSTRING str_175095);
N_NOINLINE(void, raiseIndexError)(void);
N_NIMCALL(NimStringDesc*, HEX24_175124)(Oid175005 oid);
N_NIMCALL(NimStringDesc*, mnewString)(NI len);
N_NIMCALL(NimStringDesc*, mnewString)(NI len);
N_NIMCALL(Oid175005, genoid_175132)(void);
static N_INLINE(NI, atomicinc_16601)(NI* memloc, NI x);
static N_INLINE(void, bigendian32_95052)(void* outp, void* inp);
N_NIMCALL(void, swapendian32_95011)(void* outp, void* inp);
N_NIMCALL(time_t, generatedtime_175151)(Oid175005 oid);
STRING_LITERAL(TMP623, "0123456789abcdef", 16);
extern TFrame* frameptr_19436;
NI incr_175128;
NI32 fuzz_175129;

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

N_NIMCALL(NIM_BOOL, HEX3DHEX3D_175010)(Oid175005 oid1, Oid175005 oid2) {
	NIM_BOOL result;
	NIM_BOOL LOC1;
	NIM_BOOL LOC2;
	nimfr("==", "oids.nim")
{	result = 0;
	nimln(30, "oids.nim");
	LOC1 = 0;
	LOC2 = 0;
	LOC2 = (oid1.time == oid2.time);
	if (!(LOC2)) goto LA3;
	LOC2 = (oid1.fuzz == oid2.fuzz);
	LA3: ;
	LOC1 = LOC2;
	if (!(LOC1)) goto LA4;
	LOC1 = (oid1.count == oid2.count);
	LA4: ;
	result = LOC1;
	goto BeforeRet;
	}BeforeRet: ;
	popFrame();
	return result;
}

static N_INLINE(NI, subInt)(NI a, NI b) {
	NI result;
{	result = 0;
	result = (NI)((NU64)(a) - (NU64)(b));
	{
		NIM_BOOL LOC3;
		LOC3 = 0;
		LOC3 = (((NI) 0) <= (NI)(result ^ a));
		if (LOC3) goto LA4;
		LOC3 = (((NI) 0) <= (NI)(result ^ (NI)((NU64) ~(b))));
		LA4: ;
		if (!LOC3) goto LA5;
		goto BeforeRet;
	}
	LA5: ;
	raiseOverflow();
	}BeforeRet: ;
	return result;
}

static N_INLINE(NI, addInt)(NI a, NI b) {
	NI result;
{	result = 0;
	result = (NI)((NU64)(a) + (NU64)(b));
	{
		NIM_BOOL LOC3;
		LOC3 = 0;
		LOC3 = (((NI) 0) <= (NI)(result ^ a));
		if (LOC3) goto LA4;
		LOC3 = (((NI) 0) <= (NI)(result ^ b));
		LA4: ;
		if (!LOC3) goto LA5;
		goto BeforeRet;
	}
	LA5: ;
	raiseOverflow();
	}BeforeRet: ;
	return result;
}

N_NIMCALL(NI, hexbyte_175015)(NIM_CHAR hex) {
	NI result;
	nimfr("hexbyte", "oids.nim")
	result = 0;
	nimln(33, "oids.nim");
	switch (((NU8)(hex))) {
	case 48 ... 57:
	{
		NI TMP613;
		nimln(34, "oids.nim");
		TMP613 = subInt(((NI) (((NU8)(hex)))), ((NI) 48));
		result = ((NI) ((NI)(TMP613)));
	}
	break;
	case 97 ... 102:
	{
		NI TMP614;
		NI TMP615;
		nimln(35, "oids.nim");
		TMP614 = subInt(((NI) (((NU8)(hex)))), ((NI) 97));
		TMP615 = addInt(((NI) ((NI)(TMP614))), ((NI) 10));
		result = ((NI) ((NI)(TMP615)));
	}
	break;
	case 65 ... 70:
	{
		NI TMP616;
		NI TMP617;
		nimln(36, "oids.nim");
		TMP616 = subInt(((NI) (((NU8)(hex)))), ((NI) 65));
		TMP617 = addInt(((NI) ((NI)(TMP616))), ((NI) 10));
		result = ((NI) ((NI)(TMP617)));
	}
	break;
	default:
	{
	}
	break;
	}
	popFrame();
	return result;
}

static N_INLINE(NI, chckRange)(NI i, NI a, NI b) {
	NI result;
{	result = 0;
	{
		NIM_BOOL LOC3;
		LOC3 = 0;
		LOC3 = (a <= i);
		if (!(LOC3)) goto LA4;
		LOC3 = (i <= b);
		LA4: ;
		if (!LOC3) goto LA5;
		result = i;
		goto BeforeRet;
	}
	goto LA1;
	LA5: ;
	{
		raiseRangeError(((NI64) (i)));
	}
	LA1: ;
	}BeforeRet: ;
	return result;
}

N_NIMCALL(Oid175005, parseoid_175074)(NCSTRING str) {
	Oid175005 result;
	NCSTRING bytes;
	NI i;
	nimfr("parseOid", "oids.nim")
	memset((void*)(&result), 0, sizeof(result));
	nimln(41, "oids.nim");
	bytes = ((NCSTRING) ((&result.time)));
	nimln(42, "oids.nim");
	i = ((NI) 0);
	{
		nimln(43, "oids.nim");
		while (1) {
			NI TMP618;
			NI LOC3;
			NI TMP619;
			NI TMP620;
			NI LOC4;
			NI TMP621;
			if (!(i < ((NI) 12))) goto LA2;
			nimln(44, "oids.nim");
			TMP618 = mulInt(((NI) 2), i);
			LOC3 = 0;
			LOC3 = hexbyte_175015(str[(NI)(TMP618)]);
			TMP619 = mulInt(((NI) 2), i);
			TMP620 = addInt((NI)(TMP619), ((NI) 1));
			LOC4 = 0;
			LOC4 = hexbyte_175015(str[(NI)(TMP620)]);
			bytes[i] = ((NIM_CHAR) (((NI)chckRange((NI)((NI)((NU64)(LOC3) << (NU64)(((NI) 4))) | LOC4), ((NI) 0), ((NI) 255)))));
			nimln(45, "oids.nim");
			TMP621 = addInt(i, ((NI) 1));
			i = (NI)(TMP621);
		} LA2: ;
	}
	popFrame();
	return result;
}

N_NIMCALL(void, oidtostring_175092)(Oid175005 oid, NCSTRING str_175095) {
	NCSTRING str;
	Oid175005 o;
	NCSTRING bytes;
	NI i;
	nimfr("oidToString", "oids.nim")
	nimln(50, "oids.nim");
	str = str_175095;
	nimln(51, "oids.nim");
	o = oid;
	nimln(52, "oids.nim");
	bytes = ((NCSTRING) ((&o)));
	nimln(53, "oids.nim");
	i = ((NI) 0);
	{
		nimln(54, "oids.nim");
		while (1) {
			NI b;
			NI TMP622;
			NI TMP624;
			NI TMP625;
			NI TMP626;
			if (!(i < ((NI) 12))) goto LA2;
			nimln(55, "oids.nim");
			b = ((NU8)(bytes[i]));
			nimln(56, "oids.nim");
			TMP622 = mulInt(((NI) 2), i);
			if ((NU)((NI)((NU64)((NI)(((NI) (b)) & ((NI) 240))) >> (NU64)(((NI) 4)))) > (NU)(((NimStringDesc*) &TMP623)->Sup.len)) raiseIndexError();
			str[(NI)(TMP622)] = ((NimStringDesc*) &TMP623)->data[(NI)((NU64)((NI)(((NI) (b)) & ((NI) 240))) >> (NU64)(((NI) 4)))];
			nimln(57, "oids.nim");
			TMP624 = mulInt(((NI) 2), i);
			TMP625 = addInt((NI)(TMP624), ((NI) 1));
			if ((NU)((NI)(((NI) (b)) & ((NI) 15))) > (NU)(((NimStringDesc*) &TMP623)->Sup.len)) raiseIndexError();
			str[(NI)(TMP625)] = ((NimStringDesc*) &TMP623)->data[(NI)(((NI) (b)) & ((NI) 15))];
			nimln(58, "oids.nim");
			TMP626 = addInt(i, ((NI) 1));
			i = (NI)(TMP626);
		} LA2: ;
	}
	nimln(59, "oids.nim");
	str[((NI) 24)] = 0;
	popFrame();
}

N_NIMCALL(NimStringDesc*, HEX24_175124)(Oid175005 oid) {
	NimStringDesc* result;
	nimfr("$", "oids.nim")
	result = 0;
	nimln(62, "oids.nim");
	result = mnewString(((NI) 24));
	nimln(63, "oids.nim");
	oidtostring_175092(oid, result->data);
	popFrame();
	return result;
}

static N_INLINE(NI, atomicinc_16601)(NI* memloc, NI x) {
	NI result;
	result = 0;
	(*memloc) += x;
	result = (*memloc);
	return result;
}

static N_INLINE(void, bigendian32_95052)(void* outp, void* inp) {
	nimfr("bigEndian32", "endians.nim")
	nimln(58, "endians.nim");
	swapendian32_95011(outp, inp);
	popFrame();
}

N_NIMCALL(Oid175005, genoid_175132)(void) {
	Oid175005 result;
	int t;
	NI32 i;
	NI LOC1;
	nimfr("genOid", "oids.nim")
	memset((void*)(&result), 0, sizeof(result));
	nimln(75, "oids.nim");
	t = time(NIM_NIL);
	nimln(77, "oids.nim");
	i = ((NI32)chckRange(incr_175128, ((NI32) (-2147483647 -1)), ((NI32) 2147483647)));
	nimln(78, "oids.nim");
	LOC1 = 0;
	LOC1 = atomicinc_16601((&incr_175128), ((NI) 1));
	nimln(80, "oids.nim");
	{
		if (!(fuzz_175129 == ((NI32) 0))) goto LA4;
		nimln(82, "oids.nim");
		srand(t);
		nimln(83, "oids.nim");
		fuzz_175129 = rand();
	}
	LA4: ;
	nimln(84, "oids.nim");
	bigendian32_95052(((void*) ((&result.time))), ((void*) ((&t))));
	nimln(85, "oids.nim");
	result.fuzz = fuzz_175129;
	nimln(86, "oids.nim");
	bigendian32_95052(((void*) ((&result.count))), ((void*) ((&i))));
	popFrame();
	return result;
}

N_NIMCALL(time_t, generatedtime_175151)(Oid175005 oid) {
	time_t result;
	NI32 tmp;
	NI32 dummy;
	nimfr("generatedTime", "oids.nim")
	result = 0;
	tmp = 0;
	nimln(91, "oids.nim");
	dummy = oid.time;
	nimln(92, "oids.nim");
	bigendian32_95052(((void*) ((&tmp))), ((void*) ((&dummy))));
	nimln(93, "oids.nim");
	result = ((time_t) (tmp));
	popFrame();
	return result;
}
NIM_EXTERNC N_NOINLINE(void, stdlib_oidsInit000)(void) {
	nimfr("oids", "oids.nim")
	popFrame();
}

NIM_EXTERNC N_NOINLINE(void, stdlib_oidsDatInit000)(void) {
}
