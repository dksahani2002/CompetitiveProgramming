#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;cin>>n;
    vector<int>ans={1};
    for(int i=1;i<=n;i++){
        int carry=0;
        for(int j=0;j<ans.size();j++){
            int p=ans[j]*i+carry;
            carry=p/10;
            ans[j]=p%10;
        }
        while(carry){
            ans.push_back(carry%10);
            carry/=10;
        }
    }
    reverse(ans.begin(),ans.end());
    for(auto x:ans){
        cout<<x;
    }
    cout<<endl;
}

signed main()
{ 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _t=1;
    // cin >> _t;
    while (_t--)
        solve();
}