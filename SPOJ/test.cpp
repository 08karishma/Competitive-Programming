#include <iostream>
#include <vector>
#include <cstring>
#include <math.h>
#include <map>
#include <algorithm>
#include <climits>
#define f first
#define s second
#define MAXN 15
#define MAXK 11
#define ll long long
#define bc(x) __builtin_popcount(x)
using namespace std;

ll grid[3001][3001];
int R, C;

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
        cin>>R>>C;
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                grid[i][j] = 1;
            }
        }
        int K; cin>>K;
        while(K--){
            int Ri, Ci; cin>>Ri>>Ci;
            grid[Ri][Ci]=0;
        }
        for(int i=1; i<R; i++){
            for(int j=1; j<C; j++){
                if(grid[i][j]==0) continue;
                grid[i][j] = min(grid[i-1][j], min(grid[i-1][j-1], grid[i][j-1]))+1;
            }
        }
        ll ans = 0;
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                ans += grid[i][j];
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
