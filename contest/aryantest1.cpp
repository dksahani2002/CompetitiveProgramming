#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
 
vector<int> solve(int Q, vector<vector<long long>>query)
{
    for(auto x:query){
        int l=x[0];
        int r=x[1];
        int cnt=0;
        int i=2;  
        while(cnt+(i*(i+1))<=l){
             cnt+=(i*(i+1));
             i=2*i; 

        }
        int ans=0; 
        
        while(cnt+(i*(i+1))<=r){
             cnt+=(i*(i+1));
             i=2*i;
             ans+=i+1; 
        }
         while(cnt<=r){
            ans++;
            cnt+=i;
        }
        cout<<ans<<endl;
    }
    return {};
}
signed main()
{
    int t=1;
    // cin >> t;
    while (t--)
    {
        vector<vector<long long>>query;
        query.push_back({1,10});
        query.push_back({2,8});
        query.push_back({7,15});
        vector<long long> ans=solve(3,query);
        // for(auto i:ans)cout<<i<<" ";
        cout<<endl;
    }
}