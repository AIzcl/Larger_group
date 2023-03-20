/***************************************************************************************
 *	File Name				:	duLinkedList.h
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

#ifndef DULINKEDLIST_H_INCLUDED
#define DULINKEDLIST_H_INCLUDED

/**************************************************************
*	Macro Define Section
**************************************************************/

#define LEN sizeof(struct Node)

/**************************************************************
*	Struct Define Section
**************************************************************/

// define element type
//双链节节点结构 
typedef struct Node{
	Node *pre;     
	long data;
	Node *next;
}Node;


/**************************************************************
*	Prototype Declare Section
**************************************************************/

/**
 *  @name        : void menu1(); 
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
void menu1(); 

/**
 *  @name        : Node *creat(); 
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
Node *creat(); 

/**
 *  @name        : void print(Node *head); 
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
void print(Node *head); 

/**
 *  @name        : Node *destroy(Node *head);
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Node *destroy(Node *head);

/**
 *  @name        : void find(Node *head); 
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
void find(Node *head); 

/**
 *  @name        : Node *del(Node *head);
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
Node *del(Node *head);

/**
 *  @name        :  Node *insert(Node *head);
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
 Node *insert(Node *head); 
 
 /**
 *  @name        : void modify(Node *head);
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
 void modify(Node *head);

 /**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif
