#include <iostream>
#include <cstdio>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

int main()
{
    freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);
    int n;
    cin >> n;
    getchar();
    while(n--) {
        vector<int> v;
        string line;
        getline(cin, line);
        stringstream ss(line);
        int tmp;
        while(ss >> tmp) {
            //int tmp; ss >> tmp;
            v.push_back(tmp);
        }
        //v.pop_back();
        sort(v.begin(),v.end());
        for(int i = 0; i < v.size(); ++i) cout << v[i] << ' ';
        cout << endl;
    }
    fclose (stdout);
    fclose (stdin);
    return 0;
}
