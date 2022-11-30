#include <bits/stdc++.h>
using namespace std;
#define double long double
const int mod=1e9+7;
void solve()
{
    int n,k;cin>>n>>k;
    vector<int>v1(n),v2(n);
    for(int i=0;i<n;i++)cin>>v1[i];
    for(int i=0;i<n;i++)cin>>v2[i];
    double l=0,r=1e18;
    double ans=0;
    while (abs(l-r)>1e-9)
    {
        double mid=(l+r)/2.0;
        priority_queue<double,vector<double>,greater<double>>pq;
        for(int i=0;i<n;i++){
            double val=(1.0*v1[i]-mid*v2[i]);
            pq.push(val);
            if(pq.size()>k){
                pq.pop();
            }
        }
        double res=0.0;
        while(!pq.empty()){
            res+=pq.top();
            pq.pop();
        }
        if(res>=0.0){
            ans=mid;
            l=mid;
        }else{
            r=mid;
        }
        /* code */
    }
    cout<<fixed<<setprecision(6)<<ans<<endl;
    
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