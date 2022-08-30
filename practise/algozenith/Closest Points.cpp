#include <bits/stdc++.h>
using namespace std;
#define int long long int
void solve()
{
    int n, k;
    cin >> n >> k;
    priority_queue<pair<int, pair<int, int>>> pq;
    // priority_queue
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        int dist =(x * x + y * y); 
        if(pq.size()<k){
            pq.push({ dist , {x, y}});
        }else{
            pair<int, pair<int, int>>fst=pq.top();
            if(dist<fst.first){
                pq.pop();
                pq.push({ dist , {x, y}});
            }
        }
    }
    vector<  pair<int, int >> v;
    while(pq.size()){
        pair<int, pair<int, int>>fst=pq.top();
        v.push_back(fst.second);
        pq.pop();
    }
    reverse(v.begin(),v.end());
    for(auto i:v){
        cout<<i.first<<" "<<i.second<<endl;
    }

    // // sort(v.begin(), v.end());
    // for (int i = 0; i < k; i++)
    // {
    //     pair<int, pair<int, int>> x = v[i];
    //     // cout<<x.second.first<<" "<<x.second.second<<endl;
    //     if (i < n - 1)
    //     {
    //         pair<int, pair<int, int>> y = v[i + 1];
    //         if (x.first==y.first)
    //         {
    //             if (x.second.first < y.second.first)
    //             {
    //                 cout << x.second.first << " " << x.second.second << endl;
    //             }
    //             else
    //             {
    //                 cout << y.second.first << " " << y.second.second << endl;
    //                 swap(y.second.first, y.second.second);
    //             }
    //         }
    //         else
    //         {
    //             cout << x.second.first << " " << x.second.second << endl;
    //         }
    //     }
    //     else
    //     {
    //         cout << x.second.first << " " << x.second.second << endl;
    //     }
    // }
}

signed main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}