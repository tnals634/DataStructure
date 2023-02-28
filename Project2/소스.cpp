#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
	ElementType Data;
	struct tagNode* PrevNode; // Data ���� ����Ŵ
	struct tagNode* NextNode; // Data �ĸ� ����Ŵ
}Node;

//��� ����
Node* DLL_CreateNode(ElementType NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = NewData;
	NewNode->PrevNode = NULL;
	NewNode->NextNode = NULL;

	return NewNode;
}

//��� �Ҹ�
void DLL_DestroyNode(Node* Node)
{
	free(Node);
}

//��� �߰�
void DLL_AppendNode(Node** Head, Node* NewNode)
{
	//��� ��尡 NULL�̶�� ���ο� ��尡 Head�� �ȴ�.
	if ((*Head) == NULL)
	{
		*Head = NewNode;
	}
	else
	{
		//������ ã�� NewNode�� �����Ѵ�.
		Node* Tail = (*Head);
		while (Tail->NextNode != NULL)
		{
			Tail = Tail->NextNode;
		}

		Tail->NextNode = NewNode;
		NewNode->PrevNode = Tail; //���� ������ ���ο� ������ PrevNode�� ����Ŵ
	}
}

//��� Ž�� ����
Node* DLL_GetNodeAt(Node* Head, int Location)
{
	Node* Current = Head;

	while (Current != NULL && (--Location) >= 0)
	{
		Current = Current->NextNode;
	}
	
	return Current;
}

//��� ���� ����
void DLL_RemoveNode(Node** Head, Node* Remove)
{
	if (*Head == Remove)
	{
		*Head = Remove->NextNode;
		if ((*Head) != NULL)
		{
			(*Head)->PrevNode = NULL;
		}

		Remove->PrevNode = NULL;
		Remove->NextNode = NULL;
	}
	else
	{
		Node* Temp = Remove;

		if (Remove->PrevNode != NULL)
		{
			Remove->PrevNode->NextNode = Temp->NextNode;
		}

		if (Remove->NextNode != NULL)
		{
			Remove->NextNode->PrevNode = Temp->PrevNode;
		}

		Remove->PrevNode = NULL;
		Remove->NextNode = NULL;
	}
}

//��� ����
void DLL_InsertAfter(Node* Current, Node* NewNode)
{
	NewNode->NextNode = Current->NextNode;
	NewNode->PrevNode = Current;

	if (Current->NextNode != NULL)
	{
		Current->NextNode->PrevNode = NewNode;
		Current->NextNode = NewNode;
	}
}

//��� ���� ����
int DLL_GetNodeCount(Node* Head)
{
	unsigned int Count = 0;
	Node* Current = Head;

	while (Current != NULL)
	{
		Current = Current->NextNode;
		Count++;
	}

	return Count;
}

int main()
{
	Node* List = NULL;

	DLL_AppendNode(&List, DLL_CreateNode(117));
	DLL_AppendNode(&List, DLL_CreateNode(199));
	return 0;
}