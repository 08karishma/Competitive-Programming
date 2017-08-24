#include <iostream>
#include <cstring>
#include <math.h>
#define MAX 501
using namespace std;

int n; 
int w_pref[MAX][MAX], m_pref[MAX][MAX];
int partner[2][MAX]; //0 for men, 1 for women
int prop_till[MAX];

int checkPref(int w, int m1, int m2){
	//return 0 is m1 more preferred by w else return 1
	for(int i=0; i<n; i++){
		if(w_pref[w][i]==m1) return 0;
		else if(w_pref[w][i]==m2) return 1;
	}
	return -1;
}

int checkIfExists(){
	for(int m=0; m<n; m++){
		if(partner[0][m]==-1 && prop_till[m]<n-1) return m;
	}
	return -1;
}

int main() {
	int t; scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			int j; scanf("%d", &j); j--;
			for(int k=0; k<n; k++){
				scanf("%d", &w_pref[j][k]);
				w_pref[j][k]--;
			}
		}
		for(int i=0; i<n; i++){
			int j; scanf("%d", &j); j--;
			for(int k=0; k<n; k++){
				scanf("%d", &m_pref[j][k]);
				m_pref[j][k]--;
			}
		}
		memset(partner, -1, sizeof partner);
		memset(prop_till, -1, sizeof prop_till);
		while(1){
			int m = checkIfExists();
			if(m==-1) break;
			int i = prop_till[m];
			int w = m_pref[m][i+1];
			if(partner[1][w]==-1){
				partner[0][m]=w;
				partner[1][w]=m;
			}
			else{
				int prefers = checkPref(w, m, partner[1][w]);
				if(prefers==0){
					partner[0][partner[1][w]]=-1;
					partner[0][m]=w;
					partner[1][w]=m;
				}
			}
			prop_till[m]++;
		}
		for(int i=0; i<n; i++){
			printf("%d ", i+1);
			printf("%d\n", partner[0][i]+1);
		}
	}
	return 0;
}