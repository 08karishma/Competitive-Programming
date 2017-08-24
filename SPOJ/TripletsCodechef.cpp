#include <iostream>
#include <cstring>
#include <climits>
#define f first
#define s second
#define MAX 100001
using namespace std;

int n;
int energy[21][3];
int dp[21][3];

int helper(int start, int prev){
    if(start==n) return 0;
    if(prev!=-1 && dp[start][prev]!=-1) return dp[start][prev];
    int ans = INT_MAX;
    for(int i=0; i<3; i++){
        if(i==prev) continue;
        ans = min(ans, energy[start][i]+helper(start+1, i));
    }
    return dp[start][prev]=ans;
}

int main(){
    int t; scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        memset(dp, -1, sizeof dp);
        for(int i=0; i<n; i++){
            scanf("%d%d%d", &energy[i][0], &energy[i][1], &energy[i][2]);
        }
        printf("%d\n", helper(0, -1));
    }
    return 0;
}