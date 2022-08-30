#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n,z;
    cin>>n>>z;
    int ans=0;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    while(z!=0){
        for(int i=0;i<n;i++){
            int temp=v[i];
                 v[i]=(z|v[i]);
                 z=temp&z;
        }
    }
    cout<<*max_element(v.begin(),v.end())<<endl;
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