#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve()
{
    int n;cin>>n;
    vector<string>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    bool check=true;
    int i=0;
    while(i<n){//col
        int j=0;
        for(;j<n;j++){
            if(v[i][j]!='.'){
                i++;
                break;
            } 
        }
        if(j==n){
            cout<<"NO\n"<<endl;
            return;
        }
    }
    i=0;
    while(i<n){//row
        int j=0;
        for(;j<n;j++){
            if(v[j][i]!='.'){
                i++;
                break;
            } 
        }
        if(j==n){
            cout<<"NO\n"<<endl;
            return;
        }
    }
    int l=0,r=0;
    while(l<n && r<n){
        if(v[l][r]!='.'){
            break;
        }
        l++;
        r++;
    }
    if(l==n && r==n){
        cout<<"NO\n";
        return;
    }
    l=0,r=n-1;
    while(l<n && r<n){
        if(v[l][r]!='.'){
            break;
        }
        l++;
        r--;
    }
    if(l==n && r==-1){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n"<<endl;
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