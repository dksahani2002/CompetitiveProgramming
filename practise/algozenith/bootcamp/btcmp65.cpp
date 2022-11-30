#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
void solve()
{
    int n;cin>>n;
    int cnt=0,dig=1;
    while(cnt+pow(2,(dig-1)/2)<n){
        cnt+=pow(2,(dig-1)/2);
        dig++;
    }
    int mid=(dig-1)/2;
    string ans(mid+1,'0');
    ans[0]='1';
    cnt++;
    int d=n-cnt;
    for(int i=0;i<mid+1;i++){
        if(d&(1<<i)){
            ans[mid-i]='1';
        }
    }
    string t=ans.substr(0,dig/2);
    reverse(t.begin(),t.end());
   if(n>1) ans+=t;
   int res=0;
   for(int i=0;i<ans.size();i++){
    if(ans[i]=='1'){
        res+=pow(2,i);
    }
   }
    cout<<res<<endl;
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