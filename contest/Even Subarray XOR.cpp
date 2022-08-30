#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{ 
    int n;
    cin>>n;
    // int dig=0;
    // int m=n;
    // while(m>0){
    //     dig++;
    //     m/=2;
    // }
    // cout<<dig<<endl;
    vector<int>v1(n),v2(n);
    int check;
    if((n)%2==1){
        check=n+3;
    }else{
        check=n+2;
    }
    for(int i=2;i<n+2;i++){
        v1[i-2]=i;
        v2[i-2]=i+check;
    }
    for(int i=0;i<n;i++){
        cout<<v1[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<v2[i]<<" ";
    }
    cout<<endl;
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