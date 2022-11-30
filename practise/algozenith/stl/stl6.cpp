#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int arr[10000100];
// void init(){
//     for(int i=1;i<1000001;i++){
//         arr[i]=1;
//         for(int j=i*i;j<1000001;j=j*j){
//             arr[j]=0;
//         }
//     }
// }
void solve()
{
    int n;cin>>n;
    // cout<<arr[n]<<endl;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";

}
signed main()
{
    int t=1;
    cin >> t;
    // init();
    while (t--)
    {
        solve();
    }
}