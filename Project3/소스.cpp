#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
	ElementType Data;
	struct tagNode* PrevNode;
	struct tagNode* NextNode;
}Node;

//노드 추가
void CDLL_AppendNode(Node** Head, Node* NewNode)
{
	//헤드 노드가 NULL이람녀 새로운 노드가 Head가 된다.
	if ((*Head) == NULL)
	{
		*Head = NewNode;
		(*Head)->NextNode = *Head;
		(*Head)->PrevNode = *Head;
	}
	else
	{
		//테일과 헤드 사이에 NewNode를 삽입
		Node* Tail = (*Head)->PrevNode;
		Tail->NextNode->PrevNode = NewNode;
		Tail->NextNode = NewNode;

		NewNode->NextNode = (*Head);
		NewNode->PrevNode = Tail; // 새로운 테일의 PrevNode가 기존의 테일을 가리킴
	}
}

//노드 제거
void CDLL_RemoveNode(Node** Head, Node* Remove)
{
	if (*Head == Remove)
	{
		(*Head)->PrevNode->NextNode = Remove->NextNode;
		(*Head)->NextNode->PrevNode = Remove->PrevNode;

		*Head = Remove->NextNode;

		Remove->PrevNode = NULL;
		Remove->NextNode = NULL;
	}
	else
	{
		Remove->PrevNode->NextNode = Remove->NextNode;
		Remove->NextNode->PrevNode = Remove->PrevNode;

		Remove->PrevNode = NULL;
		Remove->NextNode = NULL;
	}
}