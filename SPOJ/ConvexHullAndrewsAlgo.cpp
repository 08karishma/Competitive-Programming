#include <iostream>
#include <algorithm>
#include <cstring>
#include <math.h>
#define f first
#define s second
#define MAX 100001
using namespace std;

struct point{
	double x, y;
	int index;
	bool operator <(const point &p) const {
		if(x!=p.x) return x < p.x;
		if(y!=p.y) return y < p.y;
		return index < p.index;
	}
};

int n, hull_size; 
point P[MAX];
point hull[2*MAX];

bool comp(point p1, point p2){
	if(p1.y!=p2.y) return p1.y<p2.y;
	return p1.x<p2.x;
}

//returns cross product of BA and CA vectors
double cross(point a, point b, point c){
	return (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
}

void findHull(){
	sort(P, P+n);
	int k=0;
	//build lower hull
	for(int i=0; i<n; i++){
		if(i>0 && P[i].x==P[i-1].x && P[i].y==P[i-1].y) continue;
		while(k>=2 && cross(hull[k-2], hull[k-1], P[i])<=0) k--;
		hull[k++]=P[i];
	}
	int t=k+1;
	//build upper hull
	for(int i=n-2; i>=0; i--){
		if(i>0 && P[i].x==P[i-1].x && P[i].y==P[i-1].y) continue;
		while(k>=t && cross(hull[k-2], hull[k-1], P[i])<=0) k--;
		hull[k++]=P[i];
	}
	hull_size=k;
	//the hull will now contain the complete closed polygon eg, ABCDA
}

int main() {
	int t; scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			scanf("%lf%lf", &P[i].x, &P[i].y);
			P[i].index=i+1;
		}
		findHull();
		double circumf=0;
		for(int i=0; i<hull_size-1; i++){
			double temp = (hull[i+1].x-hull[i].x)*(hull[i+1].x-hull[i].x);
			temp += (hull[i+1].y-hull[i].y)*(hull[i+1].y-hull[i].y);
			temp = sqrt(temp);
			circumf += temp;
		}
		printf("%0.2f\n", circumf);

		//find bottommost point
		int bmst = 0;
		for(int i=1; i<hull_size; i++){
			if(hull[bmst].y>hull[i].y) bmst=i;
			else if(hull[bmst].y==hull[i].y && hull[bmst].x>hull[i].x) bmst=i;
		}
		int i=bmst;
		if(hull_size==1) hull_size=2;
		do{
			printf("%d ", hull[i].index);
			i=(i+1)%(hull_size-1);
		}while(i!=bmst);
		
		printf("\n\n");
	}
	return 0;
}