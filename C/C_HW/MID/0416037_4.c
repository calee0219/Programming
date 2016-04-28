#include <stdio.h>
#include <string.h>

char num[100000];

int main()
{
	scanf( "%s", num );
	int order = 0;
	int n_len = strlen( num );
	int i;
	for ( i = 0; i < n_len; i++ )
	{
		if ( num[i] != ',' )
		{
			num[order] = num[i];
			order++;
		}
	}
	n_len = n_len / 2 + 1;
	int max = num[n_len-1];
	for ( i = n_len-2; i >= 0; i-- )
	{
		if ( num[i] >= max )
			max = num[i];
		else
			break;
	}
	int pivot = i;
	int min = max;
	int p_min = i+1;
	for ( i; i < n_len; i++ )
	{
		if ( num[i] > num[pivot] && num[i] < min )
		{
			min = num[i];
			p_min = i;
		}
	}
	num[p_min] = num[pivot];
	num[pivot] = min;
	int j;
	for ( i = 0; i < n_len; i++ )
		for ( j = pivot+1; j < n_len-1; j++ )
			if ( num[j] > num[j+1] )
			{
				int tmp = num[j];
				num[j] = num[j+1];
				num[j+1] = tmp;
			}
	int che = 0;
	for ( i = 0; i < n_len; i++ )
	{
		if ( che )
			printf( "," );
		che = 1;
		printf( "%c", num[i] );
	}
	return 0;
}
