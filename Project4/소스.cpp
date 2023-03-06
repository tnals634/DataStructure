#include <stdio.h>
#include <stdlib.h>

//배열 기반 스택과 스택의 노드 표현
typedef int ElementType;

typedef struct tagNode
{
	ElementType Data;
}Node;

typedef struct tagArrayStack
{
	int Capacity;
	int Top;
	Node* Nodes;
}ArrayStack;

//스택 및 노드 생성/소멸 연산

void AS_CreateStack(ArrayStack** Stack, int Capacity)
{
	//스택을 자유 저장소에 생성
	(*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));

	//입력된 Capacity만큼의 노드를 자유 저장소에 생성
	(*Stack)->Nodes = (Node*)malloc(sizeof(Node) * Capacity);

	//Capacity 및 top 초기화
	(*Stack)->Capacity = Capacity;
	(*Stack)->Top = -1;
}

//노드와 스택을 삭제
void AS_DestroyStack(ArrayStack* Stack)
{
	//노드를 자유 저장소에서 해제
	free(Stack->Nodes);

	//스택을 자유 저장소에서 해제
	free(Stack);
}

//노드 삽입 연산
void AS_Push(ArrayStack* Stack, ElementType Data)
{
	Stack->Top++;
	Stack->Nodes[Stack->Top].Data = Data;
}

//노드 제거 연산
ElementType AS_Pop(ArrayStack* Stack)
{
	int Position = Stack->Top--;
	return Stack->Nodes[Position].Data;
}