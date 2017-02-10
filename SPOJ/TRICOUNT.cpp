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
		ll n; SI(n);
		ll res=0;
		if(n%2==0){
			res= ((2*n*n*n) + (5*n*n) + (2*n)) / 8;
		}
		else{
			res= ((2*n*n*n) + (5*n*n) + (2*n) - 1) / 8;
		}
		cout<<res<<endl;
	}
	return 0;
}
