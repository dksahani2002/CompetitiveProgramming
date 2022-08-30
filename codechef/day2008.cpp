#include<bits/stdc++.h> 
using namespace std; 
int main() {
   int n;cin>>n;
   vector<int>v(n);
   map<int,int>mp;
   for(int i=0;i<n;i++){
    cin>>v[i];
    mp[v[i]]++;

   }
   if(n%2){
    cout<<-1<<endl;
    return 0;
   }
   int nn=n/2;
   sort(v.begin(),v.end());
   vector<int>ans;
   for(int i=0;i<n;i++){
      int x=v[i]*3;
      if(mp.find(x)!=mp.end()){
        ans.push_back(v[i]);
        mp[x]--;
        if(mp[x]==0)mp.erase(x);
      }
      if(ans.size()==nn)break;
   }
   if(ans.size()!=nn){
    cout<<-1<<endl;
   }else{
    for(auto i:ans){
      cout<<i<<" ";
    }
    cout<<endl;
   }
}