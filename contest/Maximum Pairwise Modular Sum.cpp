#include <bits/stdc++.h>
using namespace std;
#define int long long
 
void sol()
{
    // string s;
      int n,m;
      cin>>n>>m;
      set<int>v;
      for(int i=0;i<n;i++){
          int x;cin>>x;
          v.insert(x); 
      } 
      int ans=INT_MIN;
      auto it=v.end();
      --it;
      auto it2=v.end();
      ans=max(ans,2*(*it));
      if(v.size()<=1){
          cout<<2*(*it)<<endl;
          return;
      }else{
          --it2;
          --it2;
          int a=*it;
          int b=*it2;
          ans=max(ans, a+b + (a-b)%m);
          int diff=(b-a)%m;
          if(diff<0)diff+=m;
           
           ans=max(ans,a+b+diff);
      } 
      cout<<ans<<endl;
    return;
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
        sol();
}