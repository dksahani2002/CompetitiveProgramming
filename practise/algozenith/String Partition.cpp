#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{ 
     string s;
     cin>>s;
     vector<int>v(26,-1);
     int n=s.size();
     for(int i=0;i<n;i++){
         v[s[i]-'a']=i;
     }
    //   for(int i=0;i<n;i++){
    //     cout<<"check i: "<<s[i]<<" "<<v[s[i]-'a']<<endl;;
    //  }
     int ans=0,len=0;
      for(int i=0;i<n;i++){
          ans=max(ans,v[s[i]-'a']);
          if(ans==i){
              cout<<len+1<<" ";
            //   cout<<"i: "<<i<<" v[s[i]-'a']: "<<v[s[i]-'a']<<endl;
              len=0;
          }else{
              len++;
          }
     }
     cout<<endl; 
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