//WATCH THIS - https://www.youtube.com/watch?v=n7r4Dp6cVg8

#include <iostream>
#include <cstring>
#include <climits>
#include <queue>
#include <vector>
#define NIL 0
#define INF INT_MAX
#define MAX 150001
using namespace std;

vector<int> graph[MAX];
int n, m, p;
// n: number of nodes on left side(in U), nodes are numbered 1 to n
// m: number of nodes on right side(in V), nodes are numbered n+1 to n+m
// graph = NIL[0] ∪ U ∪ V
int match[MAX], dist[MAX];

//in bfs, when searching for successors from a vertex in U, 
//only unmatched edges may be traversed, while from a vertex in V
//only matched edges may be traversed. 
bool bfs(){
	queue<int> Q;
	//dist[i]=INF for vertices in U which are part of unmatched edges
	//whereas dist[i]!=INF means matched edges
	for(int i=1; i<=n; i++){
		if(match[i]==NIL){
			dist[i]=0;
			Q.push(i);
		}
		else dist[i]=INF;
	}
	dist[NIL]=INF;
	while(!Q.empty()){
		int u = Q.front(); Q.pop();
		if(u!=NIL){
			for(int i=0; i<graph[u].size(); i++){
				int v = graph[u][i];
				//dist[match[v]]=INF means we are traversing a matched edge
				if(dist[match[v]]==INF) {
					dist[match[v]]=dist[u]+1;
					Q.push(match[v]);
				}
			}
		}
	}
	//Q becomes empty only when one or more free vertices in V are reached.
	return dist[NIL]!=INF;
}

bool dfs(int u){
	if(u!=NIL){
		for(int i=0; i<graph[u].size(); i++){
			int v= graph[u][i];
			//match[v] is in next layer as u, i.e match[v] lies after u in augmenting path
			if(dist[match[v]]==dist[u]+1){
				if(dfs(match[v])){
					match[v]=u;
					match[u]=v;
					return true;
				}
			}
		}
		//mark u as visited so that dfs u is never called in future for this stage (since dfs(u) is false)
		dist[u] = INF;
		return false;
	}
	return true;
}

int hopcroft_karp(){
    memset(match, 0, sizeof match);
	int matching =0;
	//match[] is assumed NIL for all i in graph
	while(bfs()){
		for(int i=1; i<=n; i++){
			if(match[i]==NIL && dfs(i)){
				matching++;
			}
		}
	}
	return matching;
}

int main() {
	scanf("%d%d%d", &n, &m, &p);
	while(p--){
		int x, y; scanf("%d%d", &x, &y);
		graph[x].push_back(y+n);
		graph[y+n].push_back(x);
	}
    int ans = hopcroft_karp();
    printf("%d\n", ans);
	return 0;
}

//bfs tells whether a path bw unmatched vertices in U and unmatched ertices in V exists
//dfs updates the value of match which is a result of adding that augmenting path in our final total matchings
//hopcroft_karp does the adding