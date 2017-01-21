#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; ++i) {
        int p;
        cin >> p;
        v.push_back(p);
    }
    sort(v.begin(),v.end());
    int q;
    cin >> q;
    for(int i = 0; i < q; ++i) {
        int m;
        cin >> m;
        cout << upper_bound(v.begin(), v.end(), m)-v.begin() << endl;
    }
    return 0;
}
