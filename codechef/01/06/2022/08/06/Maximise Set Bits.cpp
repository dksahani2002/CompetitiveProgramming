#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n,k;
    cin>>n>>k;                                                      
    int totbit=k;
    // for(int i=0;i<32;i++){
    //     if(k&(1<<i)){
    //         totbit+=(1<<i);
    //     }
    // }
    if(n==1){
        int c=0;
        for(int i=0;i<31;i++){
            if(k&(1<<i))c++;
        }
        cout<<c<<endl;
        return;
    }
    int ans=0;
    // int mul=1;
    // while(totbit>0){
    //     if(totbit>=n*mul){
    //         ans+=n;
    //     }
    //     else{
    //         ans+=totbit/(mul);
    //     }  
    //     totbit-=mul*n;
    //     mul*=2;
    // }
    int i=0;
    bool val=true;
    while(val){
        if(k>=(1<<i)*n){
            ans+=n;
            k-=(1<<i)*n;
            val=true;
        }else{
            int cnt=k/((1<<i) );
            k-=cnt*(1<<i);
            ans+=cnt;
            if(k){
                
                k=(1<<i)-k;
                for(int j=0;j<31;j++){
                    if((1<<j)&k)ans-=1;
                }
                ans+=1;
            }
            val=false;
        }
        i++;

    }
    cout<<ans<<endl;
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
