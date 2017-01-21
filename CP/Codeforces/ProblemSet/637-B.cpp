#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> v;
    for(int i = 0; i < n; ++i) {
        string str;
        cin >> str;
        v.push_back(str);
    }
    map<string,int> m;
    for(int i = n-1; i >= 0; --i) {
        if(!m[v[i]]) cout << v[i] << endl;
        m[v[i]] = 1;
    }
    return 0;
}
