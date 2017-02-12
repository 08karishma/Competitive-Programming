#include <bits/stdc++.h>
#define ll long long
using namespace std;

string addString(string s1, string s2){
	int i=s2.length()-1; int j=s1.length()-1;
	while(i>=0){
		if(s2[i]=='1') s1[j]='6';
		j--; i--;
	}
	return s1;
}

string int2bin(ll n){
	if(n==1) return "1";
	if(n==0) return "0";
	string s= int2bin(n/2);
	int x=n%2;
	s+= x+'0';
	return s;
}

string findNum(ll x, int r){
	if(r==1 && x==1) return "5";
	if(r==1 && x==2) return "6";
	string s1;
	for(int i=0; i<r; i++) s1.append(1,'5');
	string s2= int2bin(x-1);
	return addString(s1, s2);
}

int main() {
	// your code goes here
	int n; scanf("%d", &n);
	while(n--){
		long long k; scanf("%lld", &k);
		double r1 = log2(k/2+1);
		int r = r1;
		long long x = k - 2*((long long)pow(2,r)-1);
		if(x!=0) r=r+1;
		else x=(long long) pow(2,r);
		//r is the number of digits in the number
		cout<<findNum(x, r)<<endl;
	}
	return 0;
}
