#include <iostream>
#include <climits>
using namespace std;

int main()
{
	// cout<<"2000000 500"<<endl;

	// int i;
	// cout<<"100 1000 10000"<<endl;
 //    for(int j=1; j<=1000; j++){
 //    	cout<<-j<<" ";
 //    	// for( i=1; i<=5000; i++) {
	//     // 	cout<<"98";
	//     // }cout<<endl;
 //    }
 //    cout<<endl;
    // for(int j=1; j<=4; j++){
    	// for(int i=1; i<=200000; i++){
	    // 	cout<<"3 ";
	    // }
	   //  cout<<endl;
    // }

    int n; cin>>n;
    int prev=0;
    for(int i=0; i<n; i++){
    	int x; cin>>x; cout<<prev+x<<" ";
    	prev = prev+x;
    }
    return 0;
}

1 3 6 9 13 18 23 29 36 45 54 64 76 90 105 