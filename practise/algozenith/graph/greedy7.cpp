#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve()
{
    int n;cin>>n;
    vector<int>v(n);
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        sum+=v[i];
    }
    int avg=sum/n;
    sort(v.begin(),v.end());
     int temp=0,ans=0;
     for(auto i:v){
        temp+=(i-avg)*(i-avg);
     }
     ans=temp;
     temp=0;
      for(auto i:v){
        temp+=(i-avg-1)*(i-avg-1);
     }
     ans=min(ans,temp);
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