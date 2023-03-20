#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "judgelinkedlist.h" 
/*
#define LEN sizeof(struct Node)

//节点结构体 
typedef struct Node {
	long data;      //数据 
	struct Node *next;   //指向下一个节点的指针（存储下一个节点的地址） 
}Node;


Node *creat(); //用于创建链表并且初始化数据
void judge(Node *head); //用于判断链表是否成环 
void menu1();  //主页面菜单 
*/

int main()
{
	Node *head;
	head=NULL;
	while(1)
	{
		system("cls");
		menu1();
		char command;
		command=getch();
		switch(command)
		{
			case'1' :exit(0);
			case'2' :head=creat();break;
			case'3' :judge(head);break;
			default  :printf("您输入的数据非法!请您重新输入!!(按任意键返回输入)\n");getch();
		}
	}
	

	
 } 
 
 //菜单 
void menu1()
{
	printf("\n\t\t\t++++++++++++++++++++++++\n\t\t\t+欢迎来到链表操作页面+\n\t\t\t++++++++++++++++++++++++\n");
    printf("\n		******************菜单栏*****************\n");
	printf("\t\t*\t      1.结束链表操作          *\n");
	printf("\t\t*\t      2.初始化链表              *\n");
	printf("\t\t*\t      3.判断是否成环            *\n");
	printf("		*****************************************\n");
	printf("\n");
	printf("\t\t请输入指令：[\t]\b\b\b");
}

 
 //创建链表 
Node *creat()
{
	system("cls");
	printf("欢迎来到初始化链表页面!!\n");
	Node *head1,*p1,*p2;
	head1=NULL;
	int num = 1;
	p1=p2=(struct Node *)malloc(LEN);
	printf("请输入整数数据(当输入整数数据为0时代表完成初始化)：\n");
	scanf("%ld",&p1->data); 
	while(p1->data!=0)
	{                         
		if(num==1)
		{
			head1=p1;
			num++;
		}else
		{
			p2->next=p1;
		}
		p2=p1;
		p1=(struct Node *)malloc(LEN);
		printf("请输入整数数据(当输入整数数据为0时代表完成初始化)：\n");
	    scanf("%ld",&p1->data); 
	}
	char m;
	
	again:
		
	printf("需要成环请输入'a',不需要成环请输入'b'!!\n");
	m=getch();
	if(m=='b')
	{
		p2->next=NULL;
	}else if(m=='a')
	{
		p2->next=head1;
	}else
	{
		printf("输入错误!!\n");
		goto again;                      //请注意这波!!我使用了goto语句，主要是为了方便,不过一般会使用循环. 
	}

	printf("初始化完成!!\n");
	system("pause");
	Sleep(100);
	return(head1);
}

//判断函数
void judge(Node *head)
{
	if(head==NULL)
	{
		printf("您未进行初始化单链表!!\n请您按任意键返回!!\n");
		system("pause"); 
		return ;
	}
	system("cls");
	//利用快慢指针,并且都从指定的头结点开始 
	Node *fast,*slow;
	fast=head;
	slow=head;
	
	while(fast!=NULL&&fast->next!=NULL)
	{
		fast=fast->next->next;
		slow=slow->next;
		if(slow==fast)
		{
			printf("该链表成环!!!\n");
			getch();
			return;
		}
	}
	printf("该链表不成环!!\n");
	system("pause");
	return;
	
} 
