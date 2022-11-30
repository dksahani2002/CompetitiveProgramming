    #include <bits/stdc++.h>
    using namespace std;
    #define int long long
    const int mod=1e9+7;
    void solve()
    {
        int n;cin>>n;
        vector<int>v(n);
        int ans=0;
        // priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++){
            cin>>v[i];
            ans+=v[i];
            // pq.push({v[i],i});
        }
        // while(pq.size()>1){
        //     auto p1=pq.top();pq.pop();
        //     auto p2=pq.top();pq.pop();
        //     p1.first--;
        //     p2.first--;
        //     if(p1.first>0)pq.push(p1);
        //     if(p2.first>0)pq.push(p2);
        // }
        // int ans=0;
        // while(!pq.empty()){
        //     auto p=pq.top();pq.pop();
        //     ans+=p.first;
        // }
        sort(v.begin(),v.end());
        ans-=v[n-1];
        if(ans>=v[n-1]){
            cout<<(ans-v[n-1])%2<<endl;
        }else{
            ans=v[n-1]-ans;
            cout<<ans<<endl;
        }

    }
    signed main()
    {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int t=1;
        cin >> t;
        while (t--)
        {
            solve();
        }
    }