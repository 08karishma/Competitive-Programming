#include <iostream>
#include <vector>
#include <cstring>
#include <math.h>
#include <map>
#include <algorithm>
#include <climits>
#define f first
#define s second
#define MAXN 100005
#define ll long long
#define INF -1e+16
#define MOD 1000000007
#define rep(i, start, end) for(ll i=start; i<end; i++)

using namespace std;
ll arr[MAXN];

ll odd[MAXN];
ll even[MAXN];

int main()
{
	// cout << 20*262145*2*21<<endl;
	// int t; cin >> t;
	ll n,q;
	cin >> n >> q;
	rep(i,0,n) {
		cin >> arr[i];
		if(i==0){
			even[i]=arr[i];
		}
		else if(i==1) odd[i]=arr[i];
		else if(i%2==0) even[i]=arr[i]^even[i-2];
		else odd[i]=arr[i]^odd[i-2];
	}

	while(q--){
		ll l,r;
		cin >> l >> r;
		l--;r--;
		if(((l-r+1)%2)==0){
			cout << 0 << endl;
		}
		else{
			if(l%2==0){
				ll ans=even[r]^even[l];
				ans^=arr[l];
				cout << (ans%MOD) << endl;
			}
			else{
				ll ans=odd[r]^odd[l];
				ans^=arr[l];
				cout << (ans%MOD) << endl;
			}

		}
	}
    return 0;
}