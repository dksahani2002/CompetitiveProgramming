#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
int n,m;
string s,t;
int dp[1001][1001];
int rec(int l, int r){  
    if(l==n || r==m){
        return 0;
    }
    auto &ans=dp[l][r];
    if(ans!=-1)return ans;
    ans=max(rec(l+1,r),rec(l,r+1));
    if(s[l]==t[r]){ 
      ans=max(ans,1+rec(l+1,r+1))  ;
    } 
    return ans;
}
string ShortestCommonSupersequence(string &str1, string &str2) {
    // write code here.
    s=str1;
    t=str2;
     n=s.size();m=t.size();
     int l=0,r=0;
      memset(dp,-1,sizeof(dp));
      string res="";
    while(l<n && r<m){
        if(s[l]==t[r]){
            // res.push_back(s[l]);
            res+=s[l];
            l++;
            r++;
        }else{
            if(rec(l+1,r)>rec(l,r+1)){
                // res.push_back(s[l]);
                res+=s[l];
                l++;
            }else{
                // res.push_back(t[r]);
                res+=t[r];
                r++;
            }
        }
    }
     while(l<n){
        // res.push_back(s[l]);
        res+=s[l];
        l++;
    }
    while(r<m){
        // res.push_back(t[r]);
        res+=t[r];
        r++;
    }
   
     return res; 
}                                                                            
 
void checker() {
    string x, y;
    cin >> x >> y;
    auto s = ShortestCommonSupersequence(x, y);
    cout << s.size() << endl;
    bool f = 1;
    int i = 0, j = 0;
    while (i < x.size() && j < s.size()) {
        if (x[i] == s[j])i++, j++;
        else j++;
    }
    if (i != x.size())f = 0;
    i = 0, j = 0;
    while (i < y.size() && j < s.size()) {
        if (y[i] == s[j])i++, j++;
        else j++;
    }
    if (i != y.size())f = 0;
    cout << f << endl;
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

 
    int t = 1;
    // int i = 1;
    cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        checker();
        // i++;
    }
    return 0;
}