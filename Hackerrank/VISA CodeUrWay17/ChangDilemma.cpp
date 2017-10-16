#include <bits/stdc++.h>
#define f first
#define s second
#define MAXN 17
#define ll long long
#define INF -1e+16
#define MOD 1000000007
#define rep(i, start, end) for(int i=start; i<end; i++)

using namespace std;
ll arr[MAXN];
ll n,k;
ll dp[131074][2][21];

ll helper(int y, int z, int m){
	int x=__builtin_popcount(y);
	if(x==n && m<=k) return 1;
	else if(x==n) return 0;
	if(m>k) return 0;
	if(dp[y][z][m]!=-1) return dp[y][z][m];
	if(z==1){
		ll ans=0;
		rep(i,0,n){
			if((1<<i)&y) continue;
			ans+=helper(y+(1<<i), z, m+abs(arr[x]-(i+1)));
		}
		return dp[y][z][m]=ans;
	} 
	else{
		ll ans=0;
		rep(i,0,n){
			if((1<<i)&y || arr[x]<(i+1)) continue;
			if(arr[x]==(i+1)) ans+=helper(y+(1<<i), 0, m+abs(arr[x]-(i+1)));
			else ans+=helper(y+(1<<i), 1, m+abs(arr[x]-(i+1)));
		}
		return dp[y][z][m]=ans;
	}
}

int main()
{
	// cout << 20*262145*2*21<<endl;
	int t; cin >> t;
	while(t--){
		memset(dp,-1,sizeof(dp));
    	cin >> n >>k;
    	rep(i,0,n) cin >> arr[i];
    	cout << (helper(0,0,0)-1) << endl;
	}
	// int n; cin >> n;
	// rep(i,0,n) cin >> arr[i];

	// int ans=0;


    return 0;
}