#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{ 
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    int i=0;
    int count=0;
    while(i<n-1){
        if(v[i]==v[i+1]){
            count++;
        }
        i++;
    }
    cout<<n-count<<endl;
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