#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
const int mod=1e9+7;
 vector<int>v;
int rec(int i, int incdec,int prev){
    if(i>=n)return 1;
    int ans=0;
    if(prev==-1 || incdec){
       if(prev==-1) ans+=rec(i+1,incdec,i)+rec(i+1,!incdec,i)+rec(i+1,incdec,prev);
       else if(v[i]>v[prev] && (v[i]-v[prev])<=k) ans+=rec(i+1,incdec,i)+rec(i+1,!incdec,i)+rec(i+1,incdec,prev);
       else ans+=rec(i+1,incdec,prev)+rec(i+1,!incdec,i);
    }else{
        if(v[i]<v[prev] && v[prev]-v[i]<=k)ans+=rec(i+1,0,i)+rec(i+1,0,prev);
        else ans+=rec(i+1,0,prev);
    }
    return ans;
    
}
void solve()
{
    cin>>n>>k;
    v.clear();
    v.resize(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<rec(0,1,-1)<<endl;

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