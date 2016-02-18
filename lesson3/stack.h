#include <stdio.h>
#include <stdlib.h>
#ifndef _STACK_H 

struct Node;
typedef int ElementType ;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

int IsEmpty(Stack S);
Stack CreateStack(void);
void DeposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);

#endif

struct Node{
	ElementType Element;
	PtrToNode Next;
};

int IsEmpty(Stack S){
	return S ->Next == NULL;
}
Stack CreateStack(void){
	Stack p = (Stack)malloc(sizeof(struct Node));
	if(NULL == p) {
		printf("Out Of Space!!");
		return ;
	}
	p->Next = NULL;
	MakeEmpty(p);
	return p;
}
void DeposeStack(Stack S) {
	PtrToNode p = S, temp;
	if(NULL != p) {
		temp = p->Next;
		free(p);
		p = temp;
	};
}
void MakeEmpty(Stack S){
	if(NULL == S) {
		printf("Must use CreateStack first!");
		return;
	} else {
		while(!IsEmpty(S)){
			Pop(S);
		}
	}
}
void Push(ElementType X, Stack S) {

}
ElementType Top(Stack S);
void Pop(Stack S);