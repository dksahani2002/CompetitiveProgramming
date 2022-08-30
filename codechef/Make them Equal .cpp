#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int a,b,c;
    cin>>a>>b>>c;
    int odd,even;
    if(a==b && b==c){
        cout<<"YES\n";
        return;
    }
    if(a&1 && b&1 && c&1){
        cout<<"NO\n";
        return;
    }else if(a%2==0 && b%2==0 && c%2==0){
        
        cout<<"NO\n";
        return;
    }else{
        if(a==b || b==c || a==c){
            int mini=min({a,b,c});
            if(mini+1==a || mini+1==b){
                cout<<"YES\n";
        return;
            }
             cout<<"NO\n";
                return;
        }
        cout<<"YES\n";
        return;
    }  
     
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