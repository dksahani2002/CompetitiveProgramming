#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,k;
vector<int>v;
int rec(int i,set<int>st){
    if(i>=n)return st.size()<=k;
    int ans=0;
    if(st.count(v[i])>0){
        ans=rec(i+1,st);
    }else{
        ans+=rec(i+1,st);
        st.insert(v[i]);
        ans+=rec(i+1,st);
    }
    return ans;
}
void solve()
{
    cin>>n>>k;
    v.resize(n);
    for(int i=0;i<n;i++)cin>>v[i];
    set<int>st;
    cout<<rec(0,st)<<endl;
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