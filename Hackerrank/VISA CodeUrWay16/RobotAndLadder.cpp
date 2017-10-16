#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
#define mod 1000000007
using namespace std;

int n, k;
int dp[501][2001];

int helper(int i, int x){
    if(i>n) return 0;
    if(i==n) return 1;
    if(dp[i][x]!=-1) return dp[i][x];
    ll ans = helper(i+1, k);
    if(x>0) ans += helper(i+2, x-1);
    ans %= mod;
    return dp[i][x]= ans;
}

int main() {
    cin>>n>>k;
    memset(dp, -1, sizeof dp);
    cout<<helper(0, k)<<endl;
    return 0;
}
