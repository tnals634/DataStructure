#include "ArrayStack.h"

//스택 생성
void AS_CreateStack(ArrayStack** Stack, int Capacity)
{
	//스택을 자유 저장소에 생성
	(*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));

	//입력된 Capacity만큼의 노드를 자유 저장소에 생성
	(*Stack)->Nodes = (Node*)malloc(sizeof(Node));

	//Capacity 및 Top 초기화
	(*Stack)->Capacity = Capacity;
	(*Stack)->Top = -1;
}

//노드 소멸
void AS_DestroyStack(ArrayStack* Stack)
{
	//노드를 자유 저장소에서 해제
	free(Stack->Nodes);

	//스택을 자유 저장소에서 해제
	free(Stack);
}

//노드 삽입
void AS_Push(ArrayStack* Stack, ElementType Data)
{
	Stack->Top++;
	Stack->Nodes[Stack->Top].Data = Data;
}

//노드 제거
ElementType AS_Pop(ArrayStack* Stack)
{
	int Position = Stack->Top--;
	return Stack->Nodes[Position].Data;
}

//최상위 노드 반환
ElementType AS_Top(ArrayStack* Stack)
{
	return Stack->Nodes[Stack->Top].Data;
}

//스택 사이즈
int AS_GetSize(ArrayStack* Stack)
{
	return Stack->Top + 1;
}

//비어있는지 확인
int AS_IsEmpty(ArrayStack* Stack)
{
	return (Stack)->Top == -1;
}

int AS_IsFull(ArrayStack* Stack)
{
	return Stack->Top == (Stack->Capacity) - 1;
}