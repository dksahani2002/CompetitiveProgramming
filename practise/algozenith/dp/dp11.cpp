    #include <bits/stdc++.h>
    using namespace std;
    #define int long long
    const int mod=1e18+7;
    int n,m,kk;
    vector<int>v;
    vector<vector<int>>paint;
    int dp[101][101][101];
    int rec(int i, int prevcol,int k){
        if(k<0)return 1e18;
        if(i>=n){
            if(k==0)return 0;
            return 1e18;
        }
        if(dp[i][prevcol][k]!=-1)return dp[i][prevcol][k];
        int ans=1e18;
        if(v[i]!=0){
        return  dp[i][prevcol][k]=rec(i+1,v[i],k-(prevcol!=v[i] || i==0));
        }
        for(int col=1;col<=m;col++){
            ans=min(ans,paint[i][col-1]+rec(i+1,col,k-(prevcol!=col)));
        }
        return  dp[i][prevcol][k]= ans;
    }
    void solve()
    {
        cin>>n>>m>>kk;
        v.clear();
        v.resize(n);
        paint.clear();
        paint.resize(n,vector<int>(m));
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)cin>>v[i];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>paint[i][j];
            }
        }
        int ans=rec(0,v[0],kk);
        if(ans==1e18){
            cout<<-1<<endl;
            return;
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