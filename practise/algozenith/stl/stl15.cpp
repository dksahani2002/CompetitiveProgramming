#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve()
{
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    multiset<int>st;
    for(int i=0;i<n;i++){
        auto it=upper_bound(st.begin(),st.end(),v[i]);
        if(it==st.end()){
            st.insert(v[i]);
        }else{
            st.erase(it);
            st.insert(v[i]);
        }
         
        
    }
    cout<<st.size()<<endl;
    
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