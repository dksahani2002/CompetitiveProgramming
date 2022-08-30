#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int x;cin>>x;
    int y=0 ;
        int idx=0;
        for(int i=0;i<32;i++){ 
            if(x&(1<<i)){ 
                idx++; 
            } 
        }
        if(idx>1){
            for(int i=0;i<32;i++){ 
            if(x&(1<<i)){ 
                 cout<<(1<<i)<<endl;
                 return; 
            } 
            }
        }else{ 
            for(int i=0;i<32;i++){ 
                if(x&(1<<i)){ 
                     y=(1<<i);
                    break; 
                } 
            }
            for(int i=0;i<32;i++){ 
                if(x&(1<<i)){ 
                     continue;
                }else{
                    y+=(1<<i);
                    cout<<y<<endl;
                    return;
                } 

            }
        } 
         
    
    
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}