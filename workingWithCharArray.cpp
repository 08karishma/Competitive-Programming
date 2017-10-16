#include <iostream>
#include <vector>
#include <cstring>
#include <math.h>
#include <stack>
#include <algorithm>
#include <climits>
#define pii pair<int,int>
#define f first
#define s second
#define MAXN 100001
#define ll long long
#define INF LLONG_MAX
#define MOD 1000000007
using namespace std;

int main()
{   


    char s1[101];
    scanf("%s", s1);
    printf("%s\n", s1);
    cout<<strlen(s1)<<endl;
    cout<<s1<<endl<<endl;

    char s2[101] = "JOHN"; //strlen = 4
    cout<<s2<<endl<<endl;

    char s3[] = "ALEX"; //strlen = 4
    cout<<s3<<endl<<endl;

    //WRONG!
    char s4[4] = {'J', 'O', 'H', 'N'};
    cout<<strlen(s4)<<endl; //garbage
    cout<<s4<<endl<<endl; //prints garbage values

    char s5[5] = {'J', 'O', 'H', 'N', '\0'}; //strlen = 4
    cout<<s5<<endl<<endl;

    //pointer to char
    char c1[5] = "JOHN";
    char *c2 = c1; //c2 can be used similar as c1
    cout<<c2[3]<<endl<<endl; //prints 'N' //strlen(c2)=4

    char *c = "Hello"; //string gets stored as compile time constant
    //c[0] = 'a'; //ERROR!, since c is constant now

    //ERROR!!
    //char s6[4] = "JOHN"; 

    //char s7[10];
    //s7 = "HELLO";

    return 0;
}
