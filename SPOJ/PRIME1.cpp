#include <bits/stdc++.h>
#define si(n) scanf("%d",&n);
using namespace std;

int prime[100001];

void findAllPrimes(){
	for(int i=0; i<=100000; i++){
		prime[i]=1;
	}
	for(long long i=2; i*i<=100; i++){
		if(prime[i]==1){
			for(long long j=2*i;j<=100000;j+=i){
				prime[j]=0;
			}
		}
	}
}

int main() {
	// your code goes here
	int n; cin>>n;
	findAllPrimes();
	while(n>0){
		int x; si(x);
		int y; si(y);
		int segment[y-x+1];
		for(int i=0; i<=y-x; i++){
			segment[i]=1;
		}
		// memset(segment,1,sizeof(segment));
		for(int i=2; i*i<=y; i++){
			//cout<<prime[i]<<endl;
			if(prime[i]==1){
				for(int j=2*i; j<=y; j+=i){
					if(j>=x) segment[j-x]=0;
				}
			}
		}
		for(int i=0; i<=y-x; i++){
			// cout<<segment[i]<<endl;
			if(segment[i]==1 && i+x!=1) cout<<i+x<<endl;
		}
		cout<<endl;
		n--;
	}
	return 0;
}
