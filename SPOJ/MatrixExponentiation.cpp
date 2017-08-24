#include <iostream>
#include <cstring>
#include <vector>
#include <math.h>
#define MAX 10
#define mod 1000000000
using namespace std;

int n, size;
long long c[MAX], b[MAX];

struct Matrix{
	long long X[MAX][MAX];
	void init(){
		memset(X, 0, sizeof X);
		for(int i=0; i<MAX; i++) X[i][i]=1;
	}
};

void multMat(Matrix &res, Matrix &m1, Matrix &m2){ //res=m1*m2
	memset(res.X, 0, sizeof res.X);
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			for(int k=0; k<size; k++){
				res.X[i][k] += (m1.X[i][j] * m2.X[j][k]);
				res.X[i][k] %= mod;
			}
		}
	}
}

Matrix fast_exp(int x, Matrix &m){
	Matrix res;
	res.init();
	Matrix temp;
	if(x==1) return m;
	if(x>0){
		if(x%2==0){
			temp = fast_exp(x/2, m); //temp=m^(x/2)
			multMat(res, temp, temp); // m=temp^2=(m^(x/2))^2
		}
		else{
			temp = fast_exp(x-1, m);//temp = m^(x-1)
			multMat(res, temp, m); //res=temp*m
		}
	}
	return res;
}

void form_matrix(Matrix &m){
	memset(m.X, 0, sizeof m.X);
	for(int i=1; i<size; i++) m.X[i][i-1]=1;
	for(int i=0; i<size; i++) m.X[i][size-1]=c[size-i-1];	
}

int main() {
	int t; scanf("%d", &t);
	while(t--){
		scanf("%d", &size);
		for(int i=0; i<size; i++) scanf("%lld", &b[i]);
		for(int i=0; i<size; i++) scanf("%lld", &c[i]);
		scanf("%d", &n); n--;
		if(n<size){
			printf("%lld\n", b[n]);
			continue;
		}
		Matrix M;
		form_matrix(M);
		M = fast_exp(n-size+1, M);
		Matrix A; 
		memset(A.X, 0, sizeof A.X);
		for(int i=0; i<size; i++) A.X[0][i]=b[i];
		Matrix res;	
		multMat(res, A, M);
		printf("%lld\n", res.X[0][size-1]);
		
	}
	return 0;
}
