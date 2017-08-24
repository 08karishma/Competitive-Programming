#include <bits/stdc++.h>
using namespace std;

struct data{
	char type;
	int val, mapp, pos;
};

data d[200001]; //stores all data from all queries in a sorted mannar
data query[200001]; //stores execution order of the queries since we have sorted d
int save[200001]; //save[i]=j means d[j].mapp=save[i], i.e jth data has been mapped to i
int my_set[200001]; //stores the actual set, my_set[i]=1 if save[i] is present in set
int tree[200001];

bool comp(data d1, data d2){
	if(d1.val==d2.val) return d1.pos < d2.pos;
	return d1.val < d2.val;
}

void update(int ind, int x){
	for(; ind<200001; ind+=ind&(-ind)){
		tree[ind]+=x;
	}
}

int read(int ind){
	int ans =0;
	for(; ind>0; ind-=ind&(-ind)){
		ans+=tree[ind];
	}
	return ans;
}

int bin_search(int k){
	int s=0, e=200000;
	while(s<e){
		int m=(s+e)/2;
		int num=read(m);
		if(num>=k) e=m;
		else s=m+1;
	}
	return s;
}

int main()
{
    int q; scanf("%d", &q);
    for(int i=0; i<q; i++){
    	scanf(" %c", &d[i].type);
    	scanf("%d", &d[i].val);
    	d[i].pos = i+1;
    }
    sort(d, d+q, comp);

    //Coordinate Compression
    int cnt=1; 
    d[0].mapp=cnt; int prev = d[0].val;
    save[cnt]=d[0].val;
    for(int i=1; i<q; i++){
    	if(d[i].val==prev){
    		d[i].mapp=cnt;
    	}
    	else{
    		cnt++;
    		d[i].mapp=cnt;
    		save[cnt]=d[i].val;
    		prev=d[i].val;
    	}
    }

    //storing the queries
    for(int i=0; i<q; i++){
    	query[d[i].pos]=d[i]; //d[i].pos is 1-indexed
    }

    cnt=0;
    for(int i=1; i<=q; i++){
    	// cout<<query[i].type<<","<<query[i].val<<","<<query[i].mapp<<endl;
    	if(query[i].type=='I'){
    		if(my_set[query[i].mapp]==0){
    			my_set[query[i].mapp]=1;
    			update(query[i].mapp, 1);
    			cnt++;
    		}
    	}
    	else if(query[i].type=='D'){
    		if(my_set[query[i].mapp]==1){
    			my_set[query[i].mapp]=0;
    			update(query[i].mapp, -1);
    			cnt--;
    		}
    	}
    	else if(query[i].type=='K'){
    		//in this, we need to find the mapp value in BIT for which the number of occurences of 
    		//all value less than it is = K-1
    		if(query[i].val>cnt) printf("invalid\n");
    		else printf("%d\n", save[bin_search(query[i].val)]); 
    	}
    	else{
    		printf("%d\n", read(query[i].mapp-1));
    	}
    }

    return 0;
}
