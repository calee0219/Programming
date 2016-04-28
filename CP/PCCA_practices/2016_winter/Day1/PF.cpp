/*************************************************************************
	> File Name: PF.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年02月17日 (週三) 16時11分20秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
            long long int n;
            cin >> n;
            if(n <= 1) {cout << "no" << endl; continue;}
            bool che = 1;
            for(int i = 2; i <= sqrt(n); ++i)
                if(n % i == 0) {che = 0; cout << "no" << endl; break;}
            if(che) cout << "yes" << endl;
        }
    return 0;
}
