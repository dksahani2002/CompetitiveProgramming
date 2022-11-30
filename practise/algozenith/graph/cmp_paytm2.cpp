#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve()
{
    // int arr[] = {-3, -3, -7, -7, -1, -7, 3, 3, -2, -1, 0, -7};
   int  arr[] = {3, 4, -8, 6, -7, 5};
    priority_queue<int,vector<int>,greater<int>>pq;
    int sum=0;
    vector<int>ans;
    for(int i=0;i<6;i++){
         if(arr[i]<0)pq.push(arr[i]);
        sum+=arr[i];
        ans.push_back(arr[i]);
        if(sum<0){
             auto it=find(ans.begin(),ans.end(),pq.top());
             sum-=*it;
             ans.erase(it);
        }
    }
    for(auto i:ans){
        cout<<i<<" ";
    }

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