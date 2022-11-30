#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
string s;
int rec(int l, int r,int cnt){
    if(l>r)return 0;
    int ans=(cnt+1)*(cnt+1)+rec(l+1,r,0);
    for(int i=l+1;i<=r;i++){
       if(s[i]==s[l]) ans=max(ans,rec(l+1,i-1,0)+rec(i,r,cnt+1));
    }
    return ans;
}
void solve()
{
    int n;cin>>n;
    cin>>s;
    cout<<rec(0,n-1,0)<<endl;
}
signed main()
{
    int t=1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}