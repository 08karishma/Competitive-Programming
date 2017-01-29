#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
#define ll long long
using namespace std;

int lucky[1001];

bool isLucky(int n){
	int pf=0;
	if(n%2==0){
		pf++;
		while(n%2==0) n=n/2;
	}
	for(int i=3; i<=sqrt(n); i+=2){
		if(n%i==0){
			pf++; if(pf>=3) return true;
			while(n%i==0) n=n/i;
		}
	}
	if(n>2) pf++;
	if(pf>=3) return true;
	return false;
}

void build(){
	int cnt=1;
	int n=30;
	while(cnt<=1000){
		while(!isLucky(n)) n++;
		lucky[cnt]=n;
		n++; cnt++;
	}
}

int main() {
	build();
	int t; si(t);
	while(t--){
		int x; si(x);
		printf("%d\n", lucky[x]);
	}
	return 0;
}
