#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int sum,n,k;
vector<int>v;
int rec(int i, int tot){
    if(tot<0)return 0;
    if(i>=n){
        return (tot==0);
    }
    return rec(i+1,tot-v[i])+rec(i+1,tot);
}
void solve()
{
    cin>>n>>k;
    v.clear();
    v.resize(n);
    sum=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        sum+=v[i];
    }
    if(sum<=2*(k+1)){
        cout<<0<<endl;
        return;
    }
    cout<<pow(n,2)-2*rec(0,k)-2<<endl;
}
signed main()
{
    int t=1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}