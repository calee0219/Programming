/*************************************************************************
	> File Name: PJ.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年01月26日 (週二) 10時28分04秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	int i;
	int a[200000+1]={};
	for(i=1;i<=n;i++)
	{scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	int num=1;
	int sum=0;
	int value=a[n];
	int ans=0;
	int now=n;
	for(i=n-1;i>=1;i--)
	{
		if(a[i]==a[i+1]) num++;
		else
		{
			if(now-1>=value)
			{
				ans=now;
				break;
			}else
			{
				now-=num;
				value=a[i];
				num=1;
			}
		}
	}
	if(now-1>=value)
		ans=now;
	printf("%d\n",ans);
}

