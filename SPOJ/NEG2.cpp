#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
using namespace std;

string convert(int n){
	if(n==0) return "0";
	string s="";
	while(n!=0){
		int q= n/-2;
		int r= n%-2;
		if(r<0){
			r+=2;
			q++;
		}
		n=q;
		if(r==0) s+="0";
		else s+="1";
	}
	reverse(s.begin(), s.end());
	return s;
}

int main() {
	int n; si(n);
	cout<<convert(n)<<endl;
	return 0;
}
