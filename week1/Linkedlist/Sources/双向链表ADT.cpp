#include <stdio.h>
#include <stdlib.h>
#include <conio.h>    //getch()
#include <windows.h>  //Sleep()
#define LEN sizeof(struct Node)

//˫���ڽڵ�ṹ 
typedef struct Node{
	Node *pre;     
	long data;
	Node *next;
}Node;



void menu1();  //��ҳ��˵� 
Node *creat();   //����˫���б� 
void print(Node *head);  //��ӡ 
Node *destroy(Node *head); //���� 
void find(Node *head);     //���� 
Node *del(Node *head);   //ɾ�� 
Node *insert(Node *head);  //���� 
void modify(Node *head);   //�޸� 


int main()
{
	Node *head;
	head=NULL;
	while(1)
	{
	system("cls");
	char command;
	menu1();
	command=getch();
	switch(command)
	{
		    case '1' : exit(0);
        	case '2' :head=creat() ;break;
        	case '3' :head=insert(head);break;
        	case '4' :head=del(head) ;break;
        	case '5' :print(head) ;break;
        	case '6' :find(head);break;
        	case '7' :modify(head);break;
        	case '8' :head=destroy(head);break;
        	default  :printf("����������ݷǷ�!������������!!(���������������)\n");getch();
	}
	
    }
	
}


//�˵� 
void menu1()
{
	printf("\n\t\t\t++++++++++++++++++++++++\n\t\t\t+��ӭ����˫�������ҳ��+\n\t\t\t++++++++++++++++++++++++\n");
    printf("\n		******************�˵���*****************\n");
	printf("\t\t*\t      1.����˫�������          *\n");
	printf("\t\t*\t      2.��ʼ��˫����            *\n");
	printf("\t\t*\t      3.����                    *\n");
	printf("\t\t*\t      4.ɾ��                    *\n");
	printf("\t\t*\t      5.��ӡ                    *\n");
	printf("\t\t*\t      6.��ѯ                    *\n");
	printf("\t\t*\t      7.�޸�                    *\n");
	printf("\t\t*\t      8.����                    *\n");
	printf("		*****************************************\n");
	printf("\n");
	printf("\t\t������ָ�[\t]\b\b\b");
}


//����˫���� 
Node *creat()
{
	system("cls");
	printf("��ӭ������ʼ��������ҳ��!!\n");
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
			head1->pre=NULL;
			num++;
		}else
		{
			p2->next=p1;
			p1->pre=p2;
		}
		p2=p1;
		p1=(struct Node *)malloc(LEN);
		printf("��������������(��������������Ϊ0ʱ������ɳ�ʼ��)��\n");
	    scanf("%ld",&p1->data); 
	}
	p2->next=NULL;
	printf("��ʼ�����������!!\n");
	system("pause");
	Sleep(100);
	return(head1);
}

//��ӡ 
void print(Node *head)
{
	if(head==NULL)
	{
		printf("��δ���г�ʼ��˫����!!\n���������������!!\n");
		system("pause"); 
		return ;
	}
	Node *p;
	p=head;
	printf("\n��ӡ��˫�������£�\n");
	do
	{
		printf("%ld\n",p->data);
		p=p->next;
	}while(p!=NULL);
    system("pause");
    return;
}


//����
Node *destroy(Node *head)
{
	if(head==NULL)
	{
		printf("��δ���г�ʼ��������!!\n���������������!!\n");
		system("pause"); 
		return(head);
	}
    Node *p1;
	while(head!=NULL)
	{
		p1=head;
		head=head->next;
		free(p1);
	}
	printf("���ٳɹ�!!\n");
	system("pause");
	return(head);
} 


//����
void find(Node *head)
{
	if(head==NULL)
	{
		printf("��δ���г�ʼ��������!!\n���������������!!\n");
		system("pause"); 
		return;
	}
	system("cls");
	Node *p;
	p=head;
	int j=1,i;
	printf("������Ҫ��ѯ�Ľڵ��λ�ã�\n");
	scanf("%d",&i);
	if(i<=0)
	{
		printf("��������!!��������ڵ���1������!!��������!!\n");
		Sleep(1000);
		return;
	}
	while((j<i) && (p->next!=NULL))
	{
		p=p->next;
		j++;
	}
	if(i==j)
	{
		printf("�����е�%d��λ�õ�ֵ��%d\n",i,p->data);
		system("pause");
		return;
	}else{
		printf("δ�ҵ�!!");
		system("pause");
		return;
	}
} 

