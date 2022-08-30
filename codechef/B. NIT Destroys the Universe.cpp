#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin>>n;
    int ans=0;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
   
    int i=0;
    while(i<n){
        int temp=0;
        while(v[i]!=0){
                i++;
                temp=1;
        }
        if(temp)ans++;
        i++;
    }
    if(ans>=2){
        cout<<2<<endl;
        return;
    }
    cout<<ans<<endl;
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