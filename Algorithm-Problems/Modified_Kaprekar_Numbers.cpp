#include <bits/stdc++.h>

using namespace std;

bool kapcheck(int n){
    long long n1 = n;
    long long pow1 = n1*n1;

    string s = to_string(pow1);
    long len1 = s.length();
    long sum = 0;
    long a=0;
    long b = 0;

    for(long i = 0;i<len1;i++){
        if(i<len1/2){
            char p = s[i];
            long k = p - '0'; 
            a = a*10+k;
        }
        else{
            char p = s[i];
            long k = p - '0'; 
            b = b*10+k;
        }
    }

    sum = a+b;
    if(sum==n)
        return true;
    else
        return false;
}

void kaprekarNumbers(int p, int q) {
    int cnt = 0;
    for(int i=p;i<=q;i++){
        if(kapcheck(i)){
            cout<<i<<" ";
            cnt++;
        }
    }
    if(cnt==0)
        cout<<"INVALID RANGE";
}

int main(){
    int n1 = 1;
    int n2 = 99999;
    kaprekarNumbers(n1,n2);
    
}