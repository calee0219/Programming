#include <bits/stdc++.h>
using namespace std;
struct str{
    int t, w;
};

bool cmp(str a, str b);

vector<str> v;
pair<int,int> p[1000+1];
int c;

int winum(void);

int main()
{
    int N;
    scanf("%d", &N);
    while(N--)
    {
        int w, k;
        scanf("%d%d", &w, &k);
        for(int i = 0; i < k; ++i)
        {
            int t;
            scanf("%d%d", &t, &c);
            for(int j = 0; j < c; ++j)
                scanf("%d%d", &p[i].first, &p[i].second);
            str tmp;
            tmp.w = winum();
            cout << tmp.w << " ";
            tmp.t = t;
            v.push_back(tmp);
        }
        sort(v.begin(), v.end(), cmp);
        int max = 0;
        int piece = 1;
        for(int i = 0; i < k; ++i)
        {
            for(int j = 0; j < v[i].t; ++j)
            {
                if(max <= w)
                    break;
                max += v[i].w;
                piece++;
            }
        }
        if(max <= w)
            printf("Je treba %d cleku.\n", piece);
        else
            printf("Kapacita zakladny je pouze %d lidi.\n", max);
    }
    return 0;
}

int winum(void)
{
    cout << c << ' ';
    int ans = c*6;
    cout << ans << ' ';
    for(int i = 0; i < c-1; ++i)
    {
        for(int j = i+1; j < c; ++j)
        {
            printf("%d %d %d %d", p[i].first, p[i].second, p[j].first, p[j].second);
            if(p[i].first==p[j].first&&p[i].second<=p[j].second+1&&p[i].second>=p[j].second-1)
                ans -= 2;
            else if(p[i].second==p[j].second&&p[i].first<=p[j].first+1&&p[i].first>=p[j].first-1)
                ans -= 2;
            else if(p[i].first==p[j].first-1&&p[i].second==p[j].second+1)
                ans -= 2;
            else if(p[i].first==p[j].first+1&&p[i].second==p[j].second-1)
                ans -= 2;
        }
    }
    cout << ans << endl;
    return ans;
}

bool cmp(str a, str b)
{
    return a.t > b.t;
}
