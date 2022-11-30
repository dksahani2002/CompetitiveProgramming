#include <bits/stdc++.h>
using namespace std;
 

int main()
{
    int n;
    cin >> n ; 
    vector<int>v(n);
    long long  sum=0;
    for(int i=0;i<n;i++){ 
        cin>>v[i]; 
        sum+=v[i];
    }
    if(sum%3!=0){
        cout<<0<<endl;
        return 0;
    }
    sum/=3;
    vector<long long>pf(n);
    for(int i=0;i<n;i++){
        if(i)pf[i]=pf[i-1]+v[i];
        else pf[i]=v[i];
    }
    long long cnt=0;
    long long ans=0;
    for(int i=0;i<n-1;i++){
        if(pf[i]==2*sum)ans+=cnt;
        if(pf[i]==sum)cnt++;
    }
    cout<<ans<<endl;
    return 0;
}