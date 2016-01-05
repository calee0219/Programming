#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int graph[101];
int save[100];
int check[101];

int list(int num, int lenth);

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	while(n)
	{
		memset(graph, 0, 101*sizeof(long long int));
		memset(check, 0, 101*sizeof(int));
		for(size_t i = 0; i < m; ++i)
		{
			int p, c;
			scanf("%d%d", &p, &c);
			graph[p] += 1 << c;
		}
		list(n, 0);
//		printf("\n");
		scanf("%d%d", &n, &m);
	}
	return 0;
}

int list(int num, int lenth)
{
	if(lenth == num)
	{
		for(size_t i = 0; i < num; ++i)
			printf("%d ", save[i]);
		printf("\n");
		return 1;
	}
	for(size_t i = 1; i <= num; ++i)
	{
		int che = 0;
		for(size_t j = 1; j <= num; ++j)
		{
			if(graph[j] >> i & 1)
			{
				che = 1;
				break;
			}
		}
		if(che) continue;
		if(check[i] == 0)
		{
			check[i] = 1;
			save[lenth] = i;
			long long int tmp = graph[i];
			graph[i] = 0;
//			list(num, lenth+1);
			if(list(num, lenth+1))
				return 1;
			graph[i] = tmp;
			check[i] = 0;
		}
	}
	return 0;
}

