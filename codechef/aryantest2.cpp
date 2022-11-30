#include <bits/stdc++.h>
using namespace std;
#define int long long
 
void solve()
{
    int n,m;cin>>n>>m;
    if(n==m){
        cout<<"Yes\n";
        for(int i=0;i<n;i++)cout<<1<<" ";
        cout<<endl;
        return;
    }
    if(m<n || (m%2!=0 && n%2==0)){
        cout<<"No\n";
        return;
    }
    vector<int>A(n,m/n);
    if(n%2==1)A[0]+=(m%n);
    else{
        int left=m%n;
        for(int i=0;i<left;i++)A[i]++;

    }
    cout<<"Yes\n";
    for(int i=0;i<n;i++)cout<<A[i]<<" "; 
    cout<<endl;
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