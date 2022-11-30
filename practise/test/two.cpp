 #include <bits/stdc++.h>
 using namespace std;
 #define int long long
 const int mod=1e9+7;
 int n;
 int v[100100];
 struct node{
     int sum;
     node(int c=0){
         sum+=c;
     }
 };
 node tree[400400];
 node merge(node &a,node&b){
      return (a.sum+=b.sum);
 }
 void build(int index, int l,int r){
     if(l==r){
         tree[index]=node(v[l]);//logic change
         return;
     }
     int mid=(l+r)/2;
     build(2*index,l,mid);
     build(2*index+1,mid+1,r);
     tree[index]=merge(tree[2*index],tree[2*index+1]);
 }
 void update(int index, int l ,int r,int pos, int val){
     if(pos<l || pos>r)return;
     if(l==r){
         v[l]=val;
         tree[index]=node(v[l]);
         return;
     }
     int mid=(l+r)/2;
     update(2*index,l,mid,pos,val);
     update(2*index+1,mid+1,r,pos,val);
     tree[index]=merge(tree[2*index],tree[2*index+1]);
 }
 node query(int index, int l, int r, int lq, int rq){
     if(rq<l || lq>r)return node();
     if(lq<=l && r<=rq)return tree[index];
     int mid=(l+r)/2;
     tree[2*index]=query(2*index,l,mid,lq,rq);
     tree[2*index+1]=query(2*index+1,mid+1,r,lq,rq);
     return tree[index]= merge(tree[2*index],tree[2*index+1]);
 }
 void solve()
 {
    //  cin>>n;
    int m=5;

     n=8;
    //  multiset<int>st;
     for(int i=0;i<n;i++)v[i]=1;
     vector<int>arr(m),brr(m),res;
     for(int i=0;i<m;i++){
        cin>>arr[i];
        // st.insert(i+1);
     }
     build(1,0,n-1);
     node ans=query(1,0,n-1,0,n-1);
     for(int i=0;i<m;i++){
        cin>>brr[i];
        ans=query(1,0,n-1,0,brr[i]-1);
        int s=ans.sum;
        auto it=st.lower_bound(s+brr[i]);
        cout<<arr[*it-1]<<" ";
        st.erase(it);
        update(1,0,n-1,brr[i]-1,-1);
     }
     
 
 
 }
 signed main()
 {
     int t=1;
    //  cin >> t;
     while (t--)
     {
         solve();
     }
 }