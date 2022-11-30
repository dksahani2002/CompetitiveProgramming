#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
      int n,k;
      cin>>n>>k;
      vector<int>v(n);
      for(int i=0;i<n;i++){
        cin>>v[i];
      }
      int l=0,len=0;
      for(int i=1;i<n;i++){
            if(2*v[i]<=v[i-1]){
                l=i;
            }
            if(i-l>=k){
                len++;
            }
      }
      cout<<len<<endl;
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