#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
string s,t;
int dp[1001][3][1001];
int rec(int i, int ty, int left){
    if(i>=n){
        return 0;
    }
    //p=0
    //r=1
    //s=2
    if(dp[i][ty][left]!=-1)return dp[i][ty][left];
    int win=0;
    if(ty==0){//P
        if(s[i]=='S')win=1;
    }else if(ty==1){//R
        if(s[i]=='P')win=1;
    }else if(ty==2){
        if(s[i]=='R')win=1;
    }
    int ans=0;
    if(left<k){
        // change 
        ans=win+max({rec(i+1,ty,left ),rec(i+1,(ty+1)%3,left+1 ),rec(i+1,(ty+2)%3,left+1)});
    }else{
        //notchange
        ans=win+rec(i+1,ty,left);
    } 
    return dp[i][ty][left]=ans;
}
void solve()
    //p=0
{	//r=1
    //s=2
    cin>>n>>k;
    cin>>s;
    t="";
    memset(dp,-1,sizeof(dp));
    int res=max({rec(0,0,0),rec(0,1,0 ),rec(0,2,0)});
    int c=0,p,ans=res;
    if(res==rec(0,0,0))p=0;
    else if(res==rec(0,1,0))p=1;
    else p=2;

    for(int i=0;i<n;i++){
        if(c+(p!=0)<=k && ans==rec(i,0,c+(p!=0))){
            if(i && (p!=0))c++;
            p=0;
            t.push_back('P'); 
            if(s[i]=='R')ans--;
        }else if(c+(p!=1)<=k && ans==rec(i,1,c+(p!=1))){
            if(i && (p!=1))c++;
            p=1;
            t.push_back('R'); 
            if(s[i]=='S')ans--;

        }else if(c+(p!=2)<=k && ans==rec(i,2,c+(p!=2))){
            if(i && (p!=2))c++;
            p=2;
            t.push_back('S'); 
            if(s[i]=='P')ans--;

        }
    }

    cout<<res<<endl<<t<<endl;


    //
    int cnt=0;
    string moves;
    ans=res;
    if(res==rec(0,0,0))p=0;
    else if(res==rec(0,1,0))p=1;
    else p=2;
    for (int i = 0; i < n; i++) {
        if (cnt + (p != 0) <= k && ans == rec(i, 0,cnt + (p != 0))) {
            if (i && p != 0)cnt++;
            p = 0;
            moves.push_back('P');
            if (s[i] == 'R')ans--;
        }
        else if (cnt + (p != 1) <= k && ans == rec(i,1, cnt + (p != 1))) {
            if (i && p != 1)cnt++;
            p = 1;
            moves.push_back('R');
            if (s[i] == 'S')ans--;
        }
        else if (cnt + (p != 2) <= k && ans == rec(i,2 ,cnt + (p != 2))) {
            if (i && p != 2)cnt++;
            p = 2;
            moves.push_back('S');
            if (s[i] == 'P')ans--;
        } 
    }
    cout<<moves<<endl;
    //

}

signed main()
{ 
    int _t;
    cin >> _t;
    while (_t--)
        solve();
}