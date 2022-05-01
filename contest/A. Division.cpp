#include <bits/stdc++.h>
using namespace std;
#define int long long
//  void solve(){
//
// }

signed main()
{
    int t;
    cin >> t;

    while (t--)
    {
        // cout << t << endl;
        int n, m;
        cin >> n >> m;
        vector<string> s(n);

        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
            // cout<<s[i]<<endl;
        }
        for (int j = 0; j < m; j++)
        {
             int i=0,c=0;
             while(i<n){
                
                 if(s[i][j]=='*'){
                     s[i][j]='.';
                     c++;
                     
                 } 
                if(s[i][j]=='o'){
                     for(int k=i-1;k>=0;k--){
                         if(c==0)break;
                         s[k][j]='*';
                         c--;
                     }
                      
                 }else if(i==n-1){
                     for(int k=i;k>=0;k--){
                         if(c==0)break;
                         s[k][j]='*';
                         c--;
                     } 
                 }
                  i++;
             }
        }
        for (int i = 0; i < n; i++)
        {
            // cout<<" no i "<<i<<" ";
            cout << s[i] << endl;
        }
        cout << endl;
    }
    return 0;
}