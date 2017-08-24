#include <iostream>
#include <cstring>
#include <vector>
#include <math.h>
using namespace std;

double a, b, c;

double f(double x){
	return (a*x) + (b*sin(x)) - c;
}

double fdash(double x){
	return a + (b*cos(x));
}

int main(){
	int t; scanf("%d", &t);
	while(t--){
		scanf("%lf%lf%lf", &a, &b, &c);
		double x0 = (c/a);
		int cnt=40;
		while(1){
			double func = f(x0);
			if(cnt<0) break;
			cnt--;
			double x1 = x0 - (func/(fdash(x0)));
			x0 = x1;
		}
		printf("%.6f\n", x0);
	}
}