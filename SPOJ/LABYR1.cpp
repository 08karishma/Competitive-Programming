#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
using namespace std;

int lab[1001][1001];
int r; int c;

bool isVal(int i, int j){
	if(i<0 || j<0 || i>=r || j>=c || lab[i][j]==0) return false;
	return true;
}

pair<int, pair<int,int>> bfs(pair<int,int> p){
	int dep=0;
	stack<pair<int,int>> s1;
	stack<pair<int,int>> s2;
	int visited[r][c]={0};
	s1.push(p); int x=-1; int y=-1;
	while(!s1.empty() || !s2.empty()){
		x=s1.top().first; y=s1.top().second;
		visited[x][y]=1;
		s1.pop();
		if(isVal(x-1,y) && visited[x-1][y]!=1) s2.push(make_pair(x-1,y));
		if(isVal(x,y-1) && visited[x][y-1]!=1) s2.push(make_pair(x,y-1));
		if(isVal(x,y+1) && visited[x][y+1]!=1) s2.push(make_pair(x,y+1));
		if(isVal(x+1,y) && visited[x+1][y]!=1) s2.push(make_pair(x+1,y));
		if(s1.empty()){
			if(!s2.empty()){
				while(!s2.empty()) {
					s1.push(s2.top());
					s2.pop();
				}
				dep++;
			}
		}
	}
	pair<int, pair<int,int>> ans;
	ans.first=dep; ans.second.first=x; ans.second.second=y;
	return ans;
}

int main() {
	int t; si(t);
	while(t--){
		si(c); si(r);	
		pair<int,int> valP=make_pair(-1,-1);
		for(int i=0; i<r; i++){
			for(int j=0; j<c; j++){
				char x; scanf(" %c",&x);
				lab[i][j] = (x=='#') ? 0 : 1;
				if(valP.first==-1 && lab[i][j]==1) valP=make_pair(i,j);
			}
		}
		pair<int, pair<int,int>> p1= bfs(valP);
		int ans;
		if(p1.first==0) ans=0;
		else ans= bfs(p1.second).first;
		printf("Maximum rope length is %d.\n",ans);
	}
	return 0;
}
