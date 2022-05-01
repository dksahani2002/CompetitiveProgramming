#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main()
{ 
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int a[n+1];
        int totSum=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            totSum+=a[i];
        }
        int ans=INT_MIN;
        int val1=0,val2=0;
        int sum=0;
        for(int i=1;i<=n;i++){
                sum+=a[i];
                if(sum==0){
                    if(totSum>0){
                        val1=0;
                        val2=n-i;
                        ans=max(ans,val1+val2);
                    }else{
                        val1=0;
                        val2=-1;
                        ans=max(ans,val1+val2);
                    }
                }else if(sum>0){
                    val1=i;
                    if(totSum-sum>0){
                        val2=(n-i);
                    }else if(totSum==sum){
                        val2=0;
                    }else{
                        val2=-1;
                    }
                    ans=max(ans,val1+val2);
                }else{
                    val1=-1;
                    if(totSum+sum>0){
                        val2=(n-i);
                    }else{
                        val2=-1;
                    }
                    ans=max(ans,val1+val2);
                }

        }
        cout<<ans<<endl;
    }
    return 0;
}