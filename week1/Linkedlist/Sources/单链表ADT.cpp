#include <stdio.h>
#include <stdlib.h>    //()malloc()
#include <conio.h>     //getch()
#include <windows.h>   //Sleep()
#define LEN sizeof(struct Node)

int x = 0;     //����һ��ȫ�ֱ�����������ĸ��� 


//�ڵ�ṹ�� 
typedef struct Node {
	long data;      //���� 
	struct Node *next;   //ָ����һ���ڵ��ָ�루�洢��һ���ڵ�ĵ�ַ�� 
}Node;

void menu1();  //��ҳ��˵� 
Node *creat(); //���ڴ��������ҳ�ʼ������
Node *del(Node *head);   //ɾ�� 
void print(Node *head);  //��ӡ 
Node *destroy(Node *head); //���� 
void find(Node *head);     //���� 
Node *insert(Node *head);  //���� 
void modify(Node *head);   //�޸� 
Node *odd_even_exchange(Node *head);  //��żλ����λ�� 
void find_middle(Node *head);         //���ҵ������е� 
Node *reversal(Node *head);           //��ת(�ݹ�ͷǵݹ�-����)
Node *recursion(Node *head);          //�ݹ麯��ʵ�ַ�ת 




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
        	case '3' :head=insert(head) ;break;
        	case '4' :head=del(head) ;break;
        	case '5' :print(head) ;break;
        	case '6' :find(head) ;break;
        	case '7' :modify(head);break;
        	case '8' :head=destroy(head);break;
        	case '9' :head=odd_even_exchange(head);break;
        	case 'a' :find_middle(head);break;
        	case 'b' :head=reversal(head);break;
        	default  :printf("����������ݷǷ�!������������!!(���������������)\n");getch();
	}
	
    }
	
}

//�˵� 
void menu1()
{
	printf("\n\t\t\t++++++++++++++++++++++++\n\t\t\t+��ӭ�������������ҳ��+\n\t\t\t++++++++++++++++++++++++\n");
    printf("\n		******************�˵���*****************\n");
	printf("\t\t*\t      1.�������������          *\n");
	printf("\t\t*\t      2.��ʼ��������            *\n");
	printf("\t\t*\t      3.����                    *\n");
	printf("\t\t*\t      4.ɾ��                    *\n");
	printf("\t\t*\t      5.��ӡ                    *\n");
	printf("\t\t*\t      6.��ѯ                    *\n");
	printf("\t\t*\t      7.�޸�                    *\n");
	printf("\t\t*\t      8.����                    *\n");
	printf("\t\t*\t      9.��żλ����              *\n");
	printf("\t\t*\t      a.�����е�                *\n");
	printf("\t\t*\t      b.����ת               *\n");
	printf("		*****************************************\n");
	printf("\n");
	printf("\t\t������ָ�[\t]\b\b\b");
}


