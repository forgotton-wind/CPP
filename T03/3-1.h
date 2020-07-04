#ifndef A
#define A

typedef struct _node {
	int data;
	struct _node* next;
}Node, * Linklist;

typedef struct _list {
	Node* head;
	Node* tail;
}List;

void func1(int, int);
void func2(int, int);

#endif
