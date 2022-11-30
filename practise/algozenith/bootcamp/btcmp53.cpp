#include <bits/stdc++.h>
using namespace std;

vector<string>v;
int dp[101][101][101];
int rec(int i, int leftx, int lefty){
    if(leftx<0 || lefty<0)return -1e9;
    if(i>=v.size())return 0;
    if(dp[i][leftx][lefty]!=-1)return dp[i][leftx][lefty];
    int ans=rec(i+1,leftx,lefty);
    int cntx=0,cnty=0;
    for(auto ch:v[i]){
        if(ch=='0')cntx++;
        else cnty++;
    }
    ans=max(ans,1+rec(i+1,leftx-cntx,lefty-cnty));
    return dp[i][leftx][lefty]=ans;
}
int findMaxSubset(vector<string> &vv, int x, int y)
{
    //Complete the function
    v=vv;
    memset(dp,-1,sizeof(dp));
   return rec(0,x,y);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, x, y;
    cin >> n >> x >> y;
    vector<string> v(n);
    for (auto &i : v)
    {
        cin >> i;
    }
    cout << findMaxSubset(v, x, y) << '\n';
    return 0;
}