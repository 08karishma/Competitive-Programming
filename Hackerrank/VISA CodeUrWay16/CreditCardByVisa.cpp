#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

vector<int> adj[10];
int indeg[10];
int vis[10];

int main() {
    int t; cin>>t;
    while(t--){
        for(int i=0; i<10; i++){
            adj[i].clear(); indeg[i]=0; vis[i]=0;
        }
        int m; cin>>m;
        string cards[m];
        for(int i=0; i<m; i++){
            string s; cin>>s;
            cards[i]=s;
            for(int i=0; i<s.length()-1; i++){
                int x = s[i]-'0'; int y=s[i+1]-'0';
                if(x!=y){
                    adj[x].push_back(y); indeg[y]++;
                }
            }
        }
        
        int flag=1; 
        
        int cnt=0, allVis=0;
        for(int i=0; i<10; i++){
            if(indeg[i]==0) cnt++;
        }
        if(cnt!=1) flag=0;
        
        vector<int> vec;
        queue <int> q;
        for(int i=0; i<10; i++){
            if(indeg[i]==0){
                q.push(i); vis[i]=1;
            }
        }
        
        //for(int i=0; i<10; i++) cout<<indeg[i]<<" ";
        //cout<<endl;
        
        while(flag && !q.empty()){ 
            
            int u=q.front(); //cout<<u<<endl;
            q.pop();
            vec.push_back(u);
            for(int i=0; i<adj[u].size(); i++) indeg[adj[u][i]]--;
            //for(int i=0; i<10; i++) cout<<indeg[i]<<" ";
            //cout<<endl;
            cnt=0, allVis=1;
            for(int i=0; i<10; i++){
                if(vis[i]==0) allVis=0;
                if(vis[i]==0 && indeg[i]==0) cnt++;
            }
            if(allVis) break;
            if(cnt!=1){
                flag=0; break;
            } 
            
            for(int i=0; i<10; i++){
                if(vis[i]==0 && indeg[i]==0){
                    q.push(i); vis[i]=1;
                }
            }            
        }
                
        if(flag==0) {
            cout<<-1<<endl;
        }
        else{
            unordered_map<int, int> mp;
            for(int i=0; i<10; i++) mp[vec[i]] = i;
            //for(int i=0; i<vec.size(); i++) cout<<vec[i]<<" ";
            for(int i=0; i<m; i++){
                for(int j=0; j<cards[i].size(); j++){
                    int x = cards[i][j]-'0';
                    cout<<mp[x];
                }
                cout<<endl;
            }
        }
        cout<<endl;
    }
    return 0;
}
