#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    priority_queue <int, vector<int>, greater<int> > pq;
    int n;
    cin>>n;
    int c,k;
    vector<int> v1;
    for(int i=0;i<n;i++){
        cin>>c;
        switch(c){
            case 1:
                cin>>k;
                pq.push(k);
                break;
            case 2:
                cin>>k;
                v1.push_back(k);
                break;
            case 3:
                while(std::count(v1.begin(), v1.end(), pq.top())) {
                    v1.erase(std::remove(v1.begin(), v1.end(), pq.top()), v1.end());
                    pq.pop();
                
                }
                if(!pq.empty())
                    cout<<pq.top()<<endl;
                break;
            default:
                break;
        }
    
        
    }  
    return 0;
}
