#include"LQueue.h"
#include<stdio.h> 

enum{datatype,INT,CHAR,DOUBLE};

int main(int argc, char *argv[]) 
{
	int t;
	printf("����ʵ���������ͣ�\n");
    printf("1. ���� 2. �ַ��� 3. ������(��ȷ��С�����2λ) \n");
    scanf("%d", &t);
    while(t<1 || t>3)
    {
     	printf("Ӧ������[1,3]֮���������\n�����䣺");
      	scanf("%d", &t);
    }
    switch(t)
    {
     	case INT:{
     	int a = 1,b = 2,c = 3,d = 4;
     	int head; 
     	printf("��������Q1����ʼ��.\n������Ԫ������Ϊint.\n"); 
		LQueue Q1;
		Q1.data_size = sizeof(int); 
		InitLQueue(&Q1);
		if(IsEmptyLQueue(&Q1))
			printf("��ʱ����Ϊ��.\n");
		else
			printf("��ʱ���в�Ϊ��.\n");
			
		printf("�������Ԫ��1,2,3,4\n");
		EnLQueue(&Q1,&a);
		EnLQueue(&Q1,&b);
		EnLQueue(&Q1,&c);
		EnLQueue(&Q1,&d);
		printf("��ʱ���еĳ�����%d\n",LengthLQueue(&Q1));
		GetHeadLQueue(&Q1, &head);
		printf("��ʱ��ͷԪ��Ϊ��%d\n",head);
		TraverseLQueue(&Q1, LPrint);

		printf("���Ӷ�ͷԪ��.\n");
		DeLQueue(&Q1);
		TraverseLQueue(&Q1, LPrint);
		if(IsEmptyLQueue(&Q1))
			printf("��ʱ����Ϊ��.\n");
		else
			printf("��ʱ���в�Ϊ��.\n");
		printf("��ն���.\n");
		ClearLQueue(&Q1);
		if(IsEmptyLQueue(&Q1))
			printf("��ʱ����Ϊ��.\n");
		else
			printf("��ʱ���в�Ϊ��.\n");
			
		printf("���ٶ���.\n");	
		DestoryLQueue(&Q1);
		break;
		}
		case CHAR: {
		char a = 'a',b = 'b',c = 'c',d = 'd';
		char head;
		
     	printf("��������Q2����ʼ��.\n������Ԫ������Ϊchar.\n"); 
		LQueue Q2;
		Q2.data_size = sizeof(char); 
		InitLQueue(&Q2);
		if(IsEmptyLQueue(&Q2))
			printf("��ʱ����Ϊ��.\n");
		else
			printf("��ʱ���в�Ϊ��.\n");
			
		printf("�������Ԫ��a,b,c,d\n");
		EnLQueue(&Q2,&a);
		EnLQueue(&Q2,&b);
		EnLQueue(&Q2,&c);
		EnLQueue(&Q2,&d);
		printf("��ʱ���еĳ�����%d\n",LengthLQueue(&Q2));
		GetHeadLQueue(&Q2, &head);
		printf("��ʱ��ͷԪ��Ϊ��%c\n",head);
		TraverseLQueue(&Q2, LPrint);
		
		printf("���Ӷ�ͷԪ��.\n");
		DeLQueue(&Q2);
		TraverseLQueue(&Q2, LPrint);

		if(IsEmptyLQueue(&Q2))
			printf("��ʱ����Ϊ��.\n");
		else
			printf("��ʱ���в�Ϊ��.\n");
		printf("��ն���.\n");
		ClearLQueue(&Q2);
		if(IsEmptyLQueue(&Q2))
			printf("��ʱ����Ϊ��.\n");
		else
			printf("��ʱ���в�Ϊ��.\n");
			
		printf("���ٶ���.\n");
		DestoryLQueue(&Q2);
		break;
		}
        case DOUBLE:{
		double a = 1.00,b = 2.00,c = 3.00,d = 4.00;
		double head = 0;
		
     	printf("��������Q3����ʼ��.\n������Ԫ������Ϊdouble.\n"); 
		LQueue Q3;
		Q3.data_size = sizeof(double); 
		InitLQueue(&Q3);
		if(IsEmptyLQueue(&Q3))
			printf("��ʱ����Ϊ��.\n");
		else
			printf("��ʱ���в�Ϊ��.\n");
			
		printf("�������Ԫ��1.00,2.00,3.00,4.00\n");
		EnLQueue(&Q3,&a);
		EnLQueue(&Q3,&b);
		EnLQueue(&Q3,&c);
		EnLQueue(&Q3,&d);
		printf("��ʱ���еĳ�����%d\n",LengthLQueue(&Q3));
		GetHeadLQueue(&Q3, &head);
		printf("��ʱ��ͷԪ��Ϊ��%f\n",head);
		TraverseLQueue(&Q3, LPrint);
		
		printf("���Ӷ�ͷԪ��.\n");
		DeLQueue(&Q3);
		TraverseLQueue(&Q3, LPrint);
		
		if(IsEmptyLQueue(&Q3))
			printf("��ʱ����Ϊ��.\n");
		else
			printf("��ʱ���в�Ϊ��.\n");
		printf("��ն���.\n");
		ClearLQueue(&Q3);
		if(IsEmptyLQueue(&Q3))
			printf("��ʱ����Ϊ��.\n");
		else
			printf("��ʱ���в�Ϊ��.\n");
			
		printf("���ٶ���.\n");
		DestoryLQueue(&Q3);
		break;
		}
   }
   getchar(); 
   getchar(); 
	return 0;
}
