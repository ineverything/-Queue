#include"AQueue.h"
#include<stdio.h>
#include<string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

enum {datatype,INT,CHAR,DOUBLE};
int main(int argc, char *argv[]) 
{
	int t;
	 
	printf("����ʵ���������ͣ�:\n");
    printf("1. ���� 2. �ַ��� 3. ������(��ȷ��С�����2λ) \n");
    scanf("%d", &t);
    while(t<1 || t>=4)
    {
     	printf("Ӧ������[1,3]֮���������\n�����䣺");
      	scanf("%d", &t);
    }
    switch(t)
    {
     	case INT:{
     	int a = 1,b = 2,c = 3,d = 4;
     	int head;
     	printf("��������Q1����ʼ��.\n������󳤶�Ϊ10.\n������Ԫ������Ϊint.\n"); 
		AQueue Q1;
		Q1.data_size = sizeof(int); 
		InitAQueue(&Q1);
		if(IsEmptyAQueue(&Q1))
			printf("��ʱ����Ϊ��.\n");
		else
			printf("��ʱ���в�Ϊ��.\n");
			
		printf("�������Ԫ��1,2,3,4\n");
		EnAQueue(&Q1,&a);
		EnAQueue(&Q1,&b);
		EnAQueue(&Q1,&c);
		EnAQueue(&Q1,&d);
		printf("��ʱ���еĳ�����%d\n",LengthAQueue(&Q1));
		GetHeadAQueue(&Q1, &head);
		printf("��ʱ��ͷԪ��Ϊ��%d\n",head);
		TraverseAQueue(&Q1, APrint);
	//	APrint(&Q1,Q1.data_size);
		printf("���Ӷ�ͷԪ��.\n");
		DeAQueue(&Q1);
		TraverseAQueue(&Q1, APrint);
	//	APrint(&Q1,Q1.data_size);
		
		if(IsFullAQueue(&Q1))
			printf("��ʱ��������.\n");
		else
			printf("��ʱ����δ��.\n");
		printf("��գ����ٶ���.\n");
		ClearAQueue(&Q1);	
		DestoryAQueue(&Q1);
		break;
		}
		case CHAR: {
		char a = 'a',b = 'b',c = 'c',d = 'd';
		char head;
		
     	printf("��������Q2����ʼ��.\n������󳤶�Ϊ10.\n������Ԫ������Ϊchar.\n"); 
		AQueue Q2;
		Q2.data_size = sizeof(char); 
		InitAQueue(&Q2);
		if(IsEmptyAQueue(&Q2))
			printf("��ʱ����Ϊ��.\n");
		else
			printf("��ʱ���в�Ϊ��.\n");
			
		printf("�������Ԫ��a,b,c,d\n");
		EnAQueue(&Q2,&a);
		EnAQueue(&Q2,&b);
		EnAQueue(&Q2,&c);
		EnAQueue(&Q2,&d);
		printf("��ʱ���еĳ�����%d\n",LengthAQueue(&Q2));
		GetHeadAQueue(&Q2, &head);
		printf("��ʱ��ͷԪ��Ϊ��%c\n",head);
		TraverseAQueue(&Q2, APrint);
		
		printf("���Ӷ�ͷԪ��.\n");
		DeAQueue(&Q2);
		TraverseAQueue(&Q2, APrint);

		
		if(IsFullAQueue(&Q2))
			printf("��ʱ��������.\n");
		else
			printf("��ʱ����δ��.\n");
		printf("��գ����ٶ���.\n");
		ClearAQueue(&Q2);	
		DestoryAQueue(&Q2);
		break;
		}
        case DOUBLE:{
		double a = 1.00,b = 2.00,c = 3.00,d = 4.00;
		double head;
     	printf("��������Q3����ʼ��.\n������󳤶�Ϊ10.\n������Ԫ������Ϊdouble.\n"); 
		AQueue Q3;
		Q3.data_size = sizeof(double); 
		InitAQueue(&Q3);
		if(IsEmptyAQueue(&Q3))
			printf("��ʱ����Ϊ��.\n");
		else
			printf("��ʱ���в�Ϊ��.\n");
			
		printf("�������Ԫ��1.00,2.00,3.00,4.00\n");
		EnAQueue(&Q3,&a);
		EnAQueue(&Q3,&b);
		EnAQueue(&Q3,&c);
		EnAQueue(&Q3,&d);
		printf("��ʱ���еĳ�����%d\n",LengthAQueue(&Q3));
		GetHeadAQueue(&Q3, &head);
		printf("��ʱ��ͷԪ��Ϊ��%f\n",head);
		TraverseAQueue(&Q3, APrint);

		printf("���Ӷ�ͷԪ��.\n");
		DeAQueue(&Q3);
		TraverseAQueue(&Q3, APrint);

		
		if(IsFullAQueue(&Q3))
			printf("��ʱ��������.\n");
		else
			printf("��ʱ����δ��.\n");
		printf("��գ����ٶ���.\n");
		ClearAQueue(&Q3);	
		DestoryAQueue(&Q3);
		break;
		}
}
	getchar(); 
	getchar(); 
	return 0;
}
