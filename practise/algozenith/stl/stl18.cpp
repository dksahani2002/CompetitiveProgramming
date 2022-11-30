#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int mod=1e9+7;
void solve()
{
    int q;cin>>q;
    stack<int>s1,s2;
    int front;
    while(q--){
        string type;cin>>type;
        if(type=="push"){
            int x;cin>>x;
            if(s1.empty()){
                front=x;
            }
            s1.push(x);
            
            // s2.push(x);
            
        }else if(type=="pop"){
             if(s2.empty()){
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
             }
            cout<<s2.top()<<'\n';
            s2.pop();
        }else{
            if(s2.empty()){
                cout<<front<<'\n';
            }else{
                cout<<s2.top()<<'\n';
            }
        }
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