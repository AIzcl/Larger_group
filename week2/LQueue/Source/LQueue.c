#include "LQueue.h" 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#ifndef LQUEUE_C_INCLUDED
#define LQUEUE_C_INCLUDED

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q)
{
	if(flag == 1)
	{
		Node *p;
		p = (Node* )malloc(sizeof(Node));
		p->next = NULL;
		Q->front = Q->rear = p;
		Q->length = 0;
		printf("\n初始化完成!!\n");
		flag = 0;      //标记初始化 
		system("pause"); 
		return;
    }else if(flag == 0)
    {
    	printf("\n已经初始化，请先销毁再重新初始化!!\n");
    	system("pause");
    	return;
	}
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q)
{
	if(flag == 1)
	{
		printf("\n您未进行初始化队列!!\n");
		system("pause");
		return;
	}else if(flag ==0)
	{
		ClearLQueue(Q);
		free(Q->front);
		free(Q);
		Q=NULL;
		printf("\n成功销毁!!\n");
		system("pause");
		flag =1;   //重新标记 
		return;
	}

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
	if(flag == 1)
	{
		return SIGN;
	}else if(flag == 0)
	{
		if(Q->front == Q->rear)
		{
			return TRUE;
		}else
		{
			return FALSE;
		}
	}

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
	if(flag == 1)
	{
		return SIGN;
	}else if(flag == 0)
	{
		if(IsEmptyLQueue(Q) == TRUE)
		{
			return FALSE;
		}
			if(type == 'i')
		{
			*(int*)e = *(int*)Q->front->next->data;
		}else if(type == 'f')
		{
			*(float*)e = *(float*)Q->front->next->data;
		}else
		{
			*(char*)e = *(char*)Q->front->next->data;
		}
		return TRUE;
	}
	
	
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q){
	printf("\n队列的长度为%d\n",Q->length);
	system("pause");
	return TRUE;
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
	if(flag == 1)
	{
		printf("\n您未进行初始化队列!!\n");
		system("pause");
		return FALSE;
	}else if(flag == 0)
	{
		Node *p = (Node*)malloc(sizeof(Node));
		p->data = data;
		p->next = NULL;
		Q->rear->next = p;
		Q->rear = p;
		Q->length++;
		printf("\n成功入队!!!\n");
		system("pause");
		return TRUE;
	}

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
	if(flag == 1)
	{
		printf("\n您未进行初始化队列!!\n");
		return FALSE;
	}else if(flag == 0)
	{
		if(IsEmptyLQueue(Q))
		{
			return FALSE;
		}
	
		Node *p = NULL;
		p = Q->front;
		Q->front = p->next;
		free(p);
		Q->length--;
		printf("\n成功出队!!\n");
		return TRUE;
	}
	
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q)
{
	if(flag == 1)
	{
		printf("\n您未进行初始化队列!!\n");
		system("pause");
		return ;
	}else if(flag == 0)
	{
		int i;
		while(!IsEmptyLQueue(Q))
		{
			for(i=0;i<Q->length;i++)
			{
				DeLQueue(Q);
			} 
		}
		printf("\n已清空!!\n");
		return;
	}

}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
{
	Node* p =(Node*)malloc(sizeof(Node));
	p=Q->front->next;
	while(p != NULL)
	{
		foo(p->data);
		p = p->next;
	}
	system("pause");
	return TRUE;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 
 *  @notice      : None
 */
void LPrint(void *q){
	if(type == 'i')
	{
		printf("[%d]  ",*(int*)q);
	}else if(type == 'f')
	{
		printf("[%.2f]  ",*(float*)q);
	}else
	{
		printf("[%c]  ",*(double*)q);
	}
	return;
}


void menu()    //菜单 
{
	printf("\n\t\t\t++++++++++++++++++++++++\n\t\t\t+欢迎来到队列操作页面+\n\t\t\t++++++++++++++++++++++++\n");
    printf("\n		******************菜单栏*****************\n");
	printf("\t\t*\t      1.结束队列操作            *\n");
	printf("\t\t*\t      2.初始化队列              *\n");
	printf("\t\t*\t      3.判断是否为空            *\n");
	printf("\t\t*\t      4.得到队头元素            *\n");
	printf("\t\t*\t      5.销毁队列                *\n");
	printf("\t\t*\t      6.获取队列长度            *\n");
	printf("\t\t*\t      7.清空队列                *\n");
	printf("\t\t*\t      8.入队                    *\n");
	printf("\t\t*\t      9.出队                    *\n");
	printf("\t\t*\t      10.遍历队列               *\n");
	printf("		*****************************************\n");
	printf("\n");
	printf("\t\t请输入指令：[\t]\b\b\b");
}

void checkinput(int* r)    //检查 
{
	int error = 0, i = 0;
	char c[50] = { 0 };
	do {
		gets(c);
		error = 0;
		for (i = 0; c[i] != '\0'; i++) {
			if (i == 0 && c[i] == '-')
			{
				continue;
			}
			if (c[i] < '0' || c[i]>'9')
				error = 1;
		}
		if (error) printf("输入错误，请重新输入！\n");
	} while (error);
	*r = atoi(c);  //转化为整数 
}


///////////////////////////////////////////////////////////////
void get_type()
{
	while(1)
	{
		type = '\0';
		printf("请告诉我您要保留哪种数据:\n");
		printf("\n“i”表示整数，“f”表示浮点数，而“c”表示字符！\n");
		scanf("%c", &type);
		while(getchar() != '\n');
		if(type=='i' || type=='f' || type=='c')
			break;
		else
		{
			system("cls");
			printf("输入错误!!\n");
		}
	}
}

void get_int(void **data)
{
	printf("\n输入整数:\n");
	int *p = (int*)malloc(sizeof(int));
	char s[50];
	int flag=1;
	while(1)
	{
		gets(s);
		if(*s == '-')
		{
			if(strlen(s) < 6)
			{
				int i;
				for(i=1; i<6 && s[i]!='\0'; i++)
					if(s[i]<'0' || s[i]>'9');
					{
						flag = 0;
						break;
					}
				if(flag == 1)
				{
					*p = 0;
					for(i=1; i<6 && s[i]!='\0'; i++)
						*p = (*p)*10 + s[i] - '0';
					(*p) *= -1;
					*data = (void*)p;
					return;
				}
			}
		}
		else if(strlen(s) < 5)
		{
			int i;
			for(i=0; i<5 && s[i]!='\0'; i++)
				if(s[i]<'0' || s[i]>'9')
				{
					flag = 0;
					break;
				}
			if(flag == 1)
			{
				*p = 0;
				for(i=0; i<5 && s[i]!='\0'; i++)
					*p = (*p)*10 + s[i] - '0';
				*data = (void*)p;
				return;
			}
		}
		printf("请给我一个大于-10000且小于10000的正确整数;\n");
		flag=1;
	}	
}

void get_float(void **data)
{
	printf("请输入一个浮点数（当输入字符时，将默认为0）：\n");
	float *p = (float*)malloc(sizeof(float));
	*p = 0.0;
	scanf("%f", p);
	*data = (void*)p;
	while(getchar() != '\n');
}

void get_char(void **data)
{
	printf("请输入一个字符:\n");
	char *p = (char*)malloc(sizeof(char));
	*p = '0';
	scanf("%c", p);
	while(getchar() != '\n');
	*data = (void*)(p);
}


/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
#endif // LQUEUE_H_INCLUDED


