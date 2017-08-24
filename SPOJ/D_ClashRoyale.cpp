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

ll M, N;
ll K[MAXN];
ll L[MAXN];
ll A[MAXN][MAXK];
ll C[MAXN][MAXK];

void fill(int pos, ll cur_m, ll cur_a, vector<int> &vec, map<ll, ll> &mp){
    if(pos==4){
        if(cur_m > M) return;
        if(mp.find(cur_m)==mp.end()) mp[cur_m] = cur_a;
        else mp[cur_m] = max(mp[cur_m], cur_a);
        return;
    }
    // cout<<vec.size()<<endl;
    ll ind = vec[pos];
    ll curl = L[ind];
    ll tot = 0; 
    while(curl<=K[ind]){
        fill(pos+1, cur_m+tot, cur_a+A[ind][curl], vec, mp);
        tot += C[ind][curl]; curl++;
    }
}

ll meet_in_the_Middle(map<ll, ll> &mp3, map<ll, ll> &mp4){
    map<ll, ll> mp1, mp2;
    //iterate through mp3 in increasing order of coins
    //add only those in mp1 where more power is there for more coins
    ll thresh = -1;
    for(auto it=mp3.begin(); it!=mp3.end(); it++){
        if(it->s > thresh){
            mp1[it->f] = it->s;
            thresh = it->s;
        }
    }
    // do same for mp4
    thresh = -1;
    for(auto it=mp4.begin(); it!=mp4.end(); it++){
        if(it->s > thresh){
            mp2[it->f] = it->s;
            thresh = it->s;
        }
    }

    ll ans = 0;

    //for each (coins, power) in mp1, find (<=M-coins, power1) in m2
    for(auto it=mp1.begin(); it!=mp1.end(); it++){
        auto it2 = mp2.upper_bound(M-(it->f));
        if(it2 == mp2.begin()) continue; // all coins in mp2 are > M-mp1Coins
        it2--;
        ans = max(ans, (it->s)+(it2->s));
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
        cin>>M>>N;
        for(int i=0; i<N; i++){
            cin>>K[i]>>L[i];
            for(int j=1; j<=K[i]; j++) cin>>A[i][j];
            for(int j=1; j<K[i]; j++) cin>>C[i][j];
        }

        ll ans = 0;
        for(ll i=0; i<(1LL<<N); i++){
            if(bc(i)!=8) continue;
            vector<int> vec1, vec2;
            for(int j=0; j<N; j++){
                //if jth bit is set in i
                if(i & (1<<j)) {
                    if(vec1.size()<4) vec1.push_back(j);
                    else vec2.push_back(j);
                }
            }
            map<ll, ll> mp1, mp2;
            fill(0, 0, 0, vec1, mp1);
            fill(0, 0, 0, vec2, mp2);
            ans = max(ans, meet_in_the_Middle(mp1, mp2));
        }
        cout<<ans<<endl;
    }

    return 0;
}
