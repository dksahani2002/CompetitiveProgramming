#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve()
{
    int n,k;cin>>n>>k;
    vector<int>v(n),v2(n,0);
    int zerocnt=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        zerocnt+=(v[i]==0);
    }
    if(k==0){
        if(zerocnt)cout<<-1<<endl;
        else cout<<0<<endl; 
        return;
    }

    int ans=0;
    bool flip=0;
    for( int i=0;i<n;i++){
        flip^=v2[i];
        if(v[i]^flip==0){
            if(i+k-1<n){
                ans++;
                 flip^=1;
                 v2[i+k]^=1;
            }else{
                cout<<-1<<endl;
                return;
            }
        }
    }
     
    cout<<ans<<endl;
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