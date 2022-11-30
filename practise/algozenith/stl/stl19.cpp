#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve()
{
    int q;cin>>q;
    set<int>st,st2;
    while(q--){
        int type,x;cin>>type>>x;
        if(type==1){
            st.insert(x);
            st2.erase(x);
            if(!st.count(x+1))st2.insert(x+1);
        }else{
            if(!st.count(x)){
                cout<<x<<"\n";
            }else{
                cout<<*st2.lower_bound(x)<<"\n";

            }
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}