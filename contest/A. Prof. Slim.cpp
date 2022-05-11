#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v(n);
        int minusct=0;
        for(int i=0;i<n;i++){
            cin>>v[i];
            if(v[i]<0){
                minusct++;
            }
        }
        int flag=1;
        int k=minusct;
        minusct-=1;
        while(minusct>0){
            if(abs(v[minusct])>abs(v[minusct-1])){
                cout<<"NO\n";
                flag=0;
                break;
            }
            minusct--;
        }
        if(flag){
            int fl2=1;
            while(k<n-1){
                if(abs(v[k])>abs(v[k+1])){
                    cout<<"NO\n";
                    fl2=0;
                    break;
                }
                k++;
            }
            if(fl2){
                cout<<"YES\n";
            }
        }
        
    }
}