#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;cin>>n;
    int m=n;
    int ans=0;  
    int cnt=0;
    for (int i=2; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            // If divisors are equal, print only one
            if (n/i == i)
                {ans++;
                cnt++;}
 
            else // Otherwise print both
                ans+=2;
        }
    }
    ans*=2;
     
    
    if(m%2==0)ans+=1;
    else ans+=2;
    cout<<ans<<endl;
      
     
     
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