/***************************************************************************************
 *	File Name				:	linkedList.h
 *	CopyRight				:	2020 QG Studio
 *	SYSTEM					:   win10
 *	Create Data				:	2020.3.28
 *
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *
 *
 ***************************************************************************************/

 /**************************************************************
*	Multi-Include-Prevent Section
**************************************************************/
#ifndef JUDGELINKEDLIST_H_INCLUDE
#define JUDGELINKEDLIST_H_INCLUDE


/**************************************************************
*	Macro Define Section
**************************************************************/
#define LEN sizeof(struct Node)

/**************************************************************
*	Struct Define Section
**************************************************************/

// define element type

typedef struct Node {
	long data;      //数据 
	struct Node *next;   //指向下一个节点的指针（存储下一个节点的地址） 
}Node;

/**************************************************************
*	Prototype Declare Section
**************************************************************/

/**
 *  @name        :void menu1();
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
void menu1();

/**
 *  @name        : Node *creat();
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
Node *creat();

/**
 *  @name        : Node *creat();
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
 void judge(Node *head);

 /**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif
