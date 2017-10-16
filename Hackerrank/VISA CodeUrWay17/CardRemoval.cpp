#include <iostream>
#include <vector>
#include <cstring>
#include <math.h>
#include <map>
#include <algorithm>
#include <climits>
#define f first
#define s second
#define MAXN 200010
#define ll long long
#define INF -1e+16
#define MOD 1000000007
#define si(n) scanf("%d",&n)
using namespace std;

int main()
{
    int n; cin>>n;
    int ans = 0;
    while(1){
        if(n&1) break;
        ans++; n/=2;
    }
    cout<<ans<<endl;
    return 0;
}
