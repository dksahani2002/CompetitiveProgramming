#include <bits/stdc++.h>
using namespace std;
#define int long long
 
void solve()
{ 
     int n;cin>>n;
     int count=0;
    //   for(int i=n;i>=0;i--){
    //       int sum=0,temp=i;
    //       while(sum<n && temp>0){
    //           sum+=temp;
    //           temp--;
    //       }
    //       if(sum==n){
    //           if(temp==0)count++;
    //           count++;
    //       }
    //   }
    int i=1;
    while(1){
        int val=n-(i*(i-1))/2;
        if(val<0)break;
        if(val%i==0)count++;
        i++;
    }
      cout<<count<<endl;
    return;
} 
signed main()
{
    int t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}