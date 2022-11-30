#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;cin>>n;
    int i=0;
    int s=0;
    while(s<n){
        s+=i;
        i++;
    }
    i--;
    int k=n-1;
    vector<int>ans(n);
    ans[n-1]=n;
    int j=n-2;
    
        while(i>0){
            ans[j]=i;
            i--;
            j--;
        }
    for(int i=0;i<j;i++){
        ans[i]=k--;
    }
    for(auto i:ans){
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