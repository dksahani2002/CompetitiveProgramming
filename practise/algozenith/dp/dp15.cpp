#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int mod=1e9+7;
int n,k;
string s;
vector<int>v;
int dp[1001][1001][3];
int back[1001][1001][3];
int find(int first, int second){
    return (second+1)%3==first;
}
int rec(int i, int cnt,int p){
    if(cnt>k)return -1e9;
    if(i==n)return 0;
    auto &ans= dp[i][cnt][p];
    if(ans!=-1)return ans;
    for(int j=2;j>=0;j--){
         int temp=find(v[i],j)+rec(i+1,cnt+(j!=p),j);
         ans=max(ans,temp);
        if(ans==temp)back[i][cnt][p]=j;
    }
    return ans;
}
string str;
void print(int i, int cnt,int p){
    if(i==n)return;
    int x=back[i][cnt][p];
    if(x==0)str+='P';
    else if(x==1)str+='R';
    else if(x==2)str+='S';
    print(i+1,cnt+((i>0)?(x!=p):0),x);
}
void solve()
{
    cin>>n>>k;
    cin>>s;
    v.clear();
    v.resize(n);
    for(int i=0;i<n;i++){
        if(s[i]=='P')v[i]=0;
        else if(s[i]=='R')v[i]=1;
        else if(s[i]=='S')v[i]=2;
    }
    memset(dp,-1,sizeof(dp));
    int ans=max(rec(0,0,0),rec(0,0,1));
     ans=max(ans,rec(0,0,2));
     cout<<ans<<endl;

     int p;
     if(ans==rec(0,0,2))p=2;
     if(ans==rec(0,0,1))p=1;
     if(ans==rec(0,0,0))p=0;
     print(0,0,p);
    
     cout<<str<<endl;
     str.clear();
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