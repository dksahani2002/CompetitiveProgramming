#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
void solve()
{
    string s;
    cin>>s;
    int l=0,r=s.size()-1;
    while(l<r){
        if(s[l]!=s[r]){
            bool t=true;
            int i=l+1,j=r;
            while(i<j){
                if(s[i]!=s[j]){
                    t=false;
                    break;
                }
                i++;
                j--;
            }
            if(t){
                cout<<"Y\n";
                return;
            }
            i=l,j=r-1;
            t=true;
            while(i<j){
                if(s[i]!=s[j]){
                    t=false;
                    break;
                }
                i++;
                j--;
            }
            if(t){
                cout<<"Y\n";
                return;
            }
            cout<<"N\n";
            return;
        }
        l++;r--;
    }
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