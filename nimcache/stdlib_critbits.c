/* Generated by Nim Compiler v0.13.0 */
/*   (c) 2015 Andreas Rumpf */
/* The generated code is subject to the original license. */
/* Compiled for: Linux, amd64, gcc */
/* Command for C compiler:
   gcc -c  -w  -I/usr/lib/nim -o /home/cyril/Projects/provider/nimcache/stdlib_critbits.o /home/cyril/Projects/provider/nimcache/stdlib_critbits.c */
#define NIM_INTBITS 64

#include "nimbase.h"
typedef struct Nodeobj176396 Nodeobj176396;
typedef struct Critbittree176390 Critbittree176390;
typedef struct NimStringDesc NimStringDesc;
typedef struct TGenericSeq TGenericSeq;
typedef struct TNimType TNimType;
typedef struct TNimNode TNimNode;
typedef struct Cell47905 Cell47905;
typedef struct Cellseq47921 Cellseq47921;
typedef struct Gcheap50218 Gcheap50218;
typedef struct Gcstack50216 Gcstack50216;
typedef struct Cellset47917 Cellset47917;
typedef struct Pagedesc47913 Pagedesc47913;
typedef struct Memregion30088 Memregion30088;
typedef struct Smallchunk30040 Smallchunk30040;
typedef struct Llchunk30082 Llchunk30082;
typedef struct Bigchunk30042 Bigchunk30042;
typedef struct Intset30014 Intset30014;
typedef struct Trunk30010 Trunk30010;
typedef struct Avlnode30086 Avlnode30086;
typedef struct Gcstat50214 Gcstat50214;
typedef struct Nodeobj176610 Nodeobj176610;
typedef struct Critbittree176604 Critbittree176604;
typedef struct Basechunk30038 Basechunk30038;
typedef struct Freecell30030 Freecell30030;
struct  TGenericSeq  {
NI len;
NI reserved;
};
struct  NimStringDesc  {
  TGenericSeq Sup;
NIM_CHAR data[SEQ_DECL_SIZE];
};
struct  Critbittree176390  {
Nodeobj176396* root;
NI count;
};
typedef Nodeobj176396* TY176408[2];
struct  Nodeobj176396  {
NI byte;
NIM_CHAR otherbits;
NIM_BOOL isleaf;
union{
TY176408 child;
struct {NimStringDesc* key;
} S2;
} isleafU;
};
typedef N_NIMCALL_PTR(void, TY3489) (void* p, NI op);
typedef N_NIMCALL_PTR(void*, TY3494) (void* p);
struct  TNimType  {
NI size;
NU8 kind;
NU8 flags;
TNimType* base;
TNimNode* node;
void* finalizer;
TY3489 marker;
TY3494 deepcopy;
};
struct  TNimNode  {
NU8 kind;
NI offset;
TNimType* typ;
NCSTRING name;
NI len;
TNimNode** sons;
};
struct  Cell47905  {
NI refcount;
TNimType* typ;
};
struct  Cellseq47921  {
NI len;
NI cap;
Cell47905** d;
};
struct  Cellset47917  {
NI counter;
NI max;
Pagedesc47913* head;
Pagedesc47913** data;
};
typedef Smallchunk30040* TY30103[512];
typedef Trunk30010* Trunkbuckets30012[256];
struct  Intset30014  {
Trunkbuckets30012 data;
};
struct  Memregion30088  {
NI minlargeobj;
NI maxlargeobj;
TY30103 freesmallchunks;
Llchunk30082* llmem;
NI currmem;
NI maxmem;
NI freemem;
NI lastsize;
Bigchunk30042* freechunkslist;
Intset30014 chunkstarts;
Avlnode30086* root;
Avlnode30086* deleted;
Avlnode30086* last;
Avlnode30086* freeavlnodes;
};
struct  Gcstat50214  {
NI stackscans;
NI cyclecollections;
NI maxthreshold;
NI maxstacksize;
NI maxstackcells;
NI cycletablesize;
NI64 maxpause;
};
struct  Gcheap50218  {
Gcstack50216* stack;
void* stackbottom;
NI cyclethreshold;
Cellseq47921 zct;
Cellseq47921 decstack;
Cellset47917 cycleroots;
Cellseq47921 tempstack;
NI recgclock;
Memregion30088 region;
Gcstat50214 stat;
};
struct  Critbittree176604  {
Nodeobj176610* root;
NI count;
};
typedef Nodeobj176610* TY176622[2];
struct  Nodeobj176610  {
NI byte;
NIM_CHAR otherbits;
NIM_BOOL isleaf;
union{
TY176622 child;
struct {NimStringDesc* key;
NI val;
} S2;
} isleafU;
};
struct  Gcstack50216  {
Gcstack50216* prev;
Gcstack50216* next;
void* starts;
void* pos;
NI maxstacksize;
};
typedef NI TY30019[8];
struct  Pagedesc47913  {
Pagedesc47913* next;
NI key;
TY30019 bits;
};
struct  Basechunk30038  {
NI prevsize;
NI size;
NIM_BOOL used;
};
struct  Smallchunk30040  {
  Basechunk30038 Sup;
Smallchunk30040* next;
Smallchunk30040* prev;
Freecell30030* freelist;
NI free;
NI acc;
NF data;
};
struct  Llchunk30082  {
NI size;
NI acc;
Llchunk30082* next;
};
struct  Bigchunk30042  {
  Basechunk30038 Sup;
Bigchunk30042* next;
Bigchunk30042* prev;
NI align;
NF data;
};
struct  Trunk30010  {
Trunk30010* next;
NI key;
TY30019 bits;
};
typedef Avlnode30086* TY30093[2];
struct  Avlnode30086  {
TY30093 link;
NI key;
NI upperbound;
NI level;
};
struct  Freecell30030  {
Freecell30030* next;
NI zerofield;
};
N_NIMCALL(Nodeobj176396*, rawinsert_176425)(Critbittree176390* c, NimStringDesc* key);
N_NIMCALL(void, nimGCvisit)(void* d, NI op);
N_NIMCALL(void, TMP794)(void* p, NI op);
N_NIMCALL(void*, newObj)(TNimType* typ, NI size);
N_NIMCALL(void, unsureAsgnRef)(void** dest, void* src);
N_NIMCALL(void, FieldDiscriminantCheck)(NI olddiscval, NI newdiscval, TNimNode** a, NI L);
N_NOINLINE(void, raiseFieldError)(NimStringDesc* f);
N_NIMCALL(NimStringDesc*, copyStringRC1)(NimStringDesc* src);
static N_INLINE(void, nimGCunrefNoCycle)(void* p);
static N_INLINE(Cell47905*, usrtocell_51840)(void* usr);
static N_INLINE(void, nimFrame)(TFrame* s);
N_NOINLINE(void, stackoverflow_22201)(void);
static N_INLINE(void, popFrame)(void);
static N_INLINE(void, rtladdzct_53401)(Cell47905* c);
N_NOINLINE(void, addzct_51817)(Cellseq47921* s, Cell47905* c);
N_NOINLINE(void, raiseIndexError)(void);
static N_INLINE(NI, addInt)(NI a, NI b);
N_NOINLINE(void, raiseOverflow)(void);
static N_INLINE(NI, subInt)(NI a, NI b);
static N_INLINE(NI, chckRange)(NI i, NI a, NI b);
N_NOINLINE(void, raiseRangeError)(NI64 val);
static N_INLINE(void, asgnRefNoCycle)(void** dest, void* src);
N_NIMCALL(NIM_BOOL, containsorincl_176383)(Critbittree176390* c, NimStringDesc* key);
N_NIMCALL(Nodeobj176610*, rawinsert_176638)(Critbittree176604* c, NimStringDesc* key);
N_NIMCALL(void, TMP807)(void* p, NI op);
N_NIMCALL(void, inc_176597)(Critbittree176604* c, NimStringDesc* key);
N_NIMCALL(void, incl_176820)(Critbittree176390* c, NimStringDesc* key);
TNimNode* NimDT_176396_isleaf[3];
STRING_LITERAL(TMP795, "key", 3);
STRING_LITERAL(TMP797, "child", 5);
TNimNode* NimDT_176610_isleaf[3];
STRING_LITERAL(TMP816, "val", 3);
TNimType NTI176396; /* NodeObj */
extern TNimType NTI104; /* int */
extern TNimType NTI136; /* char */
extern TNimType NTI130; /* bool */
TNimType NTI176408; /* array[0..1, ref NodeObj[system.void]] */
extern TNimType NTI138; /* string */
TNimType NTI176393; /* Node */
extern TNimNode* NimDT_176396_isleaf[3];
extern TFrame* frameptr_19436;
extern Gcheap50218 gch_50259;
TNimType NTI176610; /* NodeObj */
TNimType NTI176622; /* array[0..1, ref NodeObj[system.int]] */
TNimType NTI176607; /* Node */
extern TNimNode* NimDT_176610_isleaf[3];
N_NIMCALL(void, TMP794)(void* p, NI op) {
	Nodeobj176396* a;
	NI LOC1;
	a = (Nodeobj176396*)p;
	switch ((*a).isleaf) {
	case NIM_FALSE:
	LOC1 = 0;
	for (LOC1 = 0; LOC1 < 2; LOC1++) {
	nimGCvisit((void*)(*a).isleafU.child[LOC1], op);
	}
	break;
	case NIM_TRUE:
	nimGCvisit((void*)(*a).isleafU.S2.key, op);
	break;
	} 
}

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

