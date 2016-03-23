//************************
//Created by Chia-Hsuan Lu
//Date 2016.02.07
//************************

#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdlib>
using namespace std;

int main(){
    int n, m, step;
    bool dodo;
//input
    printf("--------------------------------\n");
    printf("Type n:");
    scanf("%d", &n);
    printf("Type m:");
    scanf("%d", &m);
    printf("--------------------------------\n");
    if (m >= 2 * n){
        printf("m too large");
        system("pause");
        return 0;
    } 
//initialization
    queue<vector<char> > bfss;
    queue<vector<int> > str;
    queue<vector<int> > to;
    vector<int> tmp_str;
    vector<int> tmp_to;
    vector<char> tmp_bfss_a;
    vector<char> tmp_bfss_b;
    vector<char> goal_1;
    vector<char> goal_2;
    vector<vector<char> > data;
    vector<vector<int> > fin_str;
    vector<vector<int> > fin_to;
//0 space
//1 color 1
//2 color 2
//-1 div
    for (int i = 0;i < 2 * n;++i) goal_1.push_back(((i + 1) % 2) + 1);
    for (int i = 0;i < 2 * n;++i) goal_2.push_back(((i) % 2) + 1);
//  for (int k = 0;k < 2 * n;++k) printf("%d ",goal[k]);
    for (int i = 0;i < 2 * m;++i) tmp_bfss_a.push_back(0);
    for (int i = 0;i < n;++i) tmp_bfss_a.push_back(1);
    for (int i = 0;i < n;++i) tmp_bfss_a.push_back(2);
    for (int i = 0;i < 2 * m;++i) tmp_bfss_a.push_back(0);
    bfss.push(tmp_bfss_a);
    data.push_back(tmp_bfss_a);
    tmp_bfss_a.clear();
    for (int i = 0;i < 2 * n + 4 * m;++i) tmp_bfss_a.push_back(-1);
    bfss.push(tmp_bfss_a);
//  tmp_str.push_back(-1);
//  tmp_to.push_back(-1);
    str.push(tmp_str);
    to.push(tmp_to);
    step = 0;
    dodo = 0;
//bfs
    printf("Step 0...   ");
    while (bfss.size() > 1){
        tmp_bfss_a = bfss.front();
        bfss.pop();
        if (tmp_bfss_a[0] == -1){
            ++step;
            if (dodo){
                printf("done\nLeast step is %d with %d methods.\n", step, fin_str.size());
                for (int i = 0;i < fin_str.size();++i){
                    printf("--------------------------------\nmethod %d\n", (i+1));
                    tmp_str = fin_str[i];
                    tmp_to = fin_to[i];
                    for (int j = 0;j < tmp_str.size();++j) printf("%d %d\n", tmp_str[j] + 1, tmp_to[j] + 1);
                }
                printf("--------------------------------\n");
                system("pause");
                return 0;
            }
            printf("done\nstep %d...    ", step);
            bfss.push(tmp_bfss_a);
            continue;
        }
        for (int i = 0;i < (2 * n + 4 * m) - m + 1;++i){
            bool can_str = 1;
            for (int j = 0;j < m;++j) can_str = can_str & ((tmp_bfss_a[i + j] == 1) | (tmp_bfss_a[i + j] == 2));
            if (!can_str) continue;
//          printf("i=%d\n",i);
            for (int j = 0;j < (2 * n + 4 * m) - m + 1;++j){
                bool can_to = 1;
                for (int k = 0;k < m;++k) can_to = can_to & (tmp_bfss_a[j + k] == 0);
                if (!can_to) continue;
//              printf("    j=%d\n",j);
                tmp_bfss_b = tmp_bfss_a;
                for (int k = 0;k < m;++k){
                    tmp_bfss_b[j + k] = tmp_bfss_b[i + k];
                    tmp_bfss_b[i + k] = 0;
                }
                if (find(data.begin(), data.end(), tmp_bfss_b) != data.end()) continue;
                bool equ = 0;
                for (int k = 0;k < (2 * n + 4 * m) - m;++k) equ = equ | equal(goal_1.begin(), goal_1.end(), tmp_bfss_b.begin() + k);
                for (int k = 0;k < (2 * n + 4 * m) - m;++k) equ = equ | equal(goal_2.begin(), goal_2.end(), tmp_bfss_b.begin() + k);
                bfss.push(tmp_bfss_b);
                data.push_back(tmp_bfss_b);
//              for (int k = 0;k < 6 * n;++k) printf("%d ",tmp_bfss_b[k]);
//              printf("\n");
                tmp_str = str.front();
                tmp_str.push_back(i);
                str.push(tmp_str);
                tmp_to = to.front();
                tmp_to.push_back(j);
                to.push(tmp_to);
                if (equ){
//                  printf("%d", tmp_str.size());
                    fin_str.push_back(tmp_str);
                    fin_to.push_back(tmp_to);
                    dodo = 1;
                }
            }
        }
        str.pop();
        to.pop();
//      system("pause");
    }
    printf("No method in extra 2m space!");
    system("pause");
    return 0;
}
