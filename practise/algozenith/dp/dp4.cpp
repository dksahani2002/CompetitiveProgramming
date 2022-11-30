#include <bits/stdc++.h>
using namespace std;

#define ll long long 

int dp[101][101010];
int back[101][101010];
int rec(vector<int> &arr , int l , int sumleft){
    if(sumleft==0){
        return 1;
    }
    if(l>int(arr.size()) || sumleft<0){
        return 0;
    }
    if(dp[l][sumleft]!=-1){
        return dp[l][sumleft];
    }
    int ans=0;
    if(rec(arr,l+1,sumleft)){
        back[l][sumleft]=0;
        ans=1;
    }
    if(rec(arr,l+1,sumleft-arr[l])){
        back[l][sumleft]=1;
        ans=1;
    }
    return dp[l][sumleft]=ans;
}

void ansgen(vector<int> &ans,vector<int> &arr,int l ,int sumleft){
    if(sumleft==0){
        return ;
    }
    if(back[l][sumleft]==1){
        ans.push_back(l);
        ansgen(ans,arr,l+1,sumleft-arr[l]);
        return ;
    }
    else{
        ansgen(ans,arr,l+1,sumleft);
    }
    return ;
}

vector<vector<int>> subset_queries(vector<int> &arr, vector<int> &queries) {
    // Write code here.
    vector<vector<int>> res;

    int q=int(queries.size());
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<q;i++){

        rec(arr,0,queries[i]);
    }
    for(int i=0;i<q;i++){
        if(rec(arr,0,queries[i])==1){
            vector<int> ans;
            ansgen(ans,arr,0,queries[i]);
            res.push_back(ans);
        }
        else{
            vector<int> ans(1,-1);
            res.push_back(ans);
        }
        
    }
    return res;
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