#include <bits/stdc++.h>
using namespace std;

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
vector<int>v;
int nn;
// int dp[100010][3][2];
vector<vector<vector<int>>>dp;
long long rec(int i,int left, int buy){
    if(left<0)return -1e9;
    if(i>=nn){
        if(left>=0)return 0;
        return -1e9;
    }
    if(dp[i][left][buy]!=-1)return dp[i][left][buy];
    long long ans=rec(i+1,left,buy);
    if(buy){
        ans=max(ans,-v[i]+rec(i+1,left,!buy));
    }else{
        ans=max(ans,v[i]+rec(i+1,left-1,!buy));
    }
    return dp[i][left][buy]=ans;
}
long long BuyAndSellStock(vector<int> &a, int k)
{
    // Complete the function
    nn=a.size();
    v=a;
    dp.clear();
    dp.assign(nn+1,vector<vector<int>>(k+1,vector<int>(2,-1)));
    return rec(0,k,1);
}

int main()
{
    IOS int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (long long i = 0; i < n; ++i)
            cin >> a[i];

        cout << BuyAndSellStock(a, k) << "\n";
    }
    return 0;
}