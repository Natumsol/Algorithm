#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(){
	int i ;
	Position header = (Position)malloc(sizeof Node), tail, node;
	tail = header;
	for(i = 0; i < 5; i ++) {
		node = (Position)malloc(sizeof Node);
		node -> Element = i;
		tail -> Next = node;
		tail = node;
	}
	tail -> Next = NULL;

	Insert(100, header, header);
	DeleteList(header);
	return 0;
}

