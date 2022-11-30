#include <bits/stdc++.h>
using namespace std;
#define int long long
void towerofhanoi(int n , char from_rod , char to_rod , char aux_rod){
    if(n==1){
        cout<<"Move disk 1 from rod "<<from_rod<<" to rod "<<to_rod<<endl;
        return;
    }
    towerofhanoi(n-1,from_rod,aux_rod,to_rod);
    cout<<"Move disk " <<n<<" from rod "<<from_rod<<" to rod "<<to_rod<<endl;
    towerofhanoi(n-1,aux_rod,to_rod,from_rod);

}
void solve()
{ 
     int n;cin>>n;
     towerofhanoi(n,'A','C','B');
     cout<<((1<<n)-1)<<endl;
    return;
}

signed main()
{
    int t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}