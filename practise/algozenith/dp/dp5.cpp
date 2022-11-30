#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
    string s,t;
// bool rec(string s1, string s2){
//     if(s1.compare(s2)==0)return true;
//     if(s1.size()<=1)return false;
//     int n=s1.length(); 
//     string key=s1+' '+s2;
//     if(mp.find(key)!=mp.end())return mp[key];
//     for(int i=1;i<n;i++){
//         if(rec(s1.substr(0,i),s2.substr(n-i)) && rec(s1.substr(i),s2.substr(0,n-i))) return true;   if(rec(s1.substr(0,i),s2.substr(0,i)) && rec(s1.substr(i ),s2.substr(i )))return true;
//     }
//     return mp[key]= false;
// }
int dp[41][41][41];
bool rec(int l,int r, int i, int j){
    if(l>r || i>j)return false;
    if(l==r)return s[l]==t[i];
    if(dp[l][r][i]!=-1)return dp[l][r][i];
    for(int mid=l;mid<r;mid++){
        int dis1=mid-l;
        int dis2=r-mid;
        if(rec(l,mid,i,i+mid-l) && rec(mid+1,r,j-(r-mid-1),j))return  dp[l][r][i]= true;
        if(rec(l,mid,j-(mid-l),j) && rec(mid+1,r,i,i+(r-mid-1)))return  dp[l][r][i]= true;
    }
    return  dp[l][r][i]= false;
}
void solve()
{
    cin>>s>>t;
    if(s.size()!=t.size()){
        cout<<"No\n";
        return;
    }
    // if(rec(s,t)){
    //     cout<<"Yes\n";
    // }else{
    //     cout<<"No\n";
    // }
    memset(dp,-1,sizeof(dp));
    if(rec(0,s.size()-1,0,t.size()-1)){
        cout<<"Yes\n";
    }else{
        cout<<"No\n";
    }
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