#include "LinkStack.h"
#include "LinkStack.c"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>


int main()
{
	int i,command,remark;   //remark是用来接收函数返回值的 
	ElemType data,e,length,size; 
	LinkStack* s = (LinkStack*)malloc(sizeof(LinkStack*));
	s->top = NULL;  //判断链栈是否被初始化 
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
					    	printf("\n已经存在一个链栈，请销毁之前的链栈!!\n");
					    	system("pause");
					  }else
					  {
		                    initLStack(s);
		                    printf("\n请输入链栈的长度(当你按下回车键时，系统默认为0)：\n");
		                    checkinput(&size);
		                    for(i=0;i<size;i++)
		                    {
		                    	printf("\n请输入你的数据(当你按下回车键时，系统默认为0):\n");
		                    	checkinput(&data);
		                        pushLStack(s,data);
							}
							printf("\n链栈初始化成功!!\n");
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
        			printf("\n栈顶元素为%d\n",e);
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
        			printf("\n链栈的长度为%d\n",length);
				}
        		system("pause");
				break;
			}
        	case 7 :
			{
				if(!s->top)
				{
		        	printf("\n请先初始化\n");
		        	system("pause");
				}else 
				{
					printf("\n请输入你的数据(当你按下回车键时，系统默认为0):\n");
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
			default :printf("\n输入错误,请重新输入!!\n");getch();
	    }
	} 
}
