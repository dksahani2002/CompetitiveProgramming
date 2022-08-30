#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
string s;
bool check(int mid){
    int l=-1,r=n,cnt=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1')cnt++;
        if(cnt<=mid)l=i;
    }
    if(cnt+1<=mid)return 1;
    while(r>0 && s[r-1]=='0')r--;
    if(l>=r)return 1;
    cnt=0;
    for(int i=l+1;i<r;i++){
        if(s[i]=='0')cnt++;
    }
    if(cnt<=mid)return 1;
    while(l>=0){
        l--;cnt++;
        while(l>=0 && s[l]=='0'){
            l--;
            cnt++;
        }
        r--;
        while(s[r-1]=='0'){
            r--;
            cnt--;
        }
        if(cnt<=mid)return 1;
    }
    return 0;
}
void sol()
{
    // string s;
    cin >> s;
    // int ans = 0;
    n = s.size();
    int l=0,r=n,ans=n;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            r=mid-1;
            ans=mid;
        }else{
            l=mid+1;
        }
    }
    cout<<ans<<endl;
    return;
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
        sol();
}