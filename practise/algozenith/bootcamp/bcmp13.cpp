#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve()
{
    int n;cin>>n;
    vector<int>v(3);
    v[0]=2;
    v[1]=3;
    v[2]=5;
    vector<int>ans(n+1);
    ans[0]=1;
    int i=0,j=0,k=0;
    for(int l=1;l<=n;l++){
        int val=min({ans[i]*v[0],ans[j]*v[1],ans[k]*v[2]});
        if(val==ans[i]*v[0])i++;
        if(val==ans[j]*v[1])j++;
        if(val==ans[k]*v[2])k++;
        ans[l]=val;
    }
    // for(auto e:ans)cout<<e<<" ";
    // cout<<endl;
    cout<<ans[n-1]<<endl;
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