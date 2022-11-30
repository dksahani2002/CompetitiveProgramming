#include <bits/stdc++.h>
using namespace std;
#define int long long
   
int solve()
{   int s=1;
    int i=1;
     while(s*i<1000000){ 
        s=39*i;
        i++;
     }
     cout<<s<<endl;
}

signed main()
{
    int t=1;
    // cin >> t;
    while (t--)
    {
        cout<<solve();
    }
}