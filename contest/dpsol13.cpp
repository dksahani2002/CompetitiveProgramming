#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
string s;
vector<int>v;
int dp[1001][1001][4];
int rec(int i, int change,int pty){
    if(i>=n)return 0;
    int  ans=0; 
    if(dp[i][change][pty]!=-1)return dp[i][change][pty];
    if((pty==0 && s[i]=='S') || (pty==1 && s[i]=='P') || (pty==2 && s[i]=='R'))ans=1;
    if(change<k)return dp[i][change][pty]= ans+max({rec(i+1,change,pty),rec(i+1,change+1,(pty+1)%3),rec(i+1,change+1,(pty+2)%3)});
    return dp[i][change][pty]= ans+rec(i+1,change,pty);
}
void solve()
{
     cin>>n>>k;
     cin>>s;
     v.resize(n);
     for(auto i=0;i<n;i++)v[i]=(s[i]-'A');
     memset(dp,-1,sizeof(dp));
     int val=rec(0,0,0);
     cout<<val<<endl;
     //generate();
     string mov="";
     cout<<mov<<endl;


     //string moves;
     
    int p=2,cnt=0,ans=val;
    string moves;
    if(rec(0,0,0)==val)p=0;
    if(rec(0,0,1)==val)p=1;
    for (int i = 0; i < n; i++) {
        if (cnt + (p != 0) <= k && ans == rec(i, cnt + (p != 0), 0)) {
            if (i && p != 0)cnt++;
            p = 0;
            moves.push_back('P');
            if (s[i] == 'S')ans--;
        }
        else if (cnt + (p != 1) <= k && ans == rec(i, cnt + (p != 1), 1)) {
            if (i && p != 1)cnt++;
            p = 1;
            moves.push_back('R');
            if (s[i] == 'P')ans--;
        }
        else if (cnt + (p != 2) <= k && ans == rec(i, cnt + (p != 2), 2)) {
            if (i && p != 2)cnt++;
            p = 2;
            moves.push_back('S');
            if (s[i] == 'R')ans--;
        }
    }
    cout << moves << endl;

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