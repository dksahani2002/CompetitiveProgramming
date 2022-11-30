#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
bool check(string&s){
    int l=0,r=s.size()-1;
    while(l<=r){
        if(s[l]!=s[r])return false;
        l++;
        r--;
    }
    return true;
}
void solve()
{
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        string str=s.substr(0,i)+s.substr(i+1);
        if(check(str)){
            cout<<"Y\n";
            return;
        }
    }
    cout<<"N\n";
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