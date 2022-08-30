#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin>>n;
    vector<int>v(n);

    // map<int,int>mp;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    map<int,int>mp;
    int i;
    for( i=n-1;i>=0;i--){
         if(i+1<n && v[i]>v[i+1]){
             break;
         }else{
            mp[v[i]]=i;
         } 
    }
    // cout<<"mp.size(): "<<mp.size()<<endl;

    int ans=0;
   for(int j=0;j<=i;j++){
    if(mp.find(v[j])!=mp.end()){
        ans=max(mp[v[j]],ans);
    }else{
        mp[v[j]]=j;
    } 
   }
    map<int,int>mpl;
    for(int i=0;i<=ans;i++){
        mpl[v[i]]++;
    }
    cout<<mpl.size()<<endl;
    
//    cout<<endl;
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