#include "list.h"
#include <stdlib.h>
struct Node{
	ElementType Element;
	Position Next;
};
List MakeEmpty(List L) {
	L->Next = NULL;
	return L;
}
int IsEmpty(List L) {
	if(NULL != L->Next)
		return 1;
	return 0;
}
int IsLast(Position P, List L){
	return P -> Next == NULL;
}
Position Find(ElementType X, List L){
	Position CurrentPosition = L -> Next;
	while(CurrentPosition){
		if(CurrentPosition -> Element == X)
			return CurrentPosition;
		CurrentPosition = CurrentPosition -> Next;
	}
	return NULL;	
}
Position  FindPrevious(ElementType X, List L){
	Position CurrentPosition = L -> Next;
	Position PreviousPosition = L;
	while(CurrentPosition){
		if(CurrentPosition -> Element == X)
			return PreviousPosition;
		PreviousPosition = CurrentPosition;
		CurrentPosition = CurrentPosition -> Next;

	}
	return NULL;
}
void Delete(ElementType X, List L) {
	Position PreviousPosition = FindPrevious(X, L);
	if(PreviousPosition && IsLast(PreviousPosition, L)){
		free(PreviousPosition -> Next);
		PreviousPosition -> Next = PreviousPosition -> Next -> Next;
	}

}
void Insert(ElementType X, List L, Position P){
	Position Pos = (Position)malloc(sizeof Node);
	if(Pos){
		Pos -> Element = X;
		Pos -> Next = P -> Next -> Next;
		P -> Next = Pos;
	}
}
void DeleteList(List L){
	Position CurrentPosition = L, temp;
	while(CurrentPosition){
		temp = CurrentPosition -> Next;
		free(CurrentPosition);
		CurrentPosition = temp;
	}
	L -> Next = NULL;
}
Position Header(List L){
	if(L)
		return L;
}
Position First(List L){
	if(L && L -> Next)
		return L -> Next;
	return NULL;
}
Position Advance(List L){

}
ElementType Retrieve(Position P){

}