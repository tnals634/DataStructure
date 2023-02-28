#include "LinkedList.h"

//��� ����
Node* SLL_CreateNode(ElementType NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = NewData; // �����͸� ����
	NewNode->NextNode = NULL; // ���� ��忡 ���� �����ʹ� NULL�� �ʱ�ȭ

	return NewNode; // ����� �ּҸ� ��ȯ
}

//��� �Ҹ�
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

//��� �߰�
void SLL_AppendNode(Node** Head, Node* NewNode)
{
	//��� ��尡 NULL�̶�� ���ο� ��尡 Head�� �ȴ�.
	if ((*Head) == NULL)
	{
		*Head = NewNode;
	}
	else
	{
		//������ ã�� NewNode�� ����
		Node* Tail = (*Head);
		while (Tail->NextNode != NULL)
		{
			Tail = Tail->NextNode;
		}

		Tail->NextNode = NewNode;
	}
}

//��� ����
void SLL_InsertAfter(Node* Current, Node* NewNode) // Ư�� ��� �ڿ� ���ο� ��� ����
{
	NewNode->NextNode = Current->NextNode;
	Current->NextNode = NewNode;
}

void SLL_InsertNewHead(Node** Head, Node* NewHead) // ��� �տ� ���ο� ��� ����
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

void SLL_InsertBefore(Node** Head, Node* Current, Node* NewNode) // Ư�� ��� �տ� ���ο� ��� ����
{
	NewNode->NextNode = Current;

	Node* BeforeNode = *Head;

	while (BeforeNode != NULL && BeforeNode->NextNode != Current)
	{
		BeforeNode = BeforeNode->NextNode;
	}

	BeforeNode->NextNode = NewNode;
}

//��� ����
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

//��� Ž��
Node* SLL_GetNodeAt(Node* Head, int Location)
{
	Node* Current = Head;

	while (Current != NULL && (--Location) >= 0)
	{
		Current = Current->NextNode;
	}

	return Current;
}

//��� ���� ����
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