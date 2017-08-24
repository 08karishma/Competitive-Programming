#include <iostream>
#include <cstring>
#include <math.h>
#include <climits>
using namespace std;

int ans[3][51];
int n,q;
int dp[51][51][51];

int helper(int ind, int s0, int s1){
	if(ind==q && s0==0 && s1==0) return 0;
	if(ind==q) return INT_MIN;
	if(dp[ind][s0][s1]!=-1) return dp[ind][s0][s1];
	int res=INT_MIN;
	int temp;
	if(ans[0][ind]==ans[1][ind] && ans[0][ind]!=ans[2][ind]) {
		temp = helper(ind+1, s0, s1);
		if(temp>=0) res = 1+temp;
		if(s0>0 && s1>0) res = max(res, helper(ind+1, s0-1, s1-1));
	}
	else if(ans[0][ind]==ans[1][ind] && ans[0][ind]==ans[2][ind]){
		if(s0>0 && s1>0) {
			temp = helper(ind+1, s0-1, s1-1);
			if(temp>=0) res= 1+temp;
		}
		res = max(res, helper(ind+1, s0, s1));
	}
	else{
		if(ans[0][ind]==ans[2][ind]) {
			if(s1>0) res = helper(ind+1, s0, s1-1);
			if(s0>0) {
				temp = helper(ind+1, s0-1, s1);
				if(temp>=0) res = max(res, 1+temp);
			}
		}
		else if(ans[1][ind]==ans[2][ind]) {
			if(s0>0) res = helper(ind+1, s0-1, s1);
			if(s1>0) {
				temp = helper(ind+1, s0, s1-1);
				if(temp>=0) res= max(res, 1+temp);
			}
		}
	}
	return dp[ind][s0][s1]=res;
}

int main() {
	std::ios::sync_with_stdio(false);
	int t; cin>>t;
	int cnt=1;
	while(t--){
		cout<<"Case #"<<cnt++<<": ";
		cin>>n>>q;
		for(int i=0; i<n+1; i++){
			for(int j=0; j<q; j++){
				char c; cin>>c;
				if(c=='T') ans[i][j]=1;
				else ans[i][j]=0;
			}
		}
		int scores[n];
		for(int i=0; i<n; i++) cin>>scores[i];
		if(n==2){
			memset(dp,-1,sizeof dp);
			int myScore=helper(0, scores[0], scores[1]);
			cout<<myScore<<endl;
		}
		else if(n==1){
			int match=0;
			for(int j=0; j<q; j++){
				if(ans[0][j]==ans[1][j]) match++;
			}
			cout<<q-abs(scores[0]-match)<<endl;
		}
	}
	return 0;
}