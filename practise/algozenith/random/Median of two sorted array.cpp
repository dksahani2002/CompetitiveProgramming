#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{ 
  int n,m;
  cin>>n>>m;   
  vector<int>v1;
  for(int i=0;i<n;i++){
      int x;cin>>x;
      v1.push_back(x);
  }
  for(int i=0;i<m;i++){
      int x;cin>>x;
      v1.push_back(x);
  }
  sort(v1.begin(),v1.end());
  if((n+m)%2){
      cout<<v1[(n+m)/2]<<endl;
  }else{
      int i=(n+m)/2;
       cout<<(v1[i]+v1[i-1])/2<<endl;
  }
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