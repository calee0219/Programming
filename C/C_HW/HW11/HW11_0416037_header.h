/***HW11_0416037_header.h***/
#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

struct Node* insert(int value, struct Node* head);
struct Node* reverse(struct Node* head);
struct Node* removed(struct Node* head);
struct Node* pop_next(struct Node* head);
// Traverse linked list and print them out
void traverse(struct Node* temp);

