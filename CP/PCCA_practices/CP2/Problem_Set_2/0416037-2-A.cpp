/*************************************************************************
	> File Name: PA.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年02月24日 (週日 ) 10時57分39秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int n;
bool first = true;
void train(void);

int main()
{
    bool inside = true;
    scanf("%d", &n);
    while(n)
    {
        if(inside) inside = false;
        else cout << endl;
        train();
        scanf("%d", &n);
    }
    return 0;
}

void train(void)
{
    while(true)
    {
        vector<int> v;
        int c;
        int ord = 1;
        for(int i = 1; i <= n; ++i)
        {
            scanf("%d", &c);
            if(c == 0) return;
            if(!v.empty() && v.back() == c)
            {
                v.pop_back();
                continue;
            }
            while(ord <= n)
            {
                v.push_back(ord);
                ord++;
                if(!v.empty() && v.back() == c)
                {
                    v.pop_back();
                    break;
                }
            }
        }
        if(first) first = false;
        else cout << endl;
        if(v.empty())
            cout << "Yes";
        else
            cout << "No";
    }
}
