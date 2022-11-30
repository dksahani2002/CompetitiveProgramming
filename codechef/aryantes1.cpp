#include <bits/stdc++.h>
using namespace std;
#define int long long
 
void solve()
{
    int n;cin>>n;
    vector<int>A(n);
    for(int i=0;i<n;i++)cin>>A[i];
    int x=max_element(A.begin(),A.end())-A.begin();
    int y=min_element(A.begin(),A.end())-A.begin();
    int ans=0;
    for(int i=0;i<n-1;i++){
        ans=max(ans,A[i]-A[i+1]);
    } 
    ans=max(ans,A[n-1]-A[0]);
    ans=max(ans,A[n-1]-A[y]);
    cout<<max(ans,A[x]-A[0])<<endl;
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