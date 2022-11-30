#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
vector<vector<int>>multi(vector<vector<int>>gu,vector<vector<int>>gv){
    int n=gu.size();
    vector<vector<int>>res(n,vector<int>(n,1e9));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int temp=1e9;
            for(int k=0;k<n;k++){
                temp=min(temp,max(gu[i][k],gv[k][j]));
            }
            res[i][j]=temp;
        }
    }
    return res;
}
vector<vector<int>>expo(vector<vector<int>>&g,int d){
    int n=g.size();
    vector<vector<int>>res(n,vector<int>(n,1e9));
    for(int i=0;i<n;i++)res[i][i]=0;
    while(d){
        if(d&1){
            res=multi(res,g);
        }
        g=multi(g,g);
        d/=2;
    }
    return res;
}
int minDurability(int n,int m,vector<int>from,vector<int>to,vector<int>temp,int s,int t,int d){
    vector<vector<int>>g(n,vector<int>(n,1e9));
    for(int i=0;i<m;i++){
        int u=from[i]-1;
        int v=to[i]-1;
        int w=temp[i];
        g[u][v]=min(g[u][v],w);
    }
    vector<vector<int>>res=expo(g,d);
    if(res[s-1][t-1]==1e9){
        return -1;
    }
    return res[s-1][t-1];
}
void solve()
{
    int n,m;cin>>n>>m;
    vector<int>fromi(m),toi(m),temp(m);
    for(int i=0;i<m;i++)cin>>fromi[i];
    for(int i=0;i<m;i++)cin>>toi[i];
    for(int i=0;i<m;i++)cin>>temp[i];
    int s,t,d;
    cin>>s>>t>>d;
    cout<<minDurability(n,m,fromi,toi,temp,s,t,d)<<endl;
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