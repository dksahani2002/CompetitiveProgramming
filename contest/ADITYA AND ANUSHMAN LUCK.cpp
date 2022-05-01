#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;cin>>n; 
    priority_queue<int>pq;
     int x;
    for(int i=0;i<n;i++){
       
        cin>>x;
        pq.push(x);
    }
    int score1=0,score2=0 ;
    bool chance=1;
    while(!pq.empty()){
        int val=pq.top();pq.pop();
        if(chance){
            score1+=val;
            if(val>1){
                pq.push(val/2);
            }
            
            chance=false;
        }else{
            score2+=val;
            if(val>1){
                pq.push(val/2);
            }
            chance=true;
        }
        

    }
    cout<<abs(score1-score2)<<endl;
}

signed main()
{
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
}