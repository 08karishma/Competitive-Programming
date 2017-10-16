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
using namespace std;

bool isVowel(char c){
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
    return false;
}

int main()
{
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        int k; cin>>k;
        
        ll vow=0, cons=0;
        int i=0;
        for(i=0; i<k; i++){
            if(isVowel(s[i])) vow++;
            else cons++;
        }
        cout<<(vow*cons);
        
        int start = 0;
        while(i<s.length()){
            if(isVowel(s[start])) vow--;
            else cons--;
            start++;
            if(isVowel(s[i])) vow++;
            else cons++;
            i++;
            cout<<(vow*cons);
        }
        cout<<endl;
    }
    return 0;
}
