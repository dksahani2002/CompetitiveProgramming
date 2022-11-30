#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,q,c;
void solve()
{
    cin>>n>>q>>c;
    int brt[101][101][11]={0};
    for(int i=0;i<n;i++){
        int x,y,w;cin>>x>>y>>w;
        brt[x][y][w]++;
    }
    for(int k=0;k<11;k++){
        for(int i=1;i<101;i++){
            for(int j=1;j<101;j++){
                brt[i][j][k]+=brt[i-1][j][k];
                brt[i][j][k]+= brt[i][j-1][k];
                brt[i][j][k]-= brt[i-1][j-1][k];
            }
        }
    }
    while(q--){
        int t,x1,y1,x2,y2;
        cin>>t>>x1>>y1>>x2>>y2;
        int val=0;
        for(int i=0;i<=c;i++){ 
            int cur=(i+t)%(c+1);
            val+=(brt[x2][y2][i]+brt[x1-1][y1-1][i]-brt[x1-1][y2][i]-brt[x2][y1-1][i])*cur;
        }
        cout<<val<<endl;
    }
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