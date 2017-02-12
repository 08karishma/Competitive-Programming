#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
#define ll long long
using namespace std;

ll dp[65][10];

ll helper(int n, int lim){
	if(n==1) return lim+1;
	if(dp[n][lim]!=-1) return dp[n][lim];
	ll ans=0;
	for(int i=0; i<=lim; i++){
		ans += helper(n-1, lim-i);
	}
	return dp[n][lim]=ans;
}

int main() {
	int t; si(t);
	memset(dp, -1, sizeof(dp));
	while(t--){
		int i; si(i);
		int n; si(n);
		printf("%d %lld\n", i, helper(n, 9));
	}
	return 0;
}
