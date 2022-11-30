#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    n=n*k+(n+1);
    m=m*k+(m+1);
    vector<vector<char>>v(n,vector<char>(m,'*'));
    int cc=0;
    while(cc<k){
        for(int i=1+cc;i<n;i+=(k+1)){
            int ch=0;
            while(ch<k){
                for(int j=1+ch;j<m;j+=(k+1)){
                    v[i][j]='.';
                }
                ch++;
            }
        }
        cc++;
    }
    for(int i=0;i<n;i++){
        if(i%(k+1)==0)continue;
        int st=i%(2*(k+1));
        for(int j=st;j<m;j+=2*(k+1)){
            v[i][j]='\\';
        }
    }
    for(int i=0;i<n;i++){
        if(i%(k+1)==0)continue;
        int st=(2*(k+1))-i%(2*(k+1));
        for(int j=st;j<m;j+=2*(k+1)){
            v[i][j]='/';
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<v[i][j];
        }
        cout<<endl;
    }
    cout<<endl;

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