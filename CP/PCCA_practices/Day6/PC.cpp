/*************************************************************************
	> File Name: PC.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年01月27日 (週三) 10時36分52秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

vector<int> v[4];

bool cmp(int v1, int v2)
{
    return v1 > v2;
}

int main()
{
    int N;
    cin >> N;
    for(int i = 0; i < N; ++i)
    {
        int tmp;
        scanf("%d", &tmp);
        v[1].push_back(tmp);
    }
    sort(v[1].begin(), v[1].end(), cmp);
    int m;
    cin >> m;
    while(m--)
    {
        char move;
        cin >> move;
        if(move == 'm')
        {
            int m1, m2;
            scanf("%d%d", &m1, &m2);
            if(v[m1].empty())
                printf("But %d is empty!\n", m1);
            else if(!v[m2].empty() && v[m1].back() > v[m2].back())
                printf("Illegal Move\n");
            else
            {
                v[m2].push_back(v[m1].back());
                v[m1].pop_back();
            }
            
        }
        else
        {
            int ask;
            scanf("%d", &ask);
            if(v[ask].empty())
                printf("But %d is empty!\n", ask);
            else
                printf("%d\n", v[ask].back());
        }
    }
    return 0;
}

