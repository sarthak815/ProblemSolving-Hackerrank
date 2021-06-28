#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    stack<int> st1;
    stack<int> st2;
    int n,q,n1;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>q;
        if(q==1){
            cin>>n1;
            st1.push(n1);
        }
        else{
            if(st2.empty()){
                while(!st1.empty()){
                    st2.push(st1.top());
                    st1.pop();
                }
            }
            
            if(q==2)
                st2.pop();
            if(q==3)
                cout<<st2.top()<<endl;
        }
    }
    
    return 0;
}
