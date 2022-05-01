#include <bits/stdc++.h>
using namespace std;
// #define int long long
void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            count++;
        }
    }
    int a[n]={0};
    
    if (k % 2 == 0)
    {//playing with zero
       int rem_move=k;
       if(rem_move<=count){
           for(int i=0;i<n;i++){
               if(s[i]=='0'){
                   s[i]='1';
                   rem_move--;
                   a[i]++;
               }
           }
       }else{
           rem_move-=count;
           for(int i=n-1;i>=0;i--){
               if(s[i]=='0'){
                   s[i]='1';
                   a[i]++;
               }else{
                   if(rem_move>0){
                       s[i]='0';
                       a[i]++;
                       rem_move--;
                   } 
               }
           }
       }
    }
    cout << s << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}