#include<bits/stdc++.h>
using namespace std;
// #define int long long
void sol(){
    int n,m,k;
    cin>>n>>m>>k;
    string a,b;
    cin>>a;
    cin>>b;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    string c="";
    int i=0,j=0;
    int i1=0,j1=0;
    while(i<n && j<m){
        if(i<n && i1<k && a[i]<=b[j] ){
            c+=a[i];
            i++;
            i1++;
            j1=0;
        }
        if(i<n && i1==k && b[j]>a[i] ){
            c+=b[j];
            i1=0;
            j++;
        }
        if(j<m && j1<k && a[i]>b[j]){
            c+=b[j];
            j++;
            j1++;
            i1=0;
        }
        if(j<m && j1==k && a[i]>b[j]){
            c+=a[i];
            i++;
            j1=0;
        }
       
    }
    // while(i<n){
    //     c+=a[i];
    //     i++;
    // }
    // while(j<m){
    //     c+=b[j];
    //     j++;
    // }
    cout<<c<<endl;
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        sol();
    }
}