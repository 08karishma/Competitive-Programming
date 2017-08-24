#include <iostream>
#include <cstring>
#include <stack>
#include <vector> 
using namespace std;

int main() {
    int n; scanf("%d", &n);
    int ans = 0;
    for(int i=0; i<n; i++){
        long long x; scanf("%lld", &x);
        if(x%2) ans++;
    }
    if(ans==0) printf("Second\n");
    else printf("First\n");
    return 0;
}