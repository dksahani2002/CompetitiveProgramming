#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
int grid[1001][1001];
void swapRow(int i,int j){
    for(int col=0;col<m;col++){
        swap(grid[i][col],grid[j][col]);
    }
}
void swapCol(int i,int j){
    for(int row=0;row<n;row++){
            swap(grid[row][i],grid[row][j]);
        }
}
void solve()
{
    cin>>n>>m>>k;
    // grid.clear();
    // int grid[n][m];
    // memset(grid,0,sizeof(grid));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)cin>>grid[i][j];
    }
    int r[n],c[m];
    for(int i=0;i<n;i++)r[i]=i;
    for(int i=0;i<m;i++)c[i]=i;
    while(k--){
        char ch;
        int i,j;
        cin>>ch>>i>>j;
        i--;j--;
        if(ch=='c'){
            // swapCol(i,j);
            swap(r[i],r[j]);
            // for(int col=0;col<m;col++){
            //     swap(grid[i][col],grid[j][col]);
            // }
        }else if(ch=='r'){
            swap(c[i],c[j]);
            // swapRow(i,j);
            // for(int row=0;row<n;row++){
            //     swap(grid[row][i],grid[row][j]);
            // }
        }else{
            cout<<grid[r[i]][c[j]]<<endl;
        }
    }
}

signed main()
{
    int t=1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}