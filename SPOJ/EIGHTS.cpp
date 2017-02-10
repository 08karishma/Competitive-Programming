#include <bits/stdc++.h>
#define si(n) scanf("%d",&n)
#define SI(n) scanf("%lld",&n)
typedef long long ll;
#define rep(i,n) for(int i=0; i<n; i++)
using namespace std;

int main() {
	// your code goes here
	int t; si(t);
	while(t--){
		ll k; SI(k);
		k=k-1;
		ll res=0;
		if(k%4==0) res=192;
		else if(k%4==1) res=442;
		else if(k%4==2) res=692;
		else res=942;
		res+= (k/4)*1000;
		cout<<res<<endl;
	}
	return 0;
}
