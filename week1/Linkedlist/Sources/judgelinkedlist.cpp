#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "judgelinkedlist.h" 
/*
#define LEN sizeof(struct Node)

//�ڵ�ṹ�� 
typedef struct Node {
	long data;      //���� 
	struct Node *next;   //ָ����һ���ڵ��ָ�루�洢��һ���ڵ�ĵ�ַ�� 
}Node;


Node *creat(); //���ڴ��������ҳ�ʼ������
void judge(Node *head); //�����ж������Ƿ�ɻ� 
void menu1();  //��ҳ��˵� 
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
			default  :printf("����������ݷǷ�!������������!!(���������������)\n");getch();
		}
	}
	

	
 } 
 
 //�˵� 
void menu1()
{
	printf("\n\t\t\t++++++++++++++++++++++++\n\t\t\t+��ӭ�����������ҳ��+\n\t\t\t++++++++++++++++++++++++\n");
    printf("\n		******************�˵���*****************\n");
	printf("\t\t*\t      1.�����������          *\n");
	printf("\t\t*\t      2.��ʼ������              *\n");
	printf("\t\t*\t      3.�ж��Ƿ�ɻ�            *\n");
	printf("		*****************************************\n");
	printf("\n");
	printf("\t\t������ָ�[\t]\b\b\b");
}

 
 //�������� 
Node *creat()
{
	system("cls");
	printf("��ӭ������ʼ������ҳ��!!\n");
	Node *head1,*p1,*p2;
	head1=NULL;
	int num = 1;
	p1=p2=(struct Node *)malloc(LEN);
	printf("��������������(��������������Ϊ0ʱ������ɳ�ʼ��)��\n");
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
		printf("��������������(��������������Ϊ0ʱ������ɳ�ʼ��)��\n");
	    scanf("%ld",&p1->data); 
	}
	char m;
	
	again:
		
	printf("��Ҫ�ɻ�������'a',����Ҫ�ɻ�������'b'!!\n");
	m=getch();
	if(m=='b')
	{
		p2->next=NULL;
	}else if(m=='a')
	{
		p2->next=head1;
	}else
	{
		printf("�������!!\n");
		goto again;                      //��ע���Ⲩ!!��ʹ����goto��䣬��Ҫ��Ϊ�˷���,����һ���ʹ��ѭ��. 
	}

	printf("��ʼ�����!!\n");
	system("pause");
	Sleep(100);
	return(head1);
}

//�жϺ���
void judge(Node *head)
{
	if(head==NULL)
	{
		printf("��δ���г�ʼ��������!!\n���������������!!\n");
		system("pause"); 
		return ;
	}
	system("cls");
	//���ÿ���ָ��,���Ҷ���ָ����ͷ��㿪ʼ 
	Node *fast,*slow;
	fast=head;
	slow=head;
	
	while(fast!=NULL&&fast->next!=NULL)
	{
		fast=fast->next->next;
		slow=slow->next;
		if(slow==fast)
		{
			printf("������ɻ�!!!\n");
			getch();
			return;
		}
	}
	printf("�������ɻ�!!\n");
	system("pause");
	return;
	
} 
