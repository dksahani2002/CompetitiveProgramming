#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    string t;cin>>t;
    int n;cin>>n;
    map<string,int>mp;
    int mxlen=INT_MIN;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        mxlen=max(mxlen,(int)s.size());
        mp[s]++;
    }
    int c=0;
    // string t;
    int j=0;
    while(j<t.size() && j>=0){
        int l=mxlen;
         while(l>0 && mp.find(t.substr(j,min(l,t.size()-j)))==mp.end()){
            l--;
         }
         c+=(l!=mxlen && l>0);
         if(l!=mxlen && l>0)j=j+l;
         if(l==0)j--;

    }
    cout<<c<<endl;
    return;
}

signed main()
{
    int tst;
    cin >> tst;
    while (tst--)
    {
        solve();
    }
}