#include "LinkedList.h"

//노드 생성
Node* SLL_CreateNode(ElementType NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = NewData; // 데이터를 저장
	NewNode->NextNode = NULL; // 다음 노드에 대한 포인터는 NULL로 초기화

	return NewNode; // 노드의 주소를 반환
}

//노드 소멸
void SLL_DestroyNode(Node* Node)
{
	free(Node);
}

void SLL_DestroyAllNodes(Node** List)
{
	Node* Current = *List;
	Node* Delet = *List;
	while (Current != NULL)
	{
		Delet = Current;
		Current = Current->NextNode;
		free(Delet);
	}
}

//노드 추가
void SLL_AppendNode(Node** Head, Node* NewNode)
{
	//헤드 노드가 NULL이라면 새로운 노드가 Head가 된다.
	if ((*Head) == NULL)
	{
		*Head = NewNode;
	}
	else
	{
		//테일을 찾아 NewNode에 연결
		Node* Tail = (*Head);
		while (Tail->NextNode != NULL)
		{
			Tail = Tail->NextNode;
		}

		Tail->NextNode = NewNode;
	}
}

//노드 삽입
void SLL_InsertAfter(Node* Current, Node* NewNode) // 특정 노드 뒤에 새로운 노드 삽입
{
	NewNode->NextNode = Current->NextNode;
	Current->NextNode = NewNode;
}

void SLL_InsertNewHead(Node** Head, Node* NewHead) // 헤드 앞에 새로운 노드 삽입
{
	if (Head == NULL)
	{
		(*Head) = NewHead;
	}
	else
	{
		NewHead->NextNode = (*Head);
		(*Head) = NewHead;
	}
}

void SLL_InsertBefore(Node** Head, Node* Current, Node* NewNode) // 특정 노드 앞에 새로운 노드 삽입
{
	NewNode->NextNode = Current;

	Node* BeforeNode = *Head;

	while (BeforeNode != NULL && BeforeNode->NextNode != Current)
	{
		BeforeNode = BeforeNode->NextNode;
	}

	BeforeNode->NextNode = NewNode;
}

//노드 제거
void SLL_RemoveNode(Node** Head, Node* Remove)
{
	if (*Head == Remove)
	{
		*Head = Remove->NextNode;
	}
	else
	{
		Node* Current = *Head;
		while (Current != NULL && Current->NextNode != Remove)
		{
			Current = Current->NextNode;
		}

		if (Current != NULL)
			Current->NextNode = Remove->NextNode;
	}
}

//노드 탐색
Node* SLL_GetNodeAt(Node* Head, int Location)
{
	Node* Current = Head;

	while (Current != NULL && (--Location) >= 0)
	{
		Current = Current->NextNode;
	}

	return Current;
}

//노드 개수 세기
int SLL_GetNodeCount(Node* Head)
{
	int Count = 0;
	Node* Current = Head;

	while (Current != NULL)
	{
		Current = Current->NextNode;
		Count++;
	}

	return Count;
}