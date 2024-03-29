#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int arr[100100];
struct node{
    int mini;
    int cnt;
    node(int m=1e9 , int c=0){
        mini=m;
        cnt=c;
    }
};
node t[400400];
node merge(node a , node b){
    if(a.mini==b.mini){
        return node(a.mini,a.cnt+b.cnt);
    }else if(a.mini<b.mini){
        return a;
    }else {
        return b;
    }
}
void build(int index, int l , int r){
    if(l==r){
        t[index]=node(arr[l],1);
        return;
    }
    int mid=(l+r)/2;
    build(index*2,l,mid);
    build(index*2+1,mid+1,r);
    t[index]=merge(t[index*2],t[index*2+1]);
}
void update(int index ,int l , int r , int pos , int val){
    if(pos<l || pos>r){
        return;
    }
    if(l==r){
        t[index]=node(val,1);
        arr[l]=val;
        return;
    }
    int mid=(l+r)/2;
    update(index*2,l,mid,pos,val);
    update(index*2+1,mid+1,r,pos,val);
    t[index]=merge(t[index*2],t[index*2+1]);
}
node query(int index , int l , int r , int lq ,int rq){
    if(l>rq || r<lq ){
        return 1e9;
    }
    if(lq<=l && r<=rq){
        return t[index];
    }
    int mid=(l+r)/2;
    return merge(query(index*2,l,mid,lq,rq),query(index*2+1,mid+1,r,lq,rq));
}
void solve()
{ 
     cin>>n;
     for(int i=0;i<n;i++)cin>>arr[i];
     build(1,0,n-1);
     int q;cin>>q;
     while(q--){
         int ch;cin>>ch;
         if(ch==1){
             int x,v;cin>>x>>v;
             update(1,0,n-1,x,v);
         }else{
             int l , r;
             cin>>l>>r;
             node x=query(1,0,n-1,l,r);
             cout<<x.mini<<endl;
             cout<<x.cnt<<endl;
         }
     }
    return;
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