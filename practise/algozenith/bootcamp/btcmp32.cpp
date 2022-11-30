#include <bits/stdc++.h>
using namespace std;

int KthElement(vector<int> &a, vector<int> &b, int k)
{
    // Complete the function
    int l=*min_element(a.begin(),a.end());
     l=min(l,*min_element(b.begin(),b.end()));
     int r=*max_element(a.begin(),a.end());
     r=max(r,*max_element(b.begin(),b.end()));
    int ans=0;
    while(l<=r){
        int mid=(l+r)/2;
        int cnt=lower_bound(a.begin(),a.end(),mid)-a.begin();
         cnt+=lower_bound(b.begin(),b.end(),mid)-b.begin();
         if(cnt<=k-1){
            ans=mid;
            l=mid+1;
         }else{
            r=mid-1;
         }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    
    vector<int> a(n), b(m);
    
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    for (int i = 0; i < m; i++)
        cin >> b[i];
    
    cout << KthElement(a, b, k) << '\n';

    return 0;
}