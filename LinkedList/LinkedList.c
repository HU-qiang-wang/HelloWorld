#include"LinkedList.h"

int main(void)
{
	struct Node* L = NULL;
	L = create();
	insert_tail(L, 10);
	insert_tail(L, 20);
	show(L);

	return 0;
}

