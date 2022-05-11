#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(a) a.begin(), a.end()
void dfs(int node, vector<int> &p, vector<int> &vis, vector<int> &ans)
{
    if (vis[node] == 1)
        return;
    vis[node] = 1;
    ans.push_back(node);
    dfs(p[node], p, vis, ans);
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> p(n + 1);
        vector<vector<int>> g(n + 1);
        int root;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            p[i] = x;
            g[x].push_back(i);
            g[i].push_back(x);
        }
        if (n == 1)
        {
            cout << 1 << endl;
            cout << 1 << endl;
            cout << 1 << endl;
            cout << endl;
            continue;
        }
        vector<int> leaf;
        for (int i = 1; i <= n; i++)
        {
            if (g[i].size() == 1)
                leaf.push_back(i);
        }

        vector<int> ans;
        vector<vector<int>> res;
        vector<int> vis(n + 1, 0);
        for (auto i : leaf)
        {
            dfs(i, p, vis, ans);
            if (ans.size() == 0)
                continue;
            // cout<<ans.size()<<endl;
            // for(int j=ans.size()-1; j>=0; j--) cout<<ans[j]<<" ";
            // cout<<endl;
            reverse(all(ans));
            res.push_back(ans);
            ans.clear();
        }
        cout << res.size() << endl;
        for (auto i : res)
        {
            cout << i.size() << endl;
            for (auto j : i)
                cout << j << " ";
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}