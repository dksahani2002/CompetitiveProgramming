#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{ 
    string s;
    cin>>s;
    vector<vector<int>>v(26);
    for(int i=0;i<s.length();i++)v[s[i]-'a'].push_back(i); 
    
    int ans=1;
    for(int i=0;i<26;i++){
        int curlen=1;
        int prevlen=0;
        int curans=0;
        for(int j=1;j<v[i].size();j++){
             if(v[i][j]==v[i][j-1]+1)curlen++;
             else{
                 prevlen=0;
                 if(v[i][j]==v[i][j-1]+2){
                     prevlen=curlen;
                 }
                 curlen=1;
             }
             curans=max(curans,curlen+prevlen);
        }
        curans+=(v[i].size()>curans);
        ans=max(ans,curans);
    }
    cout<<ans<<endl;
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