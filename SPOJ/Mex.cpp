#include <iostream>
#include <cstring>
#include <unordered_map>
#define f first
#define s second
#define mod 1000000007
using namespace std;

int main()
{
    int t; scanf("%d", &t);
    while(t--){
        int n; scanf("%d", &n);
        int par1[n], par2[n];
        int isLeaf1[n];
        for(int i=1; i<n; i++){
            int u, v; scanf("%d%d", &u, &v);
            par1[v-1]=u-1;
        }
        for(int i=1; i<n; i++){
            int u, v; scanf("%d%d", &u, &v);
            par2[v-1]=u-1;
        }
        unordered_map<int,int> anc1;    
        for(int i=0; i<n; i++){
            int ans=0;
            int j=i;
            while(j!=0){
                anc1[par1[j]]=1; j=par1[j];
            }
            j=i;
            while(j!=0){
                if(anc1.find(par2[j])!=anc1.end()) ans++;
                j=par2[j];
            }
            printf("%d ", ans);
        }
        printf("\n");
    }
    return 0;
}