//�������� 
Node *creat()
{
	x=0;
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
		x=x+1;                              //ÿ��ѭ����������һ����� 
		printf("%d\n",x);
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
	p2->next=NULL;
	printf("��ʼ�����������!!\n");
	system("pause");
	Sleep(100);
	return(head1);
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
		if(head->data==data)
		{
			head=head->next;
			//
			free(p);     //�ͷŶ�̬�ڴ� 
			x--;
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
			
			
			if(p1->data==data)
			{
				p->next=p1->next;   //������̬�洢�����Ӵ������м��p1 
				//
				p=p1;
				free(p1);
				x--;
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


//��ӡ 
void print(Node *head)
{
	if(head==NULL)
	{
		printf("��δ���г�ʼ��������!!\n���������������!!\n");
		system("pause"); 
		return ;
	}
	Node *p;
	p=head;
	printf("\n��ӡ�ĵ��������£�\n");
	do
	{  
		printf("%ld\n",p->data);
		p=p->next;
	}while(p!=NULL);
    system("pause");
    return;
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
	printf("������Ҫ����Ľ���λ��\n�Լ�Ҫ���������������:\n");
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
    m=getch();
	if(m=='a')
	{
	Node *q=(Node *)malloc(LEN);
	q->next=p->next;
	p->next=q;
	q->data=p->data;
	p->data=e;
    }else if(m=='b'){
	Node *s=(Node *)malloc(LEN);
	s->data=e;
	s->next=p->next;
	p->next=s;
    }else{
    	printf("��������!!\n");
    	system("pause");
    	return head;
	}
	x--;
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


//��żλ����λ�� -------------------------------
Node *odd_even_exchange(Node *head)
{
	if(head==NULL)
	{
		printf("��δ���г�ʼ��������!!\n���������������!!\n");
		system("pause"); 
		return head;
	}
	system("cls");
	/*---------------------------------------����ֵ�ĵ��� 
	Node *p,*q;
	long t;     //tΪ�м���� 
	p=head;
	q=head->next;
	t=p->data;
	p->data=q->data;
	q->data=t;
	while(q->next!=NULL &&q->next->next!=NULL)
	{
		p=q->next;
		q=p->next;
		t=p->data;
		p->data=q->data;
		q->data=t;
	}
	printf("��żλ�����ɹ�!!\n");
	system("pause");
	return;
	*/
	
	
	//���µķ����ǽ������ 
	int i;         //������ 
	
	Node *p,*q,*s;
	p=head;
	q=head->next;

    
	head=q;
	p->next=q->next;             //p��q��żλ���� 
	q->next=p;
	
	
	
	s=p;         //s���ڱ�� 
	
	
	for(i=1;i<=(x/2)-1;i++)
	{
		p=s->next;
		q=p->next;            //p��q����ת�� 
		
		s->next=q;
		p->next=q->next;    //p��q��żλ���� 
		q->next=p;
		 
		s=p;               //�ٴα�� 
	}
	printf("��żλ�����ɹ�!!\n");
	system("pause");
	return head;
} 

//���ҵ�������е�
void find_middle(Node *head)
{
	if(head==NULL)
	{
		printf("��δ���г�ʼ��������!!\n���������������!!\n");
		system("pause"); 
		return ;
	}
	system("cls");
	Node *fast,*slow;    //�������ָ�� 
	fast=head;
	slow=head;
	while((fast!=NULL)&&(fast->next!=NULL))
	{
		fast=fast->next->next;
		slow=slow->next; 
	}
	printf("��������е����������Ϊ��%ld\n",slow->data);
	system("pause");
	return;
} 


//����ת 
Node *reversal(Node *head)
{
	if(head==NULL)
	{
		printf("��δ���г�ʼ��������!!\n���������������!!\n");
		system("pause"); 
		return head;
	}
	system("cls");
	char m;
	printf("ʹ�÷ǵݹ鷽��ʵ��������'a',ʹ�õݹ鷽��ʵ��������'b'!!\n");
	m=getch();
	if(m=='a')
	{
		Node *p,*q;
		p=head->next;
		head->next=NULL;
		while(p!=NULL)
		{
			q=p;
			p=p->next;
			q->next=head;
			head=q;
		}
		printf("����ת�ɹ�!!\n");
	}else if(m=='b')
	{
		head=recursion(head);
		printf("����ת�ɹ�!!\n");
	}else
	{
		printf("�������!!\n");
	}
	
	system("pause");
	return head;
	
}


//�ݹ麯��ʵ�ַ�ת
//1.�ݹ����ֹ������;2.δ�ﵽ��ֹ������һֱ�ݹ飬�����ݹ���ʲô������ʲô �� 
//��Ҫע��ÿһ��ݹ����β�head�ĺ��� 
Node *recursion(Node *head)
{
	Node *last;
	if(head->next==NULL)
	{
		return head;                 //�ݹ���� 
	}else
	{
		last=recursion(head->next);   //��� 
        //������һ��ݹ��Ҫ����	
		head->next->next=head;
		head->next=NULL;
		//����
		return last; 
	}
} 



