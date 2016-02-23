#include<cstdio>
#include<cstring>
#include<stack>
#include<algorithm>
using namespace std;
typedef long long LL;
const int SIZEN=100005;
const int SIZEM=300005;
const int INF=1e9;
const int MOD=1e9+7;
struct edge{
    int to,next;
};
edge e[SIZEM];
int cost[SIZEN],head[SIZEN];
int DFN[SIZEN],low[SIZEN],sscn[SIZEN];
LL sz,s_cost,num_cost,dfs_time,ssc_cnt;
void addedge(int u,int v){
    e[sz].to=v;
    e[sz].next=head[u];
    head[u]=sz++;
}
void init(){
    memset(DFN,0,sizeof(DFN));
    memset(low,0,sizeof(low));
    memset(sscn,0,sizeof(sscn));
    memset(head,-1,sizeof(head));
    sz=0;num_cost=1;s_cost=0;
    dfs_time=1;ssc_cnt=0;
}
stack<int> S;
void tarjan(int u){
    DFN[u]=low[u]=dfs_time++;
    S.push(u);
    for(int i=head[u];i!=-1;i=e[i].next){
        int v=e[i].to;
        if(!DFN[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(DFN[v]&&!sscn[v]){
            low[u]=min(low[u],DFN[v]);
        }
    }
    if(DFN[u]==low[u]){
        int x;
        int Min=INF,cnt=0;
        ssc_cnt++;
        for(;;){
            x=S.top();S.pop();
            sscn[x]=ssc_cnt;
            if(cost[x]<Min){
                Min=cost[x];
                cnt=1;
            }
            else if(cost[x]==Min) cnt++;
            if(x==u) break;
        }
        s_cost=s_cost+Min;num_cost=(long long)num_cost*cnt%MOD;
    }
}
int read(){
    char ch=' ';
    int flag=1;
    while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
    if(ch=='-') {flag=-1;ch=getchar();}
    int ret=0;
    while(ch<='9'&&ch>='0'){
        ret=ret*10+ch-'0';
        ch=getchar();
    }
    return ret*flag;
}
int main()
{
    int i, j;
    int n, m;
    int u, v;
    while(scanf("%d",&n)!=EOF){
        init();
        for(i=1;i<=n;i++) cost[i]=read();
        scanf("%d",&m);
        while(m--){
            u=read();v=read();
            addedge(u,v);
        }
        for(i=1;i<=n;i++)
            if(!DFN[i]) tarjan(i);
        printf("%I64d %I64d\n",s_cost,num_cost);
    }
    return 0;
}

