#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
     int n;
     cin>>n;
     map<int,int>mp;
     vector<int>v(n);
     for(int i=0;i<n;i++){
        cin>>v[i];
        v[i]%=10;
        mp[v[i]]++;
     }
     for(auto i:mp){ 
        for(auto j:mp){
            for(auto k:mp){
                int a=i.first;
                int b=j.first;
                int c=k.first;
                if((a+b+c)%10==3){
                    if(a==b && b==c && mp[a]>2){
                        cout<<"Yes\n";
                        return;
                    }
                    if(a==b && b!=c && mp[a]>1){
                        cout<<"Yes\n";
                        return;
                    }
                    if(a!=b && b==c && mp[b]>1){
                        cout<<"Yes\n";
                        return;
                    }
                    if(a!=c && b==c && mp[b]>1){
                        cout<<"Yes\n";
                        return;
                    }
                    if(a!=b && b!=c && a!=c){
                        cout<<"Yes\n";
                        return;
                    }
                    
                }
            }
        }
     } 
     cout<<"No\n" ;
     return;
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