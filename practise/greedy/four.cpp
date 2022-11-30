#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
void solve()
{
    int k;cin>>k;
    string s;cin>>s;
    stack<char>st;
    for(int i=0;i<s.size();i++){
        while(!st.empty() && st.top()>s[i] && k>0){
            k--;
            st.pop();
        }
        st.push(s[i]);
    }
    string t="";
    while(!st.empty()){
        t+=st.top();st.pop();
    }
    reverse(t.begin(),t.end());
    while(k--)t.pop_back();
    int i=0;
    while(i<t.size()-1 && t[i]=='0')i++;
    t=t.substr(i);
    cout<<t<<endl;
}
signed main()
{
    fast;
    int t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}