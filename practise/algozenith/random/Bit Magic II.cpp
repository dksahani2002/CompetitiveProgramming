#include <bits/stdc++.h>
using namespace std;
#define int long long
void binary(int n){
    for(int i=63;i>=0;i--){
        if(n&(1<<i))cout<<1;
        else cout<<0;
    }
    cout<<endl;
}
int msb(int x){
    if(x==0)return -1;
    if(x<0) return 63;
    return (int)__lg(x);
}
int rsb(int x){
    if(x==0)return -1;
    return msb(x^(x-1));
}
int pow2(int x){
    if(x<=1)return false;
    return (__builtin_popcountll(x)==1);
}
int pow2_div(int x){
    if(x==0)return -1;
    return (1LL<<__builtin_ctzll(x));
}
int pow2_n(int x){
    if(x<=1)return 2;
    return (1LL<<64-__builtin_ctzll(x-1));
}
void solve()
{
    int n;
    binary(n);
    cout<<msb(n)<<endl;
    cout<<rsb(n)<<endl;
    cout<<pow2(n)<<endl;
    cout<<pow2_div(n)<<endl;
    cout<<pow2_n(n)<<endl;
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