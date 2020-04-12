#include"LQueue.h"
#include<stdio.h> 

enum{datatype,INT,CHAR,DOUBLE};

int main(int argc, char *argv[]) 
{
	int t;
	printf("你想实现哪种类型？\n");
    printf("1. 整型 2. 字符型 3. 浮点型(精确到小数点后2位) \n");
    scanf("%d", &t);
    while(t<1 || t>3)
    {
     	printf("应输入在[1,3]之间的整数！\n请重输：");
      	scanf("%d", &t);
    }
    switch(t)
    {
     	case INT:{
     	int a = 1,b = 2,c = 3,d = 4;
     	int head; 
     	printf("创建队列Q1并初始化.\n队列中元素类型为int.\n"); 
		LQueue Q1;
		Q1.data_size = sizeof(int); 
		InitLQueue(&Q1);
		if(IsEmptyLQueue(&Q1))
			printf("此时队列为空.\n");
		else
			printf("此时队列不为空.\n");
			
		printf("依次入队元素1,2,3,4\n");
		EnLQueue(&Q1,&a);
		EnLQueue(&Q1,&b);
		EnLQueue(&Q1,&c);
		EnLQueue(&Q1,&d);
		printf("此时队列的长度是%d\n",LengthLQueue(&Q1));
		GetHeadLQueue(&Q1, &head);
		printf("此时队头元素为：%d\n",head);
		TraverseLQueue(&Q1, LPrint);

		printf("出队队头元素.\n");
		DeLQueue(&Q1);
		TraverseLQueue(&Q1, LPrint);
		if(IsEmptyLQueue(&Q1))
			printf("此时队列为空.\n");
		else
			printf("此时队列不为空.\n");
		printf("清空队列.\n");
		ClearLQueue(&Q1);
		if(IsEmptyLQueue(&Q1))
			printf("此时队列为空.\n");
		else
			printf("此时队列不为空.\n");
			
		printf("销毁队列.\n");	
		DestoryLQueue(&Q1);
		break;
		}
		case CHAR: {
		char a = 'a',b = 'b',c = 'c',d = 'd';
		char head;
		
     	printf("创建队列Q2并初始化.\n队列中元素类型为char.\n"); 
		LQueue Q2;
		Q2.data_size = sizeof(char); 
		InitLQueue(&Q2);
		if(IsEmptyLQueue(&Q2))
			printf("此时队列为空.\n");
		else
			printf("此时队列不为空.\n");
			
		printf("依次入队元素a,b,c,d\n");
		EnLQueue(&Q2,&a);
		EnLQueue(&Q2,&b);
		EnLQueue(&Q2,&c);
		EnLQueue(&Q2,&d);
		printf("此时队列的长度是%d\n",LengthLQueue(&Q2));
		GetHeadLQueue(&Q2, &head);
		printf("此时队头元素为：%c\n",head);
		TraverseLQueue(&Q2, LPrint);
		
		printf("出队队头元素.\n");
		DeLQueue(&Q2);
		TraverseLQueue(&Q2, LPrint);

		if(IsEmptyLQueue(&Q2))
			printf("此时队列为空.\n");
		else
			printf("此时队列不为空.\n");
		printf("清空队列.\n");
		ClearLQueue(&Q2);
		if(IsEmptyLQueue(&Q2))
			printf("此时队列为空.\n");
		else
			printf("此时队列不为空.\n");
			
		printf("销毁队列.\n");
		DestoryLQueue(&Q2);
		break;
		}
        case DOUBLE:{
		double a = 1.00,b = 2.00,c = 3.00,d = 4.00;
		double head = 0;
		
     	printf("创建队列Q3并初始化.\n队列中元素类型为double.\n"); 
		LQueue Q3;
		Q3.data_size = sizeof(double); 
		InitLQueue(&Q3);
		if(IsEmptyLQueue(&Q3))
			printf("此时队列为空.\n");
		else
			printf("此时队列不为空.\n");
			
		printf("依次入队元素1.00,2.00,3.00,4.00\n");
		EnLQueue(&Q3,&a);
		EnLQueue(&Q3,&b);
		EnLQueue(&Q3,&c);
		EnLQueue(&Q3,&d);
		printf("此时队列的长度是%d\n",LengthLQueue(&Q3));
		GetHeadLQueue(&Q3, &head);
		printf("此时队头元素为：%f\n",head);
		TraverseLQueue(&Q3, LPrint);
		
		printf("出队队头元素.\n");
		DeLQueue(&Q3);
		TraverseLQueue(&Q3, LPrint);
		
		if(IsEmptyLQueue(&Q3))
			printf("此时队列为空.\n");
		else
			printf("此时队列不为空.\n");
		printf("清空队列.\n");
		ClearLQueue(&Q3);
		if(IsEmptyLQueue(&Q3))
			printf("此时队列为空.\n");
		else
			printf("此时队列不为空.\n");
			
		printf("销毁队列.\n");
		DestoryLQueue(&Q3);
		break;
		}
   }
   getchar(); 
   getchar(); 
	return 0;
}
