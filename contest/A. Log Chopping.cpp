#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        priority_queue<int>pq;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            pq.push(x);
        }
        bool move=true;
        while(!pq.empty()){
            int l=pq.top();
            pq.pop();
            if(l==1 ){
                if(move){
                    cout<<"maomao90\n";
                }else{
                    cout<<"errorgorn\n";
                }
                break;
            }else{
                pq.push(l/2);
                pq.push(l/2+l%2);
                move=!move;
            }
        }
    }
}