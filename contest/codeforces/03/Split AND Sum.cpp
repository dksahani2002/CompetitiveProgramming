#include <bits/stdc++.h>
using namespace std;
#define int long long
  
void solve()
{
    int n;
    cin >> n;
    int arr[n];
    int tsum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        tsum += arr[i];
    }
    int currsum = 0;
    for (int i = 0; i < n; i++)
    {
        currsum += arr[i];
        if ((currsum & (tsum - currsum)) != 0)
        {
            cout << "YES" << endl;
            cout << 2 << endl;
            cout << 1 << " " << i + 1 << endl;
            cout << i + 2 << " " << n << endl;
            return;
        }
        else
        {
            int temp = currsum - arr[i];
            if (((temp) & (arr[i]) & (tsum - currsum)) != 0)
            {
                cout << "YES" << endl;
                cout << 3 << endl;
                cout << 1 << " " << i << endl;
                cout << i + 1 << " " << i + 1 << endl;
                cout << i + 2 << " " << n << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}

signed main()
{
    int t;
    cin >> t;
     
    while (t--)
    {
        solve();
    }
}