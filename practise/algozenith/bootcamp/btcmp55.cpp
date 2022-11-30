#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
int kad(vector<int>&v){
    int n=v.size();
    int sum=-1e9,tsum=0;
    for(int i=0;i<n;i++){
        tsum+=v[i];
        sum=max(sum,tsum);
        if(tsum<0)tsum=0;
    }
    return sum;
}
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>v(n,vector<int>(m));
    vector<vector<int>>q=v;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
            q[i][j]=v[i][j];
            if(j)v[i][j]+=v[i][j-1];
        } 
    }
    int ans=-1e9;
   
    for(int i=0;i<m;i++){
        for(int j=i;j<m;j++){
            vector<int>vv;
            for(int k=0;k<n;k++){
                if(i==0)vv.push_back(v[k][j]);
                else vv.push_back((v[k][j]-v[k][i-1]));
            }
            ans=max(ans,kad(vv));
        }
    }
    
    cout<<ans<<endl;
}
signed main()
{
    fast;
    int t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}