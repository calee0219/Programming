#include <bits/stdc++.h>
using namespace std;

vector<pair<int, long long int> > v;

int main()
{
    int n, d;
    cin >> n >> d;
    for(int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a,b));            // 資產, 友情
    }
    sort(v.begin(),v.end());
    long long int ans = 0;
    long long int tt = 0;                       // 區間內的友情總和
    int p1 = 0, p2 = 0;                         // 前面的pointer, 後面的pointer
    for(p2 = 0; p2 < v.size(); ++p2) {
        tt += v[p2].second;
        // 如果區間內最前及最後的資產差超過d就要將前面的人剃掉(不然最前面的人就會感覺pool)
        while(v[p2].first - v[p1].first >= d) {
            tt -= v[p1].second;
            ++p1;
        }
        ans = max(tt,ans);                      // 每次發現更大的友情合，就把答案更新
    }
    cout << ans;
    return 0;
}
