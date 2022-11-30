#include <bits/stdc++.h>
using namespace std;
const int mx=1e5+10;
#define ll long long
int dp[100][mx];
int n;
vector<int>v;
bool rec(int i,int sum){
    if(sum<0)return 0;
    if(i==-1)return (sum==0);
    if(dp[i][sum]!=-1)return dp[i][sum];
    return dp[i][sum]=(rec(i-1,sum) | rec(i-1,sum-v[i]));
}
vector<vector<int>> subset_queries(vector<int> &arr, vector<int> &queries) {
    // Write code here.
     
    v=arr;
    n=v.size();
    memset(dp,-1,sizeof(dp));
    vector<vector<int>>ans;
    for(auto x:queries){
        if(rec(n-1,x)){
            vector<int>temp;
            int i=n-1;
           while(x){
             if(rec(i-1,x-v[i])){
                x-=v[i];
                temp.push_back(i);
            }
            i--;
           }
           reverse(temp.begin(),temp.end());
           ans.push_back(temp);
        }else{
            ans.push_back({-1});
        }
    }
    return ans;
}

void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)cin >> arr[i];
    vector<int> queries(Q);
    for (int i = 0; i < Q; i++)cin >> queries[i];
    auto ans = subset_queries(arr, queries);

    // checker.
    if (ans.size() != Q) {
        cout << 101 << endl;
        return;
    }
    for (int i = 0; i < Q; i++) {
        auto x = ans[i];
        if (x.size() == 0) {
            cout << 101 << endl;
            continue;
        }
        if (x.size() == 1 && x[0] == -1) {
            cout << -1 << endl;
            continue;
        }
        ll sum = 0, p = -10;
        for (auto y : x) {
            if (y < 0 || y >= N || p >= y ) { // valid 0-indexed.
                sum = -1111;
                break;
            }
            p = y;
            sum += arr[y];
        }
        if (sum == queries[i]) {
            cout << 1 << endl;
        }
        else cout << 101 << endl;
    }
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
 
    int t = 1;
    // int i = 1;
    // cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}