#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
int solve()
{   string t="1028993";
    cout<<stoll(t,nullptr,10)<<endl;
    int n;cin>>n;
    vector<int>a(n),b(n),c(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    for(int i=0;i<n;i++)c[i]=b[i]-a[i];
    // sort(c.begin(),c.end());
    int neg=0,pos=0;
    for(int i=0;i<n;i++){
        if(abs(c[i])%2!=0)return 0;
        if(c[i]<0)neg+=c[i];
        else pos+=c[i];
    }
    if(abs(neg)!=pos)return 0;
    return 1;
}

signed main()
{
    fast;
    int t=1;
    cin >> t;
    while (t--)
    {
       cout<<solve()<<endl;
    }
}