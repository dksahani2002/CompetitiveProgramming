#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    map<int,int>row,col;
    vector<vector<int>>v(n,vector<int>(m));
    for(int i=0;i<n;i++)row[i]=i;
    for(int i=0;i<m;i++)col[i]=i;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)cin>>v[i][j];
    }
    while(k--){
        char s;
        int i,j;
        cin>>s>>i>>j;
        i--,j--;
        if(s=='r'){
            row[i]=j;
            row[j]=i;
        }else if(s=='c'){
            col[i]=j;
            col[j]=i;
        }else{
            cout<<v[row[i]][col[j]]<<endl;
        }

    }
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