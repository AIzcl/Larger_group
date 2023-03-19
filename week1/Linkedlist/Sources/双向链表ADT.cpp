#include <stdio.h>
#include <stdlib.h>
#include <conio.h>    //getch()
#include <windows.h>  //Sleep()
#define LEN sizeof(struct Node)

//双链节节点结构 
typedef struct Node{
	Node *pre;     
	long data;
	Node *next;
}Node;



void menu1();  //主页面菜单 
Node *creat();   //创建双向列表 
void print(Node *head);  //打印 
Node *destroy(Node *head); //销毁 
void find(Node *head);     //查找 
Node *del(Node *head);   //删除 
Node *insert(Node *head);  //插入 
void modify(Node *head);   //修改 


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
        	default  :printf("您输入的数据非法!请您重新输入!!(按任意键返回输入)\n");getch();
	}
	
    }
	
}


//菜单 
void menu1()
{
	printf("\n\t\t\t++++++++++++++++++++++++\n\t\t\t+欢迎来到双链表操作页面+\n\t\t\t++++++++++++++++++++++++\n");
    printf("\n		******************菜单栏*****************\n");
	printf("\t\t*\t      1.结束双链表操作          *\n");
	printf("\t\t*\t      2.初始化双链表            *\n");
	printf("\t\t*\t      3.插入                    *\n");
	printf("\t\t*\t      4.删除                    *\n");
	printf("\t\t*\t      5.打印                    *\n");
	printf("\t\t*\t      6.查询                    *\n");
	printf("\t\t*\t      7.修改                    *\n");
	printf("\t\t*\t      8.销毁                    *\n");
	printf("		*****************************************\n");
	printf("\n");
	printf("\t\t请输入指令：[\t]\b\b\b");
}


//创建双链表 
Node *creat()
{
	system("cls");
	printf("欢迎来到初始化单链表页面!!\n");
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
			head1->pre=NULL;
			num++;
		}else
		{
			p2->next=p1;
			p1->pre=p2;
		}
		p2=p1;
		p1=(struct Node *)malloc(LEN);
		printf("请输入整数数据(当输入整数数据为0时代表完成初始化)：\n");
	    scanf("%ld",&p1->data); 
	}
	p2->next=NULL;
	printf("初始化单链表完成!!\n");
	system("pause");
	Sleep(100);
	return(head1);
}

//打印 
void print(Node *head)
{
	if(head==NULL)
	{
		printf("您未进行初始化双链表!!\n请您按任意键返回!!\n");
		system("pause"); 
		return ;
	}
	Node *p;
	p=head;
	printf("\n打印的双链表如下：\n");
	do
	{
		printf("%ld\n",p->data);
		p=p->next;
	}while(p!=NULL);
    system("pause");
    return;
}


//销毁
Node *destroy(Node *head)
{
	if(head==NULL)
	{
		printf("您未进行初始化单链表!!\n请您按任意键返回!!\n");
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
	printf("销毁成功!!\n");
	system("pause");
	return(head);
} 


//查找
void find(Node *head)
{
	if(head==NULL)
	{
		printf("您未进行初始化单链表!!\n请您按任意键返回!!\n");
		system("pause"); 
		return;
	}
	system("cls");
	Node *p;
	p=head;
	int j=1,i;
	printf("请输入要查询的节点的位置：\n");
	scanf("%d",&i);
	if(i<=0)
	{
		printf("输入有误!!请输入大于等于1的整数!!即将返回!!\n");
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
		printf("链表中第%d个位置的值是%d\n",i,p->data);
		system("pause");
		return;
	}else{
		printf("未找到!!");
		system("pause");
		return;
	}
} 

//删除 
Node *del(Node *head)
{
	if(head==NULL)
	{
		printf("您未进行初始化单链表!!\n请您按任意键返回!!\n");
		system("pause"); 
		return head;
	}
	system("cls");
	char isAgain; 
	Node *p,*p1;
	long data;
	printf("欢迎来到删除页面!!\n请输入要删除整数数据：");
	scanf("%ld",&data);
again://注意!!

    p=head;
	while(1)
	{
		if(head->data==data)    //处理头结点 
		{
			head=head->next;
			head->pre=NULL;
			free(p);     //释放动态内存 
			printf("继续删除按 1 ，返回按 2 \n");
			isAgain=getch();
			if(isAgain=='1')
			{
				printf("请输入要删除的整数数据：");
				scanf("%ld",&data);
				goto again;                                    //注意!!! 
			}
			else if(isAgain=='2')
			{
				break;
		    }
			else
			{
				printf("输入错误!!\n");
				Sleep(2000);
				break;
			}
		}else
		{
			p1=p;
			p1=p->next;   //p1指向下一动态内存存储区 
			
			
			if(p1->data==data&&p1->next!=NULL)   //处理中间结点 
			{
				p->next=p1->next;   //两个动态存储区连接处跳开中间的p1 
				p1->next->pre=p;
				p=p1;
				free(p1);
				printf("继续删除按 1 ，返回按 2 \n");
				isAgain=getch();
				if(isAgain=='1')
				{
					printf("请输入要删除整数数据：");
					scanf("%ld",&data);
					goto again;
				} 
				else if(isAgain=='2')
				{
					break;
				}
				else
			    {
				printf("输入错误!!\n");
				Sleep(2000);
				break;
			    }
			}else if(p1->data==data&&p1->next==NULL) //处理最后一个结点 
			{
				p->next=NULL;
				p=p1;
				free(p1);
				printf("继续删除按 1 ，返回按 2 \n");
				isAgain=getch();
				if(isAgain=='1')
				{
					printf("请输入要删除整数数据：");
					scanf("%ld",&data);
					goto again;
				} 
				else if(isAgain=='2')
				{
					break;
				}
				else
			    {
				printf("输入错误!!\n");
				Sleep(2000);
				break;
			    }
			} 
			
			
			p=p->next;  
		   if(p->next==NULL)
		   {
		   	printf("您输入有误!!!\n即将返回!!\n");
		   	system("pause");
		   	Sleep(2000);
		   	return head;
		   }
		}
	}
	
	
	printf("成功删除!!\n即将返回!!\n");
	Sleep(2000);
	system("pause");
	return head; 
	
}

//插入 
Node *insert(Node *head)
{
	if(head==NULL)
	{
		printf("您未进行初始化单链表!!\n请您按任意键返回!!\n");
		system("pause"); 
		return(head);
	}
	system("cls");
	int i;
	long e;
	char m;
	printf("请分别输入要插入的结点的位置\n以及要插入结点的整数数据:\n");
	scanf("%d %ld",&i,&e);
	if(i<1)
	{
		printf("输入的位置有误!!\n");
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
	printf("输入'a'代表前插，输入'b'代表后插!!\n");
    m=getch();                                            //这里的前插与后插算法差不多一样，
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
    	printf("输入有误!!\n");
    	system("pause");
    	return head;
	}
	printf("插入成功!!\n");
	system("pause");
	return head;
}
//修改 
void modify(Node *head)
{
	if(head==NULL)
	{
		printf("您未进行初始化单链表!!\n请您按任意键返回!!\n");
		system("pause"); 
		return;
	}
	system("cls");
	Node *p;
	p=head;
	int j=1,i;
	long data; 
	printf("请输入要修改的节点的位置\n以及该结点对应的新数据：\n");
	scanf("%d %ld",&i,&data);
	if(i<=0)
	{
		printf("输入有误!!请输入大于等于1的整数!!即将返回!!\n");
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
		printf("修改成功!!\n");
		system("pause");
		return;
	}else{
		printf("未找到!!");
		system("pause");
		return;
	}
}
