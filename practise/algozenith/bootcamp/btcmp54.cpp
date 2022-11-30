#include <bits/stdc++.h>
using namespace std;
    int power(long long a, long long b, int mod){
        long long res=1LL;
        a%=mod;
        if(a==0)return a;
        while(b){
            if(b&1)res=(res*a)%mod;
            b/=2;
            a=(a*a)%mod;
        }
        return res%mod;
    }
int findMaxProd(int N)
{
    long long n=N;
    long long mod=1e9+7;
    if(n<=3)return n-1;
    else if(n%3==0){
        long long val=1LL*power(3LL,n/3,mod);
        val%=mod;
        return val;
    }
    else if(n%3==1){ 
        long long val=4LL*power(3LL,(n-4)/3,mod);
        val%=mod;
        return val;
    }
    long long val=2LL*power(3LL,n/3,mod);
    val%=mod;
    return val;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << findMaxProd(n) << '\n';
    }
    return 0;
}