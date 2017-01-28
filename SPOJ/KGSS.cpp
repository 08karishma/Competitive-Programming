#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
#define ll long long
using namespace std;

int arr[100001];
int n;
pair<int,int> tree[400001];

pair<int,int> nodeUnion(pair<int,int> p1, pair<int,int> p2){
	pair<int,int> ans= make_pair(-1,-1);
	if(p1.first> p2.first){
		ans.first=p1.first;
		ans.second=max(p1.second, p2.second);
		if(ans.second<p2.first) ans.second=p2.first;
	}
	else{
		ans.first=p2.first;
		ans.second=max(p1.second, p2.second);
		if(ans.second<p1.first) ans.second=p1.first;
	}
	return ans;
}

void build(int node, int start, int end){
	if(start==end){
		tree[node].first=arr[start];
		tree[node].second=INT_MIN;
		return;
	}
	int mid = (start+end)/2;
	build(2*node, start, mid);
	build(2*node+1, mid+1, end);
	tree[node]=nodeUnion(tree[2*node], tree[2*node+1]);
}

void update(int node, int start, int end, int ind, int val){
	if(ind<start || ind>end) return;
	if(start==end){
		arr[ind]=val;
		tree[node].first=val;
		return;
	}
	int mid = (start+end)/2;
	update(2*node, start, mid, ind, val);
	update(2*node+1, mid+1, end, ind, val);
	tree[node]=nodeUnion(tree[2*node], tree[2*node+1]);
}

pair<int,int> query(int node, int start, int end, int i, int j){
	if(i<=start && j>=end) return tree[node];
	if(j<start || i>end) {
		pair<int,int> p=make_pair(INT_MIN, INT_MIN);
		return p;
	}
	int mid = (start+end)/2;
	pair<int,int> p1= query(2*node, start, mid, i, j);
	pair<int,int> p2= query(2*node+1, mid+1, end, i, j);
	return nodeUnion(p1, p2);
}

int main() {
	si(n);
	for(int i=0; i<n; i++){
		si(arr[i]);
	}
	build(1, 0, n-1);
	int q; si(q);
	for(int i=0; i<q; i++){
		char type; scanf(" %c",&type);
		int x; si(x);
		int y; si(y);
		if(type=='U') update(1, 0, n-1, x-1, y);
		else{
			pair<int,int> p= query(1, 0, n-1, x-1, y-1);
			printf("%d\n", p.first+p.second);
		}
	}
	
	return 0;
}
