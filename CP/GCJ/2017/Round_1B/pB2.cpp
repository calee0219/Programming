#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T; cin >> T;
    for(int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        int n, r, o, y, g, b, v;
        cin >> n >> r >> o >> y >> g >> b >> v;
        if(o > v+b+g || y > b+v+r || g > v+r+y || b > r+o+y || v > o+y+g || r > y+g+b) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
    }
    return 0;
}
