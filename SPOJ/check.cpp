#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define MOD 1000000007
#define INF 1e18
char s[3][60];
int ans[3];
ll dp[51][51][51];
int q;
ll fans(ll curr,ll l1,ll l2){

    if(l1<0 || l2<0){
        return -INF;
    }
    if(curr==q){
        if(l1==0 && l2==0){
            return 0;
        }
        else{
            return -INF;
        }
    }

    if(dp[curr][l1][l2]!=-1){
        return dp[curr][l1][l2];
    }

    dp[curr][l1][l2]=-INF;
    if(s[0][curr]==s[1][curr]){
        if(s[2][curr]==s[0][curr]){
            dp[curr][l1][l2]=max(dp[curr][l1][l2],1+fans(curr+1,l1-1,l2-1));
            dp[curr][l1][l2]=max(dp[curr][l1][l2],fans(curr+1,l1,l2));
        }
        else{
            dp[curr][l1][l2]=max(dp[curr][l1][l2],1+fans(curr+1,l1,l2));
            dp[curr][l1][l2]=max(dp[curr][l1][l2],fans(curr+1,l1-1,l2-1));  
        }
    }   
    else{
        if(s[0][curr]==s[2][curr]){
            dp[curr][l1][l2]=max(dp[curr][l1][l2],1+fans(curr+1,l1-1,l2));
            dp[curr][l1][l2]=max(dp[curr][l1][l2],fans(curr+1,l1,l2-1));
        }
        else{
            dp[curr][l1][l2]=max(dp[curr][l1][l2],1+fans(curr+1,l1,l2-1));
            dp[curr][l1][l2]=max(dp[curr][l1][l2],fans(curr+1,l1-1,l2));
        }
    }
    return dp[curr][l1][l2];
}
int main()
{
    int testcase;
    cin>>testcase;
    int n;
    int final;
    for(int test=1;test<=testcase;test++){
        cin>>n>>q;
        for(int i=0;i<=n;i++){
            cin>>s[i];
        }   
        for(int i=0;i<n;i++){
            cin>>ans[i];
        }
        if(n==1){
            int cnt=0;
            for(int i=0;i<q;i++){
                if(s[0][i]==s[1][i]){
                    cnt++;
                }
            }
            if(cnt>=ans[0]){
                final=ans[0]+q-cnt;
            }
            else{
                final=cnt+q-ans[0];
            }
            cout<<"Case #"<<test<<": "<<final<<endl;
        }
        else{
            for(int i=0;i<=q;i++){
                for(int j=0;j<=q;j++){
                    for(int k=0;k<=q;k++){
                        dp[i][j][k]=-1;
                    }
                }
            }
            cout<<"Case #"<<test<<": "<<fans(0,ans[0],ans[1])<<endl;    
        }
        
    }
}