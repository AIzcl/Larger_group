#include "LQueue.h"
#include "LQueue.c"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

int main()
{
	
	LQueue* Q = (LQueue* )malloc(sizeof(LQueue));
	void *data;
	get_type();
	if(type == 'i')
	{
		data = (void*)malloc(sizeof(int));
	}else if(type == 'f')
	{
		data = (void*)malloc(sizeof(float));
	}else if(type == 'c')
	{
		data = (void*)malloc(sizeof(char));
	}
	void *add_data;
	int command;  
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
				Q = (LQueue* )malloc(sizeof(LQueue));
				InitLQueue(Q);
				break;
			} 
        	case 3 :
			{
				if(flag == 1)
				{
					printf("\n��δ���г�ʼ������!!\n");
					system("pause");
				}else if(IsEmptyLQueue(Q) == TRUE)
				{
					printf("\n����Ϊ��!!\n");
					system("pause");
				}else if(IsEmptyLQueue(Q) == FALSE)
				{
					printf("\n���в�Ϊ��!!\n");
					system("pause");
				}
				break;
			}
        	case 4 :
			{
				if(flag == 1)
				{
					printf("\n��δ���г�ʼ������!!\n");
		            system("pause");
				}else if (GetHeadLQueue(Q,data) ==TRUE)
        		{
        			printf("\n��ͷԪ��Ϊ:\n");
        			LPrint(data);
        			system("pause");
				}else 
				{
					printf("\n��ȡ��ͷԪ��ʧ��!!\n");
					system("pause");
				}
				break;
			}
        	case 5 :DestoryLQueue(Q);break;
        	case 6 : 
			{
				if(flag == 1)
				{
					printf("\n��δ���г�ʼ������!!\n");
		            system("pause");
		            break;
				}else 
				{
					LengthLQueue(Q); 
				}
				break;
			}
        	case 7 :
			{
				ClearLQueue(Q);
				
				system("pause");
				break;
			} 
        	case 8 : 
			{
				if(flag == 1)
				{
				printf("\n��δ���г�ʼ������!!\n");
				system("pause");
				break;
				}
				if(type == 'i')
				{
					get_int(&add_data);
				}
				else if(type == 'f')
				{
					get_float(&add_data);
				}
				else
				{
					get_char(&add_data); 
				}
				EnLQueue(Q, add_data);
				break;
			}
        	case 9 :
			{
				DeLQueue(Q);
				system("pause");
				break;
			}
			case 10 :
			{
				if(flag == 1)
				{
					printf("\n��δ���г�ʼ������!!\n");
					system("pause");
					break;
				}else if(IsEmptyLQueue(Q) == FALSE)
				{
					TraverseLQueue(Q, LPrint);
				}else
				{
					printf("\n����һ���ն���,���ܽ��б���!!\n");
					system("pause");
				}
				break;
			} 
        	case 0 :break;
        	default  :printf("����������ݷǷ�!������������!!(���������������)\n");getch();
		}
	}

}
