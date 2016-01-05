#include <iostream>
using namespace std;

int main()
{
    string s;
    int m;
    cin >> s;
    cin >> m;
    while(m--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        size_t i;
        string tmp_str;
        for(i = 0; i < k; ++i)
            tmp_str[i] = s[r-k+i-1];
        for(i = r-k-1; i >= l-1; --i)
            s[i+k] = s[i];
        for(i = l-1; i < r-k; ++i)
            s[i] = tmp_str[i-l+1];
    }
    cout << s;
    return 0;
}

