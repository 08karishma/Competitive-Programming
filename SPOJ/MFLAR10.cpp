#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool match(char c1, char c2){
	if(tolower(c1)==tolower(c2)) return true;
	return false;
}

bool isTaut(string s){
	int i=0; char ch=s[0];
	while(i<s.length()){
		while(i<s.length() && s[i]!=' ') i++;
		if(i==s.length()) break;
		i++;
		if(!match(ch, s[i])) return false;
	}
	return true;
}

int main() {
	while(true){
		string s; getline(cin, s);
		if(s=="*") break;
		if(isTaut(s)) printf("Y\n");
		else printf("N\n");
	}
	return 0;
}
