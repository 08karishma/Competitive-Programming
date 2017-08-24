#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#define MAX 111111
#define LN 19
using namespace std;

struct node {
	int count;
	node *left, *right;
	node(int count, node *l, node *r): count(count), left(l), right(r) {}
	node *insert(int l, int r, int w);
};

vector<int> adj[MAX]; //adjacency list
map<int,int> mp; //compressed node values
int revmp[MAX]; //uncompressed original values
int v[MAX]; //stores values of nodes
int n, m, maxi; //no of nodes and edges
int pa[MAX][LN], depth[MAX]; //pa[i][j] sotres (2^j)th-parent of i
node *root[MAX];

node *null = new node(0, NULL, NULL);

node * node::insert(int l, int r, int w){
	if(l<=w && w<r){
		if(r==l+1) return new node(this->count+1, null, null);
		int m=(l+r)/2;
		return new node(this->count+1, this->left->insert(l,m,w), this->right->insert(m,r,w));
	}
	return this;
}

void dfs(int cur, int prev){
	pa[cur][0]=prev;
	depth[cur] = (prev==-1) ? 0:depth[prev]+1;
	root[cur] = ((prev==-1) ? null : root[prev])->insert(0, maxi, mp[v[cur]]);
	for(int i=0; i<adj[cur].size(); i++) {
		if(adj[cur][i]!=prev) dfs(adj[cur][i], cur);
	}
}

int LCA(int u, int v){
	if(depth[u] < depth[v]) return LCA(v,u);
	int diff = depth[u]-depth[v];
	for(int i=0; i<LN; i++){
		if((diff>>i) & 1) u=pa[u][i];
	}
	if(u!=v){
		for(int i=LN-1; i>=0; i--){
			if(pa[u][i]!=pa[v][i]){
				u=pa[u][i];
				v=pa[v][i];
			}
		}
		u=pa[u][0];
	}
	return u;
}

int query(node *a, node *b, node *c, node *d, int l, int r, int k){
	if(r==l+1) return l;
	int count = a->left->count + b->left->count - c->left->count - d->left->count;
	int m = (l+r)/2;
	if(count>=k) return query(a->left, b->left, c->left, d->left, l, m, k);
	return query(a->right, b->right, c->right, d->right, m, r, k-count);
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; i++){
		scanf("%d", &v[i]);
		mp[v[i]]=-1;
	}

	//compression of values to make them in range 0 to n-1
	maxi=0;
	for(map<int,int>::iterator it=mp.begin(); it!=mp.end(); ++it){
		mp[it->first] = maxi;
		revmp[maxi]=it->first;
		maxi++;
	}

	for(int i=0; i<n-1; i++){
		int u,v; scanf("%d%d", &u, &v);
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	memset(pa, -1, sizeof pa);
	null->left = null->right = null;
	dfs(0, -1);
	for(int i=0; i<LN-1; i++){
		for(int j=0; j<n; j++){
			if(pa[j][i]!=-1) pa[j][i+1] = pa[pa[j][i]][i];
		}
	}

	while(m--){
		int u, v, k;
		scanf("%d%d%d", &u, &v, &k);
		u--; v--;
		int lca=LCA(u,v);
		int ans = query(root[u], root[v], root[lca], (pa[lca][0]==-1 ? null : root[pa[lca][0]]), 0, maxi, k);
		printf("%d\n", revmp[ans]);
	}

	return 0;
}