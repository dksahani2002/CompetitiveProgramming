 #include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int rec(int k,vector<int>&v){
    int ans=0,i=0;
    map<int,int>mp;
    for(int j=0;j<v.size();j++){
        mp[v[j]]++;
        while(mp.size()>k){
            if(mp[v[i]]==1)mp.erase(v[i]);
            else mp[v[i]]--;
            i++;
        }
        ans+=(j-i+1);
    }
    return ans;
}

void solve()
{
    int n,k;cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    cout<<(rec(k,v)-rec(k-1,v))<<endl;
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