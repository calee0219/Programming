/*************************************************************************
	> File Name: PC.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年02月25日 (週四) 00時57分27秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int a[10000+1];

int main()
{
	int n;
	set<int> s;
	while(~scanf("%d", &n) && n)
	{
		if(n > 0)
		{
			s.insert(n);
			a[n]++;
		}
        else if(s.empty())
            continue;
		else if(n == -2)
		{
			cout << *s.rbegin() << ' ';
			a[*s.rbegin()]--;
			if(a[*s.rbegin()] == 0)
				s.erase(*s.rbegin());
		}
		else
		{
			cout << *s.begin() << ' ';
			a[*s.begin()]--;
			if(a[*s.begin()] == 0)
				s.erase(*s.begin());
		}
	}
	return 0;
}
