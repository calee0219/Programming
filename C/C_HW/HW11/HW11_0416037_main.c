/***HW11_0416037_main.c***/
#include "HW11_0416037_header.h"

int main()
{
	struct Node* head = NULL;
	printf("Input the number of data you want to insert: ");
	int N;
	scanf("%d", &N);
	printf("Data: ");
	int i;
	for(i = 0; i < N; ++i)
	{
		int t;
		scanf("%d", &t);
		//1.(1)
		head = insert(t, head);
	}
	//1.(2)
	printf("After insert: ");
	traverse(head);

	//2.(1)
	head = reverse(head);
	printf("After reveerse: ");
	//2.(2)
	traverse(head);
	//3
	printf("After removed: ");
	removed(head);
	traverse(head);
	return 0;
}

