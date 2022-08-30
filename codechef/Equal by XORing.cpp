#include <bits/stdc++.h>
using namespace std;
#define int long long
void solution(int a, int b , int n){
     int  cnt=0,tempans=0;
    int ans=0;
    if(a==b){
        cout<<0<<endl;
        return;
    }
    int xx = max(log2(a),log2(b));
    for(int i=xx;i>=0;i--){
        if(b&((1LL)<<i)){
            if(a&((1LL)<<i)){
                
            }else{
                 ans+=((1LL)<<i);
                 
            }
        }else{
            if(a&((1LL)<<i)){
                 ans+=((1LL)<<i);
            } 
        }
     }
     int set_bit=log2(ans);

     if((ans)<=n){
        cout<<1<<endl;
     }else if(n<(1LL<<set_bit)){
        cout<<-1<<endl;
     }else{
        cout<<2<<endl;
     } 
       
}
void solve()
{
    int a,b,n;cin>>a>>b>>n;
    n--;
    
      
        solution(a,b,n);
      
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