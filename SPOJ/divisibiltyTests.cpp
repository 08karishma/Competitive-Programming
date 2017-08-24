#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int num_dig, sum_of_dig;
string num;
bool isDiv[10];
int occDig[10];

bool divBySeven(){
	int check[6] = {1, 3, 2, 6, 4, 5};
	int summ=0; int j=0;
	for(int i=num_dig-1; i>=0; i--){
		summ += (num[i]-'0')*check[j];
		j = (j+1)%6;
	}
	return summ%7==0;
}

bool divTest(int i){
	if(i==1) return true;
	if(i==2) {
		int test = num[num_dig-1]-'0';
		return test%2==0;
	}
	if(i==3){
		return sum_of_dig%3==0;
	}
	if(i==4){
		if(num_dig==1) return ((num[num_dig-1]-'0')%4)==0;
		int test = num[num_dig-1]-'0';
		test += 10*(num[num_dig-2]-'0');
		return (test%4)==0;
	}
	if(i==5){
		return ((num[num_dig-1]-'0')==0 || (num[num_dig-1]-'0')==5) ;
	}
	if(i==6){
		return isDiv[2] && isDiv[3];
	}
	if(i==7){
		return divBySeven();
	}
	if(i==8){
		int test = num[num_dig-1]-'0';
		if(num_dig==1) return (test%8)==0;
		test += 10*(num[num_dig-2]-'0');
		if(num_dig==2) return (test%8)==0;
		test += 100*(num[num_dig-3]-'0');
		return (test%8)==0;
	}
	if(i==9){
		return sum_of_dig%9==0;
	}
}
	

int main() {
	while(cin>>num){
		memset(isDiv, false, sizeof isDiv);
		memset(occDig, 0, sizeof occDig);
		num_dig=num.length();
		sum_of_dig=0;
		for(int i=0; i<num_dig; i++){
			occDig[num[i]-'0']++;
			sum_of_dig += (num[i]-'0');
		}
		int ans=0;
		for(int i=1; i<=9; i++){
			if(divTest(i)) {
				ans+=occDig[i];
				isDiv[i]=true;
				// cout<<i<<" "<<isDiv[i]<<endl;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
