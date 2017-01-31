#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
#define ll long long
using namespace std;

int dp[10001][10001];
vector<pair<int,int>> v[10001];
int n;

void dijkstra(int source){
    bool vis[n+1]; int dist[n+1];
    for(int i=0; i<n+1; i++) dist[i]=INT_MAX;
    memset(vis, false , sizeof vis);            // set all vertex as unvisited
    dist[source] = 0;
    priority_queue < pair < int , int > > s;          // multiset do the job as a min-priority queue

    s.push({0 , source});                          // insert the source node with distance = 0

    while(!s.empty()){

        pair <int , int> p = s.top();        // pop the vertex with the minimum distance
        s.pop();

        int x = p.second; 
        if( vis[x] ) continue;                  // check if the popped vertex is visited before
         vis[x] = true;

        for(int i = 0; i < v[x].size(); i++){
            int e = v[x][i].first; int w = v[x][i].second;
            if(dist[x] + w < dist[e]  ){            // check if the next vertex distance could be minimized
                dist[e] = dist[x] + w;
                s.push({(-1)*dist[e],  e} );           // insert the next vertex with the updated distance
            }
        }
    }
    for(int i=1; i<=n; i++){
		dp[source][i]=dist[i];
		dp[i][source]=dist[i];
	}
}

int minCost(int s, int d){
	if(dp[s][d]!=-1) return dp[s][d];
	if(s==d) return dp[s][d]=0;
	dijkstra(s);
	return dp[s][d];
}

int main() {
	int t; si(t);
	while(t--){
		memset(dp, -1, sizeof(dp));
		unordered_map<string, int> hash;
		si(n);
		for(int i=1; i<=n; i++){
			string s; cin>>s;
			hash[s]=i;
			v[i].clear();
			int y; si(y);
			while(y--){
				int c; si(c); int d; si(d);
				v[i].push_back(make_pair(c,d));
			}
		}
		int r; si(r);
		while(r--){
			string s1, s2; cin>>s1>>s2;
			printf("%d\n",minCost(hash[s1], hash[s2]));
		}
	}
	return 0;
}
