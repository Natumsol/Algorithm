#ifndef _TREE_H

typedef int ElementType;

struct TreeNode;
typedef struct TreeNode *Position;
typedef Position SearchTree;
SearchTree MakeEmpty(SearchTree T);
Position Find(ElementType X, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(ElementType X, SearchTree T);
SearchTree Delete(ElementType X, SearchTree T);
ElementType Retrieve(Position P);

#endif /* _TREE_H */

struct TreeNode{
	ElementType Element;
	SearchTree Left;
	SearchTree Right;
} TreeNode;

SearchTree MakeEmpty(SearchTree T) {
	if(NULL != T) {
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}

Position Find(ElementType X, SearchTree T){
	if(NULL == T)
		return NULL;
	if(X > T->Element)
		return Find(X, T->Right);
	if(X < T->Element)
		return Find(X, T->Left);
	return T;
}
Position FindMin(SearchTree T){
	if(NULL == T)
		return NULL;


}
Position FindMax(SearchTree T);
SearchTree Insert(ElementType X, SearchTree T);
SearchTree Delete(ElementType X, SearchTree T);
ElementType Retrieve(Position P);




