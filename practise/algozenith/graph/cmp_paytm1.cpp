#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve()
{
    string s;cin>>s;
    vector<int>fq(26,0),vis(26,0);
    stack<char>st;
    for(int i=0;i<s.size();i++){
        fq[s[i]-'a']++;
    }
    for(int i=0;i<s.size();i++){
        fq[s[i]-'a']--;
        if(vis[s[i]-'a'])continue;
        while(!st.empty() && st.top()<s[i] && fq[st.top()-'a']>0){
                vis[st.top()-'a']=0;
                st.pop();
        }
        st.push(s[i]);
        vis[s[i]-'a']=1;
    }
    string ans;
    while(!st.empty()){
        ans=st.top()+ans;
        st.pop();
    }
    cout<<ans<<endl;
}
signed main()
{
    int t=1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}