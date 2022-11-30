#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve()
{
    // int n;cin>>n;

    string s;cin>>s;
    int n=s.size();
    map<char,int>mp;
    for(int i=0;i<n;i++)mp[s[i]]++;
    
    int c=0;
    for(auto v:mp){
        if(v.second&1){
            c++;
        }
    }
    if(c>1){
        cout<<-1<<endl;
        return;
    }
    int count=0;
    int l=0,r=n-1;
    while(l<r){
        if(s[l]!=s[r]){
            int j=r;
            int k=l;
            while(s[j]!=s[l])j--;
            while(s[k]!=s[r])k++;
            if((r-j)<(k-l)){
                while(j<r){
                   swap(s[j],s[j+1]);
                   count++,j++;
                }
            }else{
                while(k>l){
                    swap(s[k],s[k-1]);
                    count++,k--;
                }
            }
        }
        l++;r--;
    }
    cout<<count<<endl;
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