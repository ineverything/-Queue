#include"LQueue.h"
#include<stdio.h> 
#include<stdlib.h>
#include<string.h>

/**
 *  @name        : Status InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
Status InitLQueue(LQueue *Q)
{
	Node *p = (Node *)malloc(sizeof(Node));
	if (NULL == p)
		return OVERFLOWING;
	p->next = NULL;
	Q->front = p;
	Q->rear = p;
	return TRUE;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q)
{
	ClearLQueue(Q);
    
   free(Q->front);
   Q->front=NULL;
   Q->rear=NULL;
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q)
{
	if(Q->front == Q->rear)
		return TRUE;
	else 
		return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q, void *e)
{
	if (IsEmptyLQueue(Q))
		return FALSE;
	memcpy(e, Q->front->next->data, Q->data_size);//在头结点下一个节点指向的位置赋予字节数 
	return TRUE;	
 } 

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度,指针从头结点到尾结点 
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q)
{
	int length;
	Node *p = (Node *)malloc(sizeof(Node));
	p = Q->front;
	for (length = 0; p != Q->rear; length++)
		p = p->next; 
	return length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data)
{
	Node *p = (Node *)malloc(sizeof(Node));
	if (p == NULL)
		return FALSE;
	p->data = (void *)malloc(Q->data_size);
	memcpy(p->data, data, Q->data_size);
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return TRUE;	
 } 

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q)
{
	if(IsEmptyLQueue(Q))
		return FALSE;
	Node *p = (Node *)malloc(sizeof(Node));
	p = Q->front->next;
	Q->front->next = p->next;
	if (Q->front->next == NULL)  
		Q->rear = Q->front;
	free(p);
	return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q)
{
	Node *p,*ptemp;
   if(Q!=NULL){
      if(Q->front!=NULL){
          p=Q->front->next;
          while(p!=NULL){//释放队列空间 
             ptemp=p->next;
             free(p);
             p=ptemp;
          }
          Q->front->next=NULL;
          Q->rear=Q->front;
       }
    }

}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q, int size)) 
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
//foo利用Lprint打印函数 
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q, int size))
 {
	if (IsEmptyLQueue(Q))
		return FALSE;
		Node* p = (void *)malloc(Q->data_size); 
		p = Q->front->next; 
		int i = 1;
		while (p != NULL) {
			if (i % 5 == 0) printf("\n"); 
			foo(p->data, Q->data_size);
			p = p->next;
			i++;
		}
		printf("\n");
	return TRUE;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 
 *  @notice      : None
 */
void LPrint(void *q, int size) 
{
	if (size == sizeof(double))
		printf("%lf", *(double *)q);
	if (size == sizeof(char))
		printf("%c", *(char *)q);
	if (size == sizeof (int))
		printf("%d", *(int *)q);
	printf("-<");
}
