

#ifndef __MEMBLOCK_H__
#define __MEMBLOCK_H__

#include "includes.h"

/**********************************************************
*                  内存相关常用结构体声明
***********************************************************/
//常见返回值
typedef	enum  
{
	OK = 0,
	FAULT,
	OVERFLOW,
	EMPTY
}NORMAL_STATE;

//循环队列结构
typedef	struct
{
	uint16_t  front;
	uint16_t  rear;
	uint16_t  length;
	uint16_t  count;
	uint8_t	  *data;
}CIR_QUEUE,*pCIR_QUEUE;

//堆栈结构
typedef struct
{
	uint16_t top;
	uint16_t length;
	uint8_t* base;
}STORE, *pSTORE;

typedef struct     //内存监控变量
{
	uint16_t memUsedNum1;    //内存块1当前正在使用的数量
	uint16_t memUsedMax1;    //内存块1历史同一时间使用最大的数量
	uint8_t memUsedNum2;
	uint8_t memUsedMax2;
	uint8_t memUsedNum3;
	uint8_t memUsedMax3;
	uint8_t memUsedNum4;
	uint8_t memUsedMax4;
	uint8_t memUsedNum5;
	uint8_t memUsedMax5;
	uint8_t memUsedNum6;
	uint8_t memUsedMax6;
	uint8_t memUsedNum7;
	uint8_t memUsedMax7;
}MEM_Check;


//队列初始化
pCIR_QUEUE    Cir_Queue_Init(uint16_t length);
//删除队列
NORMAL_STATE  CirQ_Delete(pCIR_QUEUE ptr_Q);
//清空队列
NORMAL_STATE  CirQ_Clear(pCIR_QUEUE ptr_Q);
//得到队列保存值的数量
uint16_t      CirQ_GetLength(pCIR_QUEUE ptr_Q);
//从队列中取出一个值
NORMAL_STATE  CirQ_Pop(pCIR_QUEUE ptr_Q,uint8_t *phead);
//向队列中压入一个值
NORMAL_STATE  CirQ_OnePush(pCIR_QUEUE ptr_Q,uint8_t dat);
//向队列中压入很多值
NORMAL_STATE  CirQ_Pushs(pCIR_QUEUE ptr_Q,const uint8_t *pdata,uint16_t length);

pSTORE       Store_Init(uint16_t length);
NORMAL_STATE Store_Delete(pSTORE S);
NORMAL_STATE Store_Clear(pSTORE S);
NORMAL_STATE Store_Pop(uint8_t *pdat,pSTORE S);
uint16_t     Store_Getlength(pSTORE S);
NORMAL_STATE Store_Getdates(uint8_t *pdate,pSTORE S,uint16_t num);

NORMAL_STATE Store_Push(pSTORE S,uint8_t dat);
NORMAL_STATE Store_Pushs(pSTORE S,uint8_t *pdate,uint16_t num);


/**********************************************************
*                  内存控制相关声明
***********************************************************/

#define MEM_16B_ROW		100
#define MEM_16B_COL		18

#define MEM_32B_ROW		60
#define MEM_32B_COL		34

#define MEM_64B_ROW		70
#define MEM_64B_COL		66

#define MEM_128B_ROW	15
#define MEM_128B_COL	130

#define MEM_256B_ROW	20
#define MEM_256B_COL	258

#define MEM_512B_ROW	16
#define MEM_512B_COL	514

#define MEM_1KB_ROW	    10
#define MEM_1KB_COL	    1026

void    *Mem_malloc(uint16_t size);
uint8_t Mem_free(void **ptr);
uint8_t MemBuf_Init(void);






#endif

