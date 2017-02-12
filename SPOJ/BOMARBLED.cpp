#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	while(true){
		int n; scanf("%d", &n);
		if(n==0) break;
		int ans = 5 + 7*(n-1) + (3*(n-1)*(n-2))/2;
		printf("%d\n", ans);
	}
	return 0;
}
