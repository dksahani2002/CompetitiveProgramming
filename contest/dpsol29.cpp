#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
const int mod=1e9+7;
vector<int> rec(vector<int>&v){
    vector<int>temp,ans;

    for(int i=0;i<v.size();i++){
        if(temp.empty() || temp.back()<v[i]){
            temp.push_back(v[i]);

        }else{
            auto it=lower_bound(temp.begin(),temp.end(),v[i]);
            *it=v[i];
        }
        ans.push_back(temp.size());
    }
    return ans;
}
void solve()
{
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int>lis=rec(v);
    reverse(v.begin(),v.end());
    vector<int>lds=rec(v);
    reverse(lds.begin(),lds.end());
    int ans=0;
    for(int i=0;i<n;i++){
       if(lis[i]!=1 || lds[i]!=1 ) ans=max(ans,lis[i]+lds[i]-1);
    }
    // cout<<ans<<endl;
    if(ans<3 || lis[n-1]==n || lds[n-1]==n)cout<<-1<<endl;
    else cout<<n-ans<<endl;


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