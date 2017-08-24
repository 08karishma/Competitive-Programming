//SOLUTION HERE - http://forthright48.blogspot.in/2015/08/spoj-lcmsum-lcm-sum.html
#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

vector<int> graph[5001];
vector<int> rev_graph[5001];
stack<int> order;
int vis[5001];
vector<int> scc_members;
int v, e;

void dfs(int source){
	vis[source]=1;
	for(int i=0; i<graph[source].size(); i++){
		if(!vis[graph[source][i]]){
			dfs(graph[source][i]);
		}
	}
	order.push(source);
}

void dfs_rev(int source){
	vis[source]=1;
	for(int i=0; i<rev_graph[source].size(); i++){
		if(!vis[rev_graph[source][i]]){
			dfs_rev(rev_graph[source][i]);
		}
	}
	scc_members.push_back(source);
}

int main() {
	while(1){
		scanf("%d", &v);
		if(v==0) break;
		scanf("%d", &e);
		for(int i=0; i<5001; i++) graph[i].clear();
		for(int i=0; i<5001; i++) rev_graph[i].clear();
		while(!order.empty()) order.pop();
		for(int i=0; i<e; i++){
			int x, y; scanf("%d%d", &x, &y);
			graph[x].push_back(y);
			rev_graph[y].push_back(x);
		}
		memset(vis, 0, sizeof vis);
		for(int i=1; i<=v; i++){
			if(!vis[i]) {
				// cout<<"dfs("<<i<<") called."<<endl;
				dfs(i);
			}
		}

		memset(vis, 0, sizeof vis);
		vector<vector<int>> scc;
		while(!order.empty()){
			int source = order.top();
			// cout<<"order.top()="<<source<<endl;
			order.pop();
			if(!vis[source]){
				scc_members.clear();
				dfs_rev(source);
				if(scc_members.size()>0) scc.push_back(scc_members);
			}
		}

		for(int i=0; i<scc.size(); i++){
			for(int j=0; j<scc[i].size(); j++){
				cout<<scc[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}