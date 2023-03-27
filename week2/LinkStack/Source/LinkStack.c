#include "LinkStack.h" 
#ifndef LINKSTACK_C_INCLUDED
#define LINKSTACK_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>


//链栈

//初始化栈
Status initLStack(LinkStack *s){
	s->top = (LinkStackPtr)malloc(sizeof(StackNode));
	s->top->next = NULL;
	s->count = 0;
	return SUCCESS;
	
}

//判断栈是否为空
Status isEmptyLStack(LinkStack *s){
	if(!s->top)
	{
		printf("\n请先初始化链栈!!\n");
		system("pause");
		return ERROR;
	}else if(s->count == 0)
	{
		printf("\n这是一个空链栈!!");
		system("pause");
		return SUCCESS;
	}else
	{
		printf("\n这不是一个空链栈!!\n");
		system("pause");
		return ERROR;
	}
}

//得到栈顶元素
Status getTopLStack(LinkStack *s,ElemType *e){
	if(!s->top)
	{
		printf("\n请先初始化链栈!!\n");
		return ERROR;
	}else if(s->count == 0) 
	{
		printf("\n这是一个空栈链，无法获得栈顶元素!!\n");
		return ERROR; 
	}
	else
	{
	*e = s->top->next->data;
	printf("\n成功获得栈顶元素!!\n");
	return SUCCESS;
	}

}

//清空栈
Status clearLStack(LinkStack *s){
	if(!s->top)
	{
		printf("\n请先初始化链栈!!\n");
		system("pause");
		return ERROR;
	}else if(s->count == 0)
	{
		printf("\n这是一个空栈链!!\n");
		system("pause");
		return ERROR;
	}else
	{
		LinkStackPtr p;
		while(s->top->next != NULL)
		{
			p=s->top->next;
			free(s->top);
			s->top=p;
			s->count--;
		}
		printf("\n清空成功!!\n");
		system("pause");
		
	}
}

//销毁栈
Status destroyLStack(LinkStack *s){
	if(!s->top)
	{
		printf("\n请先初始化链栈!!\n");
		system("pause");
		return ERROR;
	 } 
	 while(s->top)
	 {
	 	LinkStackPtr p;                                         // = (LinkStackPtr)malloc(sizeof(LinkStackPtr));
	 	p=s->top->next;
	 	free(s->top);
	 	s->top=p;
	 	s->count--;
	 	if(!s->top)
	 	{
	 		printf("\n销毁成功!!\n");
	 		system("pause");
		}
	 }
}

//检测栈长度
Status LStackLength(LinkStack *s,int *length){
	if(!s->top)
	{
		printf("\n请先初始化链栈!!\n");
		return ERROR;
	}else
	{
		*length = s->count;
		return SUCCESS; 
	}
	
}

//入栈
Status pushLStack(LinkStack *s,ElemType data){
	if(!s->top)
	{
		printf("\n请先初始化链栈!");
		return ERROR;
	}else
	{
		StackNode* p;
		p = (StackNode*)malloc(sizeof(StackNode));
		p->data=data;
		p->next=s->top->next;
		s->top->next=p;
		s->count++;
		printf("\n入栈成功!!\n");
		return SUCCESS; 
		
	}
}

//出栈
Status popLStack(LinkStack *s,ElemType *data){
	if(!s->top)
	{
		printf("\n请先初始化链栈!!\n");
		return ERROR; 
	}else if(s->count == 0)
	{
		printf("\n这是一个空栈链!!\n");
		return ERROR;
	}else
	{
		LinkStackPtr p1,p2;
		p1 = s->top->next;
		p2 = p1->next;
		s->top->next = p2;
		free(p1);
		s->count--;
		printf("\n成功出栈!!!\n");
		TraverseStack(s);
		return SUCCESS;
	}
}

void menu()
{
	printf("\n\t\t\t++++++++++++++++++++++++\n\t\t\t+欢迎来到链栈操作页面+\n\t\t\t++++++++++++++++++++++++\n");
    printf("\n		******************菜单栏*****************\n");
	printf("\t\t*\t      1.结束链栈操作            *\n");
	printf("\t\t*\t      2.初始化链栈              *\n");
	printf("\t\t*\t      3.判断是否为空            *\n");
	printf("\t\t*\t      4.得到栈顶元素            *\n");
	printf("\t\t*\t      5.销毁链栈                *\n");
	printf("\t\t*\t      6.获取栈长                *\n");
	printf("\t\t*\t      7.入栈                    *\n");
	printf("\t\t*\t      8.出栈                    *\n");
	printf("\t\t*\t      9.清空链栈                *\n");
	printf("		*****************************************\n");
	printf("\n");
	printf("\t\t请输入指令：[\t]\b\b\b");
}

void TraverseStack(LinkStack* s)
{
	if (!s->top) {
		printf("\n请先初始化链栈!\n");
		system("pause"); 
		return;
	}
	else if (s->count == 0) {
		printf("\n这是一个空链栈！\n");
		system("pause");
		return;
	}
	else {
		LinkStackPtr p = s->top->next;
		printf("\n链栈为：\n\n[top]<-");
		while (p) {
			printf("[%d]<- ", p->data);
			p = p->next;
		}
		printf("[bottom]\n\n");
		printf("\n现在链栈长度为：%d\n", s->count);
		system("pause");
		return;
	}
}



void checkinput(int* r) {
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


#endif 
