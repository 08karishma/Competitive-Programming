#include <iostream>
#include <math.h>
#include <cstring>
# define PI 3.1415926535897932384626
using namespace std;

struct complex{
double Re, Im;
};

void FFT(complex *v, int n, complex *temp){
	if(n==1) return;
	complex *ve = temp, *vo = temp + (n/2);
	for(int i=0; i<n/2; i++){
			ve[i]=v[2*i];
			vo[i]=v[2*i+1];
	}
	FFT(ve, n/2, v);
	FFT(vo, n/2, v);
	complex w, z;
	for(int i=0; i<n/2; i++){
			w.Re = cos(2*PI*i/(double)n);
	        w.Im = -sin(2*PI*i/(double)n);
	        //z=w*vo[i]
	        z.Re = w.Re*vo[i].Re - w.Im*vo[i].Im;
	        z.Im = w.Re*vo[i].Im + w.Im*vo[i].Re;
	        v[i].Re = ve[i].Re + z.Re;
	        v[i].Im = ve[i].Im + z.Im;
	        v[i+n/2].Re = ve[i].Re - z.Re;
	        v[i+n/2].Im = ve[i].Im - z.Im;
	}
}

void iFFT(complex *v, int n, complex *temp){
	if(n==1) return;
	complex *ve = temp, *vo = temp + (n/2);
	for(int i=0; i<n/2; i++){
			ve[i]=v[2*i];
			vo[i]=v[2*i+1];
	}
	iFFT(ve, n/2, v);
	iFFT(vo, n/2, v);
	complex w, z;
	for(int i=0; i<n/2; i++){
			w.Re = cos(2*PI*i/(double)n);
	        w.Im = sin(2*PI*i/(double)n);
	        //z=w*vo[i]
	        z.Re = w.Re*vo[i].Re - w.Im*vo[i].Im;
	        z.Im = w.Re*vo[i].Im + w.Im*vo[i].Re;
	        v[i].Re = ve[i].Re + z.Re;
	        v[i].Im = ve[i].Im + z.Im;
	        v[i+n/2].Re = ve[i].Re - z.Re;
	        v[i+n/2].Im = ve[i].Im - z.Im;
	}
}

const int B = 10000, S = 1<<13;
int pw[] = {1, 10, 100, 1000};
long long digit[S];
char s1[S], s2[S];

int main(){
int t; scanf("%d", &t);
while(t--){
		scanf("%s%s", s1, s2);
		int len1 = strlen(s1), len2=strlen(s2);

		complex v1[S], v2[S];
		for(int j=0; j<(int)(len1+3)/4; j++){
			v1[j].Re=0; v1[j].Im=0;
		}
		for(int j=0; j<len1; j++){
			v1[j/4].Re += (double)(s1[len1-1-j]-'0')*pw[j%4];
		}
    	len1 = (len1+3)/4; 
    	for(int j=0; j<(int)(len2+3)/4; j++){
			v2[j].Re=0; v2[j].Im=0;
		}
		for(int j=0; j<len2; j++){
			v2[j/4].Re += (double)(s2[len2-1-j]-'0')*pw[j%4];
		}
    	len2 = (len2+3)/4; 
    	int u = 2;
        for (; ; u++) if (1<<u > (len1+len2+3)) break;
        int n = 1<<u;

    	for(int j=len1; j<n; j++){
    		v1[j].Re=0; v1[j].Im=0;
    	}
    	for(int j=len1; j<n; j++){
    		v2[j].Re=0; v2[j].Im=0;
    	}
		
		complex temp[n];
		FFT(v1, n, temp);
		FFT(v2, n, temp);
		//POINTWISE MULTIPLICATION
		complex c[n];
		for(int i=0; i<n; i++){
		  c[i].Re = v1[i].Re*v2[i].Re - v1[i].Im*v2[i].Im;
		  c[i].Im = v1[i].Re*v2[i].Im + v1[i].Im*v2[i].Re;
		}
		
		iFFT(c, n, temp);
		
		for(int j=0; j<n; j++) digit[j] = (long long)(c[j].Re+0.5);
        for(int j=0; j<n; j++) {
            long long d = digit[j]; digit[j] = 0;
            for (int u = 0; d; d /= B, u++) digit[j+u] += d%B;
        }
        int cut = 1;
        for (int j = n-1; j>=0; --j) {
            if (cut) {
                if (digit[j]) { printf("%d", (int)digit[j]); cut = 0; }
            }
            else printf("%04d", (int)digit[j]);
        }
        if (cut) printf("0");
        puts("");
}

return 0;
}
