#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n,m;
    cin>>n>>m;
    int dp[n][m];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)cin>>dp[i][j];
    for(int j=0;j<m;j++)
        for(int i=1;i<n;i++)dp[i][j]+=(dp[i][j])?dp[i-1][j]:0;
    int ans=-1e9;
    for(int i=0;i<n;i++){
        stack<int>st;
        for(int j=0;j<m;j++){
            while(!st.empty() && dp[i][st.top()]>dp[i][j]){
                int h=dp[i][st.top()];
                st.pop();
                int w;
                if(st.empty()){
                    w=0;
                }else{
                    w=st.top();
                }
                ans=max(ans,h*(j-w-1));
            }
            st.push(j);
        }
        while(!st.empty()){
            int h=dp[i][st.top()];
            st.pop();
            int w;
            if(st.empty()){
                w=0;
            }else{
                w=st.top();
            }
            ans=max(ans,h*(m-w-1));
        }
    }
    cout<<ans<<endl;
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