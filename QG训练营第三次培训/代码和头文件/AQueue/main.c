#include"AQueue.h"
#include<stdio.h>
#include<string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

enum {datatype,INT,CHAR,DOUBLE};
int main(int argc, char *argv[]) 
{
	int t;
	 
	printf("你想实现哪种类型？:\n");
    printf("1. 整型 2. 字符型 3. 浮点型(精确到小数点后2位) \n");
    scanf("%d", &t);
    while(t<1 || t>=4)
    {
     	printf("应输入在[1,3]之间的整数！\n请重输：");
      	scanf("%d", &t);
    }
    switch(t)
    {
     	case INT:{
     	int a = 1,b = 2,c = 3,d = 4;
     	int head;
     	printf("创建队列Q1并初始化.\n队列最大长度为10.\n队列中元素类型为int.\n"); 
		AQueue Q1;
		Q1.data_size = sizeof(int); 
		InitAQueue(&Q1);
		if(IsEmptyAQueue(&Q1))
			printf("此时队列为空.\n");
		else
			printf("此时队列不为空.\n");
			
		printf("依次入队元素1,2,3,4\n");
		EnAQueue(&Q1,&a);
		EnAQueue(&Q1,&b);
		EnAQueue(&Q1,&c);
		EnAQueue(&Q1,&d);
		printf("此时队列的长度是%d\n",LengthAQueue(&Q1));
		GetHeadAQueue(&Q1, &head);
		printf("此时队头元素为：%d\n",head);
		TraverseAQueue(&Q1, APrint);
	//	APrint(&Q1,Q1.data_size);
		printf("出队队头元素.\n");
		DeAQueue(&Q1);
		TraverseAQueue(&Q1, APrint);
	//	APrint(&Q1,Q1.data_size);
		
		if(IsFullAQueue(&Q1))
			printf("此时队列已满.\n");
		else
			printf("此时队列未满.\n");
		printf("清空，销毁队列.\n");
		ClearAQueue(&Q1);	
		DestoryAQueue(&Q1);
		break;
		}
		case CHAR: {
		char a = 'a',b = 'b',c = 'c',d = 'd';
		char head;
		
     	printf("创建队列Q2并初始化.\n队列最大长度为10.\n队列中元素类型为char.\n"); 
		AQueue Q2;
		Q2.data_size = sizeof(char); 
		InitAQueue(&Q2);
		if(IsEmptyAQueue(&Q2))
			printf("此时队列为空.\n");
		else
			printf("此时队列不为空.\n");
			
		printf("依次入队元素a,b,c,d\n");
		EnAQueue(&Q2,&a);
		EnAQueue(&Q2,&b);
		EnAQueue(&Q2,&c);
		EnAQueue(&Q2,&d);
		printf("此时队列的长度是%d\n",LengthAQueue(&Q2));
		GetHeadAQueue(&Q2, &head);
		printf("此时队头元素为：%c\n",head);
		TraverseAQueue(&Q2, APrint);
		
		printf("出队队头元素.\n");
		DeAQueue(&Q2);
		TraverseAQueue(&Q2, APrint);

		
		if(IsFullAQueue(&Q2))
			printf("此时队列已满.\n");
		else
			printf("此时队列未满.\n");
		printf("清空，销毁队列.\n");
		ClearAQueue(&Q2);	
		DestoryAQueue(&Q2);
		break;
		}
        case DOUBLE:{
		double a = 1.00,b = 2.00,c = 3.00,d = 4.00;
		double head;
     	printf("创建队列Q3并初始化.\n队列最大长度为10.\n队列中元素类型为double.\n"); 
		AQueue Q3;
		Q3.data_size = sizeof(double); 
		InitAQueue(&Q3);
		if(IsEmptyAQueue(&Q3))
			printf("此时队列为空.\n");
		else
			printf("此时队列不为空.\n");
			
		printf("依次入队元素1.00,2.00,3.00,4.00\n");
		EnAQueue(&Q3,&a);
		EnAQueue(&Q3,&b);
		EnAQueue(&Q3,&c);
		EnAQueue(&Q3,&d);
		printf("此时队列的长度是%d\n",LengthAQueue(&Q3));
		GetHeadAQueue(&Q3, &head);
		printf("此时队头元素为：%f\n",head);
		TraverseAQueue(&Q3, APrint);

		printf("出队队头元素.\n");
		DeAQueue(&Q3);
		TraverseAQueue(&Q3, APrint);

		
		if(IsFullAQueue(&Q3))
			printf("此时队列已满.\n");
		else
			printf("此时队列未满.\n");
		printf("清空，销毁队列.\n");
		ClearAQueue(&Q3);	
		DestoryAQueue(&Q3);
		break;
		}
}
	getchar(); 
	getchar(); 
	return 0;
}
