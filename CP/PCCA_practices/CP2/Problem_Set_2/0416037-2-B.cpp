/*************************************************************************
	> File Name: PB.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年02月25日 (週四) 20時01分49秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(~scanf("%d", &n) && n)
    {
        vector<int> v, sum;
        int tmp;
        for(int i = 0; i < n; ++i)
        {
            scanf("%d", &tmp);
            v.push_back(tmp);
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < n; ++i)
        {
            if(!sum.empty())
                sum.push_back(v.at(i)+sum.back());
            else
                sum.push_back(v.at(i));
        }
        int num;
        bool check = true;
        for(num = n-1; num > 0; --num)
        {
            if(v.at(num) <= sum.at(num-1))
            {
                check = false;
                break;
            }
        }
        if(check)
            cout << 0 << endl;
        else
            cout << num+1 << endl;
    }
    return 0;
}
