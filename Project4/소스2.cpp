#include "ArrayStack.h"

//���� ����
void AS_CreateStack(ArrayStack** Stack, int Capacity)
{
	//������ ���� ����ҿ� ����
	(*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));

	//�Էµ� Capacity��ŭ�� ��带 ���� ����ҿ� ����
	(*Stack)->Nodes = (Node*)malloc(sizeof(Node));

	//Capacity �� Top �ʱ�ȭ
	(*Stack)->Capacity = Capacity;
	(*Stack)->Top = -1;
}

//��� �Ҹ�
void AS_DestroyStack(ArrayStack* Stack)
{
	//��带 ���� ����ҿ��� ����
	free(Stack->Nodes);

	//������ ���� ����ҿ��� ����
	free(Stack);
}

//��� ����
void AS_Push(ArrayStack* Stack, ElementType Data)
{
	Stack->Top++;
	Stack->Nodes[Stack->Top].Data = Data;
}

//��� ����
ElementType AS_Pop(ArrayStack* Stack)
{
	int Position = Stack->Top--;
	return Stack->Nodes[Position].Data;
}

//�ֻ��� ��� ��ȯ
ElementType AS_Top(ArrayStack* Stack)
{
	return Stack->Nodes[Stack->Top].Data;
}

//���� ������
int AS_GetSize(ArrayStack* Stack)
{
	return Stack->Top + 1;
}

//����ִ��� Ȯ��
int AS_IsEmpty(ArrayStack* Stack)
{
	return (Stack)->Top == -1;
}

int AS_IsFull(ArrayStack* Stack)
{
	return Stack->Top == (Stack->Capacity) - 1;
}