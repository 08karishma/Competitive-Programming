#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define f first
#define s second
#define MAX 250
#define INF 10000
using namespace std;

int source, sink;
int n; //no of nodes
int cap[MAX][MAX];
int vis[MAX];
int par[MAX];

//returns 0 if path exists between source and sink
int bfs(){
    memset(vis, 0, sizeof vis);
    queue<int> q;
    q.push(source);
    par[source]=-1;
    while(!q.empty()){
        int t=q.front();
        q.pop();
        vis[t]=1;   
        for(int v=1; v<=n; v++){
            if(!vis[v] && cap[t][v]>0){
                q.push(v);
                par[v]=t;
            }
        }     
    }
    return vis[sink];
}

int max_flow(){
    int mflow=0;
    while(bfs()){
        int path_cap=INF;
        int cur=sink;
        while(par[cur]>-1){
            int prev=par[cur];
            path_cap=min(path_cap, cap[prev][cur]);
            cur=prev;
        }
        cur=sink;
        while(par[cur]>-1){
            int prev=par[cur];
            cap[prev][cur]-=path_cap;
            cap[cur][prev]+=path_cap;
            cur=prev;
        }
        mflow += path_cap;
    }
    return mflow;
}

int main()
{
    int t; scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        source=1; sink=n;
        memset(cap, 0, sizeof cap);
        for(int i=1; i<n; i++){
            int k; scanf("%d", &k);
            while(k--){
                int v; scanf("%d", &v);
                if(i==1 || v==n) cap[i][v]=1;
                else cap[i][v]=INF;
                cap[v][i]=0;
            }
        }
        printf("%d\n", max_flow());
    }   
    return 0;
}