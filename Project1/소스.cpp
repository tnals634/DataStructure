#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

struct Node
{
	ElementType Data;
	struct Node* NextNode;
};

Node* SLL_CreateNode(ElementType NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = NewData; // 데이터 저장
	NewNode->NextNode = NULL; //다음 노드에 대한 포인터는 NULL로 초기화

	return NewNode; //노드의 주소를 반환
}

void SLL_DestroyNode(Node* Node)
{
	free(Node);
}

void SLL_AppendNode(Node** Head, Node* NewNode)
{
	//헤드 노드가 NULL이라면 새로운 노드가 Head가 된다.
	if ((*Head) == NULL)
	{
		*Head = NewNode;
	}
	else
	{
		//테일을 찾아 NewNode를 연결
		Node* Tail = (*Head);
		while (Tail->NextNode != NULL)
		{
			Tail = Tail->NextNode;
		}

		Tail->NextNode = NewNode;
	}
}

Node* SLL_GetNodeAt(Node* Head, int Location)
{
	Node* Current = Head;

	while (Current != NULL && (--Location) >= 0)
	{
		Current = Current->NextNode;
	}

	return Current;
}

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
		{
			Current->NextNode = Remove->NextNode;
		}
	}
}

void SLL_InsertAfter(Node* Current, Node* NewNode)
{
	NewNode->NextNode = Current->NextNode;
	Current->NextNode = NewNode;
}

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

void main()
{
	Node* List = NULL;
	Node* NewNode = NULL;
	Node* MyNode = NULL;
	NewNode = SLL_CreateNode(117); //자유 저장소에 노드 생성
	SLL_AppendNode(&List, NewNode); // 생성한 노드를 List에 추가
	NewNode = SLL_CreateNode(119); // 자유 저장소에 또 다른 노드 생성
	SLL_AppendNode(&List, NewNode); // 생성한 노드를 List에 추가

	SLL_AppendNode(&List, SLL_CreateNode(117)); // 노드를 생성하여 List에 추가
	SLL_AppendNode(&List, SLL_CreateNode(119)); // 노드를 생성하여 List에 추가
	SLL_AppendNode(&List, SLL_CreateNode(212)); // 노드를 생성하여 List에 추가

	MyNode = SLL_GetNodeAt(List, 1); // 두번째 노드의 주소를 MyNode에 저장
	printf("%d\n", MyNode->Data);

	SLL_RemoveNode(&List, MyNode); // 두번째 노드 제거

	SLL_DestroyNode(MyNode); //링크드 리스트에서 제거한 노드를 메모리에서 완전히 소멸시킴.
}