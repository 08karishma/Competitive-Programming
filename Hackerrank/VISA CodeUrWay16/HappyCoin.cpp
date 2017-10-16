#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

int N;
ll A[1001];//fees
ll dp[1001][2001];
ll B[1001];

ll helper(int i, ll cur_fee){
    if(i==N) return 0;
    if(dp[i][cur_fee]!=-1) return dp[i][cur_fee];
    if(A[i] > cur_fee) return dp[i][cur_fee] = helper(i+1, cur_fee);
    return dp[i][cur_fee] = max(helper(i+1, cur_fee), B[i]+helper(i+1, cur_fee-A[i]));
}

int main() {
    ll m; cin>>m;
    cin>>N;
    memset(dp, -1, sizeof dp);
    for(int i=0; i<N; i++) cin>>B[i];
    for(int i=0; i<N; i++) cin>>A[i];
    cout<<helper(0, m)<<endl;
    return 0;
}
