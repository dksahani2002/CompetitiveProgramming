#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
int theMagicalGuess(vector<int>&arr){
    vector<int>v=arr;
    int m=(v[2]+v[3]+v[4]-v[1]-4*v[0])/13;
    int ans=m-v[0];
    return ans;
}
void solve()
{
    int n=5;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    cout<<theMagicalGuess(v)<<endl;
}
signed main()
{
    fast;
    int t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}