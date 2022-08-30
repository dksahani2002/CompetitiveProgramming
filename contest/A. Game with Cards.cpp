#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{ 
     int n;cin>>n;
     vector<int>v(n);
     for(int i=0;i<n;i++)cin>>v[i];
     int m;cin>>m;
     vector<int>v2(m);
     for(int i=0;i<m;i++)cin>>v2[i];
     int alice=*max_element(v.begin(),v.end());
     int bob=*max_element(v2.begin(),v2.end());
     if(alice==bob){
         cout<<"Alice\n";
         cout<<"Bob\n";
     }else if(alice>bob){
cout<<"Alice\n";
cout<<"Alice\n";
     }else{
          cout<<"Bob\n";
           cout<<"Bob\n";
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