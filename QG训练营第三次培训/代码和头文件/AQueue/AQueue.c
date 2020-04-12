#include"AQueue.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : ��ʼ�����У��������ռ䣬ͷβָ��Ϊ0 
 *    @param         Q ����ָ��Q
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
 *    @description : ���ٶ��У��ͷ�ÿһ���ռ� 
 *    @param         Q ����ָ��Q
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
 *    @description : �������Ƿ�����
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q)  //const���Զ��н����޸� 
{
	if( (Q->front == (Q->rear + 1) % MAXQUEUE) )
		return TRUE;
	else 
		return FALSE;
}

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
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
 *    @description : �鿴��ͷԪ��
 *    @param         Q ����ָ��Q�����Ԫ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadAQueue(AQueue *Q, void *e) //�˴�Ҳ����ʹ�ö���ָ��
{
	if (IsEmptyAQueue(Q))
		return FALSE;
	int i = Q->front; 
	i = (i + 1) % MAXQUEUE;
	memcpy(e, Q->data[i], Q->data_size);//void *memcpy(void *str1, const void *str2, size_t n) 
	return TRUE;									//�Ӵ洢�� str2 ���� n ���ַ����洢�� str1��
}		

/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : ���г���count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q)
{
	return (Q->rear - Q->front + MAXQUEUE) % MAXQUEUE;
}	

/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ����˻�Ϊ��
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
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
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
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
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
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q, int size))
 { 
	if (IsEmptyAQueue(Q))
		return FALSE;
	int i = 1;
	printf("��ʱ������Ԫ��Ϊ:\n");
	while (i <= (MAXQUEUE - Q->front + Q->rear) % MAXQUEUE ) {
		foo(Q->data[Q->front+i], Q->data_size);	
		i = (i + 1) % MAXQUEUE;
	}
	printf("\n"); 
	return TRUE;
}
/**
 *  @name        : void APrint(void *q,int size)
 *    @description : ��������
 *    @param         q ָ��q
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

