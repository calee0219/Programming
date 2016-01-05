#include <stdio.h>

void bubble_sort( int* front, int* end );
void bubble_increase( int* front, int* end );
void bubble_decrease( int* front, int* end );
void quick_sort( int* front, int* end );
void quick_increase( int* front, int* end );
void quick_decrease( int* front, int* end );
void merge_sort( int* front, int* end );
void merge_increase( int* front, int* end );
void merge_decrease( int* front, int* end );
void swap( int* a, int* b );

int main(int argc, char const *argv[])
{
	printf ( "Given N number: " );
	int N;
	scanf ( "%d", &N );
	int num[1000];
	printf ( "Input: " );
	int i;
	for (i = 0; i < N; ++i)
		scanf ( "%d", num+i );
	printf ( "0: bubble, 1: quick, 2: merge : " );
	int way;
	scanf ( "%d", &way );
	switch ( way ) {
	case 0:
		printf ( "Bubble sort\n" );
		bubble_sort( num, num+N-1 );
		break;
	case 1:
		printf ( "Quick sort\n" );
		quick_sort( num, num+N-1 );
		break;
	case 2:
		printf ( "Merge sort\n" );
		merge_sort( num, num+N-1 );
		break;
	}
	return 0;
}

void bubble_sort( int* front, int* end )
{
	int i;
	int size = end - front;
	bubble_increase( front, end );
	for (i = 0; i <= size; ++i)
		printf( "%d ", *(front+i) );
	printf( "\n" );
	bubble_decrease( front, end );
	for (i = 0; i <= size; ++i)
		printf( "%d ", *(front+i) );
	return;
}

void bubble_increase( int* front, int* end )
{
	if ( front >= end ) return;
	int size = end - front;
	int i;
	for (i = 0; i < size; ++i)
		if ( *(front+i) > *(front+i+1) )
			swap( front+i, front+i+1 );
	bubble_increase( front, end-1 );
	return;
}

void bubble_decrease( int* front, int* end )
{
	if ( front >= end ) return;
	int size = end - front;
	int i;
	for (i = 0; i < size; ++i)
		if ( *(front+i) < *(front+i+1) )
			swap( front+i, front+i+1 );
	bubble_decrease( front, end-1 );
	return;
}

void quick_sort( int* front, int* end )
{
	int i;
	int size = end - front;
	quick_increase( front, end );
	for (i = 0; i <= size; ++i)
		printf( "%d ", *(front+i) );
	printf( "\n" );
	quick_decrease( front, end );
	for (i = 0; i <= size; ++i)
		printf( "%d ", *(front+i) );
	return;
}

void quick_increase( int* front, int* end )
{
	if ( front >= end ) return;
	int* pivot = front;
	int* left = front + 1;
	int* right = end;
	while ( left < right )
	{
		while ( *right >= *pivot && right > left ) right--;
		while ( *left <= *pivot && left < right ) left++;
		if ( *left > *right )
		{
			swap( left, right );
			left++;
			right--;
		}
	}
	if ( *pivot > *right )
		swap( pivot, right );
	quick_increase( front, right-1 );
	quick_increase( left, end );
	return;
}

void quick_decrease( int* front, int* end )
{
	if ( front >= end ) return;
	int* pivot = front;
	int* left = front + 1;
	int* right = end;
	while ( left < right )
	{
		while ( *right <= *pivot && right > left ) right--;
		while ( *left >= *pivot && left < right ) left++;
		if ( *left < *right )
		{
			swap( left, right );
			left++;
			right--;
		}
	}
	if ( *pivot < *right )
		swap( pivot, right );
	quick_decrease( front, right-1 );
	quick_decrease( left, end );
	return;
}

void merge_sort( int* front, int* end )
{
	int i;
	int size = end - front;
	merge_increase( front, end );
	for (i = 0; i <= size; ++i)
		printf( "%d ", *(front+i) );
	printf( "\n" );
	merge_decrease( front, end );
	for (i = 0; i <= size; ++i)
		printf( "%d ", *(front+i) );
	return;
}

void merge_increase( int* front, int* end )
{
	if ( front >= end ) return;
	int size = end - front;
	int* mid = front + size / 2;
	merge_increase( front, mid );
	merge_increase( mid + 1, end );
	int* left = front;
	int* right = mid + 1;
	int tmp_sort[1000];
	int i;
	for (i = 0; i <= size; ++i)
	{
		if ( *left < *right && left <= mid || right > end )
		{
			tmp_sort[i] = *left;
			left++;
		}
		else
		{
			tmp_sort[i] = *right;
			right++;
		}
	}
	for (i = 0; i <= size; ++i)
		*(front + i) = tmp_sort[i];
	return;
}

void merge_decrease( int* front, int* end )
{
	if ( front >= end ) return;
	int size = end - front;
	int* mid = front + size / 2;
	merge_decrease( front, mid );
	merge_decrease( mid + 1, end );
	int* left = front;
	int* right = mid + 1;
	int tmp_sort[1000];
	int i;
	for (i = 0; i <= size; ++i)
	{
		if ( *left > *right && left <= mid || right > end )
		{
			tmp_sort[i] = *left;
			left++;
		}
		else
		{
			tmp_sort[i] = *right;
			right++;
		}
	}
	for (i = 0; i <= size; ++i)
		*(front + i) = tmp_sort[i];
	return;
}

void swap( int* a, int* b )
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
	return;
}