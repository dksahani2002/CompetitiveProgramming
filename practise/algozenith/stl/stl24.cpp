#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve()
{
    int n;cin>>n;
    vector<int>v1(n),v2(n),v3(n);
    for(int i=0;i<n;i++)cin>>v1[i];
    for(int i=0;i<n;i++)cin>>v2[i];
    for(int i=0;i<n;i++)v3[i]=v1[i]-v2[i];
    // multiset<int>st;
    sort(v3.begin(),v3.end());
    int ans=0;
    for(int i=0;i<n;i++){
        // auto it= st.find(v3[i]);
        // int temp=distance(st.begin(),it);
        // ans+=temp;
        // if(it!=st.end() ){
        //     ans--;
        // }
        // st.insert(v3[i]);
        int temp=upper_bound(v3.begin(),v3.end(),-v3[i])-v3.begin();
        ans+=max(0LL,i-temp);
    }
    cout<<ans<<endl;
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