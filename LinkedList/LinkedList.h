#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

struct Node* create(void){
	struct Node* p = NULL;
	p = (struct Node*)malloc(sizeof(struct Node));
	if(p == NULL)
	{
		printf("failed to malloc\n");
		return p;
	}
	p->next = NULL;
	return p;
}

void insert_tail(struct Node* L, int data){
	struct Node* q = NULL;
	struct Node* p = L;
	if(L == NULL)
	{
		printf("the linked list is empty\n");
		return ;
	}
	q = (struct Node*)malloc(sizeof(struct Node));
	if(q == NULL)
	{
		printf("failed to malloc\n");
		return ;
	}
	q->data = data;
	q->next = NULL;
	while(p->next != NULL)
	{
		p = p->next;
	}
	p->next = q;
	return ;
}

void show(struct Node* L){
	struct Node* q = L;
	if(L == NULL)
	{
		printf("the linked list is empty\n");
		return ;
	}
	while(q->next)
	{
		printf("%d\n",q->next->data);
		q = q->next;
	}
	return ;
}


