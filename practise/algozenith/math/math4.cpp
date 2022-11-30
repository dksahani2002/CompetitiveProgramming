#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
vector<bool>rec(int l, int r){
    int n=sqrt(r);
    vector<bool>v(n+1,false);
    vector<int>primes;
    for(int i=2;i<=n;i++){
        if(!v[i]){
            primes.push_back(i);
            for(int j=i*i;j<=n;j+=i)v[i]=true;
        }
    }
    vector<bool>isprime(r-l+1,true);
    for(auto i:primes){
        int temp2=i*i;
        int temp=(l+i-1)/temp2;
        temp=max(temp2,temp);

        for(int j=temp;j<=r;j+=i){
            isprime[j-l]=false;
        }
    }
    if(l==1)isprime[0]=false;
    return isprime;
}
void solve()
{
    int l, r;
    cin>>l>>r;
    vector<bool>ans=rec(l,r);
    set<int>print;
    for(int i=0;i<ans.size();i++){
        if(ans[i]){
            print.insert(i+l);
        }
    }
    cout<<print.size()<<endl;
    for(auto x:print){
        cout<<x<<" ";
    }
    cout<<endl;
}
signed main()
{
    int t=1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}