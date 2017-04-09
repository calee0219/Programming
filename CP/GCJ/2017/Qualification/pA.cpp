#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int t = 1; t <= T; ++t) {
        cout << "Case #" << t <<": ";
        int k;
        string str;
        cin >> str;
        cin >> k;
        int len = str.size();
        //int pan = 0;
        //int turn = (1<<k)-1;
        //for(int i = 0; i < len; ++i) {
            //pan <<= 1;
            //if(str[i] == '-') pan |= 1;
        //}
        //int ans = 0;
        //for(int i = 0; i < len-k+1; ++i) {
            //if(pan & 1) {
                //pan ^= turn;
                //ans++;
            //}
            //pan >>= 1;
            //if(!pan) break;
        //}
        //if(pan) cout << "IMPOSSIBLE" << endl;
        //else cout << ans << endl;
        int cnt = 0;
        for(int i = 0; i < len-k+1; ++i) {
            if(str[i] == '-') {
                cnt++;
                for(int j = 0; j < k; ++j)
                    str[i+j] = str[i+j]=='+'? '-':'+';
            }
        }
        bool ans = true;
        for(int i = 0; i < len; ++i) {
            if(str[i] == '-') ans = false;
        }
        if(ans) cout << cnt << endl;
        else cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
