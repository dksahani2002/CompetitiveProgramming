#include <bits/stdc++.h>
using namespace std;
#define int long long
void binary(int n){
    vector<int>vi;
    while(n>0){
        vi.push_back(n%2);
        n/=2;
    }
    for(int i=vi.size()-1;i>=0;i--){
        cout<<vi[i];
    }
    cout<<endl;
}
void solve()
{ 
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        binary(x);
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