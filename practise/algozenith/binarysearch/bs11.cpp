#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
 vector<int>v;
 int n,median;
 bool check(int mid){
    int cnt=0;
    int i=0;
    int sum=0;
    for(int j=0;j<n;j++){
        sum+=v[j];
        while(sum>mid && i<=j){
            sum-=v[i];
            i++;
        }
        cnt+=j-i+1;
    }
    return cnt>=(median);
 }
void solve()
{
    cin>>n;
    v.clear();
   v.resize(n);
   int sum=0;
   for(int i=0;i<n;i++){
    cin>>v[i];
    sum+=v[i];
   }
   median=((n*(n+1))/2+1)/2;
   int ans=0;
   int l=0,r=sum;

   while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
   }
   cout<<ans<<endl;
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