#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{ 
    int x,y;
    cin>>x>>y;
    if(x<=y){
        cout<<y-x<<endl;
    }else{
        int diff=(x-y);
        if(diff&1){
            cout<<1+(diff+1)/2<<endl;
            return;
        }
        cout<<(x-y)/2<<endl;
    } 
    
    return;
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