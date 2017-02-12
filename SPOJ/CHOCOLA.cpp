#include <bits/stdc++.h>
#define si(n) scanf("%d",&n)
#define SI(n) scanf("%lld",&n)
#define ll long long 
#define SIZE 1001
using namespace std;

ll rows[SIZE];
ll cols[SIZE];
int r; int c;//no of breaks

ll minCost(int r1, int r2, int c1, int c2){
	if(r1==r2){
		ll sum=0;
		for(int i=c1+1; i<=c2; i++){
			sum+=cols[i];
		}
		return sum;
	}
	if(c1==c2){
		ll sum=0;
		for(int i=r1+1; i<=r2; i++){
			sum+=rows[i];
		}
		return sum;
	}
	int i=r1+1;
	for(int k=r1+1; k<=r2; k++){
		if(rows[k]>rows[i]) i=k;
	}
	int j=c1+1;
	for(int k=c1+1; k<=c2; k++){
		if(cols[k]>cols[j]) j=k;
	}
	// cout<<r1<<" "<<r2<<" "<<c1<<" "<<c2<<" "<<i<<" "<<j<<endl;
	if(rows[i]>=cols[j]){
		return rows[i] + minCost(r1, i-1, c1, c2) + minCost(i, r2, c1, c2);
	}
	else{
		return cols[j] + minCost(r1, r2, c1, j-1) + minCost(r1, r2, j, c2);
	}
}

int main() {
	// your code goes here
	int t; si(t);
	while(t--){
		si(c); si(r);
		c--; r--;
		for(int i=1; i<=c; i++) {
			ll x; SI(x); cols[i]=x;
		}
		for(int i=1; i<=r; i++) {
			ll x; SI(x); rows[i]=x;
		}
		printf("%lld\n", minCost(0, r, 0, c));
	}
	return 0;
}
