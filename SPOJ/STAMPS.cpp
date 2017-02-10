#include <bits/stdc++.h>
#define si(n) scanf("%d",&n)
#define SI(n) scanf("%lld",&n)
typedef long long ll;
#define rep(i,n) for(int i=0; i<n; i++)
using namespace std;

int main() {
	// your code goes here
	int t; si(t);
	int cnt=1;
	while(t--){
		int stp; si(stp);
		int n; si(n);
		int stamps[n];
		rep(i,n) cin>>stamps[i];
		cout<<"Scenario #"<<cnt<<":"<<endl;
		sort(stamps,stamps+n);
		//rep(i,n) cout<<stamps[i]<<" ";
		int sum=0; int i=n-1;
		while(i>=0 && sum<stp){
			sum+=stamps[i];
			i--;
		}
		if(i<0 && sum<stp) cout<<"impossible"<<endl;
		else if(i<0) cout<<n<<endl;
		else cout<<n-i-1<<endl;
		cout<<endl;
		cnt++;
	}
	return 0;
}
