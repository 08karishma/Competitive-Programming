#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

vector<int> graph[50001];
vector<int> rev_graph[50001];
stack<int> order;
int vis[50001];
int comp[50001];
int v;

void dfs(int source){
    vis[source]=1;
    for(int i=0; i<graph[source].size(); i++){
        if(!vis[graph[source][i]]){
            dfs(graph[source][i]);
        }
    }
    order.push(source);
}

void dfs_rev(int source, int component){
    vis[source]=1;
    comp[source] = component;
    for(int i=0; i<rev_graph[source].size(); i++){
        if(!vis[rev_graph[source][i]]){
            dfs_rev(rev_graph[source][i], component);
        }
    }
}

int main() {
    int t; scanf("%d", &t);
    while(t--){
        scanf("%d", &v);
        for(int i=0; i<v; i++) graph[i].clear();
        for(int i=0; i<v; i++) rev_graph[i].clear();
        while(!order.empty()) order.pop();

        for(int i=0; i<v; i++){
            int m; scanf("%d", &m);
            while(m--){
                int j; scanf("%d", &j); j--;
                rev_graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }

        memset(vis, 0, sizeof vis);
        for(int i=0; i<v; i++){
            if(!vis[i]) {
                // cout<<"dfs("<<i<<") called."<<endl;
                dfs(i);
            }
        }

        memset(vis, 0, sizeof vis);
        int component=0;

        while(!order.empty()){
            int source = order.top();
            // cout<<"order.top()="<<source<<endl;
            order.pop();
            if(!vis[source]){
                dfs_rev(source, component);
            }
            component++;
        }

        int indeg[component];
        memset(indeg, 0, sizeof indeg);
        for(int i=0; i<v; i++){
            for(int j=0; j<graph[i].size(); j++){
                int k = graph[i][j];
                if(comp[i] != comp[k]){
                    indeg[comp[k]]++;
                }
            }
        }
        int c=0;
        for(int i=0; i<component; i++){
            // cout<<indeg[i]<<endl;
            if(indeg[i]==0) {
                c++; 
            }
        }

        if(c>1){
            printf("0\n");
        }
        else{
            int cnt=0;
            for(int i=0; i<v; i++){
                if(indeg[comp[i]]==0) cnt++;
            }
            printf("%d\n", cnt);
        }

    }
    return 0;
}