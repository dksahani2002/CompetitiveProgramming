#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
#define mx9		1000000007
#define mx7		10000007
#define mx6		1000006
#define mx5		200005
#define inf		1<<30                                 
#define eps		1e-9
#define mod		1000000007
#define PI		3.141592653589793238462643383279502884L
int dp[10010][2][2][2][2];
int len;
string k;
 int d;
string L, R;

string getBin(int x){
    string temp;
    for(int i=63; i >= 0; i--){
        if (x & (1LL << i))
            temp += '1';
        else
            temp += '0';
    }
    return temp;
}

int rec(int level,int tlo1,int tlo2,int thi1,int thi2){
    if (level == len)
        return 0;
        
    if (dp[level][tlo1][tlo2][thi1][thi2] != -1)
        return dp[level][tlo1][tlo2][thi1][thi2];
        
    int lo1 = 0, lo2 = 0, hi1 = 1, hi2 = 1;
    
    if (tlo1) lo1 = L[level] - '0';
    if (tlo2) lo2 = L[level] - '0';
    if (thi1) hi1 = R[level] - '0';
    if (thi2) hi2 = R[level] - '0';
    
    int res = 0;
    for(int i=lo1; i <= hi1; i++){
        int ntlo1=tlo1;
        int nthi1=thi1;
        if (i != L[level] - '0') ntlo1 = 0;
        if (i != R[level] - '0') nthi1 = 0;
        for(int j=lo2; j <= hi2; j++){
            int ans = 0;
            
            int ntlo2 = tlo2, nthi2 = thi2;
           
            if (j != L[level] - '0') ntlo2 = 0;
            if (j != R[level] - '0') nthi2 = 0;
            
            if (i == j){
                ans += rec(level+1, ntlo1, ntlo2, nthi1, nthi2);
            }
            else{
                ans += (1LL << (len - level - 1));
                ans += rec(level+1, ntlo1, ntlo2, nthi1, nthi2);
            }
            
            res = max(res, ans);
        }
    }
    
    return dp[level][tlo1][tlo2][thi1][thi2] = res;
}

void solve(){
 int n, m;
 cin>>n>>m;
 
 L = getBin(n);
 R = getBin(m);

 
 len = L.size();
 
 memset(dp, -1, sizeof(dp));
 
 cout<<rec(0, 1, 1, 1, 1)<<'\n';
 
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--)
    solve();
}