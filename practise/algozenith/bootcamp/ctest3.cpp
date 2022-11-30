#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve()
{
    int n;cin>>n;
    vector<int>v(n),x(n),y(n);
    for(int i=0;i<n;i++)cin>>v[i];
    for(int i=0;i<n;i++)cin>>x[i];
    for(int i=0;i<n;i++)cin>>y[i];
    int sumx=0,dividesx=0;
    int sumy=0,dividesy=0;
    for(int i=0;i<n;i++){
        sumx+=v[i]*x[i];
        dividesx+=v[i];
        sumy+=v[i]*y[i];
        dividesy+=v[i];
    }
    int xx=sumx/dividesx;
    int yy=sumy/dividesy;
    int sum1=1e9,sum2=1e9;
    for(int i=0;i<10001;i++){
        sum1=min(sum1, i*dividesx-sumx);
        sum2=min(sum2, i*dividesy-sumy);
    }
    cout<<sum1+sum2<<endl;
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