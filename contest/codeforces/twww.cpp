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
    map<int,int>mp1;
    for(int j=0;j<=i;j++){
        mp1[v[j]]++;
    }
    int index=-1;
    for(int j=n-1;j>i;j--){
        if(mp1.find(v[j])!=mp1.end()){
            index=j;
            break;
        }
    }
    for(int j=i+1;j<=index && index!=-1;j++){
        mp1[v[j]]++;
    }
    cout<<mp1.size()<<endl;
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