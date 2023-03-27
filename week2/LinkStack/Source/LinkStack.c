#include "LinkStack.h" 
#ifndef LINKSTACK_C_INCLUDED
#define LINKSTACK_C_INCLUDED
#include <stdio.h>
#include <stdlib.h>


//��ջ

//��ʼ��ջ
Status initLStack(LinkStack *s){
	s->top = (LinkStackPtr)malloc(sizeof(StackNode));
	s->top->next = NULL;
	s->count = 0;
	return SUCCESS;
	
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack *s){
	if(!s->top)
	{
		printf("\n���ȳ�ʼ����ջ!!\n");
		system("pause");
		return ERROR;
	}else if(s->count == 0)
	{
		printf("\n����һ������ջ!!");
		system("pause");
		return SUCCESS;
	}else
	{
		printf("\n�ⲻ��һ������ջ!!\n");
		system("pause");
		return ERROR;
	}
}

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack *s,ElemType *e){
	if(!s->top)
	{
		printf("\n���ȳ�ʼ����ջ!!\n");
		return ERROR;
	}else if(s->count == 0) 
	{
		printf("\n����һ����ջ�����޷����ջ��Ԫ��!!\n");
		return ERROR; 
	}
	else
	{
	*e = s->top->next->data;
	printf("\n�ɹ����ջ��Ԫ��!!\n");
	return SUCCESS;
	}

}

//���ջ
Status clearLStack(LinkStack *s){
	if(!s->top)
	{
		printf("\n���ȳ�ʼ����ջ!!\n");
		system("pause");
		return ERROR;
	}else if(s->count == 0)
	{
		printf("\n����һ����ջ��!!\n");
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
		printf("\n��ճɹ�!!\n");
		system("pause");
		
	}
}

//����ջ
Status destroyLStack(LinkStack *s){
	if(!s->top)
	{
		printf("\n���ȳ�ʼ����ջ!!\n");
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
	 		printf("\n���ٳɹ�!!\n");
	 		system("pause");
		}
	 }
}

//���ջ����
Status LStackLength(LinkStack *s,int *length){
	if(!s->top)
	{
		printf("\n���ȳ�ʼ����ջ!!\n");
		return ERROR;
	}else
	{
		*length = s->count;
		return SUCCESS; 
	}
	
}

//��ջ
Status pushLStack(LinkStack *s,ElemType data){
	if(!s->top)
	{
		printf("\n���ȳ�ʼ����ջ!");
		return ERROR;
	}else
	{
		StackNode* p;
		p = (StackNode*)malloc(sizeof(StackNode));
		p->data=data;
		p->next=s->top->next;
		s->top->next=p;
		s->count++;
		printf("\n��ջ�ɹ�!!\n");
		return SUCCESS; 
		
	}
}

//��ջ
Status popLStack(LinkStack *s,ElemType *data){
	if(!s->top)
	{
		printf("\n���ȳ�ʼ����ջ!!\n");
		return ERROR; 
	}else if(s->count == 0)
	{
		printf("\n����һ����ջ��!!\n");
		return ERROR;
	}else
	{
		LinkStackPtr p1,p2;
		p1 = s->top->next;
		p2 = p1->next;
		s->top->next = p2;
		free(p1);
		s->count--;
		printf("\n�ɹ���ջ!!!\n");
		TraverseStack(s);
		return SUCCESS;
	}
}

void menu()
{
	printf("\n\t\t\t++++++++++++++++++++++++\n\t\t\t+��ӭ������ջ����ҳ��+\n\t\t\t++++++++++++++++++++++++\n");
    printf("\n		******************�˵���*****************\n");
	printf("\t\t*\t      1.������ջ����            *\n");
	printf("\t\t*\t      2.��ʼ����ջ              *\n");
	printf("\t\t*\t      3.�ж��Ƿ�Ϊ��            *\n");
	printf("\t\t*\t      4.�õ�ջ��Ԫ��            *\n");
	printf("\t\t*\t      5.������ջ                *\n");
	printf("\t\t*\t      6.��ȡջ��                *\n");
	printf("\t\t*\t      7.��ջ                    *\n");
	printf("\t\t*\t      8.��ջ                    *\n");
	printf("\t\t*\t      9.�����ջ                *\n");
	printf("		*****************************************\n");
	printf("\n");
	printf("\t\t������ָ�[\t]\b\b\b");
}

void TraverseStack(LinkStack* s)
{
	if (!s->top) {
		printf("\n���ȳ�ʼ����ջ!\n");
		system("pause"); 
		return;
	}
	else if (s->count == 0) {
		printf("\n����һ������ջ��\n");
		system("pause");
		return;
	}
	else {
		LinkStackPtr p = s->top->next;
		printf("\n��ջΪ��\n\n[top]<-");
		while (p) {
			printf("[%d]<- ", p->data);
			p = p->next;
		}
		printf("[bottom]\n\n");
		printf("\n������ջ����Ϊ��%d\n", s->count);
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
		if (error) printf("����������������룡\n");
	} while (error);
	*r = atoi(c);  //ת��Ϊ���� 
}


#endif 
