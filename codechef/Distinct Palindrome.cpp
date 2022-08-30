#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n,x;
    cin>>n>>x;
    string s(n,'a');
    int l=0,r=n-1;
    int k=0;
    map<int,int>mp;
     while(l<=r){
        if(k<x){
            s[l]='z'-k;
            s[r]='z'-k;
            mp[s[l]-'a']++;
              mp[s[r]-'a']++;
            l++;
            r--;
            k++;
        }else{
            k=0;
        }
        

     }
    //  if(l==r)mp[s[l]-'a']++;
     if(mp.size()!=x){
        cout<<-1<<endl;
        return;
     }
    cout<<s<<endl;
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