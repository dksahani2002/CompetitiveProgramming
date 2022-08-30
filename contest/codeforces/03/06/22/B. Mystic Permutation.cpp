#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;cin>>n;
    vector<int>p(n),v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        p[i]=v[i];
    }
    if(n==1){
        cout<<-1<<endl;
        return ;
    }
    sort(v.begin(),v.end());
    int j=0;
    for(int i=0;i<n;i++){
        if(v[i]==p[i] && i+1<n){
            swap(v[i],v[i+1]);
        }
    }
    if(v[n-1]==p[n-1]){
        swap(v[n-1],v[n-2]);
    }  
    for(auto i:v){
        cout<<i<<" ";
    }
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