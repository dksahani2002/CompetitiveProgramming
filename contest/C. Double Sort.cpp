#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{ 
     int n;cin>>n;
     vector<int>v(n);
     for(int i=0;i<n;i++)cin>>v[i];
    //  int m;cin>>m;
     vector<int>v2(n),temp;
     for(int i=0;i<n;i++)cin>>v2[i];
    //  int top=max;
     temp=v;
     sort(temp.begin(),temp.end());
     vector<pair<int,int>>ans;
     for(int i=n-1;i>=0;i--){
         if(temp[i]==v[i])continue;
         for(int j=0;j<i;j++){
             if(v[j]==temp[i]){
                 ans.push_back({i+1,j+1});
                 swap(v2[j],v2[i]);
                 swap(v[j],v[i]);
                 break;
             }
         }
          
     }
     temp=v2;
     sort(temp.begin(),temp.end());

     for(int i=n-1;i>=0;i--){
         if(temp[i]==v2[i])continue;
         for(int j=0;j<i;j++){
             if(v2[j]==temp[i]){
                 ans.push_back({i+1,j+1});
                 swap(v2[j],v2[i]);
                 swap(v[j],v[i]);
                 break;
             }
         }
          
     } 
     vector<int>w1,w2;
     w1=v;
     w2=v2;
     sort(w1.begin(),w1.end());
     sort(w2.begin(),w2.end());
     if(w1==v && w2==v2){
         cout<<ans.size()<<endl;
         for(auto i:ans){
             cout<<i.first<<" "<<i.second<<endl;
         }
     }else{
         cout<<-1<<endl;
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