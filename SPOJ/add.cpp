#include <iostream>
#include <cstring>
#define f first
#define s second
#define mod 1000000007
using namespace std;

long long num[100001];
int n;
int power[100001];
int dp[100001];

void findAllPowers(){
    long long pow2=1;
    power[0]=pow2;
    for(int i=1; i<100001; i++) {
        pow2*=2; 
        if(pow2>=mod) pow2%=mod;
        power[i]=pow2;
    }
}

long long helper(int i){
    if(i==n-1) return num[i];
    if(dp[i]!=-1) return dp[i];

    long long ans=0, cur=1;
    for(int j=i; j<n; j++){
        cur *= num[j];
        cur%=mod;
        if(j<n-1){
            long long temp = power[n-j-2]*cur;
            // if(i==1) cout<<"temp="<<j<<" "<<n<<endl;
            temp%=mod;
            temp+=helper(j+1);
            temp%=mod;        
            ans += temp;
            ans %= mod;
        }
        else{
            ans += cur;
            ans %= mod;
        }
        // if(i==1) cout<<"cur="<<cur<<" ans="<<ans<<endl;
    }
    return dp[i]=ans%mod;
}

int main()
{
    int t; scanf("%d", &t);
    findAllPowers();
    while(t--){
        scanf("%d", &n);
        memset(dp, -1, sizeof dp);
        for(int i=0; i<n; i++){
            scanf("%lld", &num[i]);
        }
        printf("%lld\n", helper(0));
    }
    return 0;
}