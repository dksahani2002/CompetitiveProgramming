#include<bits/stdc++.h>
using namespace std;
#define int long long

void sol(){ 
    for(int i=0;i<1e6;i++){
        
    }
       int n,k; cin>>n>>k;
    int v[n];
    map<int,int>map1,map2;
    for(int iit=0;iit<n;iit++){
        cin>>v[iit];
        map2[v[iit]]++;
    }
    for(auto iit:map2){
        if(iit.second>=k){
            map1[iit.first]=iit.second;
        }
    }
    if(map1.size()==0){
        cout<<-1<<endl;
        return;
    }
    int res=1,cnt=1;
    // cout<<"l= "<<l<<endl;

    int l=map1.begin()->first;
    int r=map1.begin()->first;
    auto iit=map1.begin();
    iit++;
    while(iit!=map1.end()){
        auto jit=iit;
        jit--;
        int last=jit->first;
        cnt=1;
        while(iit!=map1.end() and iit->first-jit->first==1){
            cnt++;
            iit++;
            jit++;
        }
        if(cnt>res){
            res=cnt;
            l=last;
            r=jit->first;
        }
        if(iit!=map1.end())
        iit++;
    }
    cout<<l<<" "<<r<<endl;
    return;
        //  int ansl,ansr;
        //  vector<int>res;
        //  for(auto iit:map1){
        //      if(iit.second>=k){
        //          res.push_back(iit.first);
        //      } 
        //  }
        //  if(res.size()==0){
        //      cout<<-1<<endl;
        //  return;
        //  }
        // vector<pair<int,int>>v;
        // for(int iit=0;iit<res.size();iit++){
        //     v.push_back({res[iit],res[iit]});
        //     int jit=iit;
        //     while(res[jit+1]==res[jit]+1){
        //         jit++;
        //     }
        //     v.push_back({res[iit],res[jit]});
        // }
        // int l,r;
        // int res=INT_MIN;
        // for(int iit=0;iit<v.size();iit++){
        //     pair<int,int>p=v[iit];
        //     if(p.second-p.first>res){
        //         l=p.first;
        //         r=p.second;
        //         res=p.second-p.first;
        //     }
        // } 
}
signed main(){
    int t;cin>>t;
    while(t--){
        sol();
    }
}