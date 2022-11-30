    #include <bits/stdc++.h>
    using namespace std;
    #define int long long
    const int mod=1e9+7;
    int n,k;
    vector<int>v;
    bool check(int mid){
        int val=0;
        for(int i=1;i<n;i++){
            val+=(v[i]-v[i-1]-1)/mid;
        }
        return val<=k;
    }
    void solve()
    {
        cin>>n>>k;
        v.clear();
        v.resize(n);
        for(int i=0;i<n;i++)cin>>v[i];
        int ans=1e9;
        int l=1,r=1e9;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(mid)){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        cout<<ans<<endl;
    }
    signed main()
    {
        int t=1;
        cin >> t;
        while (t--)
        {
            solve();
        }
    }