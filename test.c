#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node * next;
};

struct node * ListCreate(){
	struct node * p;
	p = NULL;
	p = (struct node *)malloc(sizeof(struct node)*1);
	if (p == NULL)
		printf("malloc faild\n");
	else printf("malloc success\n");
	p->next=NULL;
	return p;
}

void list_show(struct node * L)
{
	if((L == NULL) || (L->next == NULL))
	{
		printf("The list L is empty\n");
		return ;
		}
	struct node * q = L;
	while(q->next)
	{
		printf("%d\n",q->next->data);
		q = q->next;
	}
	return ;
}


int ListInsert(struct node* L, int data)
{
	struct node * P_temp = NULL;
	struct node * q = NULL;
	if(L == NULL) 
	{
		printf("The list is NULL\n");
		return -1;
		}
	P_temp = (struct node *)malloc(sizeof(struct node)*1);
	if(P_temp == NULL)
	{
		printf("get memmey failed\n ");
		return -1;
		}
	P_temp->data = data;
	P_temp->next = NULL;
	q = L;
	while(q->next)
	{
		q = q->next;
	}
	q->next = P_temp;
	return 0;
}

int ListDelete(struct node * L, int data)
{
	struct node * q = L;
	struct node * temp = NULL;
	if((L == NULL)||(L->next == NULL))
	{
		printf("The list L is empty\n");
		return -1;
		}
	while(q->next)
	{
		if(q->next->data == data)
				break;
		else q = q->next;
	}
	temp = q->next;
	q->next = q->next->next;
	free(temp);
 	return 0;
}

int ListChange(struct node *L, int locate, int data)
{
	struct node * q = L;
	int temp = locate;
	if((L == NULL) || (L->next == NULL))
	{
		printf("The list L is empty\n");
		return -1;
	}
	while((locate > 0)&&(q != NULL))
	{
		q = q->next;
		locate--;
	}
	q->data = data;
	return 0;
}

void ListDestroy(struct node**L)
{
	struct node * q = NULL;
	q = *L;
	while((*L)->next)
	{
		q = (*L)->next;
		free((*L));
		*L = q;
	}
	free(*L);
	*L = NULL;
	return ;
}

int ListSearch(struct node *L, int data, struct node **q)
{	
	struct node * temp = NULL;
	int FOUNDFLAG = 0;
	if(L == NULL || L->next == NULL)
	{
		printf("The list L is empty\n");
		return -1;
	}
	temp = L;
	while(temp != NULL)
	{
		if(temp->data == data)
		{	
			FOUNDFLAG = 1;
			*q = temp;
			break;
		}
		temp = temp->next;
	}
	return FOUNDFLAG;
}

int ListSort(struct node *L)
{
	int temp ;
	struct node *q1 = NULL;//point the little value
	struct node *q2 = NULL;//bian ni lian biao
	struct node *q3 = NULL;
	q1 = L->next;
	q2 = L->next;
	q3 = L->next;
	while(q3)
	{	while(q2)
		{
			if(q2->data > q1->data)
				q1 = q2;
			q2 = q2->next;
		}
		temp = q3->data;
		q3->data = q1->data;
		q1->data = temp;
		q3 = q3->next;
		q2 = q3;
		q1 = q3;
	}
	return 1;
}

int main(void)
{
	struct node * q;
	struct node * Point = NULL;
	int flag = 0;
	q = NULL;
	q = ListCreate();
	ListInsert(q,20);
	ListInsert(q,30);
	ListInsert(q,40);
	list_show(q);
	ListSort(q);
	list_show(q);
	return 0;
}
