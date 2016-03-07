/*************************************************************************
  > File Name: 572-Oil_Deposits.cpp
  > Author: Gavin Lee
  > Mail: sz110010@gmail.com
  > Created Time: 西元2016年03月06日 (週日) 18時55分07秒
 ************************************************************************/

#include <iostream>
#include <queue>
#include <utility>
#include <cstdio>
#include <cstring>
using namespace std;

int m, n;
char c[100+1][100+1];
bool b[100+1][100+1];
queue< pair<int,int> > q;

void bfs(void);
bool yes(int i, int j);

int main()
{
    while(~scanf("%d%d", &m, &n) && m && n)
    {
        //memset(b,0,sizeof(int)*(100+1)*(100+1));
        //cout << m << n << endl;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                //cout << "hi";
                //scanf("%c", &c[i][j]);
                cin >> c[i][j];
                b[i][j] = 0;
            }
        }
        int ans = 0;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(c[i][j] == '@' && b[i][j] == 0)
                {
                    ans++;
                    q.push(make_pair(i,j));
                    bfs();
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

void bfs(void)
{
    int i = q.front().first;
    int j = q.front().second;
    b[i][j] = 1;
    // up
    if(yes(i-1,j) && c[i-1][j] == '@' && b[i-1][j] == 0)
        q.push(make_pair(i-1,j));
    // down
    if(yes(i+1,j) && c[i+1][j] == '@' && b[i+1][j] == 0)
        q.push(make_pair(i+1,j));
    // right
    if(yes(i,j+1) && c[i][j+1] == '@' && b[i][j+1] == 0)
        q.push(make_pair(i,j+1));
    // left
    if(yes(i,j-1) && c[i][j-1] == '@' && b[i][j-1] == 0)
        q.push(make_pair(i,j-1));
    // upper right
    if(yes(i-1,j+1) && c[i-1][j+1] == '@' && b[i-1][j+1] == 0)
        q.push(make_pair(i-1,j+1));
    // upper left
    if(yes(i-1,j-1) && c[i-1][j-1] == '@' && b[i-1][j-1] == 0)
        q.push(make_pair(i-1,j-1));
    // downer right
    if(yes(i+1,j+1) && c[i+1][j+1] == '@' && b[i+1][j+1] == 0)
        q.push(make_pair(i+1,j));
    // downer left
    if(yes(i+1,j-1) && c[i+1][j-1] == '@' && b[i+1][j-1] == 0)
        q.push(make_pair(i+1,j-1));
    q.pop();
    if(!q.empty())
        bfs();
    return;
}

bool yes(int i, int j)
{
    if(i >= m || i < 0)
        return false;
    if(j >= n || j < 0)
        return false;
    return true;
}
