/*************************************************************************
	> File Name: PD_1.cpp
	> Author: Gavin Lee
	> Mail: sz110010@gmail.com
	> Created Time: 西元2016年01月23日 (週六) 18時34分51秒
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    bool m[1000][1000] = {0};
    int k;
    cin >> k;
    int kt = k;
    int cnt = 0;
    int ord = 3;
    while(kt)
    {
        kt >>= 1;
        cnt++;
    }
    for(int i = 3; i <= (cnt-1)*3; i += 3)
    {
        m[i][i+1] = true;
        m[i+1][i] = true;
        m[i][i+2] = true;
        m[i+2][i] = true;
    }
    for(int i = 6; i <= cnt*3; i += 3)
    {
        m[i][i-1] = true;
        m[i][i-2] = true;
        m[i-1][i] = true;
        m[i-2][i] = true;
        ord = cnt*3;
    }
    for(int i = cnt-2; i >= 0; --i)
    {
        if(k >> i & 1)
        {
            m[3][ord+1] = true;
            m[ord+1][3] = true;
            for(int j = 0; j < 2*(cnt-1-i)-2; ++j)
            {
                ord++;
                m[ord][ord+1] = true;
                m[ord+1][ord] = true;
            }
            ord++;
            m[(cnt-i)*3][ord] = true;
            m[ord][(cnt-i)*3] = true;
        }
    }
    m[1][3] = true;
    m[3][1] = true;
    m[2][cnt*3] = true;
    m[cnt*3][2] = true;
    cout << ord << endl;
    for(int i = 1; i <= ord; ++i)
    {
        for(int j = 1; j <= ord; ++j)
        {
            if(m[i][j])
                cout << "Y";
            else
                cout << "N";
        }
        cout << endl;
    }
    return 0;
}

