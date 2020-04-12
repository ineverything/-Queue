#include"LQueue.h"
#include<stdio.h> 
#include<stdlib.h>
#include<string.h>

/**
 *  @name        : Status InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
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
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
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
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
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
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue *Q, void *e)
{
	if (IsEmptyLQueue(Q))
		return FALSE;
	memcpy(e, Q->front->next->data, Q->data_size);//��ͷ�����һ���ڵ�ָ���λ�ø����ֽ��� 
	return TRUE;	
 } 

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : ȷ�����г���,ָ���ͷ��㵽β��� 
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
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
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
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
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
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
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q)
{
	Node *p,*ptemp;
   if(Q!=NULL){
      if(Q->front!=NULL){
          p=Q->front->next;
          while(p!=NULL){//�ͷŶ��пռ� 
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
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
//foo����Lprint��ӡ���� 
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
 *    @description : ��������
 *    @param         q ָ��q
 
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
