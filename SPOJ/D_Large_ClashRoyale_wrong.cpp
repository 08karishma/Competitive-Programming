#include <iostream>
#include <vector>
#include <cstring>
#include <math.h>
#include <unordered_map>
#include <algorithm>
#include <climits>
#define f first
#define s second
#define MAXN 15
#define MAXK 11
#define ll long long
#define INF -1e+16
using namespace std;

int M, N;
int K[MAXN];
int L[MAXN];
ll A[MAXN][MAXK];
ll C[MAXN][MAXK];
ll dp[MAXN][MAXN][100001][9];
ll dp2[MAXN][10001][9];

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
        memset(dp, 0, sizeof dp);
        memset(dp2, 0, sizeof dp2);
        cin>>M>>N;
        for(int i=1; i<=N; i++){
            cin>>K[i]>>L[i];
            for(int j=1; j<=K[i]; j++) cin>>A[i][j];
            for(int j=1; j<K[i]; j++) cin>>C[i][j];
        }

        for(int i=N; i>=1; i--){
            for(int j=i; j<=N; j++){
                for(int m=0; m<100001;m++){
                    for(int x=1; x<=8; x++){
                        if(j-i+1 < x) {
                            dp[i][j][m][x] = INF;
                            continue;
                        }
                        // if(i+1<0 || j<0 || m<0 || x<0)cout<<i+1<<" "<<j<<" "<<m<<" "<<x<<endl;
                        ll ans = dp[i+1][j][m][x]; //not selectng this card 
                        ans = max(ans, A[i][L[i]] + dp[i+1][j][m][x-1]); 
                        ll tot = C[i][L[i]];
                        int lev = L[i]+1;
                        while(lev<=K[i] && tot<=m){
                            ans = max(ans, A[i][lev] + dp[i+1][j][m-tot][x-1]);
                            tot += C[i][lev]; lev++;
                        }
                        dp[i][j][m][x] = ans;
                    }
                }
            }
        }

        for(int i=N; i>=1; i--){
            for(int k=1; k<10001; k++){
                for(int x=1; x<=8; x++){
                    if(N-i+1 < x) {
                        dp2[i][k][x] = INF;
                        continue;
                    }
                    if(k==1){
                        dp2[i][k][x] = dp[i][N][100000][x];
                        continue;
                    }
                    ll ans = INF;
                    for(int j=i; j<=N; j++){
                        for(int y=0; y<=x; y++){
                            ans = max(ans, dp[i][j][100000][y] + dp2[j+1][k-1][x-y]);
                        }
                    }
                    dp2[i][k][x] = ans;
                }
            }
        }

        ll coeff = M/100000;
        ll rem = M%100000;
        ll ans = INF;
        for(int j=1; j<=N; j++){
            for(int y=0; y<=8; y++){
                ans = max(ans, dp[1][j][rem][y] + dp2[j+1][coeff][8-y]);
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
