#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
void solve()
{
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];     
    int ans=0;
    stack<int>st;
    for(int i=0;i<n;i++){
        while(!st.empty() && v[i]>v[st.top()]){
            int x=v[st.top()];
            st.pop();
            if(st.empty())break;
            ans+=(min(v[i],v[st.top()])-x)*(i-st.top()-1);
        }
        st.push(i);
    }
    cout<<ans<<endl;
}
signed main()
{
    fast;
    int t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}