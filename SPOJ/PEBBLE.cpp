#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main() {
    long long n;
    while(scanf("%lld", &n) != EOF){

        long long ans=0, cur=1;
        long long carry=0;
        long long temp;
        while(cur<=n){
            temp = cur+carry;
            ans += (temp%10);
            carry = temp/10;
            cur++;
        }
        cur=n-1;
        while(cur>=1){
            temp = cur+carry;
            ans += (temp%10);   
            carry = temp/10;
            cur--;
        }
        printf("%lld\n", ans);
    }
    return 0;
} 