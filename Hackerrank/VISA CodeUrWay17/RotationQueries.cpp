#include <iostream>
#include <vector>
#include <cstring>
#include <math.h>
#include <map>
#include <algorithm>
#include <climits>
#define f first
#define s second
#define MAXN 100010
#define ll long long
#define INF -1e+16
#define MOD 1000000007
#define rep(i, start, end) for(int i=start; i<end; i++)

using namespace std;
int arr[MAXN];
int pre[MAXN];

int main()
{
    int n,c; cin >> n >> c;

    rep(i,0,n){
    	cin >> arr[i];
    	if(i==0) pre[i]=arr[i];
    	else pre[i]=arr[i]+pre[i-1];
    	// pin(pre[i]);
    }
    int R=0,L=0;
    while(c--){
    	int type; cin >> type;
    	if(type==1){
    		int x; cin >> x;
    		R+=x;
    		R%=n;
    	}
    	else if(type==2){
    		int x; cin >> x;
    		L+=x;
    		L%=n;
    	}
    	else{
    		int l,r; cin >> l >> r;
    		l=(l-R+L+n)%n;
    		while(l<0) l+=n;
    		r=(r-R+L+n)%n;
    		while(r<0) r+=n;
    		int res=0;
    		if(l<=r){
    			
    			res=pre[r]-((l>0)?pre[l-1]:0);

    		}
    		else{
    			res=pre[n-1]-pre[l-1]+pre[r];
    		}
    		cout << res << endl;
    	}
    }
    return 0;
}