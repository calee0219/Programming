/*************************************************************************
	> File Name: PF.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年01月27日 (週三) 11時28分44秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        long long int a;
        long long int max = 0;
        while(n--)
        {
            cin >> a;
            if(a > max)
                max = a;
        }
        cout << max << endl;
    }
    return 0;
}

