#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
     string s;
     cin>>s;
     int x;
     cin>>x;
    int h=(s[1]-'0')+10*(s[0]-'0');
    int m=(s[4]-'0')+10*(s[3]-'0');
    
    int ah=x/60;
    int am=x%60; 

    int ch=(h+ah + (am+m)/60)%24;
    int cm=(am+m)%60;  
     int cnt=0,k=0; 
     if(s[0]==s[4] && s[1]==s[3])cnt++;
     while((ch!=h || cm!=m)  ){ 
        string s=to_string(ch);
        string t=to_string(cm);
        if(ch<10){
            s='0';
            s+=(ch+'0'); 
        }
        if(cm <10){
            t='0';
            t+=(cm+'0');
        }
        swap(t[0],t[1]);
        // cout<<"s: "<<s<<"t: "<<t<<endl;
        if(s==t){
            cnt++;
        }
        // cout<<ch <<" "<<cm <<endl;
        ch=(ah+ch + (cm+am)/60)%24;
        cm=(cm+am)%60; 
     }
     cout<<cnt<<endl;
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