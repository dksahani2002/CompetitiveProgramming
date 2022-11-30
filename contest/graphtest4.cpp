#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;cin>>n;
    vector<string>v(n),res(n);
    for(int i=0;i<n;i++)cin>>v[i];
    map<int,string>mp;
    for(int i=0;i<n;i++){
        int r;cin>>r;
        r--;
        res[i]=v[r];
        // cout<<res[i]<<endl;
    }
    vector<vector<int>>g(26);
    int indeg[26]{};
    for(int i=1;i<n;i++){
        string s1=res[i-1];
        string s2=res[i];
        int j=0;
        while(j<s1.size()and j<s2.size() and s1[j]==s2[j]){
            j++;
        }
        if(j==s2.size()){
            cout<<"NO"<<endl;
            return;
        }
        if(j<s1.size()){
            g[s2[j]-'a'].push_back(s1[j]-'a');
            indeg[s1[j]-'a']++;
        }

    }
    queue<int>q;
    for(int i=0;i<26;i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }
    int count=0;
    while(!q.empty()){
        int sz=q.size();
        while(sz--){
            count++;
            int node=q.front();
             q.pop();
             for(auto v:g[node]){
                if(--indeg[v]==0)q.push(v);
             }
        }
    }
    if(count==26){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
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