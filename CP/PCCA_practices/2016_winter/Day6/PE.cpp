/*************************************************************************
	> File Name: PE.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年01月27日 (週三) 14時23分48秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int N;
        cin >> N;
        int a[11];
        int l[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        for(int i = 0; i < N; ++i)
            cin >> a[i];
        long long int max = 0;
        do {
            long long int happy = 0;
            long long int sum = 0;
            for(int i = 0; i < N; ++i)
            {
                sum = happy + a[l[i]] - 1;
                happy += sum % a[l[i]];
            }
            if(happy > max)
                max = happy;
        }while(next_permutation(l, l+N));
        cout << max << endl;
    }
    return 0;
}

