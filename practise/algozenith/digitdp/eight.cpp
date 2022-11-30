 #include <bits/stdc++.h>
 using namespace std;
 #define fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
 #define int long long
 const int mod=1e9+7;
 vector<int>fenvik_tree;
 int getNext(int n){
    return n+(n&-n);
 }
 int getParent(int n){
    return n-(n&-n);
 }
 void update(int index,int val){
    while(index<=fenvik_tree.size()){
        fenvik_tree[index]+=val;
        index=getNext(index);
    }
 }
 int getSum(int index){
    int sum=0;
    while(index>0){
        sum+=fenvik_tree[index];
        index=getParent(index);
    }
    return sum;
 }
 void solve()
 {
    int n;cin>>n;
    vector<int>v(n);
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int mx=*max_element(v.begin(),v.end());
    fenvik_tree.resize(mx+1,0);

    for(int i=n-1;i>=0;i--){
        int x=v[i];
        sum+=getSum(x-1);
        update(x,1);
    }
    // cout<<endl;
    // for(auto v:fenvik_tree){
    //    if(v!=0) cout<<v<<" ";
    // }
    // // cout<<endl;
    // cout<<getSum(12)-getSum(0)<<endl;
    cout<<sum<<endl;
 }
 signed main()
 {
     fast;
     int t=1;
    //  cin >> t;
     while (t--)
     {
         solve();
     }
 }