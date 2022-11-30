#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{int n;
cin>>n;
vector<int>v(n);
for(int i=0;i<n;i++)cin>>v[i];
int count=0,maxcount=0;
for(int i=0;i<n;i++){
    maxcount=max(maxcount,v[i]);
    if(i+1==maxcount){
        count++;
    }
}
 cout<<count<<endl;    
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