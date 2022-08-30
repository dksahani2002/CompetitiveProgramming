#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<string>mapp={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"},ans;
void rec(int i ,string &s,string temp){
    if(i==s.size()){
        ans.push_back(temp);
        return;
    }
    string let=mapp[s[i]-'0'];
    for(auto &c:let){
        temp+=c;
        rec(i+1,s,temp);
        temp.pop_back();
    }
}
void solve()
{
    string s;cin>>s;
    string temp="";
    rec(0,s,temp);
    for(auto i : ans){
        cout<<i<<endl;
    }
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