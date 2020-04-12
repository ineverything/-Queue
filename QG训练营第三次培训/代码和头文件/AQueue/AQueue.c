#include"AQueue.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : 初始化队列，数组分配空间，头尾指针为0 
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitAQueue(AQueue *Q)
{
	int i;
	for (i = 0; i < MAXQUEUE; i++)
		Q->data[i] = (void *)malloc(Q->data_size);
	Q->front = 0;
	Q->rear  = 0;

}
/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : 销毁队列，释放每一个空间 
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue *Q) 
{  
	int i;
	for (i = 0; i < MAXQUEUE; i++)
		free(Q->data[i]);
}

/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : 检查队列是否已满
 *    @param         Q 队列指针Q
 *    @return         : 满-TRUE; 未满-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q)  //const不对队列进行修改 
{
	if( (Q->front == (Q->rear + 1) % MAXQUEUE) )
		return TRUE;
	else 
		return FALSE;
}

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q)
{
	if(Q->front == Q->rear)
		return TRUE;
	else 
		return FALSE;
} 
/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q 队列指针Q，存放元素e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadAQueue(AQueue *Q, void *e) //此处也可以使用二级指针
{
	if (IsEmptyAQueue(Q))
		return FALSE;
	int i = Q->front; 
	i = (i + 1) % MAXQUEUE;
	memcpy(e, Q->data[i], Q->data_size);//void *memcpy(void *str1, const void *str2, size_t n) 
	return TRUE;									//从存储区 str2 复制 n 个字符到存储区 str1。
}		

/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 队列长度count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q)
{
	return (Q->rear - Q->front + MAXQUEUE) % MAXQUEUE;
}	

/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否满了或为空
 */
Status EnAQueue(AQueue *Q, void *data)
{
	if (IsFullAQueue(Q)) 
		return FALSE;
	Q->rear = (Q->rear+1) % MAXQUEUE;
	memcpy(Q->data[Q->rear], data, Q->data_size);
	return TRUE;
}
/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q)
{
	if (IsEmptyAQueue(Q))
		return FALSE;
	Q->front = (Q->front + 1) % MAXQUEUE;
	return TRUE;
}		

/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q)
{
	if (IsEmptyAQueue(Q))
	Q->front = 0;
	Q->rear = 0;
}	
/**
 *  @name        :Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q, int size)) 
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q, int size))
 { 
	if (IsEmptyAQueue(Q))
		return FALSE;
	int i = 1;
	printf("此时队列中元素为:\n");
	while (i <= (MAXQUEUE - Q->front + Q->rear) % MAXQUEUE ) {
		foo(Q->data[Q->front+i], Q->data_size);	
		i = (i + 1) % MAXQUEUE;
	}
	printf("\n"); 
	return TRUE;
}
/**
 *  @name        : void APrint(void *q,int size)
 *    @description : 操作函数
 *    @param         q 指针q
 *  @notice      : None
 */
void APrint(void *q,int size)
{
	if (size == sizeof(double))
		printf("%lf", *(double *)q);
	if (size == sizeof(char))
		printf("%c", *(char *)q);
	if (size == sizeof (int))
		printf("%d", *(int *)q);
	printf("-<");
}	

