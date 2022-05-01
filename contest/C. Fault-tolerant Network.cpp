#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        //case1
        int ans=INT_MAX,cost=0;
        cost=abs(a[0]-b[0])+abs(a[n-1]-b[n-1]);
        ans=min(ans,cost);
        //case2
        cost=abs(a[0]-b[n-1])+abs(a[n-1]-b[0]);
        ans=min(ans,cost);
        //case3 (1)
        cost=abs(a[0]-b[0]);
        int temp1=INT_MAX;
        for(int i=0;i<n-1;i++){
            temp1=min(temp1,abs(a[n-1]-b[i]));
        }
        cost+=temp1;
        temp1=INT_MAX;
        for(int i=0;i<n-1;i++){
            temp1=min(temp1,abs(b[n-1]-a[i]));
        }
        cost+=temp1;
        ans=min(ans,cost);

        //case3 (2)
        cost=abs(a[n-1]-b[n-1]);
        int temp1=INT_MAX;
        for(int i=1;i<n;i++){
            temp1=min(temp1,abs(a[n-1]-b[i]));
        }
        cost+=temp1;
        temp1=INT_MAX;
        for(int i=1;i<n;i++){
            temp1=min(temp1,abs(b[n-1]-a[i]));
        }
        cost+=temp1;
        ans=min(ans,cost);
    }
}