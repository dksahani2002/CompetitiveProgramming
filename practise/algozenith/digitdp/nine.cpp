#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
void solve()
{
    int n=N;
    int x=X;
    vector<int> v=A;
    vector<int> ans(n);
    set<pair<int,int>> s1,s2;

    for(int i=0; i<n; i++){
        while(s2.size()&&(*s2.begin()).first+x<=v[i]){
            ans[(*s2.begin()).second]=v[i];
            s2.erase(s2.begin());
        }
        while(s1.size()&&(*s1.begin()).first+x<=v[i]){
            s2.insert(*s1.begin());
            s1.erase(s1.begin());
        }
        s1.insert({v[i],i});
    }
    while(s2.size()){
        ans[(*s2.begin()).second]=-1;
        s2.erase(s2.begin());
    }
    while(s1.size()){
        ans[(*s1.begin()).second]=-1;
        s1.erase(s1.begin());
    } 
    return ans;
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