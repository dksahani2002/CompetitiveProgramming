#include <bits/stdc++.h>
using namespace std;
#define int long long
bool prime[100100];
// bool prime2[100100];
// void SieveOfEratosthenes(int n)
// { 
   
 
//     for (int p = 2; p * p <= n; p++) {
        
//         if (prime[p] == true) {
            
//             for (int i = p * p; i <= n; i += p)
//                 prime[i] = false;
//         }
//     } 
    
// }
// bool isPrime(int n){
//     return prime[n];
// }
void solve()
{
    int n;cin>>n;
    int ans=0;
    if(n==2){
        cout<<0<<endl;
        return;
    }
     int m=n/2;
    if(n&1){
       
        cout<<((m)*(m+1))-1<<endl;
        return;
    }
     
    if(m%2==0){
        cout<<(m-1)*(m+1)-1<<endl;
        return;
    }else{
        cout<<(m-2)*(m+2)-1<<endl;

    }
     
}

signed main()
{
    int t;
    cin >> t;
    // memset(prime, true, sizeof(prime));
    // SieveOfEratosthenes(100100);
    while (t--)
    {
        solve();
    }
}