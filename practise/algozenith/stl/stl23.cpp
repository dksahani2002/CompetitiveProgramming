#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve()
{
    int  h,w,n;
    cin>>h>>w>>n;
    set<int>sh,sw;
    sh.insert(0);
    sh.insert(h);
    sw.insert(0);
    sw.insert(w);
    
    multiset<int>pqh,pqw;
    pqh.insert(h);
    pqw.insert(w);
    while(n--){
        char c;cin>>c;
        if(c=='H'){
            int x;cin>>x;
            sh.insert(x);
            auto it=sh.lower_bound(x);
            auto left=it;left--;
            auto right=it;right++;
            pqh.erase(pqh.find(*right-*left));
            pqh.insert(*it-*left);
            pqh.insert(*right-*it);
        }else{
            int x;cin>>x;
            sw.insert(x);
            auto it=sw.lower_bound(x);
            auto left=it;left--;
            auto right=it;right++;
            pqw.erase(pqw.find(*right-*left));
            pqw.insert(*it-*left);
            pqw.insert(*right-*it);
        }
        auto jalwa=pqh.end();
        jalwa--;
        int ans=*jalwa;
        jalwa=pqw.end();
        jalwa--;
        int res=*jalwa;
        cout<<ans*res<<endl;
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