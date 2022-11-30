#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
 int n,s;
bool check(int mid){
    int val=mid;
    int sum=0;
    while(mid){
        sum+=mid%10;
        mid/=10;
    }
    return val-sum>=s;
}
void solve()
{
   cin>>n>>s;
     int ans=0;
     int l=1,r=n;
     while(l<=r){
        int mid=l+(r-l)/2;
        if(check(mid)){
            r=mid-1;
        }else{
            ans=mid;
            l=mid+1;
        }
     }
     cout<<n-ans<<endl;
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