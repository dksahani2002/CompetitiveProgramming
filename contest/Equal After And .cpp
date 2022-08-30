#include <bits/stdc++.h>
using namespace std;
#define int long long
// vector<int>vt(32,0);
// void generate(int n){ 
//     for(int i=31;i>=0;i--){ 
//         if(n&(1<<i))
//             vt[i]++; 
//     } 
// }
void sol()
{
    // string s;
      int n;
      cin>>n;
      vector<int>v(n);
      int tar=(1<<31);
      --tar;
      for(int i=0;i<n;i++){
          cin>>v[i];
          tar=tar&v[i];
      }
     
     int ans=0;
     int last = v[0];
     for(int i=0;i<n-1;i++){
         if(last==tar){
             last=v[i+1];
             continue;
         }
         last=v[i+1]&last;
         ans++;
     }
     if(last!=tar)ans++;
    cout<<ans<<endl;
    return;
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
        sol();
}