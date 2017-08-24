#include <iostream>
#include <vector>
#include <cstring>
#include <math.h>
#include <unordered_map>
#include <algorithm>
#include <climits>
#define f first
#define s second
#define MAXN 9
#define MAXK 11
using namespace std;

int M, N;
int K[MAXN];
int L[MAXN];
int A[MAXN][MAXK];
int C[MAXN][MAXK];
int dp[MAXN][1001];

int helper(int cur, int coins_left){
    if(cur>N) return 0;
    int &ans = dp[cur][coins_left];

    if(ans==-1){
        ans = A[cur][L[cur]]+helper(cur+1, coins_left);
        for(int lev=L[cur]; lev<K[cur]; lev++){
            if(C[cur][lev] <= coins_left){
                ans = max(ans, A[cur][lev+1]+helper(cur+1, coins_left-C[cur][lev]));
                coins_left -= C[cur][lev];
            }
            else break;
        }
    }
    return ans;
}

int main()
{

    freopen("inputf.in", "r", stdin); // redirects standard input
    freopen("outputf.in", "w", stdout); // redirects standard output
    std::ios::sync_with_stdio(false);
    int t; cin>>t;
    int cnt=1;
    while(t--){
        cerr<<"case "<<cnt<<endl;
        cout<<"Case #"<<cnt++<<": ";
        memset(dp, -1, sizeof dp);
        cin>>M>>N;
        for(int i=1; i<=N; i++){
            cin>>K[i]>>L[i];
            for(int j=1; j<=K[i]; j++) cin>>A[i][j];
            for(int j=1; j<K[i]; j++) cin>>C[i][j];
        }
        cout << helper(1, M) << endl;
    }

    return 0;
}
