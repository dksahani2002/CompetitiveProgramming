#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol(){
    int n,m;
    cin>>n>>m;
    vector<string>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]=='R'){
                for(int l=i+1;l<n;l++){
                    for(int r=0;r<j;r++){
                        if(v[l][r]=='R'){
                            cout<<"NO\n";
                            return;
                        }
                    }
                }
                cout<<"YES\n";
                return;
            }

        }
    }
    cout<<"YES\n";
    return;
}
signed main(){
    int t;cin>>t;
   while(t--) sol();
}