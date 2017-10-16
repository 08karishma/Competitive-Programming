#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t; cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        int tails[n];
        memset(tails, 0, sizeof tails);
        while(m--){
            string s; cin>>s;
            if(s.length()==4){
                int x; cin>>x;
                tails[x-1] ^= 1;
            }
            else{
                memset(tails, 0, sizeof tails);
            }
            int cnt=0;
            for(int i=0; i<n; i++) if(tails[i]==1) cnt++;
            cout<<cnt<<endl;
        }
        cout<<endl;
    }
    return 0;
}
