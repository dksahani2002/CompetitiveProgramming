#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{ 
     int n;cin>>n;
     vector<int>v(n);
     for(int i=0;i<n;i++)cin>>v[i];
     int l=0,r=n-1;
     int score=INT_MIN;
     while(l<=r){
         int val=min(v[l],v[r])*abs(r-l);
         score=max(score,val);
         if(v[l]<v[r]){
             l++;
         }else{
             r--;
         }
     }
     cout<<score<<endl;
    return;
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