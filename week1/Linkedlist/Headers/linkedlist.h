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
#ifndef LINKEDLIST_H_INCLUDE
#define LINKEDLIST_H_INCLUDE


/**************************************************************
*	Macro Define Section
**************************************************************/
#define LEN sizeof(struct Node)
int x = 0;     //定义一个全局变量来代表结点的个数 

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
 *  @name        : Node *del(Node *head); 
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Node *del(Node *head); 

/**
 *  @name        : void print(Node *head);
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
void print(Node *head);

/**
 *  @name        : Node *destroy(Node *head);
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
Node *destroy(Node *head);

/**
 *  @name        : 
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
void find(Node *head); 

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Node *insert(Node *head);

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
void modify(Node *head);

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
Node *odd_even_exchange(Node *head);

/**
 *  @name        : void find(Node *head); 
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
void find_middle(Node *head); 

/**
 *  @name        : Node *reversal(Node *head); 
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
 Node *reversal(Node *head); 
 
 /**
 *  @name        :Node *recursion(Node *head);
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
Node *recursion(Node *head);

 /**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif
