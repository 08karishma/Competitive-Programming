#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <algorithm>
#include  <unordered_map>
#define MAX 5001
using namespace std;

vector<int> graph[MAX], rev_graph[MAX];
int sc[MAX];
stack<int> order;
int n;
int vis[MAX];

void dfs1(int u){
    vis[u]=1;
    for(int i=0; i<graph[u].size(); i++){
        int v =graph[u][i];
        if(!vis[v]) dfs1(v);
    }
    order.push(u);
}

void dfs2(int u, int comp){
    sc[u] = comp;
    vis[u] = 1;
    for(int i=0; i<rev_graph[u].size(); i++){
        int v =rev_graph[u][i];
        if(!vis[v]) dfs2(v, comp);
    }
}

int main() {
    while(1){
        int m;
        scanf("%d", &n);
        if(n==0) break;
        scanf("%d", &m);

        for(int i=1; i<=n; i++) {
            graph[i].clear();
            rev_graph[i].clear();
        }
        while(!order.empty()) order.pop();

        while(m--){
            int u,v; scanf("%d%d", &u, &v);
            graph[u].push_back(v);
            rev_graph[v].push_back(u);
        }

        memset(vis, 0, sizeof vis);
        for(int i=1; i<=n; i++){
            if(!vis[i]) dfs1(i);
        }

        int comp = 0;
        memset(vis, 0, sizeof vis);
        while(!order.empty()){
            int i = order.top(); order.pop();
            if(!vis[i]) dfs2(i, comp++);
        }

        vector<int> res;
        unordered_map<int, int> excl; //components to exclude
        for(int i=1; i<=n; i++){
            if(excl.find(sc[i])!=excl.end()) continue;
            int flag=1;
            for(int j=0; j<graph[i].size() && flag; j++){
                int v= graph[i][j];
                if(sc[i] != sc[v]){
                    flag=0;
                }
            }
            if(flag==0) excl[sc[i]]=1;
        }

        for(int i=1; i<=n; i++){
            if(excl.find(sc[i])==excl.end()) res.push_back(i);
        }

        sort(res.begin(), res.end());

        for(int i=0; i<res.size(); i++) printf("%d ", res[i]);
        printf("\n");

    }

    return 0;
}