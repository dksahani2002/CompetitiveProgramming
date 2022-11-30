#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
string s,t;
int dp[1001][1001];
int rec(int i, int j){
    if(i>=s.size())return t.size()-j;
    if(j>=t.size())return s.size()-i;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==t[j])return dp[i][j]= 1+rec(i+1,j+1);
    return dp[i][j]= 1+min(rec(i+1,j),rec(i,j+1));
}
void solve()
{
    cin>>s>>t;
    for(int i=0;i<s.size();i++){
        for(int j=0;j<t.size();j++){
            dp[i][j]=-1;
        }
    }
    int res=rec(0,0);
    string ans;
    int i=0,j=0;
    while(res--){
        if(s[i]==t[j]){
            ans+=s[i];
            i++;j++;
        }else if(rec(i+1,j)<rec(i,j+1)){
            ans+=s[i];
            i++;
        }else{
            ans+=t[j];
            j++;
        }
    }
    cout<<ans<<endl;
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