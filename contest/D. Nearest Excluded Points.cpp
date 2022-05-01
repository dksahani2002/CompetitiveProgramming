#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    map<pair<int, int>, pair<int, int>> ans;
    map<pair<int, int>, int> vis;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
        ans[{a, b}] = {0, 0};
        vis[{a, b}] = 0;
    }
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        int x = v[i].first, y = v[i].second;
        if (ans.find({x - 1, y}) == ans.end() && !vis[{x - 1, y}])
        {
            q.push({x - 1, y});
            vis[{x - 1, y}] = 1;
            ans[{x - 1, y}] = {x - 1, y};
        }
        if (ans.find({x, y - 1}) == ans.end() && !vis[{x, y - 1}])
        {
            q.push({x, y - 1});
            vis[{x, y - 1}] = 1;
            ans[{x, y - 1}] = {x, y - 1};
        }
        if (ans.find({x + 1, y}) == ans.end() && !vis[{x + 1, y}])
        {
            q.push({x + 1, y});
            vis[{x + 1, y}] = 1;
            ans[{x + 1, y}] = {x + 1, y};
        }
        if (ans.find({x, y + 1}) == ans.end() && !vis[{x, y + 1}])
        {
            q.push({x, y + 1});
            vis[{x, y + 1}] = 1;
            ans[{x, y + 1}] = {x, y + 1};
        }
    }
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        int x = cur.first, y = cur.second;
        if (ans.find({x - 1, y}) != ans.end() && !vis[{x - 1, y}])
        {
            q.push({x - 1, y});
            vis[{x - 1, y}] = 1;
            ans[{x - 1, y}] = ans[cur];
        }
        if (ans.find({x, y - 1}) != ans.end() && !vis[{x, y - 1}])
        {
            q.push({x, y - 1});
            vis[{x, y - 1}] = 1;
            ans[{x, y - 1}] = ans[cur];
        }
        if (ans.find({x + 1, y}) != ans.end() && !vis[{x + 1, y}])
        {
            q.push({x + 1, y});
            vis[{x + 1, y}] = 1;
            ans[{x + 1, y}] = ans[cur];
        }
        if (ans.find({x, y + 1}) != ans.end() && !vis[{x, y + 1}])
        {
            q.push({x, y + 1});
            vis[{x, y + 1}] = 1;
            ans[{x, y + 1}] = ans[cur];
        }
    }
    for (auto i : v)
    {
        cout << ans[i].first << " " << ans[i].first << endl;
        ;
    }
}