#include <bits/stdc++.h>
using namespace std;
#define int long long
void rec(int x, int n , int &ans , int stop){
    //  cout<<ans<<endl;
    if(stop==10)return;
    int count=0;
    int temp=x;
    vector<int>v;
    while(temp>0){
        count++; 
        v.push_back(temp%10);
        temp/=10;

    }
    if(v.size()==n){
        return stop;
    }
    if(v.size()>=n ){
        return;
    }else{
        sort(v.begin(),v.end());
        for(int i=n-1;i>=0;i--){
             if(v[i]!=1) rec(x*(temp%10),n,ans,stop+1);
        }
           
    }
    return;
}
void solve()
{ 
     int n,x;cin>>n>>x;
     if(x==1){
         cout<<-1<<endl;
         return;
     }
     int ans=-1;
     int stop=0;
     rec(x,n,ans,stop);
     cout<<stop<<endl;
    return;
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