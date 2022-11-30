 #include <bits/stdc++.h>
 using namespace std;
 #define int long long
 const int mod=1e9+7;
 int n,m;
 vector<string>g;
 void bfs(queue<pair<int,int>>&q,vector<vector<int>>&dis){
    int dx[]={1,0,-1,0};
    int dy[]={0,1,0,-1};
    while(!q.empty()){
        auto p=q.front();q.pop();
        int i=p.first;
        int j=p.second;
        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            if(x>=0 && x<n && y>=0 && y<m && g[x][y]=='.' && dis[x][y]>1+dis[i][j]){
                dis[x][y]=1+dis[i][j];
                q.push({x,y});
            }
        }
    }
 }
 void solve()
 {
    cin>>n>>m;
    g.clear();
    g.resize(n);
    for(int i=0;i<n;i++){
         cin>>g[i];
    }
    vector<vector<int>>disa(n,vector<int>(m,1e9));
    vector<vector<int>>dism(n,vector<int>(m,1e9));
    queue<pair<int,int>>qm,qa;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]=='M'){
                dism[i][j]=0;
                qm.push({i,j});
            }
            if(g[i][j]=='A'){
                disa[i][j]=0;
                qa.push({i,j});
            }
        }
    }
    bfs(qm,dism);
    bfs(qa,disa);
    int ans=0;
    int res=1e9;
    for(int i=0;i<n;i++){
        // if(g[i][0]=='.' || g[i][0]=='A'){
            if(disa[i][0]<dism[i][0]){
                ans=1;
                res=min(res,disa[i][0]);
            }
        // }
        // if(g[i][m-1]=='.' || g[i][m-1]=='A'){
            if(disa[i][m-1]<dism[i][m-1]){
                ans=1;
                res=min(res,disa[i][m-1]);
            }
        // }

    }
    for(int j=0;j<m;j++){
        // if(g[0][j]=='.' || g[0][j]=='A'){
            if(disa[0][j]<dism[0][j]){
                ans=1;
                res=min(res,disa[0][j]);
            }
        // }
        // if(g[n-1][j]=='.' || g[n-1][j]=='A'){
            if(disa[n-1][j]<dism[n-1][j]){
                ans=1;
                res=min(res,disa[n-1][j]);
            }
        // }

    }
    // cout<<disa[3][7]<<" "<<dism[3][7]<<endl;
    if(ans){
        cout<<"YES\n";
        cout<<res<<endl;
    }else{
        cout<<"NO\n";
    }
    
 }
 signed main()
 {
     int t=1;
    //  cin >> t;
     while (t--)
     {
         solve();
     }
 }