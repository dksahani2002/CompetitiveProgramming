#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;cin>>n;
    vector<int>v(n);
    map<int,int>mp;
    for(int i=0;i<n;i++){
        cin>>v[i];
        mp[v[i]]++;
    }
    if((n-mp.size())%2==0){
        cout<<mp.size()<<endl;
    }else{
        cout<<mp.size()-1<<endl;
    }
//     int a,b,c,d;
//     cin>>a>>b>>c>>d;
//     int cnt=0;
//      if(b>a)cnt++; 
//      if(c>a)cnt++;
//      if(d>a)cnt++;
//      cout<<cnt<<endl;
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