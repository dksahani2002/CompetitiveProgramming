#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
void solve(int n=1)
{
    int n;cin>>n;
    
    int change=0;
    int i=1;
    int count=0;
    while(count<=n){
        count+=pow(2,((i+1)/2));
        i++;
    }
    i--;
    count-=pow(2,((i+1)/2));
    i--; 
    string t(i+1,'1');
    int diff=n-count;
    int mid=i/2;
    for(int j=0;j<=i/2;j++){
        if(diff&(1<<j)){
            t[mid+j]='5';
            t[i-mid-j]='5';
        }
    }
    cout<<t<<endl;



}
signed main()
{
    int t=1;
    cin >> t;
    int i=1;
    while (i<=t)
    {
        solve();
        i++;
    }
}