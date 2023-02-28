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

	NewNode->Data = NewData; // ������ ����
	NewNode->NextNode = NULL; //���� ��忡 ���� �����ʹ� NULL�� �ʱ�ȭ

	return NewNode; //����� �ּҸ� ��ȯ
}

void SLL_DestroyNode(Node* Node)
{
	free(Node);
}

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
	NewNode = SLL_CreateNode(117); //���� ����ҿ� ��� ����
	SLL_AppendNode(&List, NewNode); // ������ ��带 List�� �߰�
	NewNode = SLL_CreateNode(119); // ���� ����ҿ� �� �ٸ� ��� ����
	SLL_AppendNode(&List, NewNode); // ������ ��带 List�� �߰�

	SLL_AppendNode(&List, SLL_CreateNode(117)); // ��带 �����Ͽ� List�� �߰�
	SLL_AppendNode(&List, SLL_CreateNode(119)); // ��带 �����Ͽ� List�� �߰�
	SLL_AppendNode(&List, SLL_CreateNode(212)); // ��带 �����Ͽ� List�� �߰�

	MyNode = SLL_GetNodeAt(List, 1); // �ι�° ����� �ּҸ� MyNode�� ����
	printf("%d\n", MyNode->Data);

	SLL_RemoveNode(&List, MyNode); // �ι�° ��� ����

	SLL_DestroyNode(MyNode); //��ũ�� ����Ʈ���� ������ ��带 �޸𸮿��� ������ �Ҹ��Ŵ.
}