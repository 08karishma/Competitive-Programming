#include <iostream>
#include <cstring>
#include <vector>
#define f first
#define s second
#define MAX 10001
using namespace std;

vector<int> primes;
int isPrime[MAX];
int cnt;	

void seive(){
	for(int i=1; i<MAX; i++) isPrime[i]=1;
	for(long long i=2; i*i<MAX; i++){
		if(isPrime[i]){
			for(long long j=2*i; j<MAX; j+=i){
				isPrime[j]=0;
			}
		}
	}
	for(int i=2; i<MAX; i++){
		if(isPrime[i]){
			cnt++;
			if(cnt%100==1) {
				primes.push_back(i);
			}
		}
	}
}

void segSeive(){
	int lim  = MAX;
	int low=lim, high=2*lim;
	while(low<100000001){
		for(int i=1; i<MAX; i++) isPrime[i]=1;
		for(int i=0; i<primes.size(); i++){
			int lolim = low/primes[i];
			for(int j=lolim*primes[i]; j<high; j+=primes[i]){
				if(j<low) continue;
				isPrime[j - low]=0;
			}
		}
		for(int i=0; i<MAX; i++){
			if(isPrime[i]){
				cnt++;
				if(cnt%100==1) {
					primes.push_back(i+low);
				}
			}
		}
		low+=lim;
		high+=lim;
		if(high>=100000001) high=100000001;
	}
}

int main() {
	cnt=0;
	seive();
	segSeive();
	for(int i=0; i<primes.size(); i++){
		printf("%d\n", primes[i]);
	}
	return 0;
}
