#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
vector<string>ans,res;

bool check(int r,int c){
    for(int i=0;i<9;i++){
        if(i!=r && res[i][c]==res[r][c])return false;
        if(i!=c && res[r][i]==res[r][c])return false;
    }
    int si=(r/3)*3;
    int sj=(c/3)*3;
    for(int i=si;i<si+3;i++){
        for(int j=sj;j<sj+3;j++){
            if(i!=r && j!=c && res[i][j]==res[r][c])return false;
        }
    }
    return true;
}
void rec(int i, int j){
    if(i==9){
        ans=res;
        return;
    }
    if(res[i][j]=='.'){
        for(int num=1;num<=9;num++){
            res[i][j]=num+'0';
            if(check(i,j)){
                rec(i+(j==9),(j+1)%10);
            }
        }
        res[i][j]='.';
    }else{
         rec(i+(j==9),(j+1)%10);
    }
}
void solve()
{
    res.resize(9);
    for(int i=0;i<9;i++)cin>>res[i];
    rec(0,0);
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<endl;
     

}
signed main()
{
    fast;
    int t=1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}