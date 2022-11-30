#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int BuyAndSellStock(vector<int> &a) 
{
    // Complete the function
    int n=a.size();
    int  pf[n],sf[n];
    for(int i=0;i<n;i++){
        int j=n-1-i;
        if(i)pf[i]=min(pf[i-1],a[i]);
        else pf[i]=a[i];
        if(j==n-1)sf[j]=a[j];
        else sf[j]=max(sf[j+1],a[j]);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,sf[i]-pf[i]);
    }
    return ans;
}

int main(){
   IOS
   
   int t;
   cin>>t;
   
   while(t--){
       int n;
       cin>>n;
       
       vector<int> a(n);

       for (int i = 0; i < n; ++i) {
           cin>>a[i];
       }
       
       cout << BuyAndSellStock(a) << "\n";
   }

   return 0;
}