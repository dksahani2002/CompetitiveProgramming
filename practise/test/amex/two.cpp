#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
vector<int>v;
bool check(double mid, double k){
    double work=0;
    for(int i=0;i<v.size();i++){
        if(1.0*v[i]>mid){
            work+=(1.0*v[i]-mid)*k;
        }else{
            work-=(mid-1.0*v[i]);

        }
    }
    return work<=0;
}
void solve()
{
    int n;cin>>n;
    v.clear();
    v.resize(n);
    for(int i=0;i<n;i++)cin>>v[i];
    double k;cin>>k;
    double l=1.0*(*min_element(v.begin(),v.end())),r=1.0*(*max_element(v.begin(),v.end()));
    for(int i=0;i<120;i++){
        double mid=l+(r-l)/2;
        if(check(mid,k)){
            r=mid;
        }else{
            l=mid;
        }
    }
    cout<<fixed<<setprecision(2)<<r<<endl;
}
signed main()
{
    fast;
    int t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}