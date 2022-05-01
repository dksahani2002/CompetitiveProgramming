#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        int h[n];
        h[0]=-1;
        for(int i=1;i<=n;i++){
            cin>>h[i];
        }
        while(q--){
            int x;cin>>x;
            int l=x,r=x;
            while(l>1){
                if(h[l]>h[x]){
                    break;
                }else{
                    l--;
                }
            }
            while(r<=n){
                if(h[r]>h[x]){
                    break;
                }else{
                    r++;
                }
            }
            if(l==1){
                if(r==n+1){
                    cout<<-1<<" "<<-1<<endl;
                }else{
                    cout<<-1<<" "<<h[r]<<endl;
                }
                
            }else{
                if(r==n+1){
                    cout<<h[l]<<" "<<-1<<endl;
                }else{
                    cout<<h[l]<<" "<<h[r]<<endl;
                }
            }
        }
    }
}