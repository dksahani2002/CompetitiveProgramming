#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve()
{
    int n,m,p;
    cin>>n>>m>>p;
    int a[n][m],b[m][p],c[n][p];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<p;j++){
            cin>>b[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<p;j++){
            int x=0;
            int l=0,r=0;
            while(l<m && r<m){
                x+=a[i][l]*b[l][j];
                l++;
                r++;
            }
            c[i][j]=x;
            cout<<x<<" ";
        }
        cout<<endl;
    }
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