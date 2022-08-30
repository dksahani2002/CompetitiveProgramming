#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
     int n;
     cin>>n;
     vector<int>v;
     for(int i=0;i<n;i++){
        v.push_back(i+1);
     }
     if(v.size()<3){

        while(n--){
                for(int i=0;i<n;i++){
                    cout<<v[i]<<" ";
                }
                swap(v[0],v[1]);
             n--;   
        }
        return;
     }
     int m=0;
     while(m<n-1){
        for(int i=0;i<n;i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
       if(m==0) swap(v[0],v[2]);
       else swap(v[m],v[m+1]);
             m++;   
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