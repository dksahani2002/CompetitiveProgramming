#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>v;
void ugly(){
    v.clear();
    v.resize(1501);
    v[0]=1;
    int i=0,j=0,k=0;
    for(int id=1;id<=1500;id++){
        int num=min({v[i]*2,v[j]*3,v[k]*5});
        if(num==v[i]*2)i++;
        if(num==v[j]*3)j++;
        if(num==v[k]*5)k++;
        v[id]=num;
    }
}
void solve()
{
    int n;cin>>n;
    cout<<v[n-1]<<endl;
}

signed main()
{
 

    int _t;
    cin >> _t;
    ugly();
    while (_t--)
        solve();
}