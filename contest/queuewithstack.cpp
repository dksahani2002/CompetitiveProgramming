#include <bits/stdc++.h>
using namespace std;

void solve()
{
    // write your code here
    stack<int> st1, st2;
    int q;
    cin >> q;
    while (q--)
    {
        string s;
        cin >> s;
        if (s == "push")
        {

            while (!st2.empty())
            {
                for (int i = 0; i < st2.size(); i++)
                {
                    st1.push(st2.top());
                    st2.pop();
                }
            }
            int x;
            cin >> x;
            st1.push(x);
            while(!st1.empty())
            {
                 st2.push(st1.top());
                st1.pop();
            }
        }
        else if (s == "pop")
        {
            cout << st2.top() << '\n';
            st2.pop();
        }
        else
        {
            if (!st2.empty())
                cout << st2.top() << '\n';
        }
    }
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