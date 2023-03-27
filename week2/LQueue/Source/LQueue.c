#include "LQueue.h" 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#ifndef LQUEUE_C_INCLUDED
#define LQUEUE_C_INCLUDED

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
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
		printf("\n��ʼ�����!!\n");
		flag = 0;      //��ǳ�ʼ�� 
		system("pause"); 
		return;
    }else if(flag == 0)
    {
    	printf("\n�Ѿ���ʼ�����������������³�ʼ��!!\n");
    	system("pause");
    	return;
	}
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q)
{
	if(flag == 1)
	{
		printf("\n��δ���г�ʼ������!!\n");
		system("pause");
		return;
	}else if(flag ==0)
	{
		ClearLQueue(Q);
		free(Q->front);
		free(Q);
		Q=NULL;
		printf("\n�ɹ�����!!\n");
		system("pause");
		flag =1;   //���±�� 
		return;
	}

}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
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
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
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
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q){
	printf("\n���еĳ���Ϊ%d\n",Q->length);
	system("pause");
	return TRUE;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue *Q, void *data)
{
	if(flag == 1)
	{
		printf("\n��δ���г�ʼ������!!\n");
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
		printf("\n�ɹ����!!!\n");
		system("pause");
		return TRUE;
	}

}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q)
{
	if(flag == 1)
	{
		printf("\n��δ���г�ʼ������!!\n");
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
		printf("\n�ɹ�����!!\n");
		return TRUE;
	}
	
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q)
{
	if(flag == 1)
	{
		printf("\n��δ���г�ʼ������!!\n");
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
		printf("\n�����!!\n");
		return;
	}

}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
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
 *    @description : ��������
 *    @param         q ָ��q
 
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


void menu()    //�˵� 
{
	printf("\n\t\t\t++++++++++++++++++++++++\n\t\t\t+��ӭ�������в���ҳ��+\n\t\t\t++++++++++++++++++++++++\n");
    printf("\n		******************�˵���*****************\n");
	printf("\t\t*\t      1.�������в���            *\n");
	printf("\t\t*\t      2.��ʼ������              *\n");
	printf("\t\t*\t      3.�ж��Ƿ�Ϊ��            *\n");
	printf("\t\t*\t      4.�õ���ͷԪ��            *\n");
	printf("\t\t*\t      5.���ٶ���                *\n");
	printf("\t\t*\t      6.��ȡ���г���            *\n");
	printf("\t\t*\t      7.��ն���                *\n");
	printf("\t\t*\t      8.���                    *\n");
	printf("\t\t*\t      9.����                    *\n");
	printf("\t\t*\t      10.��������               *\n");
	printf("		*****************************************\n");
	printf("\n");
	printf("\t\t������ָ�[\t]\b\b\b");
}

void checkinput(int* r)    //��� 
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
		if (error) printf("����������������룡\n");
	} while (error);
	*r = atoi(c);  //ת��Ϊ���� 
}


///////////////////////////////////////////////////////////////
void get_type()
{
	while(1)
	{
		type = '\0';
		printf("���������Ҫ������������:\n");
		printf("\n��i����ʾ��������f����ʾ������������c����ʾ�ַ���\n");
		scanf("%c", &type);
		while(getchar() != '\n');
		if(type=='i' || type=='f' || type=='c')
			break;
		else
		{
			system("cls");
			printf("�������!!\n");
		}
	}
}

void get_int(void **data)
{
	printf("\n��������:\n");
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
		printf("�����һ������-10000��С��10000����ȷ����;\n");
		flag=1;
	}	
}

void get_float(void **data)
{
	printf("������һ�����������������ַ�ʱ����Ĭ��Ϊ0����\n");
	float *p = (float*)malloc(sizeof(float));
	*p = 0.0;
	scanf("%f", p);
	*data = (void*)p;
	while(getchar() != '\n');
}

void get_char(void **data)
{
	printf("������һ���ַ�:\n");
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


