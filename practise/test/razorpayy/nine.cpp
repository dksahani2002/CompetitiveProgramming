#include<bits/stdc++.h>
using namespace std;
  int r,c;
vector<vector<int>> v;
  int x,y;

int dfs(int i,int j ,int chees,int move,int tc,vector<vector<int>> &vis){
  if(i<0 || j<0 || i>=r || j>=c || v[i][j]==1 ||vis[i][j]==1) return INT_MAX;
  if(i==x && j==y && tc==chees) return move;
  if(i==x && j==y ) return INT_MAX;
  int temp=chees;
  if(v[i][j]==2) temp+=1;
  int ans=INT_MAX;
  vis[i][j]=1;
  ans=min(ans,dfs(i+1,j,temp,move+1,tc,vis));
  ans=min(ans,dfs(i,j+1, temp,move+1,tc,vis));
  ans=min(ans,dfs(i-1,j, temp,move+1,tc,vis));
  ans=min(ans,dfs(i,j-1, temp,move+1,tc,vis));
  vis[i][j]=0;
  return ans;
}
void solve()
{
  cin>>r>>c;
  v.clear();
   v.resize(r,vector<int> (c,0));
  vector<vector<int>> vis(r,vector<int> (c,0));
  int tg=0;
  cin>>x>>y;
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      cin>>v[i][j];
      if(v[i][j]==2) tg++;
    }
  }
  int ans= dfs(0,0,0,0,tg,vis);
  if(ans==INT_MAX) cout<<"-1";
  else cout<<ans;
}
int main()
{ 
    solve();

}   