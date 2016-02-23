/*************************************************************************
	> File Name: PB_1.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年01月26日 (週二) 12時29分53秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
struct P
{
	int value,id;

};

P y[5010];
bool cmp(P a,P b)
{
	return a.value>b.value;
}
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int i,j;
	for(i=1;i<=m;i++) y[i].id=i;
	for(i=1;i<=n;i++)
	{
	for(j=1;j<=m;j++)
	{
		int a;
		scanf("%1d",&a);
		y[j].value+=a;
	}

	}
	sort(&y[1],&y[1+m],cmp);
	for(i=1;i<=m;i++) printf("%d\n",y[i].value);
	int ans[5010]={};
	int num=0;
	for(i=1;i<=m;i++)
	{
		int id=y[i].id;
		if(y[i].value>n/2 && num<15)
		{
			ans[id]=1;
			num++;
		}else if(num<8)
		{
			ans[id]=1;
			num++;
		}else
		{
		ans[id]=0;
		}

	}
	for(i=1;i<=m;i++)
	printf("%d",ans[i]);
}

