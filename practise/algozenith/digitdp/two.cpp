#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
const int mod=1e9+7;
string l,r;
set<int>st;
int dp[10][2][2][100][3];
int rec(int i, int lti, int rti, int sum,int flag){
    if(i>=r.size()){
        if(flag==1)sum=-sum;
        return st.count(sum);
    }
    int lo=0,ro=9,ans=0;
    if(lti)lo=l[i]-'0';
    if(rti)ro=r[i]-'0';
    if(dp[i][lti][rti][sum][flag]!=-1)return dp[i][lti][rti][sum][flag];
    for(int j=lo;j<=ro;j++){
        int lt=lti,rt=rti;
        if(j!=l[i]-'0')lt=0;
        if(j!=r[i]-'0')rt=0;
        if(flag==0)ans+=rec(i+1,lt,rt,sum-j,j==0?0:2);
        else if(flag==1)ans+=rec(i+1,lt,rt,sum-j,2);
        else ans+=rec(i+1,lt,rt,sum+j,1); 
    }
    return dp[i][lti][rti][sum][flag]=ans;
}
void init(){
    for(int i=2;i<=90;i++){
        bool check=true;
        for(int j=2;j*j<=i;j++){
            if(i%j==0){
                check=false;
                break;
            }
        }
        if(check)st.insert(i);

    } 
}
void solve()
{
    int ll,rr;cin>>ll>>rr;
    l=to_string(ll);
    r=to_string(rr);
    int diff=r.size()-l.size();
    string st="";
    while(diff--){
        st+='0';
    }
    l=st+l;
     memset(dp,-1,sizeof(dp));
    cout<<rec(0,1,1,0,0)<<endl;
}
signed main()
{
    fast;
    init();
    int t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}