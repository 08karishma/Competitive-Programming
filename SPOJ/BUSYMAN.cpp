#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
using namespace std;

int main() {
	// your code goes here
	int t; si(t);
	while(t--){
		int n; si(n);
		pair<int,int> dur[n];
		for(int i=0; i<n; i++){
			int x; si(x);
			int y; si(y);
			dur[i].first=y; dur[i].second=x;
		}
		sort(dur, dur+n);
		int flag[1000001]={0};
		int ans=0;
		for(int i=0; i<n; i++){
			int start=dur[i].second; int end=dur[i].first;
			int f=0;
			for(int j=start; j<=end; j++){
				if(flag[j]==1) {
					if (j==start || j==end) continue;
					else f=-1; break;
				}
			}
			if( (flag[start]==1 && flag[end]==1) || f==-1) continue;
			else{
				ans++;
				for(int j=start; j<=end; j++){
					flag[j]=1;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
} 
