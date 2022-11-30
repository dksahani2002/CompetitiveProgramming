#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
 
void solve()
{
     int n,m,k;
     cin>>n>>m>>k;
     vector<int>bus(n+1);
     vector<int>flight(n+1);
     int dp[m+1][n+1];
     for(int i=0;i<n;i++)cin>>bus[i];
     for(int i=0;i<n;i++)cin>>flight[i];
     for(int f=0;f<=m;f++){
        dp[f][0]=0;
        deque<int>dq;
        dq.push_back(0);
        for(int i=1;i<n;i++){
            if(f==0){
                dp[f][i]=dp[f][i-1]+bus[i-1];
            }else{
                dp[f][i]=dp[f][i-1]+bus[i-1]; 
                dp[f][i]=min(dp[f][i],dp[f-1][dq.front()]+flight[dq.front()]+flight[i]);
                while(!dq.empty() && dp[f-1][dq.back()]+flight[dq.back()] >dp[f-1][i]+flight[i])dq.pop_back();
                dq.push_back(i);
                if(i-dq.front()==k)dq.pop_front();
                // while(!dq.empty() && dq.back()>dp[f-1][i-1]+flight[i-1]){
                //     dq.pop_back();
                // }
                // dq.push_back(dp[f-1][i-1]+flight[i-1]);
                // if(i-k-1>=0 && dq.front()==dp[f-1][i-k-1])dq.pop_front();
                // dp[f][i]=min(dp[f][i], dq.front()+flight[i] );
            }
        }
     }
      
     cout<<dp[m][n-1]<<endl;
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