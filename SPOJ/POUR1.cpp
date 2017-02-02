#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
	if(a==0) return b;
	return gcd(b%a, a);
}

int main() {
	// your code goes here
	int t; scanf("%d", &t);
	while(t--){
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		if( (c>max(a,b)) || (c % gcd(a, b) != 0) ){
			printf("-1\n"); continue;
		}
		int x=0; int y=0; int ans1=0;
		while(x!=c && y!=c){
			if(x==0) x+=a;
			else if(y==b) y=0;
			else{
				if(y+x > b){
					x-=(b-y); y=b;
				}
				else {
					y=x+y; x=0; 
				}
			}
			ans1++;
		}
		
		x=0; y=0; int ans2=0;
		while(x!=c && y!=c){
			if(y==0) y=b;
			else if(x==a) x=0;
			else{
				if(x+y > a){
					y-=a-x;
					x=a;
				}
				else{
					x=x+y;
					y=0;
				}
			}
			ans2++;
		}
		printf("%d\n", min(ans1, ans2));
	}

	return 0;
}
