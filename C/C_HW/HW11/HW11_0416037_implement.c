/***HW11_0416037_implement.c***/
#include "HW11_0416037_header.h"

struct Node* insert(int value, struct Node* head) {
	if (head == NULL)
	{
		struct Node* temp = malloc(sizeof(struct Node));
		temp->data = value;
		head = temp;
		head->next = NULL;
	}
	else
	{
		if (head->next != NULL)
			insert(value, head->next);
		else
		{
			struct Node* temp = malloc(sizeof(struct Node));
			temp->data = value;
			temp->next = head->next;
			head->next = temp;
		}
	}
	return head;
}

struct Node* reverse(struct Node* head) {
	struct Node* temp = NULL;
	struct Node* point = head;
	while (head != NULL)
	{
		if (temp == NULL)
		{
			temp = head;
			head = head->next;
			temp->next = NULL;
		}
		else
		{
			point = head;
			head = head->next;
			point->next = temp;
			temp = point;
		}
	}
	return point;
}

struct Node* removed(struct Node* head)
{
	if(head == NULL) return head;
	struct Node* tmp = head;
	while(tmp->next != NULL)
	{
		struct Node* nxt = tmp->next;
		if(tmp->data == nxt->data)
			pop_next(tmp);
		else
			tmp = tmp->next;
	}
	return head;
}

struct Node* pop_next(struct Node* head) {
	if (head->next != NULL)
	{
		struct Node* temp = head->next;
		head->next = temp->next;
		free(temp);
	}
	return head;
}

void traverse(struct Node* temp) {
	if (temp != NULL)
	{
		printf("%d--> ", temp->data);
		traverse(temp->next);
	}
	else
		printf("NULL\n");
	return;
}

