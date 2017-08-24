#include <iostream>
#include <math.h>
#define MAX 20001
using namespace std;

int n;
int BIT[MAX];

void update(int x){
    x++; //convert from 0-indexed to 1-indexed
    while(x<=n){
        BIT[x]+=1;
        x += x&(-x);
    }
}

int query(int x){
    int ans = 0;
    while(x>0){
        ans += BIT[x];
        x -= x&(-x);
    }
    return ans;
}

int numof_popped(int l, int r){
    l++; r++; //convert from 0-indexed to 1-indexed
    if(l<=r) {
        if(l==1) return query(r);
        else return query(r)-query(l-1);
    }
    return query(n)-query(l-1)+query(r);
}

int main() {
    
    int t; scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        if(n==1){
            printf("1\n");
            continue;
        }
        for(int i=0; i<=n; i++) BIT[i]=0;
        int ind[n+1];
        ind[1]=1;
        update(1);
        for(int i=2; i<=n; i++){
            int cur_ind, prev_ind;
            prev_ind=ind[i-1];
            cur_ind=(prev_ind+1+i)%n;
            int no = numof_popped(prev_ind+1, cur_ind);
            while(no>0){
                // cout<<"no="<<no<<endl;
                prev_ind=cur_ind;
                cur_ind = (cur_ind+no)%n;
                no = numof_popped(prev_ind+1, cur_ind);
            }
            ind[i]=cur_ind;
            update(cur_ind);
            // cout<<i<<" "<<ind[i]<<endl;
        }
        int ans[n];
        for(int i=1; i<=n; i++){
            ans[ind[i]]=i;
        }
        for(int i=0; i<n; i++){
            printf("%d ", ans[i]);
        }
        printf("\n");
    }
    return 0;
}