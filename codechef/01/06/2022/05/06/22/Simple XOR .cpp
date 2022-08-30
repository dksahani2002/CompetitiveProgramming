#include<bits/stdc++.h>
using namespace std;

void sol(){
    int a,b;cin>>a>>b;
      if(a&1)
      {
        if(b-a>=4)
        {
            cout<<a+1<<" "<<a+2<<" "<<a+3<<" "<<a+4<<endl;
            
        }
        else{
            cout<<"-1 "<<endl;
        }
         return; 
      }
      else  
      {
        if(b-a>=3)
        {
            cout<<a<<" "<<a+1<<" "<<a+2<<" "<<a+3<<endl;
        }
        else {            cout<<"-1 "<<endl;
        }
        return; 
      } 
}
int main() {
int t;cin>>t;
    while(t--) {
      sol();
    }

    return 0;
}