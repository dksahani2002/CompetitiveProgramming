#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>>ans;
vector<int>temp;
void rec(int i, int n,vector<int>&v , int x,int sum){
    if(sum>x)return;
    if(i==n){
        if(sum==x){
            ans.push_back(temp);
        }
        return;
    }
    rec(i+1,n,v,x,sum);
    temp.push_back(v[i]);
    rec(i,n,v,x,sum+v[i]);
    temp.pop_back();
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    // write code here.
      rec(0,candidates.size(),candidates,target,0);
       sort(ans.begin(),ans.end());
      return ans;
}

void solve()
{ 
    int n,x;cin>>n>>x;
    vector<int>v(n); 
    for(int i=0;i<n;i++ ){
        cin>>v[i];
    }
    // vector<vector<int>>ans= combinationSum(v,x);
    vector<vector<int>>res=combinationSum(v,x);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return;
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