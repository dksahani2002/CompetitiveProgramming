#include<bits/stdc++.h>
using namespace std;
#define int long long
// int check(int ch1 ,int ch2 , int par[], int p ){
//     int m1=0,m2=0;
//     while(par[ch1]!=-1){
//          if(par[ch1]==p){
//              m1=1;
//              break;
//          }else{
//              ch1=par[ch1];
//          }
//     }
//     while(par[ch2]!=-1){
//          if(par[ch2]==p){
//              m2=1;
//              break;
//          }else{
//              ch2=par[ch1];
//          }
//      }
//      if(m1==m2)return true;
//      else return false;
// }
int fin(int ch , int par[] , int p){
    if(ch==-1)return 0;
    if(par[ch]==p)return 1;
    return fin(par[ch],par,p);
}
signed main(){
    int n;cin>>n;
    int par[n],a[n];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==i)par[i]=-1;
        else par[i]=a[i];
    }
    int q;cin>>q;
    while(q--){
        int aa,bb,cc;
        cin>>aa>>bb>>cc;
        int p1=fin(aa, par ,cc);
        int p2=fin(bb ,par,cc);
        // int p3=fin(cc,par);
        if(p1==p2 && p1!=0){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
    return 0;
}