#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
vector<int>v;
bool isPalin(int l, int r){
    if(l>r)return false;
    while(l<r && v[l]==v[r])l++,r--;
    return l==r;
}
int rec(int i,int prev){
    if(i==n-1){
        if(isPalin(prev,i))return 0;
        return 1e9;
    } 
    //partition
    if(isPalin(prev,i)){
        return min( 1+rec(i+1,i+1),rec(i+1,prev));
    }
    return rec(i+1,prev);

}
void solve()
{
    cin>>n;
    v.resize(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    // memset(dp,-1,sizeof(dp));
    cout<<rec(0,0)<<endl;
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