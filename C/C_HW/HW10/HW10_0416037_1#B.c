#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int graph[101][101];
int save[100];
int check[101];

void list(int num, int lenth);

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	while(n)
	{
		memset(graph, 0, 101*sizeof(int));
		memset(check, 0, 101*sizeof(int));
		for(size_t i = 0; i < m; ++i)
		{
			int p, c;
			scanf("%d%d", &p, &c);
			graph[p][c] = 1;
		}
		list(n, 0);
		printf("\n");
		scanf("%d%d", &n, &m);
	}
	return 0;
}

void list(int num, int lenth)
{
	if(lenth == num)
	{
		printf("hi");
		size_t i;
		for(i = 0; i < num; ++i)
			printf("%d ", save[i]);
		printf("\n");
		return;
	}
	size_t i;
	for(i = 1; i <= num; ++i)
	{
		int che = 0;
		size_t j;
		for(j = 1; j <= num; ++j)
		{
			if(graph[j][i] == 1)
			{
				che = 1;
				break;
			}
		}
		if(che) continue;
		if(check[i] == 0)
		{
			printf("%d %d\t", i, lenth);
			check[i] = 1;
			save[lenth] = i;
			size_t j;
			for(j = 0; j < num; ++j)
				graph[i][j] = 0;
			list(num, lenth+1);
		}
	}
	return;
}

