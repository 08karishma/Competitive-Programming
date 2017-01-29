#include <bits/stdc++.h>
#define si(n) scanf("%d",&n)
#define SI(n) scanf("%lld",&n)
typedef long long ll;
#define mod 1000000007
using namespace std;

int edges; int nodes;
pair<ll, pair<int, int>> p[300001];
int id[1001];

int root(int x){
	while(id[x]!=x) {
		id[x]=id[id[x]];
		x=id[x];
	}
	return x;
}

void union1(int x, int y){
	int p=root(x);
	int q= root(y);
	id[p]= id[q];
}

ll minCost(){
	ll ans=0;
	for(int i=0; i<edges; i++){
		int x= p[i].second.first;
		int y= p[i].second.second;
		if(root(x)!=root(y)){
			ans+= p[i].first;
			union1(x, y);
		}
	}
	return ans;
}

int main() {
	// your code goes here
	int t; si(t);
	while(t--){
		int cost; si(cost);
		si(nodes);
		si(edges);
		for(int i=0; i<edges; i++){
			int x; si(x);
			int y; si(y);
			ll l; SI(l);
			p[i]=make_pair(l, make_pair(x, y));
		}
		for(int i=1; i<=nodes; i++) id[i]=i;
		sort(p, p+edges);
		printf("%lld\n", cost*minCost());
	}
	return 0;
}
