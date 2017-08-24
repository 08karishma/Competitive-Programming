#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define INF 100000000
using namespace std;
#define pii pair<int,int>
#define f first
#define s second

struct state{
    int city, length, coins;
    bool operator < (const state &s) const{
        return (s.length<length); //the one with more length considered smaller 
        //since prior que puts largest state at top
    }
};

int N;
vector<int> graph[101];
vector<int> len[101];
vector<int> toll[101];
int vis[101][10001];
int dist[101][10001];

int main(){
    int t; scanf("%d", &t);
    while(t--){
        int K, R; scanf("%d%d%d", &K, &N, &R);

        for(int i=0; i<=N; i++){
            for(int j=0; j<=K; j++){
                dist[i][j]=INF;
                vis[i][j]=0;
            }
        }
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

        priority_queue<state> q;
        state st;
        st.city = 1;
        st.length = 0;
        st.coins = K;
        dist[1][K]=0;
        q.push(st);
        int ans = -1;
        while(!q.empty()){
            state cur = q.top();
            q.pop();
            if(cur.city == N) {
                ans = cur.length; break;
            }
            if(vis[cur.city][cur.coins]) continue;
            vis[cur.city][cur.coins]=1;
            for(int i=0; i<graph[cur.city].size(); i++){
                int nxt_city=graph[cur.city][i];
                int nxt_coins=cur.coins-toll[cur.city][i];
                int nxt_len = cur.length+len[cur.city][i];
                if(nxt_coins>=0 && vis[nxt_city][nxt_coins]==0){
                    if(dist[nxt_city][nxt_coins] > nxt_len){
                        dist[nxt_city][nxt_coins] = nxt_len;
                        st.city = nxt_city;
                        st.coins = nxt_coins;
                        st.length = nxt_len;
                        q.push(st);
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
}