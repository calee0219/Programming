#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    FILE * oFile, * iFile;
    iFile = fopen ("input.txt","r");
    oFile = fopen ("output.txt","w");
    int n;
    char enter;
    fscanf(iFile, "%d", &n);
    fscanf(iFile, "%c", &enter);
    while(n--) {
        int v[100010];
        char line[100000];
        int o = 0;
        for(o = 0;; ++o) {
            fscanf(iFile, "%c", line+o);
            if(line[o] == '\n') break;
        }
        int tmp = 0;
        int ord = 0;
        for(int i = 0; i < o; ++i) {
            if(line[i] >= '0' && line[i] <= '9') {
                tmp *= 10;
                tmp += line[i] - '0';
                continue;
            } else {
                if(tmp) v[ord++] = tmp;
                tmp = 0;
            }
        }
        if(tmp) v[ord++] = tmp;
        sort(v,v+ord);
        for(int i = 0; i < ord; ++i) fprintf(oFile, "%d ", v[i]);
        fprintf(oFile,"\n");
    }
    fclose (iFile);
    fclose (oFile);
    return 0;
}
