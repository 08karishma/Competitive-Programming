/*Actually gP(x) <=> prime[n>>6]&(1<<((n>>1)&31)) depend on prime[]. A short explanation about what's going on:
-We check n/2 because it will convert odd numbers to consectutive integers: 1,3,5,7... -> 0,1,2,3...
-Let k=n/2; then in prime[k/32] we store (after sieve) some integer x, which contains at its binary representation 1 
at position (k%32) iff k is a prime.
-How to do it efficiently enough? Use binary tricks. n>>1 instead of n/2, k&31 instead of k%32, k>>6 instead of k/32. To 
get i-th bit of x: x&(1<<i). The only thing I added to checkPrime — check if x is even or not: (x&1)&&...*/

#include <iostream>
#include <cstring>
#include <vector>
#include <math.h>
#define N 100000000
unsigned int prime[N / 64];
#define gP(n) (prime[n>>6]&(1<<((n>>1)&31)))
#define rP(n) (prime[n>>6]&=~(1<<((n>>1)&31)))
using namespace std;

vector<int> primes;

bool checkPrime (int x) {
	return gP(x); 
}

void sieve()
{
    memset( prime, -1, sizeof( prime ) );

    unsigned int i;
    unsigned int sqrtN = ( unsigned int )sqrt( ( double )N ) + 1;
    for( i = 3; i < sqrtN; i += 2 ) if( gP( i ) )
    {
        unsigned int i2 = i + i;
        for( unsigned int j = i * i; j < N; j += i2 ) rP( j );
    }
    
    primes.push_back(2);
    for(int i=3; i<N; i+=2){
    	if(checkPrime(i)) primes.push_back(i);
    }
}

int main(){
	sieve();
	for(int i=0; i<primes.size(); i++){
		if(i%100==0) cout<<primes[i]<<endl;
	}
}

