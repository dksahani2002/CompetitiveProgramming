#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{ 
    string s,t;
    cin>>s>>t;
    int n=s.size();
    int m=t.size();
    int good_chars=0;
    int required_good_chars=0;
    int tcnt[26]={0};
    for(char c:t){
        ++tcnt[c-'a'];
        if(tcnt[c-'a']==1)required_good_chars++;
    }
    int wcnt[26]={0};
    int start=0;
    int best_start=-1,best_end;
    for(int i=0;i<n;i++){
        ++wcnt[s[i]-'a'];
        if(wcnt[s[i]-'a']==tcnt[s[i]-'a'])++good_chars;
        while(start<=i){
            if(wcnt[s[start]-'a']-1<tcnt[s[start]-'a'])break;
            --wcnt[s[start]-'a'];
            ++start;
        }
        if(good_chars==required_good_chars){
            if(best_start==-1 || (best_end - best_start+1>i-start+1)){
                best_start=start;
                best_end=i;
            }
        } 
    }
    cout<<s.substr(best_start, (best_end - best_start + 1))<<endl;;
    return ;
    // int il=0,ir=0;
    // string ans="";
    // while(s[il]!=t[ir]){
    //     il++;
    // }
    // while(ir<m){
    //     if(s[il]==t[ir]){
    //         ans+=s[il];
    //         il++;
    //         ir++;
    //     }else{
    //         ans+=s[il];
    //         il++;
    //     }
    // }
    //  cout<<ans<<endl;
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