#include <bits/stdc++.h>
using namespace std;
 

long long BuyAndSellStock(vector<int> &a, int k)
{
    // Complete the function
    v=a;
    memset(dp,-1,sizeof(dp));
    return rec(0,2,1);
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