/************************************************************************/
/* 链表                                                                     */
/************************************************************************/
#ifndef _LIST_H
struct Node;
typedef int ElementType ;
typedef struct Node *PtrToNode;
typedef PtrToNode List; // List 为一个指向Node类型的指针
typedef PtrToNode Position;
List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(ElementType X, List L);
void Delete(ElementType X, List L);
Position FindPrevious(ElementType X, List L);
void Insert(ElementType X, List L, Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(List L);
ElementType Retrieve(Position P);

#endif /* _LIST_H */
struct Node{
	ElementType Element;
	Position Next;
}Node;
List MakeEmpty(List L) {
	L->Next = NULL;
	return L;
}
int IsEmpty(List L) {
	if(NULL != L->Next)
		return 0;
	return 1;
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
	return NULL;
}
Position First(List L){
	if(L && L -> Next)
		return L -> Next;
	return NULL;
}
Position Advance(List L){
	return 0;
}
ElementType Retrieve(Position P){
	return 0;
}