#include <bits/stdc++.h>

using namespace std;



int main()
{
    int n,t;
    vector<int> width;
    cin>>n>>t;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        width.push_back(k);
    }
        
    int c1,c2;
    for(int i=0;i<t;i++){
        cin>>c1>>c2;
        int min1=INT_MAX;
        for(int j=c1;j<c2+1;j++){
          
            if(width[j]<min1)
                min1 = width[j];
            
        }
        cout<<min1<<endl;
    }
    
    return 0;
}


