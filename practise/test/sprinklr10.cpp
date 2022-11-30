#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int n,m;
string num,op;
 
int dfs(int i,int plus,int minus){
    if(i==n-1){
        if(plus==0 && minus==0)return num[i]-'0';
        return -1e9;
    }
    int ans=-1e9;
    int sum=0;
    for(int k=i;k<n-1;k++){
        sum*=10;
        sum+=num[k]-'0';
       if(plus>0) {
        int temp=dfs(k+1,plus-1,minus);
        if(temp==-1e9)continue;
        ans=max(ans,sum+temp);

       }
       if(minus>0){
         int temp=dfs(k+1,plus,minus-1);
        if(temp==-1e9)continue;
        ans=max(ans,sum-temp);
       }
    }
    return ans;
}
int dfs2(int i,int plus,int minus){
    if(i==n-1){
        if(plus==0 && minus==0)return num[i]-'0';
        return 1e9;
    }
    int ans=1e9;
    int sum=0;
    for(int k=i;k<n-1;k++){
        sum*=10;
        sum+=num[k]-'0';
       if(plus>0) {
        int temp=dfs2(k+1,plus-1,minus);
        if(temp==1e9)continue;
        ans=min(ans,sum+temp);

       }
       if(minus>0){
         int temp=dfs2(k+1,plus,minus-1);
        if(temp==1e9)continue;
        ans=min(ans,-sum+temp);
       }
    }
    return ans;
}
void solve()
{
    cin>>n>>m;
    cin>>num>>op;
    // int sum=0,ans=-1e9,ans2=1e9;
    // for(int k=0;k<n;k++){
    //     sum*=10;
    //     sum+=num[k]-'0';
    //      ans=max(ans,sum+recmx(k+1,0));
    //      ans2=min(ans2,sum+recmn(k+1,0));
    // }
    sort(num.rbegin(),num.rend());
    int _p=0;
    for(auto ch:op){
        if(ch=='+')_p++;
    }
    cout<<dfs(0,_p,m-_p)<<endl;
    // sort(num.begin(),num.end());
    cout<<dfs2(0,_p,m-_p)<<endl;
    // cout<<ans<<" "<<ans2<<endl;
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