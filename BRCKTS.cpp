#include <bits/stdc++.h>
#define si(n) scanf("%lld", &n)
#define ll long long
using namespace std;

string tree[120001];
int n;
string word;

string unionStrings(string s1, string s2){
	int n1=s1.length(); int n2=s2.length();
	int i=0;
	while(i<n2 && i<n1 && s2[i]==')' && s1[n1-i-1]=='(') i++;
	s1=s1.substr(0, n1-i);
	s2=s2.substr(i, n2-i);
	string res=s1+s2;
	return res;
}

void build(int node, int start, int end){
	if(start==end){
		tree[node]=word[start];
		return;
	}
	int mid= (start+end)/2;
	build(2*node, start, mid);
	build(2*node+1, mid+1, end);
	tree[node]= unionStrings(tree[2*node], tree[2*node+1]);
}

void update(int node, int start, int end, int ind, char c){
	if(start>ind || end<ind) return;
	if(start==end){
		word[ind]=c;
		tree[node]=c;
		return;
	}
	int mid= (start+end)/2;
	update(2*node, start, mid, ind, c);
	update(2*node+1, mid+1, end, ind, c);
	tree[node]= unionStrings(tree[2*node], tree[2*node+1]);
}

bool check(){
	return tree[1]=="";
}

int main() {
	
	for(int i=1; i<=10; i++){
		si(n);
		cin>>word;
		build(1, 0, n-1);
		int count=1;	
		int q; si(q);
		while(q--){
			int k; si(k); 
			if(k==0){
				if(count==1) printf("Test %d:\n", i);
				if(check()) printf("YES\n");
				else printf("NO\n");
				count++;
			}
			else {
				char c= word[k-1];
				c = (c=='(') ? ')' : '(';
				update(1, 0, n-1, k-1, c);
			}
		}
	}
	return 0;
}
