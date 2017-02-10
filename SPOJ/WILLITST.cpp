#include <bits/stdc++.h>
#define si(n) scanf("%d",&n)
#define SI(n) scanf("%lld",&n)
typedef long long ll;
#define rep(i,n) for(int i=0; i<n; i++)
using namespace std;

int main() {
	// your code goes here
	ll n; SI(n);
	ll i=1;
	while(i*2<n){
		i=i*2;
	}
	if(n==1 || i*2==n) cout<<"TAK"<<endl;
	else cout<<"NIE"<<endl;
	return 0;
}
