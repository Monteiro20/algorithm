#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>

#define DATA(node) ((node)->pData)
#define LEFT(node) ((node)->pLeft)
#define RIGHT(node) ((node)->pRight)

#define EMPTY NULL
#define NO_LINK NULL

typedef enum _STATUS {ERROR=0,OK=1} STATUS;
typedef enum _BOOLEAN {FALSE=0,TRUE=1} BOOLEAN;

typedef struct _BTREE_NODE {
void *pData;
struct _BTREE_NODE *pLeft;
struct _BTREE_NODE *pRight;
} BTREE_NODE;

typedef BTREE_NODE *BTREE;

//declare functions
STATUS initBTree(BTREE*);
BOOLEAN emptyBTree(BTREE);
BOOLEAN isLeaf(BTREE_NODE*);
STATUS createNewBTNode(BTREE_NODE**, void*);
void printIntBST(BTREE);

STATUS insertIntBST(BTREE*, void*);
STATUS insertBT(BTREE*, void*, void*, void*);

//implementation of functions
STATUS initBTree(BTREE *pBT) //initialize the tree
{
	*pBT=NULL;
	return OK;
}

BOOLEAN emptyBTree(BTREE BT) //checks if the tree is empty
{
	if(BT == NULL)
		return TRUE;
	return FALSE;
	//return (BT==NULL)? TRUE : FALSE;  //another way to do
}

BOOLEAN isLeaf(BTREE_NODE *pNode) //checks whether a given node in the binary tree is a leaf
{
	if((LEFT(pNode)==NULL) && (RIGHT(pNode)==NULL))
		return TRUE;
	return FALSE;
	//return ((LEFT(pNode)==NULL) && (RIGHT(pNode)==NULL))? TRUE : FALSE;
}

void printIntBST(BTREE BT) //displays the elements of the binary tree on the screen
{
	if(emptyBTree(BT)==TRUE) 
		return;
	printIntBST(LEFT(BT));
	printf("%d, ",*(int *)DATA(BT));
	printIntBST(RIGHT(BT));
	return;
}

STATUS createNewBTNode(BTREE_NODE **pNew, void *pData)
{
	BTREE_NODE *pTemp;
	if((pTemp=(BTREE_NODE *)malloc(sizeof(BTREE_NODE)))==NULL)
		return ERROR;
	*pNew=pTemp;
	DATA(pTemp)=pData;
	LEFT(pTemp)=NULL;
	RIGHT(pTemp)=NULL;
	
	return OK;
}

STATUS insertIntBST(BTREE *pBT, void *pData)
{
	if(emptyBTree(*pBT))
	{
		BTREE_NODE *pNew;
		if(createNewBTNode(&pNew,pData)==ERROR)
			return ERROR;
		*pBT=pNew;
		return OK;
	}
	else if(*(int *)(pData) < *(int *)(DATA(*pBT)))
		insertIntBST(&(LEFT(*pBT)),pData);
	else 
		insertIntBST(&(RIGHT(*pBT)),pData);
	
	return OK;
}

int NumNos(BTREE BT)
{
	if(emptyBTree(BT))
		return 0;
	return 1+NumNos(LEFT(BT)) + NumNos(RIGHT(BT));
}

int NumFolhas(BTREE BT)
{
	if(emptyBTree(BT))
		return 0;
	if(isLeaf(BT))
		return 1;
	return NumFolhas(LEFT(BT)) + NumFolhas(RIGHT(BT));
}

main()
{
	BTREE Arvore;
	
	initBTree(&Arvore);
	
	int a=10;
	int b=5;
	int c=15;
	int d=2;
	int e=12;
	insertIntBST(&Arvore, &a);
	printIntBST(Arvore);
	printf("\n");
	insertIntBST(&Arvore, &b);
	printIntBST(Arvore);
	printf("\n");
	insertIntBST(&Arvore, &c);
	printIntBST(Arvore);
	printf("\n");
	insertIntBST(&Arvore, &d);
	printIntBST(Arvore);
	printf("\n");
	insertIntBST(&Arvore, &e);
	printIntBST(Arvore);
	printf("\n");
	
	printf("\nThe tree has %d NODES", NumNos(Arvore));
	
	printf("\nThe tree has %d LEAVES", NumFolhas(Arvore));
}



















