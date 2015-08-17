#include "list.h"
Position RadixSort(ElementType A[]){
	int i ;
	Position header = (Position)malloc(sizeof Node), tail, node;
	tail = header;
	for(i = 0; i < 5; i ++) {
		node = (Position)malloc(sizeof Node);
		node -> Element = i;
		tail -> Next = node;
		tail = node;
	}

}