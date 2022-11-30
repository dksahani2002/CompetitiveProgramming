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
    sort(v.begin(),v.end());
    int psum=0,cur=1;
    for(int i=0;i<n;i++){
        if(cur<v[i]){
            cout<<cur<<endl;
            return;
        }else{
            psum+=v[i];
            cur=psum+1;
        }
    }
    cout<<cur<<endl;
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