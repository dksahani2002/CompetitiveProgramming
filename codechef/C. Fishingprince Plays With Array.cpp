#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n,m;
    cin>>n>>m;
    int ans=0;
    vector<int>v(n);
    vector<pair<int,int>>a,b;

    for(int i=0;i<n;i++){
        cin>>v[i];
        int cnt=0;
        while(v[i]%m==0){
            cnt++;
            v[i]/=m;
        }
        a.push_back({v[i],pow(m,cnt)});
        // cout<<v[i]<<" "<<cnt<<" ";
    }
    // cout<<endl;
   int k;cin>>k;
   vector<int>v2(k);
   for(int i=0;i<k;i++){
        cin>>v2[i];
        int cnt=0;
        while(v2[i]%m==0){
            cnt++;
            v2[i]/=m;
        }
        b.push_back({v2[i],pow(m,cnt)});
         
   }
    int i=0,j=0;
    while(i<a.size() && j<b.size()){
        if(a[i].first==b[j].first){
            if(a[i].second==b[j].second){
                a[i].second=0;
                b[j].second=0;
                i++;
                j++;
            }else if(a[i].second>b[j].second){
                a[i].second-=b[j].second;
                b[j].second==0;
                j++;
            }else{
                b[j].second-=a[i].second;
                a[i].second==0;
                i++;
            }
        }else{
            cout<<"No\n";
            return;
        }
    }
    cout<<"Yes\n";
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