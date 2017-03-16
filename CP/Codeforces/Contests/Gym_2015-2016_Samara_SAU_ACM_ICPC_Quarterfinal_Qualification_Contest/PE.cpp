/*************************************************************************
	> File Name: PE.cpp
	> Author: Gavin Lee`
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年01月26日 (週二) 13時13分05秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
struct P
{	int id;
	int c;
	int r;
};
P h[100000+1];
int H[100000+1];
bool cmp(P a,P b)
{
	if(a.c==b.c)
		return a.r<b.r;
	return a.c<b.c;
}
int main()
{
int n;
scanf("%d",&n);
int i;
for(i=1;i<=n;i++)
{
int a,b;
scanf("%d %d",&a,&b);
H[i]=b;
h[i]=(P){i,a,b};
}
int last_c=h[n].c;
sort(&h[1],&h[1+n],cmp);
int h_c=1,h_r=1;
int now_id=1;
int num=0;
vector<int> ans;
int max_val=0;
int max_id=0;
for(i=1;i<=n;i++)
{
	if(h[i].c<=h_r)
	{
		if(max_val<h[i].r)
		{
		max_val=h[i].r;
		max_id=i;
		}
	}else
	{
	if(max_val<=h_r)break;
		ans.push_back(h[max_id].id);

		h_r=max_val;
		i--;
		max_val=0;
		max_id=0;
	}
}
ans.push_back(n);
if(H[ans[ans.size()-2]]<last_c)
{
	printf("No such luck\n");
	return 0;
}
printf("%d\n",ans.size());
for(i=0;i<ans.size();i++)
{
	if(i) printf(" %d",ans[i]);
	else printf("%d",ans[i]);
}
return 0;
}

