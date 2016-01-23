/*************************************************************************
	> File Name: PA.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年01月23日 (週六) 10時04分24秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int status = 0;
    int ans = 0;
    while(n--)
    {
        int tmp;
        scanf("%d", &tmp);
        status += tmp;
        if(status < 0)
        {
            ans++;
            status = 0;
        }
    }
    cout << ans;
    return 0;
}

