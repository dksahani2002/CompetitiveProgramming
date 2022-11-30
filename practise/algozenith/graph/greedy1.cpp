#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve()
{
    int m;cin>>m;
    int count[m+1][2]={0};
    vector<string>v;
    for(int i=0;i<m;i++){
        string s;cin>>s;
        v.push_back(s);
        for(auto ch:s){
            if(ch=='0')count[i][0]++;
            else count[i][1]++;
        }
    }
    vector<int>id(m);
    for(int i=0;i<m;i++){
        id[i]=i;
    }
    sort(id.begin(),id.end(),[&](int a, int b){
        return count[a][1]*(v[b].length())<count[b][1]*(v[a].length());
    });
    int ans=0;
    int temp=0;
    for(auto i:id){
        for(auto ch:v[i]){
            if(ch=='0'){
                ans+=temp;
            }else{
                temp++;
            }
        }
    }
    cout<<ans<<endl;
    
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