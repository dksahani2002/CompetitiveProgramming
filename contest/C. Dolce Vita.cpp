#include<bits/stdc++.h>
using namespace std;
#define int long long
int find(int price , int bud , int i){
    int l=0;
    int r=1e9;
    int ans=0;
    while(l<=r){
        int mid=(l+r)/2;
        int curpr=price+mid-1;
        int rembudget=bud-(i*(mid-1));
        if(curpr<=rembudget){
             ans=mid;
             l=mid+1;
        }else{
            r=mid-1;
        }
    }
    return ans;
}
signed main(){
    int t;cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        vector<int>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        int count=0,sum=0;
        for(int i=0;i<n;i++){  
                 count+=find(v[i],x-sum ,i);
                 sum+=v[i];
            }
        cout<<count<<endl;
    }
}