#include <bits/stdc++.h>
using namespace std;
#define int long long
int grid[9][9];
bool check(int i, int j , int val){
    for(int k=0;k<9;k++){
        if(grid[i][k]==val || grid[k][j]==val)return false;
        
    }
    int l=(i/3)*3,r=(j/3)*3;
    for(int a=l;a<l+3;a++){
        for(int b=r;b<r+3;b++){
            if(grid[a][b]==val)return false;
        }
    }
    return true;
}
void sudukoSolver(int i , int j){
    if(i==9){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<grid[i][j];
            }
            cout<<endl;
        }
        exit(0);
        return;
    }
    if(grid[i][j]==0){
        for(int val=1;val<=9;val++){
            if(check(i,j,val)){
                grid[i][j]=val;
                if(j==8)sudukoSolver(i+1,0);
                else sudukoSolver(i,j+1);
                grid[i][j]=0;
            }
        }
    }else{
        if(j==8)sudukoSolver(i+1,0);
        else sudukoSolver(i,j+1);
    }
}
void solve()
{
    // grid.assign(9,vector<int>(9,0));
    // grid(9);
    memset(grid,0,sizeof(grid));
    for(int i=0;i<9;i++){
        string s;cin>>s;
        for(int j=0;j<9;j++){
            if(s[j]=='.')grid[i][j]=0;
            else grid[i][j]=s[j]-'0';
        }
    }
    sudukoSolver(0,0);
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