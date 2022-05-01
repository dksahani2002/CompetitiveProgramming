#include<bits/stdc++.h>
using namespace std;
string s,t,ans;
int dp[3000][3000];
int n,m;
int rec(int i , int j){
    if(s[i]=='\0' || t[j]=='\0' ){
         return 0;
        
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int  ans=0;
    if(s[i]==t[j]){
          ans=rec(i+1 , j+1)+1;
    }
    else{
        ans= max(rec(i+1 , j),rec(i , j+1)); 
     }
     
    return dp[i][j]=ans;
}
int main(){
    cin>>s;
    cin>>t;
    n=s.size();
    m=t.size();
    memset(dp,-1,sizeof(dp));
    int de=rec(0,0);
    //cout<<de<<endl;
    ans="";
    int i=0,j=0;
    while(i!=n && j!=m){
        if(s[i]==t[j]){
            ans+=s[i];
            i++;j++;
        }
        else if(dp[i+1][j]>dp[i][j+1]){
            i++;
        }
        else{
            j++;
        }
    }
    cout<<ans<<endl;
    return 0;
}