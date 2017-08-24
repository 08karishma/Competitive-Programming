#include <iostream>
#include <cstring>
#include <vector>
#include <climits>
#define MAX 5001
#define INF INT_MAX
using namespace std;

struct edge{
    int u, v, cap, flow;
};

int n, source, sink; 
edge e[60020];
vector<int> graph[MAX];
int ptr[MAX];
int level[MAX], q[MAX];

bool bfs(){
    for(int i=0; i<=n; i++) level[i]=-1;
    level[source]=0;
    int qhead=0, qtail=0;
    q[qtail]=source; qtail++;
    while(qhead<qtail && level[sink]==-1){ //qhead==qtail means queue is empty
        int cur=q[qhead]; qhead++;
        for(int i=0;i<graph[cur].size(); i++){
            int e_cnt = graph[cur][i];
            int next = e[e_cnt].v;
            if(level[next]==-1 && e[e_cnt].flow<e[e_cnt].cap){
                q[qtail]=next;
                qtail++;
                level[next]=level[cur]+1;
            }
        }
    }
    return level[sink]!=-1;
}

long long dfs(int cur, int cur_flow){
    if(cur_flow==0) return 0;
    if(cur==sink) return (long long)cur_flow;
    for(; ptr[cur]<graph[cur].size(); ++ptr[cur]){
        int e_cnt = graph[cur][ptr[cur]];
        int next = e[e_cnt].v;
        if(level[next] != level[cur]+1) continue;
        int pushed = dfs(next, min(cur_flow, e[e_cnt].cap-e[e_cnt].flow));
        if(pushed){
            e[e_cnt].flow += pushed;
            e[e_cnt^1].flow -= pushed;
            return pushed;
        }
    }
    return 0;
}

long long dinic(){
    long long ans=0;
    while(bfs()){
        for(int i=0; i<=n; i++) ptr[i]=0;
        while(long long pushed= dfs(source, INF)){
            ans += pushed;
        }
    }
    return ans;
}

int main() {
    int m; scanf("%d%d", &n, &m);
    int e_cnt=0;
    while(m--){
        int x, y, z; scanf("%d%d%d", &x, &y, &z);
        edge e1; e1.u=x; e1.v=y; e1.flow=0; e1.cap=z;
        edge e2; e2.u=y; e2.v=x; e2.flow=0; e2.cap=z;
        graph[x].push_back(e_cnt);
        e[e_cnt++]=e1;
        graph[y].push_back(e_cnt);
        e[e_cnt++]=e2;
    }
    source=1; sink=n;
    long long ans = dinic();
    printf("%lld\n", ans);
    return 0;
} 