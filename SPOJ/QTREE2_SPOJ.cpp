#include <iostream>
#include <vector>
#define MAX 10001
#define LN 14
using namespace std;

vector<int> adj[MAX], costs[MAX];
int depth[MAX], pa[MAX][LN], subsize[MAX];
int chainHead[MAX], chainInd[MAX];
int posInBase[MAX], BaseArray[MAX];
int chainNo, ptr;
int tree[4*MAX];

void make_tree(int cur, int s, int e){
	if(s==e) {
		tree[cur]=BaseArray[s];
		return;
	}
	int m=(s+e)/2;
	make_tree(2*cur, s, m);
	make_tree(2*cur+1, m+1, e);
	tree[cur] = tree[2*cur]+tree[2*cur+1];
}

int query_tree(int cur, int s, int e, int l, int r){
	if(r<s || l>e) return 0;
	if(l<=s && r>=e) return tree[cur];
	int m=(s+e)/2;
	return query_tree(2*cur, s, m, l, r) + query_tree(2*cur+1, m+1, e, l, r);
}

void dfs(int cur, int prev){
	depth[cur] = (prev==-1) ? 0 : depth[prev]+1;
	pa[cur][0]=prev;
	subsize[cur]=1;
	for(int i=0; i<adj[cur].size(); i++){
		if(adj[cur][i]!=prev){
			dfs(adj[cur][i], cur);
			subsize[cur] += subsize[adj[cur][i]];
		}
	}
}

int LCA(int u, int v){
	if(depth[u]<depth[v]) swap(u,v);
	int diff = depth[u]-depth[v];
	for(int i=0; i<LN; i++){
		if( (diff>>i)&1 ) u=pa[u][i];
	}
	if(u==v) return u;
	for(int i=LN-1; i>=0; i--){
		if(pa[u][i] != pa[v][i]){
			u=pa[u][i];
			v=pa[v][i];
		}
	}
	return pa[u][0];
}

void HLD(int curNode, int cost, int prev){
	if(chainHead[chainNo]==-1) chainHead[chainNo]=curNode;
	chainInd[curNode]=chainNo;
	posInBase[curNode]=ptr;
	BaseArray[ptr++]=cost;

	int sc=-1, ncost;
	for(int i=0; i<adj[curNode].size(); i++){
		if(adj[curNode][i]!=prev){
			if(sc==-1 || subsize[sc]<subsize[adj[curNode][i]]) {
				sc = adj[curNode][i];
				ncost = costs[curNode][i];
			}
		}
	}
	if(sc!=-1) HLD(sc, ncost, curNode);
	for(int i=0; i<adj[curNode].size(); i++){
		if(adj[curNode][i]!=prev && adj[curNode][i]!=sc){
			chainNo++;
			HLD(adj[curNode][i], costs[curNode][i], curNode);
		}
	}
}

int query_up(int u, int v){
	if(u==v) return 0;
	int uchain, vchain=chainInd[v];
	int ans =0;
	while(1){
		uchain=chainInd[u];
		if(uchain==vchain){
			if(u==v) break;
			ans += query_tree(1, 0, ptr, posInBase[v]+1, posInBase[u]);
			break;
		}
		ans += query_tree(1, 0, ptr, posInBase[chainHead[uchain]], posInBase[u]);
		u=chainHead[uchain];
		u=pa[u][0];
	}
	return ans;
}

int query(int u, int v){
	int lca = LCA(u, v);
	int ans = query_up(u, lca);
	ans += query_up(v, lca);
	return ans;
}

int kth(int u, int v, int k){
	int lca = LCA(u, v);
	int num_left = depth[u]-depth[lca]+1; // no of nodes between lca and u, inclusive
	int from;
	if(k<num_left) from=u;
	else if(k==num_left) return lca;
	else{
		k = k-num_left;
		k = (depth[v]-depth[lca]+1)-k;
		from=v;
	}
	if(k==1) return from;
	k-=1;
	int j=0, cur=1;
	while(cur*2<=k) {
		cur*=2; j++;
	}
	from = pa[from][j];
	while(cur<k){
		from = pa[from][0];
		cur++;
	}
	return from;
}

int main() {
	int t; scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		for(int i=0; i<n; i++){
			adj[i].clear(); costs[i].clear(); 
			chainHead[i]=-1;
			for(int j=0; j<LN; j++) pa[i][j]=-1;
		}
		for(int i=0; i<n-1; i++){
			int a,b,c; scanf("%d%d%d", &a, &b, &c);
			a--; b--;
			adj[a].push_back(b);
			costs[a].push_back(c);
			adj[b].push_back(a);
			costs[b].push_back(c);
		}
		dfs(0, -1);
		for(int j=0; j<LN-1; j++){
			for(int i=0; i<n; i++){
				if(pa[i][j]!=-1){
					pa[i][j+1] = pa[pa[i][j]][j];
				}
			}
		}

		chainNo=0; ptr=0;
		HLD(0, 0, -1);
		ptr--;
		make_tree(1, 0, ptr);

		while(1){
			char s[100]; scanf("%s",s);
			if(s[0]=='D' && s[1]=='O') break;
			int u, v; scanf("%d%d", &u, &v); u--; v--;
			if(s[0]=='D'){
				printf("%d\n", query(u,v));
			}
			else{
				int k; scanf("%d", &k);
				printf("%d\n", kth(u, v, k)+1);
			}
		}
		printf("\n");
	}
	return 0;
}