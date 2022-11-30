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
    stack<int>st;
    v.push_back(-1);
    int ans=0;
    for(int i=0;i<v.size();i++){
        while(!st.empty() && v[st.top()]>v[i]){
            int h=v[st.top()];
            st.pop();
            int w=(st.empty()?i:i-st.top()-1);
            ans=max(ans,h*w);
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