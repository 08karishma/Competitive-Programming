#include <bits/stdc++.h>
#define si(n) scanf("%d",&n)
#define SI(n) scanf("%lld",&n)
#define ll long long 
#define mod 10000007
using namespace std;

ll findpow(ll n, ll k){
	if(k==1) return n%mod;
	if(k%2==0){
		ll ans = findpow(n, k/2);
		ans *= findpow(n, k/2);
		ans %= mod;
		return ans;
	}
	ll ans = findpow(n, k/2);
	ans *= findpow(n, k/2);
	ans %= mod;
	ans *= (n%mod);
	ans %= mod;
	return ans;
}

int main() {
	while(true){
		ll n; ll k; SI(n); SI(k);
		if(n==0 && k==0) break;
		ll ans = 0;
		ans = findpow(n-1, n-1);
		ans += findpow(n-1, k);
		ans %= mod;
		ans *= 2;
		ans %= mod;
		ans += findpow(n, n);
		ans %= mod;
		ans += findpow(n, k);
		ans %= mod;
		printf("%lld\n", ans);
	}
	return 0;
}
