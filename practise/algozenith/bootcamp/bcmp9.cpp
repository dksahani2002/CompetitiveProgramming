#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int maxarea(vector<int>&v){
        int ans=0;
        stack<int>st;
        v.push_back(0);
        for(int j=0;j<v.size();j++){
             while(!st.empty() && v[st.top()]>=v[j]){
                int h=v[st.top()];st.pop();
                int w=(st.empty())?j:(j-1-st.top());
                ans=max(ans,h*w);
             }
            st.push(j);
        }
        return ans;
}
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>v(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
            if(i && v[i][j])v[i][j]+=v[i-1][j];
        }
    }
    int ans=0;
     for(int i=0;i<n;i++){
       ans=max(ans,maxarea(v[i]));
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