//ɾ�� 
Node *del(Node *head)
{
	if(head==NULL)
	{
		printf("��δ���г�ʼ��������!!\n���������������!!\n");
		system("pause"); 
		return head;
	}
	system("cls");
	char isAgain; 
	Node *p,*p1;
	long data;
	printf("��ӭ����ɾ��ҳ��!!\n������Ҫɾ���������ݣ�");
	scanf("%ld",&data);
again://ע��!!

    p=head;
	while(1)
	{
		if(head->data==data)    //����ͷ��� 
		{
			head=head->next;
			head->pre=NULL;
			free(p);     //�ͷŶ�̬�ڴ� 
			printf("����ɾ���� 1 �����ذ� 2 \n");
			isAgain=getch();
			if(isAgain=='1')
			{
				printf("������Ҫɾ�����������ݣ�");
				scanf("%ld",&data);
				goto again;                                    //ע��!!! 
			}
			else if(isAgain=='2')
			{
				break;
		    }
			else
			{
				printf("�������!!\n");
				Sleep(2000);
				break;
			}
		}else
		{
			p1=p;
			p1=p->next;   //p1ָ����һ��̬�ڴ�洢�� 
			
			
			if(p1->data==data&&p1->next!=NULL)   //�����м��� 
			{
				p->next=p1->next;   //������̬�洢�����Ӵ������м��p1 
				p1->next->pre=p;
				p=p1;
				free(p1);
				printf("����ɾ���� 1 �����ذ� 2 \n");
				isAgain=getch();
				if(isAgain=='1')
				{
					printf("������Ҫɾ���������ݣ�");
					scanf("%ld",&data);
					goto again;
				} 
				else if(isAgain=='2')
				{
					break;
				}
				else
			    {
				printf("�������!!\n");
				Sleep(2000);
				break;
			    }
			}else if(p1->data==data&&p1->next==NULL) //�������һ����� 
			{
				p->next=NULL;
				p=p1;
				free(p1);
				printf("����ɾ���� 1 �����ذ� 2 \n");
				isAgain=getch();
				if(isAgain=='1')
				{
					printf("������Ҫɾ���������ݣ�");
					scanf("%ld",&data);
					goto again;
				} 
				else if(isAgain=='2')
				{
					break;
				}
				else
			    {
				printf("�������!!\n");
				Sleep(2000);
				break;
			    }
			} 
			
			
			p=p->next;  
		   if(p->next==NULL)
		   {
		   	printf("����������!!!\n��������!!\n");
		   	system("pause");
		   	Sleep(2000);
		   	return head;
		   }
		}
	}
	
	
	printf("�ɹ�ɾ��!!\n��������!!\n");
	Sleep(2000);
	system("pause");
	return head; 
	
}

//���� 
Node *insert(Node *head)
{
	if(head==NULL)
	{
		printf("��δ���г�ʼ��������!!\n���������������!!\n");
		system("pause"); 
		return(head);
	}
	system("cls");
	int i;
	long e;
	char m;
	printf("��ֱ�����Ҫ����Ľ���λ��\n�Լ�Ҫ���������������:\n");
	scanf("%d %ld",&i,&e);
	if(i<1)
	{
		printf("�����λ������!!\n");
		system("pause");
		return head;
	}
	Node *p;
	int j=1;
	p=head;
	while(p->next!=NULL && (j<i))
	{
		p=p->next;
		j++;
	}
	printf("����'a'����ǰ�壬����'b'������!!\n");
    m=getch();                                            //�����ǰ�������㷨���һ����
	if(m=='a')
	{
	Node *q=(Node *)malloc(LEN);
	if(p->pre==NULL)
	{
		q->data=e;
		
		q->next=p;
		p->pre=q;
		q->pre=NULL; 
		head=q;
	}else if(p->next==NULL)
	{
		p->next=q;
		q->pre=p;
		q->next=NULL;
		
		q->data=p->data;
		p->data=e; 
	}else
	{
		p->next->pre=q;
		q->next=p->next;
		p->next=q;
		q->pre=p;
		
		q->data=p->data;
		p->data=e;
	}
    }else if(m=='b'){
	Node *q=(Node *)malloc(LEN);
	if(p->pre==NULL)
	{
		q->data=p->data;
		p->data=e;
		
		q->next=p;
		p->pre=q;
		q->pre=NULL; 
		head=q;
	}else if(p->next==NULL)
	{
		p->next=q;
		q->pre=p;
		q->next=NULL;
		
        q->data=e;
	}else
	{
		p->next->pre=q;
		q->next=p->next;
		p->next=q;
		q->pre=p;
		
		q->data=e;
	}
    }else{
    	printf("��������!!\n");
    	system("pause");
    	return head;
	}
	printf("����ɹ�!!\n");
	system("pause");
	return head;
}
//�޸� 
void modify(Node *head)
{
	if(head==NULL)
	{
		printf("��δ���г�ʼ��������!!\n���������������!!\n");
		system("pause"); 
		return;
	}
	system("cls");
	Node *p;
	p=head;
	int j=1,i;
	long data; 
	printf("������Ҫ�޸ĵĽڵ��λ��\n�Լ��ý���Ӧ�������ݣ�\n");
	scanf("%d %ld",&i,&data);
	if(i<=0)
	{
		printf("��������!!��������ڵ���1������!!��������!!\n");
		Sleep(1000);
		return;
	}
	while((j<i) && (p->next!=NULL))
	{
		p=p->next;
		j++;
	}
	if(i==j)
	{
		p->data=data;
		printf("�޸ĳɹ�!!\n");
		system("pause");
		return;
	}else{
		printf("δ�ҵ�!!");
		system("pause");
		return;
	}
}
