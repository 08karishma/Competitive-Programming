#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;

vector<int> tree[100001];
int n;
int dp[100001][2];

int helper(int node, int parent, int flag){
    
    if(dp[node][flag]!= -1) return dp[node][flag];
    if(flag==1) {//if node is in the vertex cover
        int ans1=1;
        for(int i=0; i<tree[node].size(); i++){
            if(tree[node][i]!=parent){
                ans1 += min(helper(tree[node][i], node, 1), helper(tree[node][i], node, 0)) ;
            }
        }
        return dp[node][flag] = ans1;
    }
    else {// if not in cover
        int ans2=0;
        if(tree[node].size()==0) return dp[node][flag] = INT_MAX;
        for(int i=0; i<tree[node].size(); i++){
            if(tree[node][i]!=parent){
                ans2 += helper(tree[node][i], node, 1);
            }
        }
        return dp[node][flag] = ans2;
    }
}

int main() {
    int t; scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i=1; i<=n; i++) tree[i].clear();
        for(int i=1; i<=n-1; i++){
            int x, y; scanf("%d%d", &x, &y);
            tree[x].push_back(y);
            tree[y].push_back(x);
        }
        memset(dp, -1, sizeof(dp));
        int ans = min(helper(1, -1, 1), helper(1, -1, 0));
        for(int i=1; i<=n; i++){
            if(tree[i].size()==1) ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}