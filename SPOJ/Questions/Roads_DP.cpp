#include <iostream>
#include <cstring>
#include <vector>
#include <math.h>
#define INF 100000000
using namespace std;
#define pii pair<int,int>
#define f first
#define s second

int N;
vector<int> graph[101];
vector<int> len[101];
vector<int> toll[101];
int dp[101][10001];

int helper(int city, int coins){

    int &ans = dp[city][coins];
    if(ans==-1){
        if(city==N) ans = 0;
        else{
            ans = INF;
            for(int i=0; i<graph[city].size(); i++){
                if(toll[city][i]>coins) continue;
                ans = min(ans, len[city][i] + helper(graph[city][i], coins-toll[city][i]));
            }
        }
    }
    return ans;
}

int main(){
    int t; scanf("%d", &t);
    while(t--){
        int K, R; scanf("%d%d%d", &K, &N, &R);
        memset(dp, -1, sizeof dp);
        for(int i=1; i<=N; i++){
            graph[i].clear();
            len[i].clear();
            toll[i].clear();
        }
        while(R--){
            int u, v, l, t; scanf("%d%d%d%d", &u, &v, &l, &t);
            if(u==v) continue;
            graph[u].push_back(v);
            len[u].push_back(l);
            toll[u].push_back(t);
        }
        int ans = helper(1, K);
        if(ans==INF) ans=-1;
        printf("%d\n", ans);
    }
}