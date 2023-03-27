#include "LinkStack.h"
#include "LinkStack.c"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>


int main()
{
	int i,command,remark;   //remark���������պ�������ֵ�� 
	ElemType data,e,length,size; 
	LinkStack* s = (LinkStack*)malloc(sizeof(LinkStack*));
	s->top = NULL;  //�ж���ջ�Ƿ񱻳�ʼ�� 
	while(1)
	{
		system("cls");
		menu();
	    checkinput(&command);
	    switch(command)
	    {
		    case 1 : exit(0);
        	case 2 :
			{
					  if(s->top != NULL)
					  {
					    	printf("\n�Ѿ�����һ����ջ��������֮ǰ����ջ!!\n");
					    	system("pause");
					  }else
					  {
		                    initLStack(s);
		                    printf("\n��������ջ�ĳ���(���㰴�»س���ʱ��ϵͳĬ��Ϊ0)��\n");
		                    checkinput(&size);
		                    for(i=0;i<size;i++)
		                    {
		                    	printf("\n�������������(���㰴�»س���ʱ��ϵͳĬ��Ϊ0):\n");
		                    	checkinput(&data);
		                        pushLStack(s,data);
							}
							printf("\n��ջ��ʼ���ɹ�!!\n");
							TraverseStack(s);
					  }
				      break;
			}
        	case 3 :isEmptyLStack(s);break;
        	case 4 :
			{
        		remark = getTopLStack(s,&e);
        		if(remark == 1)
        		{
        			printf("\nջ��Ԫ��Ϊ%d\n",e);
				}
        		system("pause");
				break;
			}
        	case 5 :destroyLStack(s);break;
        	case 6 :
			{
        		remark=LStackLength(s,&length);
        		if(remark == 1)
        		{
        			printf("\n��ջ�ĳ���Ϊ%d\n",length);
				}
        		system("pause");
				break;
			}
        	case 7 :
			{
				if(!s->top)
				{
		        	printf("\n���ȳ�ʼ��\n");
		        	system("pause");
				}else 
				{
					printf("\n�������������(���㰴�»س���ʱ��ϵͳĬ��Ϊ0):\n");
		        	checkinput(&data);
		        	pushLStack(s,data);
		        	system("pause") ;
				}
				break;
			}
        	case 8 :
			{
        		popLStack(s,&data);
        		system("pause");
				break;
			}
			case 9 :clearLStack(s);break;
			case 0 :break;
			default :printf("\n�������,����������!!\n");getch();
	    }
	} 
}
