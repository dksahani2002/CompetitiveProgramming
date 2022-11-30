#include <bits/stdc++.h>
using namespace std;
#define int long long
int modInv(int b , int m){
     b=b%m;
     for(int x=1;x<m;x++){
         if((b*x)%m==1)return x;
     }

}
int modDiv(int a , int b , int m){
    a=a%m;
    int inv=modInv(b,m);
    return (inv*a)%m;
}
void solve()
{ 
    int n,m;
    cin>>n>>m;
    vector<int>v(n),p(n,0);
    vector<int>pref(n+1,1),suff(n+1,1);
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(i) pref[i]=pref[i-1]*v[i]%m;
        else pref[i]=v[i];
    }
    for(int i=n-1;i>=0;i--){ 
        if(i!=(n-1))suff[i]=suff[i+1]*v[i]%m; 
        else suff[i]=v[i];
    } 
    for(int i=0;i<n;i++){ 
       if(i>0 && i<n-1) p[i]=pref[i-1]*suff[i+1]%m;
       else if(i==0)p[i]=suff[i+1];
       else p[i]=pref[i-1];
        cout<<p[i]<<" ";
    } 
    return;
}

signed main()
{
    int t=1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}