static N_INLINE(Cell47905*, usrtocell_51840)(void* usr) {
	Cell47905* result;
	nimfr("usrToCell", "gc.nim")
	result = 0;
	nimln(131, "gc.nim");
	result = ((Cell47905*) ((NI)((NU64)(((NI) (usr))) - (NU64)(((NI)sizeof(Cell47905))))));
	popFrame();
	return result;
}

static N_INLINE(void, rtladdzct_53401)(Cell47905* c) {
	nimfr("rtlAddZCT", "gc.nim")
	nimln(212, "gc.nim");
	addzct_51817((&gch_50259.zct), c);
	popFrame();
}

static N_INLINE(void, nimGCunrefNoCycle)(void* p) {
	Cell47905* c;
	nimfr("nimGCunrefNoCycle", "gc.nim")
	nimln(246, "gc.nim");
	c = usrtocell_51840(p);
	nimln(248, "gc.nim");
	{
		nimln(180, "gc.nim");
		(*c).refcount -= ((NI) 8);
		nimln(181, "gc.nim");
		if (!((NU64)((*c).refcount) < (NU64)(((NI) 8)))) goto LA3;
		nimln(249, "gc.nim");
		rtladdzct_53401(c);
	}
	LA3: ;
	popFrame();
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

static N_INLINE(void, asgnRefNoCycle)(void** dest, void* src) {
	nimfr("asgnRefNoCycle", "gc.nim")
	nimln(264, "gc.nim");
	{
		Cell47905* c;
		nimln(349, "system.nim");
		if (!!((src == NIM_NIL))) goto LA3;
		nimln(265, "gc.nim");
		c = usrtocell_51840(src);
		nimln(182, "gc.nim");
		(*c).refcount += ((NI) 8);
	}
	LA3: ;
	nimln(267, "gc.nim");
	{
		Cell47905* c;
		nimln(349, "system.nim");
		if (!!(((*dest) == NIM_NIL))) goto LA7;
		nimln(268, "gc.nim");
		c = usrtocell_51840((*dest));
		nimln(269, "gc.nim");
		{
			nimln(180, "gc.nim");
			(*c).refcount -= ((NI) 8);
			nimln(181, "gc.nim");
			if (!((NU64)((*c).refcount) < (NU64)(((NI) 8)))) goto LA11;
			nimln(270, "gc.nim");
			rtladdzct_53401(c);
		}
		LA11: ;
	}
	LA7: ;
	nimln(271, "gc.nim");
	(*dest) = src;
	popFrame();
}

N_NIMCALL(Nodeobj176396*, rawinsert_176425)(Critbittree176390* c, NimStringDesc* key) {
	Nodeobj176396* result;
	NI TMP804;
	nimfr("rawInsert", "critbits.nim")
{	result = 0;
	nimln(60, "critbits.nim");
	{
		NIM_BOOL LOC5;
		NimStringDesc* LOC6;
		if (!((*c).root == NIM_NIL)) goto LA3;
		nimln(61, "critbits.nim");
		unsureAsgnRef((void**) (&(*c).root), (Nodeobj176396*) newObj((&NTI176393), sizeof(Nodeobj176396)));
		nimln(62, "critbits.nim");
		LOC5 = 0;
		LOC5 = NIM_TRUE;
		FieldDiscriminantCheck((NI)(NU)((*(*c).root).isleaf), (NI)(NU)(LOC5), NimDT_176396_isleaf, 3);
		(*(*c).root).isleaf = LOC5;
		nimln(63, "critbits.nim");
		if (!(((2 &(1U<<((NU)((*(*c).root).isleaf)&7U)))!=0))) raiseFieldError(((NimStringDesc*) &TMP795));
		LOC6 = 0;
		LOC6 = (*(*c).root).isleafU.S2.key; (*(*c).root).isleafU.S2.key = copyStringRC1(key);
		if (LOC6) nimGCunrefNoCycle(LOC6);
		nimln(64, "critbits.nim");
		result = (*c).root;
	}
	goto LA1;
	LA3: ;
	{
		Nodeobj176396* it;
		NI newotherbits;
		NI newbyte;
		NIM_CHAR ch_176519;
		NI dir_176528;
		NI TMP801;
		Nodeobj176396* inner;
		NIM_BOOL LOC29;
		NimStringDesc* LOC30;
		NI TMP802;
		Nodeobj176396** wherep;
		nimln(66, "critbits.nim");
		it = (*c).root;
		{
			nimln(67, "critbits.nim");
			while (1) {
				NIM_CHAR ch;
				NI dir;
				NI TMP796;
				if (!!((*it).isleaf)) goto LA9;
				nimln(68, "critbits.nim");
				{
					if (!((*it).byte < (key ? key->Sup.len : 0))) goto LA12;
					if ((NU)((*it).byte) > (NU)(key->Sup.len)) raiseIndexError();
					ch = key->data[(*it).byte];
				}
				goto LA10;
				LA12: ;
				{
					ch = 0;
				}
				LA10: ;
				nimln(69, "critbits.nim");
				TMP796 = addInt(((NI) 1), (NI)(((NI) (((NU8)(ch)))) | ((NI) (((NU8)((*it).otherbits))))));
				dir = (NI)((NU64)((NI)(TMP796)) >> (NU64)(((NI) 8)));
				nimln(70, "critbits.nim");
				if (!(((1 &(1U<<((NU)((*it).isleaf)&7U)))!=0))) raiseFieldError(((NimStringDesc*) &TMP797));
				if ((NU)(dir) > (NU)(1)) raiseIndexError();
				it = (*it).isleafU.child[(dir)- 0];
			} LA9: ;
		}
		nimln(72, "critbits.nim");
		newotherbits = ((NI) 0);
		nimln(73, "critbits.nim");
		newbyte = ((NI) 0);
		{
			{
				nimln(75, "critbits.nim");
				while (1) {
					NI TMP798;
					if (!(newbyte < (key ? key->Sup.len : 0))) goto LA17;
					nimln(76, "critbits.nim");
					{
						nimln(349, "system.nim");
						if (!(((2 &(1U<<((NU)((*it).isleaf)&7U)))!=0))) raiseFieldError(((NimStringDesc*) &TMP795));
						if ((NU)(newbyte) > (NU)((*it).isleafU.S2.key->Sup.len)) raiseIndexError();
						if ((NU)(newbyte) > (NU)(key->Sup.len)) raiseIndexError();
						if (!!(((NU8)((*it).isleafU.S2.key->data[newbyte]) == (NU8)(key->data[newbyte])))) goto LA20;
						nimln(77, "critbits.nim");
						if (!(((2 &(1U<<((NU)((*it).isleaf)&7U)))!=0))) raiseFieldError(((NimStringDesc*) &TMP795));
						if ((NU)(newbyte) > (NU)((*it).isleafU.S2.key->Sup.len)) raiseIndexError();
						if ((NU)(newbyte) > (NU)(key->Sup.len)) raiseIndexError();
						newotherbits = (NI)(((NI) (((NU8)((*it).isleafU.S2.key->data[newbyte])))) ^ ((NI) (((NU8)(key->data[newbyte])))));
						nimln(78, "critbits.nim");
						goto LA15;
					}
					LA20: ;
					nimln(79, "critbits.nim");
					TMP798 = addInt(newbyte, ((NI) 1));
					newbyte = (NI)(TMP798);
				} LA17: ;
			}
			nimln(80, "critbits.nim");
			{
				nimln(349, "system.nim");
				if (!(((2 &(1U<<((NU)((*it).isleaf)&7U)))!=0))) raiseFieldError(((NimStringDesc*) &TMP795));
				if ((NU)(newbyte) > (NU)((*it).isleafU.S2.key->Sup.len)) raiseIndexError();
				if (!!(((NU8)((*it).isleafU.S2.key->data[newbyte]) == (NU8)(0)))) goto LA24;
				nimln(81, "critbits.nim");
				if (!(((2 &(1U<<((NU)((*it).isleaf)&7U)))!=0))) raiseFieldError(((NimStringDesc*) &TMP795));
				if ((NU)(newbyte) > (NU)((*it).isleafU.S2.key->Sup.len)) raiseIndexError();
				newotherbits = ((NI) (((NU8)((*it).isleafU.S2.key->data[newbyte]))));
			}
			goto LA22;
			LA24: ;
			{
				nimln(83, "critbits.nim");
				result = it;
				goto BeforeRet;
			}
			LA22: ;
		} LA15: ;
		{
			nimln(84, "critbits.nim");
			while (1) {
				NI TMP799;
				NI TMP800;
				nimln(349, "system.nim");
				nimln(84, "critbits.nim");
				TMP799 = subInt(newotherbits, ((NI) 1));
				if (!!(((NI)(newotherbits & (NI)(TMP799)) == ((NI) 0)))) goto LA28;
				nimln(85, "critbits.nim");
				TMP800 = subInt(newotherbits, ((NI) 1));
				newotherbits = (NI)(newotherbits & (NI)(TMP800));
			} LA28: ;
		}
		nimln(86, "critbits.nim");
		newotherbits = (NI)(newotherbits ^ ((NI) 255));
		nimln(87, "critbits.nim");
		if (!(((2 &(1U<<((NU)((*it).isleaf)&7U)))!=0))) raiseFieldError(((NimStringDesc*) &TMP795));
		if ((NU)(newbyte) > (NU)((*it).isleafU.S2.key->Sup.len)) raiseIndexError();
		ch_176519 = (*it).isleafU.S2.key->data[newbyte];
		nimln(88, "critbits.nim");
		TMP801 = addInt(((NI) 1), (NI)(((NI) (((NU8)(ch_176519)))) | newotherbits));
		dir_176528 = (NI)((NU64)((NI)(TMP801)) >> (NU64)(((NI) 8)));
		inner = 0;
		nimln(91, "critbits.nim");
		inner = (Nodeobj176396*) newObj((&NTI176393), sizeof(Nodeobj176396));
		nimln(92, "critbits.nim");
		result = (Nodeobj176396*) newObj((&NTI176393), sizeof(Nodeobj176396));
		nimln(93, "critbits.nim");
		LOC29 = 0;
		LOC29 = NIM_TRUE;
		FieldDiscriminantCheck((NI)(NU)((*result).isleaf), (NI)(NU)(LOC29), NimDT_176396_isleaf, 3);
		(*result).isleaf = LOC29;
		nimln(94, "critbits.nim");
		if (!(((2 &(1U<<((NU)((*result).isleaf)&7U)))!=0))) raiseFieldError(((NimStringDesc*) &TMP795));
		LOC30 = 0;
		LOC30 = (*result).isleafU.S2.key; (*result).isleafU.S2.key = copyStringRC1(key);
		if (LOC30) nimGCunrefNoCycle(LOC30);
		nimln(95, "critbits.nim");
		(*inner).otherbits = ((NIM_CHAR) (((NI)chckRange(newotherbits, ((NI) 0), ((NI) 255)))));
		nimln(96, "critbits.nim");
		(*inner).byte = newbyte;
		nimln(97, "critbits.nim");
		if (!(((1 &(1U<<((NU)((*inner).isleaf)&7U)))!=0))) raiseFieldError(((NimStringDesc*) &TMP797));
		TMP802 = subInt(((NI) 1), dir_176528);
		if ((NU)((NI)(TMP802)) > (NU)(1)) raiseIndexError();
		asgnRefNoCycle((void**) (&(*inner).isleafU.child[((NI)(TMP802))- 0]), result);
		nimln(99, "critbits.nim");
		wherep = &(*c).root;
		{
			nimln(100, "critbits.nim");
			while (1) {
				Nodeobj176396* p;
				NIM_CHAR ch;
				NI dir;
				NI TMP803;
				nimln(101, "critbits.nim");
				p = (*wherep);
				nimln(102, "critbits.nim");
				{
					if (!(*p).isleaf) goto LA35;
					goto LA31;
				}
				LA35: ;
				nimln(103, "critbits.nim");
				{
					nimln(357, "system.nim");
					if (!(newbyte < (*p).byte)) goto LA39;
					nimln(103, "critbits.nim");
					goto LA31;
				}
				LA39: ;
				nimln(104, "critbits.nim");
				{
					NIM_BOOL LOC43;
					LOC43 = 0;
					LOC43 = ((*p).byte == newbyte);
					if (!(LOC43)) goto LA44;
					nimln(357, "system.nim");
					nimln(104, "critbits.nim");
					LOC43 = (newotherbits < ((NI) (((NU8)((*p).otherbits)))));
					LA44: ;
					if (!LOC43) goto LA45;
					goto LA31;
				}
				LA45: ;
				nimln(105, "critbits.nim");
				{
					if (!((*p).byte < (key ? key->Sup.len : 0))) goto LA49;
					if ((NU)((*p).byte) > (NU)(key->Sup.len)) raiseIndexError();
					ch = key->data[(*p).byte];
				}
				goto LA47;
				LA49: ;
				{
					ch = 0;
				}
				LA47: ;
				nimln(106, "critbits.nim");
				TMP803 = addInt(((NI) 1), (NI)(((NI) (((NU8)(ch)))) | ((NI) (((NU8)((*p).otherbits))))));
				dir = (NI)((NU64)((NI)(TMP803)) >> (NU64)(((NI) 8)));
				nimln(107, "critbits.nim");
				if (!(((1 &(1U<<((NU)((*p).isleaf)&7U)))!=0))) raiseFieldError(((NimStringDesc*) &TMP797));
				if ((NU)(dir) > (NU)(1)) raiseIndexError();
				wherep = &(*p).isleafU.child[(dir)- 0];
			}
		} LA31: ;
		nimln(108, "critbits.nim");
		if (!(((1 &(1U<<((NU)((*inner).isleaf)&7U)))!=0))) raiseFieldError(((NimStringDesc*) &TMP797));
		if ((NU)(dir_176528) > (NU)(1)) raiseIndexError();
		asgnRefNoCycle((void**) (&(*inner).isleafU.child[(dir_176528)- 0]), (*wherep));
		nimln(109, "critbits.nim");
		unsureAsgnRef((void**) (&(*wherep)), inner);
	}
	LA1: ;
	nimln(110, "critbits.nim");
	TMP804 = addInt((*c).count, ((NI) 1));
	(*c).count = (NI)(TMP804);
	}BeforeRet: ;
	popFrame();
	return result;
}

N_NIMCALL(NIM_BOOL, containsorincl_176383)(Critbittree176390* c, NimStringDesc* key) {
	NIM_BOOL result;
	NI oldcount;
	Nodeobj176396* n;
	nimfr("containsOrIncl", "critbits.nim")
	result = 0;
	nimln(124, "critbits.nim");
	oldcount = (*c).count;
	nimln(125, "critbits.nim");
	n = rawinsert_176425(c, key);
	nimln(126, "critbits.nim");
	result = ((*c).count == oldcount);
	popFrame();
	return result;
}
N_NIMCALL(void, TMP807)(void* p, NI op) {
	Nodeobj176610* a;
	NI LOC1;
	a = (Nodeobj176610*)p;
	switch ((*a).isleaf) {
	case NIM_FALSE:
	LOC1 = 0;
	for (LOC1 = 0; LOC1 < 2; LOC1++) {
	nimGCvisit((void*)(*a).isleafU.child[LOC1], op);
	}
	break;
	case NIM_TRUE:
	nimGCvisit((void*)(*a).isleafU.S2.key, op);
	break;
	} 
}

N_NIMCALL(Nodeobj176610*, rawinsert_176638)(Critbittree176604* c, NimStringDesc* key) {
	Nodeobj176610* result;
	NI TMP815;
	nimfr("rawInsert", "critbits.nim")
{	result = 0;
	nimln(60, "critbits.nim");
	{
		NIM_BOOL LOC5;
		NimStringDesc* LOC6;
		if (!((*c).root == NIM_NIL)) goto LA3;
		nimln(61, "critbits.nim");
		unsureAsgnRef((void**) (&(*c).root), (Nodeobj176610*) newObj((&NTI176607), sizeof(Nodeobj176610)));
		nimln(62, "critbits.nim");
		LOC5 = 0;
		LOC5 = NIM_TRUE;
		FieldDiscriminantCheck((NI)(NU)((*(*c).root).isleaf), (NI)(NU)(LOC5), NimDT_176610_isleaf, 3);
		(*(*c).root).isleaf = LOC5;
		nimln(63, "critbits.nim");
		if (!(((2 &(1U<<((NU)((*(*c).root).isleaf)&7U)))!=0))) raiseFieldError(((NimStringDesc*) &TMP795));
		LOC6 = 0;
		LOC6 = (*(*c).root).isleafU.S2.key; (*(*c).root).isleafU.S2.key = copyStringRC1(key);
		if (LOC6) nimGCunrefNoCycle(LOC6);
		nimln(64, "critbits.nim");
		result = (*c).root;
	}
	goto LA1;
	LA3: ;
	{
		Nodeobj176610* it;
		NI newotherbits;
		NI newbyte;
		NIM_CHAR ch_176732;
		NI dir_176741;
		NI TMP812;
		Nodeobj176610* inner;
		NIM_BOOL LOC29;
		NimStringDesc* LOC30;
		NI TMP813;
		Nodeobj176610** wherep;
		nimln(66, "critbits.nim");
		it = (*c).root;
		{
			nimln(67, "critbits.nim");
			while (1) {
				NIM_CHAR ch;
				NI dir;
				NI TMP808;
				if (!!((*it).isleaf)) goto LA9;
				nimln(68, "critbits.nim");
				{
					if (!((*it).byte < (key ? key->Sup.len : 0))) goto LA12;
					if ((NU)((*it).byte) > (NU)(key->Sup.len)) raiseIndexError();
					ch = key->data[(*it).byte];
				}
				goto LA10;
				LA12: ;
				{
					ch = 0;
				}
				LA10: ;
				nimln(69, "critbits.nim");
				TMP808 = addInt(((NI) 1), (NI)(((NI) (((NU8)(ch)))) | ((NI) (((NU8)((*it).otherbits))))));
				dir = (NI)((NU64)((NI)(TMP808)) >> (NU64)(((NI) 8)));
				nimln(70, "critbits.nim");
				if (!(((1 &(1U<<((NU)((*it).isleaf)&7U)))!=0))) raiseFieldError(((NimStringDesc*) &TMP797));
				if ((NU)(dir) > (NU)(1)) raiseIndexError();
				it = (*it).isleafU.child[(dir)- 0];
			} LA9: ;
		}
		nimln(72, "critbits.nim");
		newotherbits = ((NI) 0);
		nimln(73, "critbits.nim");
		newbyte = ((NI) 0);
		{
			{
				nimln(75, "critbits.nim");
				while (1) {
					NI TMP809;
					if (!(newbyte < (key ? key->Sup.len : 0))) goto LA17;
					nimln(76, "critbits.nim");
					{
						nimln(349, "system.nim");
						if (!(((2 &(1U<<((NU)((*it).isleaf)&7U)))!=0))) raiseFieldError(((NimStringDesc*) &TMP795));
						if ((NU)(newbyte) > (NU)((*it).isleafU.S2.key->Sup.len)) raiseIndexError();
						if ((NU)(newbyte) > (NU)(key->Sup.len)) raiseIndexError();
						if (!!(((NU8)((*it).isleafU.S2.key->data[newbyte]) == (NU8)(key->data[newbyte])))) goto LA20;
						nimln(77, "critbits.nim");
						if (!(((2 &(1U<<((NU)((*it).isleaf)&7U)))!=0))) raiseFieldError(((NimStringDesc*) &TMP795));
						if ((NU)(newbyte) > (NU)((*it).isleafU.S2.key->Sup.len)) raiseIndexError();
						if ((NU)(newbyte) > (NU)(key->Sup.len)) raiseIndexError();
						newotherbits = (NI)(((NI) (((NU8)((*it).isleafU.S2.key->data[newbyte])))) ^ ((NI) (((NU8)(key->data[newbyte])))));
						nimln(78, "critbits.nim");
						goto LA15;
					}
					LA20: ;
					nimln(79, "critbits.nim");
					TMP809 = addInt(newbyte, ((NI) 1));
					newbyte = (NI)(TMP809);
				} LA17: ;
			}
			nimln(80, "critbits.nim");
			{
				nimln(349, "system.nim");
				if (!(((2 &(1U<<((NU)((*it).isleaf)&7U)))!=0))) raiseFieldError(((NimStringDesc*) &TMP795));
				if ((NU)(newbyte) > (NU)((*it).isleafU.S2.key->Sup.len)) raiseIndexError();
				if (!!(((NU8)((*it).isleafU.S2.key->data[newbyte]) == (NU8)(0)))) goto LA24;
				nimln(81, "critbits.nim");
				if (!(((2 &(1U<<((NU)((*it).isleaf)&7U)))!=0))) raiseFieldError(((NimStringDesc*) &TMP795));
				if ((NU)(newbyte) > (NU)((*it).isleafU.S2.key->Sup.len)) raiseIndexError();
				newotherbits = ((NI) (((NU8)((*it).isleafU.S2.key->data[newbyte]))));
			}
			goto LA22;
			LA24: ;
			{
				nimln(83, "critbits.nim");
				result = it;
				goto BeforeRet;
			}
			LA22: ;
		} LA15: ;
		{
			nimln(84, "critbits.nim");
			while (1) {
				NI TMP810;
				NI TMP811;
				nimln(349, "system.nim");
				nimln(84, "critbits.nim");
				TMP810 = subInt(newotherbits, ((NI) 1));
				if (!!(((NI)(newotherbits & (NI)(TMP810)) == ((NI) 0)))) goto LA28;
				nimln(85, "critbits.nim");
				TMP811 = subInt(newotherbits, ((NI) 1));
				newotherbits = (NI)(newotherbits & (NI)(TMP811));
			} LA28: ;
		}
		nimln(86, "critbits.nim");
		newotherbits = (NI)(newotherbits ^ ((NI) 255));
		nimln(87, "critbits.nim");
		if (!(((2 &(1U<<((NU)((*it).isleaf)&7U)))!=0))) raiseFieldError(((NimStringDesc*) &TMP795));
		if ((NU)(newbyte) > (NU)((*it).isleafU.S2.key->Sup.len)) raiseIndexError();
		ch_176732 = (*it).isleafU.S2.key->data[newbyte];
		nimln(88, "critbits.nim");
		TMP812 = addInt(((NI) 1), (NI)(((NI) (((NU8)(ch_176732)))) | newotherbits));
		dir_176741 = (NI)((NU64)((NI)(TMP812)) >> (NU64)(((NI) 8)));
		inner = 0;
		nimln(91, "critbits.nim");
		inner = (Nodeobj176610*) newObj((&NTI176607), sizeof(Nodeobj176610));
		nimln(92, "critbits.nim");
		result = (Nodeobj176610*) newObj((&NTI176607), sizeof(Nodeobj176610));
		nimln(93, "critbits.nim");
		LOC29 = 0;
		LOC29 = NIM_TRUE;
		FieldDiscriminantCheck((NI)(NU)((*result).isleaf), (NI)(NU)(LOC29), NimDT_176610_isleaf, 3);
		(*result).isleaf = LOC29;
		nimln(94, "critbits.nim");
		if (!(((2 &(1U<<((NU)((*result).isleaf)&7U)))!=0))) raiseFieldError(((NimStringDesc*) &TMP795));
		LOC30 = 0;
		LOC30 = (*result).isleafU.S2.key; (*result).isleafU.S2.key = copyStringRC1(key);
		if (LOC30) nimGCunrefNoCycle(LOC30);
		nimln(95, "critbits.nim");
		(*inner).otherbits = ((NIM_CHAR) (((NI)chckRange(newotherbits, ((NI) 0), ((NI) 255)))));
		nimln(96, "critbits.nim");
		(*inner).byte = newbyte;
		nimln(97, "critbits.nim");
		if (!(((1 &(1U<<((NU)((*inner).isleaf)&7U)))!=0))) raiseFieldError(((NimStringDesc*) &TMP797));
		TMP813 = subInt(((NI) 1), dir_176741);
		if ((NU)((NI)(TMP813)) > (NU)(1)) raiseIndexError();
		asgnRefNoCycle((void**) (&(*inner).isleafU.child[((NI)(TMP813))- 0]), result);
		nimln(99, "critbits.nim");
		wherep = &(*c).root;
		{
			nimln(100, "critbits.nim");
			while (1) {
				Nodeobj176610* p;
				NIM_CHAR ch;
				NI dir;
				NI TMP814;
				nimln(101, "critbits.nim");
				p = (*wherep);
				nimln(102, "critbits.nim");
				{
					if (!(*p).isleaf) goto LA35;
					goto LA31;
				}
				LA35: ;
				nimln(103, "critbits.nim");
				{
					nimln(357, "system.nim");
					if (!(newbyte < (*p).byte)) goto LA39;
					nimln(103, "critbits.nim");
					goto LA31;
				}
				LA39: ;
				nimln(104, "critbits.nim");
				{
					NIM_BOOL LOC43;
					LOC43 = 0;
					LOC43 = ((*p).byte == newbyte);
					if (!(LOC43)) goto LA44;
					nimln(357, "system.nim");
					nimln(104, "critbits.nim");
					LOC43 = (newotherbits < ((NI) (((NU8)((*p).otherbits)))));
					LA44: ;
					if (!LOC43) goto LA45;
					goto LA31;
				}
				LA45: ;
				nimln(105, "critbits.nim");
				{
					if (!((*p).byte < (key ? key->Sup.len : 0))) goto LA49;
					if ((NU)((*p).byte) > (NU)(key->Sup.len)) raiseIndexError();
					ch = key->data[(*p).byte];
				}
				goto LA47;
				LA49: ;
				{
					ch = 0;
				}
				LA47: ;
				nimln(106, "critbits.nim");
				TMP814 = addInt(((NI) 1), (NI)(((NI) (((NU8)(ch)))) | ((NI) (((NU8)((*p).otherbits))))));
				dir = (NI)((NU64)((NI)(TMP814)) >> (NU64)(((NI) 8)));
				nimln(107, "critbits.nim");
				if (!(((1 &(1U<<((NU)((*p).isleaf)&7U)))!=0))) raiseFieldError(((NimStringDesc*) &TMP797));
				if ((NU)(dir) > (NU)(1)) raiseIndexError();
				wherep = &(*p).isleafU.child[(dir)- 0];
			}
		} LA31: ;
		nimln(108, "critbits.nim");
		if (!(((1 &(1U<<((NU)((*inner).isleaf)&7U)))!=0))) raiseFieldError(((NimStringDesc*) &TMP797));
		if ((NU)(dir_176741) > (NU)(1)) raiseIndexError();
		asgnRefNoCycle((void**) (&(*inner).isleafU.child[(dir_176741)- 0]), (*wherep));
		nimln(109, "critbits.nim");
		unsureAsgnRef((void**) (&(*wherep)), inner);
	}
	LA1: ;
	nimln(110, "critbits.nim");
	TMP815 = addInt((*c).count, ((NI) 1));
	(*c).count = (NI)(TMP815);
	}BeforeRet: ;
	popFrame();
	return result;
}

N_NIMCALL(void, inc_176597)(Critbittree176604* c, NimStringDesc* key) {
	NI oldcount;
	Nodeobj176610* n;
	nimfr("inc", "critbits.nim")
	nimln(130, "critbits.nim");
	oldcount = (*c).count;
	nimln(131, "critbits.nim");
	n = rawinsert_176638(c, key);
	nimln(132, "critbits.nim");
	{
		NI TMP817;
		if (!((*c).count == oldcount)) goto LA3;
		nimln(134, "critbits.nim");
		if (!(((2 &(1U<<((NU)((*n).isleaf)&7U)))!=0))) raiseFieldError(((NimStringDesc*) &TMP816));
		TMP817 = addInt((*n).isleafU.S2.val, ((NI) 1));
		(*n).isleafU.S2.val = (NI)(TMP817);
	}
	LA3: ;
	popFrame();
}

N_NIMCALL(void, incl_176820)(Critbittree176390* c, NimStringDesc* key) {
	Nodeobj176396* LOC1;
	nimfr("incl", "critbits.nim")
	nimln(138, "critbits.nim");
	LOC1 = 0;
	LOC1 = rawinsert_176425(c, key);
	popFrame();
}
NIM_EXTERNC N_NOINLINE(void, stdlib_critbitsInit000)(void) {
	nimfr("critbits", "critbits.nim")
	popFrame();
}

NIM_EXTERNC N_NOINLINE(void, stdlib_critbitsDatInit000)(void) {
static TNimNode* TMP792[3];
static TNimNode* TMP793[2];
static TNimNode* TMP805[3];
static TNimNode* TMP806[2];
static TNimNode TMP790[16];
NTI176396.size = sizeof(Nodeobj176396);
NTI176396.kind = 18;
NTI176396.base = 0;
NTI176396.flags = 2;
TMP792[0] = &TMP790[1];
TMP790[1].kind = 1;
TMP790[1].offset = offsetof(Nodeobj176396, byte);
TMP790[1].typ = (&NTI104);
TMP790[1].name = "byte";
TMP792[1] = &TMP790[2];
TMP790[2].kind = 1;
TMP790[2].offset = offsetof(Nodeobj176396, otherbits);
TMP790[2].typ = (&NTI136);
TMP790[2].name = "otherbits";
TMP792[2] = &TMP790[3];
TMP790[3].kind = 3;
TMP790[3].offset = offsetof(Nodeobj176396, isleaf);
TMP790[3].typ = (&NTI130);
TMP790[3].name = "isLeaf";
TMP790[3].sons = &NimDT_176396_isleaf[0];
TMP790[3].len = 2;
NTI176408.size = sizeof(TY176408);
NTI176408.kind = 16;
NTI176408.base = (&NTI176393);
NTI176408.flags = 2;
TMP790[4].kind = 1;
TMP790[4].offset = offsetof(Nodeobj176396, isleafU.child);
TMP790[4].typ = (&NTI176408);
TMP790[4].name = "child";
NimDT_176396_isleaf[0] = &TMP790[4];
TMP793[0] = &TMP790[6];
TMP790[6].kind = 1;
TMP790[6].offset = offsetof(Nodeobj176396, isleafU.S2.key);
TMP790[6].typ = (&NTI138);
TMP790[6].name = "key";
TMP793[1] = &TMP790[7];
TMP790[7].len = 0; TMP790[7].kind = 2;
TMP790[5].len = 2; TMP790[5].kind = 2; TMP790[5].sons = &TMP793[0];
NimDT_176396_isleaf[1] = &TMP790[5];
TMP790[0].len = 3; TMP790[0].kind = 2; TMP790[0].sons = &TMP792[0];
NTI176396.node = &TMP790[0];
NTI176393.size = sizeof(Nodeobj176396*);
NTI176393.kind = 22;
NTI176393.base = (&NTI176396);
NTI176393.flags = 2;
NTI176393.marker = TMP794;
NTI176610.size = sizeof(Nodeobj176610);
NTI176610.kind = 18;
NTI176610.base = 0;
NTI176610.flags = 2;
TMP805[0] = &TMP790[9];
TMP790[9].kind = 1;
TMP790[9].offset = offsetof(Nodeobj176610, byte);
TMP790[9].typ = (&NTI104);
TMP790[9].name = "byte";
TMP805[1] = &TMP790[10];
TMP790[10].kind = 1;
TMP790[10].offset = offsetof(Nodeobj176610, otherbits);
TMP790[10].typ = (&NTI136);
TMP790[10].name = "otherbits";
TMP805[2] = &TMP790[11];
TMP790[11].kind = 3;
TMP790[11].offset = offsetof(Nodeobj176610, isleaf);
TMP790[11].typ = (&NTI130);
TMP790[11].name = "isLeaf";
TMP790[11].sons = &NimDT_176610_isleaf[0];
TMP790[11].len = 2;
NTI176622.size = sizeof(TY176622);
NTI176622.kind = 16;
NTI176622.base = (&NTI176607);
NTI176622.flags = 2;
TMP790[12].kind = 1;
TMP790[12].offset = offsetof(Nodeobj176610, isleafU.child);
TMP790[12].typ = (&NTI176622);
TMP790[12].name = "child";
NimDT_176610_isleaf[0] = &TMP790[12];
TMP806[0] = &TMP790[14];
TMP790[14].kind = 1;
TMP790[14].offset = offsetof(Nodeobj176610, isleafU.S2.key);
TMP790[14].typ = (&NTI138);
TMP790[14].name = "key";
TMP806[1] = &TMP790[15];
TMP790[15].kind = 1;
TMP790[15].offset = offsetof(Nodeobj176610, isleafU.S2.val);
TMP790[15].typ = (&NTI104);
TMP790[15].name = "val";
TMP790[13].len = 2; TMP790[13].kind = 2; TMP790[13].sons = &TMP806[0];
NimDT_176610_isleaf[1] = &TMP790[13];
TMP790[8].len = 3; TMP790[8].kind = 2; TMP790[8].sons = &TMP805[0];
NTI176610.node = &TMP790[8];
NTI176607.size = sizeof(Nodeobj176610*);
NTI176607.kind = 22;
NTI176607.base = (&NTI176610);
NTI176607.flags = 2;
NTI176607.marker = TMP807;
}

