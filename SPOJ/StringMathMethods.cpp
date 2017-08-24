#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string multStrByTwo(string s){
    int n=s.length();
    int carry=0;
    string res="";
    int i=n-1;
    while(i>=0){
        int ans = (s[i]-'0')*2 + carry;
        carry = ans/10;
        ans = ans%10;
        res.append(1, ans+'0');
        i--;
    }
    if(carry!=0){
        string c= to_string(carry);
        reverse(c.begin(), c.end());
        res+=c;
    }
    reverse(res.begin(), res.end());
    i=0;
    while(i<res.length() && res[i]=='0') i++;
    if(i==res.length()) return "0";
    if(i>0) res=res.substr(i, res.length()-i);
    return res;
}

string addStr(string a, string b){
    string res="";
    int carry=0;
    int n1=a.length(), n2=b.length();
    int i=n1-1, j=n2-1;
    while(i>=0 && j>=0){
        int ans = (a[i]-'0')+(b[j]-'0')+carry;
        carry = ans/10;
        ans = ans%10;
        res.append(1, ans+'0');
        i--; j--;
    }
    while(i>=0){
        int ans = (a[i]-'0')+carry;
        carry = ans/10;
        ans = ans%10;
        res.append(1, ans+'0');
        i--; 
    }
    while(j>=0){
        int ans = (b[j]-'0')+carry;
        carry = ans/10;
        ans = ans%10;
        res.append(1, ans+'0');
        j--;
    }
    while(carry>0){
        int ans = carry;
        carry = ans/10;
        ans = ans%10;
        res.append(1, ans+'0');
    }
    reverse(res.begin(), res.end());
    i=0;
    while(i<res.length() && res[i]=='0') i++;
    if(i==res.length()) return "0";
    if(i>0) res=res.substr(i, res.length()-i);
    return res;
}

string subtStr(string a, string b){ //return a-b
    string res="";
    int carry=0;
    int n1=a.length(), n2=b.length();
    int i=n1-1, j=n2-1;
    while(i>=0 && j>=0){
        int a1=a[i]-'0'; int b1=b[j]-'0';
        a1-=carry;
        int ans;
        if(a1>=b1){
            ans=a1-b1; carry=0;
        }
        else{
            a1+=10; ans=a1-b1; carry=1;
        }
        res.append(1, ans+'0');
        i--; j--;
    }
    while(i>=0){
        int a1=a[i]-'0'; 
        a1-=carry;
        int ans;
        if(a1>=0){
            ans=a1; carry=0;
        }
        else{
            a1+=10; ans=a1; carry=1;
        }
        res.append(1, ans+'0');
        i--; 
    }
    reverse(res.begin(), res.end());
    i=0;
    while(i<res.length() && res[i]=='0') i++;
    if(i==res.length()) return "0";
    if(i>0) res=res.substr(i, res.length()-i);
    return res;
}

int main() {
    int t; scanf("%d", &t);
    while(t--){
        string b, c, d;
        cin>>b>>c>>d;
        c = multStrByTwo(c);
        string a = subtStr(c, b);
        a = subtStr(a, d);
        cout<<a<<endl;
    }
    return 0;
} 