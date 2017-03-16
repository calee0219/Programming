#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int v[100010];
char line[1000010];

int main()
{
    freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);
    int n;
    scanf("%d", &n);
    //getchar();
    while(true) {
        char a = getchar();
        if(a == '\n') break;
    }
    while(n--) {
        int o = 0;
        for(o = 0;; ++o) {
            line[o] = getchar();
            if(line[o] == '\n' || line[o] == EOF) break;
        }
        int tmp = 0;
        int ord = 0;
        for(int i = 0; i < o; ++i) {
            if(line[i] >= '0' && line[i] <= '9') {
                if(i > 0 && (line[i-1] < '0' || line[i-1] > '9')) {
                    v[ord++] = tmp;
                    tmp = 0;
                }
                tmp *= 10;
                tmp += line[i] - '0';
                continue;
            }
        }
        v[ord++] = tmp;
        sort(v,v+ord);
        for(int i = 0; i < ord; ++i) printf("%d ", v[i]);
        printf("\n");
    }
    fclose (stdin);
    fclose (stdout);
    char c;
    for (c = 'A' ; c <= 'Z' ; c++) putchar (c);
    return 0;
}
