#include <bits/stdc++.h>
#define si(n) scanf("%lld", &n)
#define ll long long
// #define pi 3.1415926535
using namespace std;

int main() {
	int t; si(t);
	while(t--){
		double n; scanf("%lf",&n);
		if(n<=1){
			printf("1\n"); continue;
		}
		double e=exp(1);
		double ans= ((log10(2*M_PI*n))/2) + (n*log10(n/e)) + 1;
		ll res=floor(ans);
		printf("%lld\n", res);
	}
	return 0;
}
