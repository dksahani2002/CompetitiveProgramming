 #include <bits/stdc++.h>
 using namespace std;
 #define int long long
 const int mod=1e9+7;
 int n;
 int v[100100];
 struct node{
     int mini;
     int cnt;
     node(int m=1e9, int c=0){
         mini=m;
         cnt=c;
     }
 };
 node tree[400400];
 node merge(node &a,node&b){
     if(a.mini==b.mini)return node(a.mini,a.cnt+b.cnt);
     else if(a.mini>b.mini)return b;
     return a;
 }
 void build(int index, int l,int r){
     if(l==r){
         tree[index]=node(v[l],1);//logic change
         return;
     }
     int mid=(l+r)/2;
     build(2*index,l,mid);
     build(2*index+1,mid+1,r);
     tree[index]=merge(tree[2*index],tree[2*index+1]);
 }
 void update(int index, int l ,int r,int a,int b, int val){
     if(b<l || a>r)return;
     if(a>=l and b<=r){
        t[index].min+=val;
        return;
     }
     if(l==r){
        //  v[l]=val;
         tree[index]+=val;
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
     cin>>n;
     for(int i=0;i<n;i++)cin>>v[i];
     build(1,0,n-1);
     node ans=query(1,0,n-1,0,n-1);
     cout<<ans.mini<<ans.cnt<<endl;
      update(1,0,n-1,3,8);
     ans=query(1,0,n-1,0,n-1);
     cout<<ans.mini<<ans.cnt<<endl;
 
 
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