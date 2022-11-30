#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int v[1500];
void pre(){
    int i=0;
    int j=0;
    int k=0;
    v[0]=1;
    for(int l=1;l<=15;l++){
        int ele=min({2*v[i],3*v[j],5*v[k]});
        v[l]=ele;
        if(ele==2*v[i])i++;
        if(ele==3*v[j])j++;
        if(ele==5*v[k])k++;
        // cout<<" "<<ele<<"endl ";
    }
}
void solve()
{
    int n;cin>>n;
    cout<<v[n-1]<<endl;
}
signed main()
{
    pre();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}