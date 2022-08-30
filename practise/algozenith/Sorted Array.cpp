#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{ 
     int n,k;cin>>n>>k;
     vector<int>v(n);
     for(int i=0;i<n;i++)cin>>v[i];
     sort(v.begin(),v.end());
    auto l=lower_bound(v.begin(),v.end(),k) ;
    auto r=upper_bound(v.begin(),v.end(),k);
    r--;
    if(*l==k && *r==k){
        int a=l-v.begin();
        int b=r-v.begin();

       cout<<a+1<<" "<<b+1<<endl;
        return;
    }else{
         cout<<-1<<endl;
    }

    return;
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