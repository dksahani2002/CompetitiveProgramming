#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{ 
     int n;cin>>n;
     vector<pair<int,int>>v;
     for(int i=0;i<n;i++){
         int a,b;cin>>a>>b;
         v.push_back(make_pair(a,b));
     }
     sort(v.begin(),v.end());
     vector<pair<int,int>>ans;
     ans.push_back(v[0]);
     for(int i=1;i<n;i++){
         pair<int,int> last=ans[ans.size()-1];
         pair<int,int> cur=v[i];
         if(cur.first<=last.second){
             ans.pop_back();
        //  pair<int,int> temp=v[i];
             
             ans.push_back({min(last.first,cur.first),max(last.second,cur.second)});
         }else{
             ans.push_back(cur);
         }
     }
     for(auto i:ans){
         cout<<i.first<<" "<<i.second<<endl;
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