#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve()
{
    int n,m;
    cin>>n>>m;
    n=n*2+(n+1);
    m=m*2+(m+1);
    vector<vector<char>>v(n,vector<char>(m,'*'));
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<v[i][j];
    //     }
    //     cout<<endl;
    // }
    for(int i=1;i<n;i+=3){
        for(int j=1;j<m;j+=3){
            v[i][j]='.';
        }
        for(int j=2;j<m;j+=3){
            v[i][j]='.';
        }
    }
    for(int i=2;i<n;i+=3){
        for(int j=1;j<m;j+=3){
            v[i][j]='.';
        }
        for(int j=2;j<m;j+=3){
            v[i][j]='.';
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<v[i][j];
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