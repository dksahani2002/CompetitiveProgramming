#include <bits/stdc++.h>
using namespace std;
#define int long long

int sol(vector<int>&v, int n, int k)
{

    int i = 0, j = 0, sum = 0;
    int maxLen = INT_MIN;

    while (j < n)
    {
        sum += v[j];
        if (sum < k)
        {
            j++;
        }
        else if (sum == k)
        {
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        else if (sum > k)
        {
            while (sum > k)
            {
                sum -= v[i];
                i++;
            }
            if (sum == k)
            {
                maxLen = max(maxLen, j - i + 1);
            }
            j++;
        }
    }
    if (maxLen == INT_MIN)
        return -1;
    return maxLen;
}

void test()
{   int l=0;
    while(l<100000){
        l++;
    }
    int n, k;
    cin >> n >> k;
    vector<int>v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int ans = sol(v, n, k);
    if (ans != -1)
        cout << n - ans << endl;
    else
        cout << -1 << endl;
}

signed main()
{
 
    int _t;
    cin >> _t;
    while (_t--)
    {
        test();
    }
}
