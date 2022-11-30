#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>vv;
int n;
map<string,int>mp;
int rec(string v){
    if(v.size()==0)return 0;
    if(mp.find(v)!=mp.end())return mp[v];
    int ans=0;
    int l=0;
    int r=v.size()-1;
    for(int i=l;i<=r;i++){
            int len=0;
            int j=i,k=i;
            while(j>=l && v[j]==v[i])j--;
            while(k<=r && v[k]==v[i])k++;
            len=k-j-1;
            string temp;
            if(j>=0)temp+=v.substr(0,j+1);
            if(k<=r)temp+=v.substr(k);
             
            ans=max(ans,len*len+rec(temp));
    }
    return mp[v]=ans;
}
void solve()
{
    cin>>n;
    vv.clear();
    vv.resize(n);
    string s;
    for(int i=0;i<n;i++){
        cin>>vv[i];
        s+=vv[i]+'0';
    }
    cout<<rec(s)<<endl;
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