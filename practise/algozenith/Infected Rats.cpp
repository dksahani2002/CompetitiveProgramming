                                                                                                                                                                                                                                                                                                                                                                                                        #include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;cin>>n;
    vector<int>v(n),arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    cout<<"jgsdjgdsak"<<endl;
    int c=0;
    v=arr;
     while(true){
    vector<int>t;
        c++;
    t.push_back(v[0]);
    for(int i=1;i<(int)v.size();i++){
        if(v[i]<v[i-1]){
          t.push_back(v[i]); 
        } 
    }
       
        vector<int>s=t;
        sort(s.rbegin(),s.rend());
        for(int i=0;i<s.size();i++){
            // cout<<s[i]<<" "<<t[i]<<endl;
        }
        if(s==t){
            cout<<"c: "<<c<<endl;
            return 0;
        }
     v=t;
     }
    return 0;
}
