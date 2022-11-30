#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve()
{
    int n,k,a;
    cin>>n>>k>>a;
    int m;cin>>m;
    vector<int>v(m);
    for(int i=0;i<m;i++)cin>>v[i];
    if(((n+1)/(a+1))<k){
        cout<<-1<<endl;
        return;
    } 
    set<int>st;
    st.insert(0);
    st.insert(n+1);
    int res=(n+1)/(a+1);     
    for(int i=0;i<m;i++){
        auto it=st.lower_bound(v[i]);
        if(*it==v[i])continue;
        auto left=it;left--;
        auto right=it;
        res-=(*right-*left)/(a+1);
        res+=(*right-v[i])/(a+1);
        res+=(v[i]-*left)/(a+1);
        // cout<<*left<<" "<<*right<<endl;
        if(res<k){
            cout<<i+1<<endl;
            return;
        }
         st.insert(v[i]);
    }
    cout<<-1<<endl;
    
}
signed main()
{
    int t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}