// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// void solve()
// { 
//      int n;cin>>n;
//      vector<int>v(n);
//      map<int,int>mp;
//      for(int i=0;i<n;i++){
//          cin>>v[i];
//          mp[v[i]]++;
//      }
//      map<int,int>mp2;
    
//      for(auto i:mp){
//          if(i.second>1){
//             mp2[i.first]=i.second;
//          }  
//      }
//      int mid=(n-1)/2;
//      int l=mid,r=mid+1;
//      int rl=0;
//      int rr=n-1;
//         while(l>=0 && r<n){
//             if(mp2.find(v[l])!=mp2.end() && mp2.find(v[r])!=mp2.end()){
//                 while(v[rl]!=v[l] && v[rl]!=v[r] && rl<l){
//                     rl++;
//                 }
//                 while(v[rr]!=v[l] && v[rr]!=v[r] && rr>r){
//                     rr--;
//                 }

//                 l--;
//                 r++;
//             }
//             if(mp2.find(v[l])==mp2.end()){
//                 l--;
//             }
//             if(mp2.find(v[r])==mp2.end()){
//                 r++;
//             }
//         }
//      cout<<"fuck:"<<endl;
//     return;
// }

// signed main()
// {
//     int t=1;
//     cin >> t;
//     while (t--)
//     {
//         solve();
//     }
// }

#include <bits/stdc++.h>
using namespace std;
 
map<int, int> mp;
int r, ans, j, n;

int Sol(vector<int>&v)
{
    mp.clear();
    r = n - 1, ans = n, j = 0;
    for (int i = 0; i < n; ++i)
    {
        r = n - i - 1;
        int value;
         mp.find(v[i]) != mp.end() ? value = mp[v[i]] : value = 0;
        j = max(value, j);
        mp[v[i]] = 1 + i;
        ans = min(ans, min(j, r) + j + r);
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int>v(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> v[i];
        }
        cout << Sol(v) << "\n";
    }
    return 0;
}